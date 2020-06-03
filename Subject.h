#pragma once
#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include "String.h"

class Subject
{
private:
	int subjectID;      // ���ǹ�ȣ
	String subjectName;
	//char * subjectName;   // �����̸� //������ : �����޸� �Ҵ�.

public:
	int progresscount;	// ���� �����
	int attendcount;    // �⼮��
	int late;			// ������

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