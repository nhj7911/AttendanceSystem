#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

#include "AttendanceCommon.h"

class MinusException
{
private:
	int time;    // ������ ������ �Ǵ� �ð�

public:
	MinusException(int val) : time(val)
	{  }

	void ShowExceptionInfo(void) const
	{
		cout << "�ð� :" << time << "���� ��ȿ���� �ʽ��ϴ�!" << endl;
	}
};

class ExcessException
{
private:
	int subjecttime; // ���� �ð�
	int time; // ������ ������ �Ǵ� �ð�
public:
	ExcessException(int st, int t)
		: subjecttime(st), time(t)
	{  }

	void ShowExceptionInfo() const
	{
		cout << "�����ð����� " << time-subjecttime << "�� �ʰ��߽��ϴ�!" << endl;
	}
};

#endif