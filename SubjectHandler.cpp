#include "pch.h"
#include "SubjectHandler.h"
#include "AttendanceCommon.h"
#include "Subject.h"
#include "NormalHourSubject.h"
#include "HalfHourSubject.h"
#include "String.h"

SubjectHandler::SubjectHandler() :subjectNum(0) {}
SubjectHandler::~SubjectHandler() {
	for (int i = 0; i < subjectNum; i++)
		delete subjectArr[i];
}
void SubjectHandler::ShowMenu(void)
{
	cout << "-----Menu------" << endl;
	cout << "1. ������" << endl;
	cout << "2. ��    ��" << endl;
	cout << "3. ��    ��" << endl;
	cout << "4. ��� ��Ȳ ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void SubjectHandler::MakeSubject(void)
{
	/*
	int id;
	char name[NAME_LEN];
	int count = 0; // ������ : ���� ������� 0���� �ʱ�ȭ

	cout << "[������]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "��  ��: ";	cin >> name;
	cout << endl;
	*/
	int subject_sel;
	cout << "[���� �ð� ����]" << endl;
	cout << "1. 3�ð� ����" << endl;
	cout << "2. 1�ð� 30�� ����" << endl;
	cin >> subject_sel;

	//subjectArr[subjectNum++] = new Subject(id, count, name);

	if (subject_sel == NORMAL) {
		MakeNormalHourSubject();
	}
	else
		MakeHalfHourSubject();

}
void SubjectHandler::MakeNormalHourSubject() {
	int id;
	//char name[NAME_LEN];
	String name;
	int count = 0; // ������ : ���� ������� 0���� �ʱ�ȭ

	cout << "[3�ð����� ������]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "��  ��: ";	cin >> name;
	cout << endl;
	subjectArr[subjectNum++] = new NormalHourSubject(id, count, name);
}

void SubjectHandler::MakeHalfHourSubject() {
	int id;
	//char name[NAME_LEN];
	String name;
	int count = 0; // ������ : ���� ������� 0���� �ʱ�ȭ

	cout << "[1�ð�30�� ���� ������]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "��  ��: ";	cin >> name;
	cout << endl;

	subjectArr[subjectNum++] = new HalfHourSubject(id, count, name);
}

void SubjectHandler::Attend(void)
{
	int time;
	int id;
	cout << "[��    ��]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "��������ð�: ";	cin >> time;

	try {
		for (int i = 0; i < subjectNum; i++)
		{
			if (subjectArr[i]->GetAccID() == id)
			{
				subjectArr[i]->Attendhandling(time);
				//	cout << "�⼮�Ϸ�" << endl << endl;
				return;
			}
		}
		cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
		return;
	}
	catch (MinusException& expt) {
		expt.ShowExceptionInfo();
		cout << "�ð��� ���Է��ϼ���." << endl;
	}
	catch (ExcessException& expt) {
		expt.ShowExceptionInfo();
		cout << "�ð��� ���Է��ϼ���." << endl;
	}
}

void SubjectHandler::Absent(void)
{
	int submit;
	int id;
	cout << "[��    ��]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "���������⿩��(1.���� 2.����X): "; cin >> submit;

	for (int i = 0; i < subjectNum; i++)
	{
		if (subjectArr[i]->GetAccID() == id)
		{
			subjectArr[i]->Absenthandling(submit);
			//	cout << "�Ἦ�Դϴ�." << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void SubjectHandler::ShowAllAttendanceInfo(void) const
{
	for (int i = 0; i < subjectNum; i++)
	{
		subjectArr[i]->ShowAttendanceInfo();
		cout << endl;
	}
}