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
//나혜지 : 복사생성자
Subject::Subject(const Subject & ref)
	:subjectID(ref.subjectID), progresscount(ref.progresscount)
{
	subjectName = new char[strlen(ref.subjectName) + 1];
	strcpy(subjectName, ref.subjectName);
}

//나혜지 : 연산자오버로딩
Subject& Subject::operator=(const Subject& ref) {
	subjectID = ref.subjectID;
	progresscount = ref.progresscount;

	delete[]subjectName;
	subjectName = new char[strlen(ref.subjectName) + 1];
	strcpy(subjectName, ref.subjectName);
	return *this;
}
*/

// 나혜지 :const 선언
int Subject::GetAccID() const { return subjectID; }

void Subject::Attendhandling(int time)	// 나혜지 : 출석처리하는 함수
{
	int subjecttime = 90; //수업시간 1시간 30분
	if (time < 0)
		throw MinusException(time);
	if (subjecttime < time)
		throw ExcessException(subjecttime,time);

	progresscount += 1;
	attendcount += 1;
	cout << "출석완료" << endl << endl;
	/*
		// 1시간 30분수업 기준
		// 5분 이후 -> 지각
		// 지각 3번 -> 결석 1번
		// 수업의 30%(27분) 이후 -> 결석
		if (time <= 5) {
			progresscount += 1;
			attendcount += 1;
			cout << "출석완료" << endl << endl;
		}
		else if (time <= 27) {
			progresscount += 1;
			attendcount += 1;
			late += 1;
			cout << "지각입니다." << endl << endl;
			if (late == 3) {
				//absentcount++;
				late = 0;
				attendcount -= 1;
			}
		}
		else {
			//absentcount++;
			progresscount += 1;
			cout << "결석입니다." << endl << endl;
		}
	*/
}

void Subject::Absenthandling(int submit) // 나혜지 : 결석처리하는 함수
{
	// 사유서 제출했으면 -> 출석
	// 사유서 제출안했으면 -> 결석
	if (submit == 1) {
		progresscount += 1;
		attendcount += 1;
		cout << "출석완료" << endl << endl;
	}
	else if (submit == 2) {
		//absentcount++;
		progresscount += 1;
		cout << "결석입니다." << endl << endl;
	}
}

// 출석률 계산하는 함수
void Subject::attendanceRate(int count, int count2) {
	double rate = 0;
	try {
		if (count2 == 0)
			throw count2;
		rate = (double)count / (double)count2 * 100;
		cout << "출석률: " << rate << "%" << endl;
	}
	catch (int expn) {
		rate = expn;
		cout << "강의를 진행하지 않았습니다." << endl;
	}
}

void Subject::ShowAttendanceInfo()
{
	cout << "과목ID: " << subjectID << endl;
	cout << "이  름: " << subjectName << endl;
	cout << "강의진행수: " << progresscount << endl;
	cout << "출석수: " << attendcount << endl;
	cout << "지각수: " << late << endl;

	attendanceRate(attendcount, progresscount);
}

/*
Subject::~Subject() // 나혜지 : 소멸자
{
	delete[]subjectName;
}
*/