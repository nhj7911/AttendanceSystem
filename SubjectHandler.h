#pragma once
#ifndef __SUBJECTHANDLER_H__
#define __SUBJECTHANDLER_H__

#include "Subject.h"
#include "BoundCheckArray.h"

class SubjectHandler {
private: //나혜지 : 전역변수에 선언되어 있는것을 SubjectHandler 멤버변수에 추가
	//Subject * subjectArr[100];   // Subject 저장을 위한 배열
	//BoundCheckSubjectPtrArray subjectArr; 
	BoundCheckArray<Subject*> subjectArr;
	//int subjectNum = 0;        // 저장된 Subject 수
	int subjectNum; // 생성자에서 초기화해줬음
public:
	SubjectHandler();
	~SubjectHandler();
	void ShowMenu(void);
	void MakeSubject(void);
	void Attend(void);
	void Absent(void);
	void ShowAllAttendanceInfo(void) const;

protected:
	void MakeNormalHourSubject();
	void MakeHalfHourSubject();
};

#endif