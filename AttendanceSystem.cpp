// AttendanceSystem3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

 /*
  * Attendance System Ver 0.2
  * 작성자: 나혜지
  * 내  용: Subject 클래스 정의, 객체 포인터 배열 적용
  */

#include "pch.h"
#include "AttendanceCommon.h"
#include "SubjectHandler.h"

//const int NAME_LEN = 20;

/*
// 나혜지 : 함수를 미리 선언
void ShowMenu(void);       // 메뉴출력
void MakeSubject(void);    // 과목추가를 위한 함수
void Attend(void);         // 출석
void Absent(void);         // 결석
void ShowAllAttendanceInfo(void); // 출결조회
*/

/*
//나혜지 : 명령어 명칭으로 줌
enum { MAKE = 1, ATTEND, ABSENT, INQUIRE, EXIT };

class Subject
{
private:
	int subjectID;      // 과목번호
	int progresscount;	// 강의 진행수
	int attendcount;    // 출석수
	int late;			// 지각수
	//int absentcount;	// 결석수
	char * subjectName;   // 과목이름 //나혜지 : 동적메모리 할당.

public:
	Subject(int ID, int progresscount, char * name)
		: subjectID(ID), progresscount(progresscount)
	{
		subjectName = new char[strlen(name) + 1];
		strcpy(subjectName, name);
	}

	//나혜지 : 복사생성자
	Subject(const Subject & ref)
		:subjectID(ref.subjectID), progresscount(ref.progresscount)
	{
		subjectName = new char[strlen(ref.subjectName) + 1];
		strcpy(subjectName, ref.subjectName);
	}

	// 나혜지 :const 선언
	int GetAccID() const { return subjectID; }

	void Attendhandling(int time)	// 나혜지 : 출석처리하는 함수
	{
		//progresscount+=1;
		// 10분 이상 -> 지각
		// 지각 3번 -> 결석 1번
		// 105분 이상 -> 결석
		if (time < 10) {
			progresscount += 1;
			attendcount += 1;
			cout << "출석완료" << endl << endl;
		}
		else if (time < 105) {
			progresscount += 1;
			attendcount += 1;
			late += 1;
			cout << "지각입니다." << endl << endl;
			if (late == 3) {
				//	absentcount++;
				//	attendcount -= 1;
				late = 0;
			}
		}
		else {
			//absentcount++; 
			progresscount += 1;
			cout << "결석입니다." << endl << endl;
		}
	}

	void Absenthandling(int submit) // 나혜지 : 결석처리하는 함수
	{
		//progresscount += 1;
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
	void attendanceRate(int count, int count2) {
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

	void ShowAttendanceInfo()
	{
		cout << "과목ID: " << subjectID << endl;
		cout << "이  름: " << subjectName << endl;
		cout << "강의진행수: " << progresscount << endl;
		cout << "출석수: " << attendcount << endl;

		attendanceRate(attendcount, progresscount);
		//cout << "출석률: " << attendanceRate(attendcount) << endl;
	}

	~Subject() // 나혜지 : 소멸자
	{
		delete[]subjectName;
	}
};
*/
/*
class SubjectHandler {
private: //나혜지 : 전역변수에 선언되어 있는것을 SubjectHandler 멤버변수에 추가
	Subject * subjectArr[100];   // Subject 저장을 위한 배열
	//int subjectNum = 0;        // 저장된 Subject 수
	int subjectNum; // 생성자에서 초기화해줬음
public:
	SubjectHandler() :subjectNum(0) {}
	~SubjectHandler() {
		for (int i = 0; i < subjectNum; i++)
			delete subjectArr[i];
	}
	void ShowMenu(void)
	{
		cout << "-----Menu------" << endl;
		cout << "1. 과목등록" << endl;
		cout << "2. 출    석" << endl;
		cout << "3. 결    석" << endl;
		cout << "4. 출결 현황 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
	}

	void MakeSubject(void)
	{
		int id;
		char name[NAME_LEN];
		int count = 0; // 나혜지 : 강의 진행률은 0으로 초기화

		cout << "[과목등록]" << endl;
		cout << "과목ID: ";	cin >> id;
		cout << "이  름: ";	cin >> name;
		cout << endl;

		subjectArr[subjectNum++] = new Subject(id, count, name);
	}

	void Attend(void)
	{
		int time;
		int id;
		cout << "[출    석]" << endl;
		cout << "과목ID: ";	cin >> id;
		cout << "수업진행시간: ";	cin >> time;

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
	}

	void Absent(void)
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

	void ShowAllAttendanceInfo(void) const
	{
		for (int i = 0; i < subjectNum; i++)
		{
			subjectArr[i]->ShowAttendanceInfo();
			cout << endl;
		}
	}
};

Subject * subjectArr[100];   // Subject 저장을 위한 배열
int subjectNum = 0;        // 저장된 Subject 수
*/

int main(void)
{
	SubjectHandler manager;
	int choice;

	while (1)
	{
		manager.ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			manager.MakeSubject();
			break;
		case ATTEND:
			manager.Attend();
			break;
		case ABSENT:
			manager.Absent();
			break;
		case INQUIRE:
			manager.ShowAllAttendanceInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}

	/* // AccountHandler에 소멸자로 써줌
	for (int i = 0; i < subjectNum; i++)
		delete subjectArr[i];
	*/

	return 0;
}

/*
void ShowMenu(void)
{
	cout << "-----Menu------" << endl;
	cout << "1. 과목등록" << endl;
	cout << "2. 출    석" << endl;
	cout << "3. 결    석" << endl;
	cout << "4. 출결 현황 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeSubject(void)
{
	int id;
	char name[NAME_LEN];
	int count=0; // 나혜지 : 강의 진행률은 0으로 초기화

	cout << "[과목등록]" << endl;
	cout << "과목ID: ";	cin >> id;
	cout << "이  름: ";	cin >> name;
	cout << endl;

	subjectArr[subjectNum++] = new Subject(id, count, name);
}

void Attend(void)
{
	int time;
	int id;
	cout << "[출    석]" << endl;
	cout << "과목ID: ";	cin >> id;
	cout << "수업진행시간: ";	cin >> time;

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
}

void Absent(void)
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

void ShowAllAttendanceInfo(void)
{
	for (int i = 0; i < subjectNum; i++)
	{
		subjectArr[i]->ShowAttendanceInfo();
		cout << endl;
	}
}
*/
