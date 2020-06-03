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
	cout << "1. 과목등록" << endl;
	cout << "2. 출    석" << endl;
	cout << "3. 결    석" << endl;
	cout << "4. 출결 현황 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void SubjectHandler::MakeSubject(void)
{
	/*
	int id;
	char name[NAME_LEN];
	int count = 0; // 나혜지 : 강의 진행률은 0으로 초기화

	cout << "[과목등록]" << endl;
	cout << "과목ID: ";	cin >> id;
	cout << "이  름: ";	cin >> name;
	cout << endl;
	*/
	int subject_sel;
	cout << "[수업 시간 선택]" << endl;
	cout << "1. 3시간 수업" << endl;
	cout << "2. 1시간 30분 수업" << endl;
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
	int count = 0; // 나혜지 : 강의 진행률은 0으로 초기화

	cout << "[3시간수업 과목등록]" << endl;
	cout << "과목ID: ";	cin >> id;
	cout << "이  름: ";	cin >> name;
	cout << endl;
	subjectArr[subjectNum++] = new NormalHourSubject(id, count, name);
}

void SubjectHandler::MakeHalfHourSubject() {
	int id;
	//char name[NAME_LEN];
	String name;
	int count = 0; // 나혜지 : 강의 진행률은 0으로 초기화

	cout << "[1시간30분 수업 과목등록]" << endl;
	cout << "과목ID: ";	cin >> id;
	cout << "이  름: ";	cin >> name;
	cout << endl;

	subjectArr[subjectNum++] = new HalfHourSubject(id, count, name);
}

void SubjectHandler::Attend(void)
{
	int time;
	int id;
	cout << "[출    석]" << endl;
	cout << "과목ID: ";	cin >> id;
	cout << "수업진행시간: ";	cin >> time;

	try {
		for (int i = 0; i < subjectNum; i++)
		{
			if (subjectArr[i]->GetAccID() == id)
			{
				subjectArr[i]->Attendhandling(time);
				//	cout << "출석완료" << endl << endl;
				return;
			}
		}
		cout << "유효하지 않은 ID 입니다." << endl << endl;
		return;
	}
	catch (MinusException& expt) {
		expt.ShowExceptionInfo();
		cout << "시간만 재입력하세요." << endl;
	}
	catch (ExcessException& expt) {
		expt.ShowExceptionInfo();
		cout << "시간만 재입력하세요." << endl;
	}
}

void SubjectHandler::Absent(void)
{
	int submit;
	int id;
	cout << "[결    석]" << endl;
	cout << "과목ID: ";	cin >> id;
	cout << "사유서제출여부(1.제출 2.제출X): "; cin >> submit;

	for (int i = 0; i < subjectNum; i++)
	{
		if (subjectArr[i]->GetAccID() == id)
		{
			subjectArr[i]->Absenthandling(submit);
			//	cout << "결석입니다." << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void SubjectHandler::ShowAllAttendanceInfo(void) const
{
	for (int i = 0; i < subjectNum; i++)
	{
		subjectArr[i]->ShowAttendanceInfo();
		cout << endl;
	}
}