#include "pch.h"
#include "AttendanceCommon.h"
#include "Subject.h"
#include "SubjectException.h"

Subject::Subject(int ID, int progresscount, String name)
	: subjectID(ID), progresscount(progresscount)
{
	//subjectName = new char[strlen(name) + 1];
	//strcpy(subjectName, name);
	subjectName = name;
}

/*
//������ : ���������
Subject::Subject(const Subject & ref)
	:subjectID(ref.subjectID), progresscount(ref.progresscount)
{
	subjectName = new char[strlen(ref.subjectName) + 1];
	strcpy(subjectName, ref.subjectName);
}

//������ : �����ڿ����ε�
Subject& Subject::operator=(const Subject& ref) {
	subjectID = ref.subjectID;
	progresscount = ref.progresscount;

	delete[]subjectName;
	subjectName = new char[strlen(ref.subjectName) + 1];
	strcpy(subjectName, ref.subjectName);
	return *this;
}
*/

// ������ :const ����
int Subject::GetAccID() const { return subjectID; }

void Subject::Attendhandling(int time)	// ������ : �⼮ó���ϴ� �Լ�
{
	int subjecttime = 90; //�����ð� 1�ð� 30��
	if (time < 0)
		throw MinusException(time);
	if (subjecttime < time)
		throw ExcessException(subjecttime,time);

	progresscount += 1;
	attendcount += 1;
	cout << "�⼮�Ϸ�" << endl << endl;
	/*
		// 1�ð� 30�м��� ����
		// 5�� ���� -> ����
		// ���� 3�� -> �Ἦ 1��
		// ������ 30%(27��) ���� -> �Ἦ
		if (time <= 5) {
			progresscount += 1;
			attendcount += 1;
			cout << "�⼮�Ϸ�" << endl << endl;
		}
		else if (time <= 27) {
			progresscount += 1;
			attendcount += 1;
			late += 1;
			cout << "�����Դϴ�." << endl << endl;
			if (late == 3) {
				//absentcount++;
				late = 0;
				attendcount -= 1;
			}
		}
		else {
			//absentcount++;
			progresscount += 1;
			cout << "�Ἦ�Դϴ�." << endl << endl;
		}
	*/
}

void Subject::Absenthandling(int submit) // ������ : �Ἦó���ϴ� �Լ�
{
	// ������ ���������� -> �⼮
	// ������ ����������� -> �Ἦ
	if (submit == 1) {
		progresscount += 1;
		attendcount += 1;
		cout << "�⼮�Ϸ�" << endl << endl;
	}
	else if (submit == 2) {
		//absentcount++;
		progresscount += 1;
		cout << "�Ἦ�Դϴ�." << endl << endl;
	}
}

// �⼮�� ����ϴ� �Լ�
void Subject::attendanceRate(int count, int count2) {
	double rate = 0;
	try {
		if (count2 == 0)
			throw count2;
		rate = (double)count / (double)count2 * 100;
		cout << "�⼮��: " << rate << "%" << endl;
	}
	catch (int expn) {
		rate = expn;
		cout << "���Ǹ� �������� �ʾҽ��ϴ�." << endl;
	}
}

void Subject::ShowAttendanceInfo()
{
	cout << "����ID: " << subjectID << endl;
	cout << "��  ��: " << subjectName << endl;
	cout << "���������: " << progresscount << endl;
	cout << "�⼮��: " << attendcount << endl;
	cout << "������: " << late << endl;

	attendanceRate(attendcount, progresscount);
}

/*
Subject::~Subject() // ������ : �Ҹ���
{
	delete[]subjectName;
}
*/