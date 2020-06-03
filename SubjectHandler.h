#pragma once
#ifndef __SUBJECTHANDLER_H__
#define __SUBJECTHANDLER_H__

#include "Subject.h"
#include "BoundCheckArray.h"

class SubjectHandler {
private: //������ : ���������� ����Ǿ� �ִ°��� SubjectHandler ��������� �߰�
	//Subject * subjectArr[100];   // Subject ������ ���� �迭
	//BoundCheckSubjectPtrArray subjectArr; 
	BoundCheckArray<Subject*> subjectArr;
	//int subjectNum = 0;        // ����� Subject ��
	int subjectNum; // �����ڿ��� �ʱ�ȭ������
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