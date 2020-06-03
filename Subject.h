#pragma once
#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include "String.h"

class Subject
{
private:
	int subjectID;      // 강의번호
	String subjectName;
	//char * subjectName;   // 수업이름 //나혜지 : 동적메모리 할당.

public:
	int progresscount;	// 강의 진행수
	int attendcount;    // 출석수
	int late;			// 지각수

	Subject(int ID, int progresscount, String name);
	//Subject(int ID, int progresscount, char * name);
	//Subject(const Subject & ref);
	//Subject& operator=(const Subject& ref);

	int GetAccID() const;

	virtual void Attendhandling(int time); 

	void Absenthandling(int submit);
	void attendanceRate(int count, int count2);
	void ShowAttendanceInfo();
	//~Subject();
};

#endif