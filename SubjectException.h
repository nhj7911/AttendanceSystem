#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

#include "AttendanceCommon.h"

class MinusException
{
private:
	int time;    // 예외의 원인이 되는 시간

public:
	MinusException(int val) : time(val)
	{  }

	void ShowExceptionInfo(void) const
	{
		cout << "시간 :" << time << "분은 유효하지 않습니다!" << endl;
	}
};

class ExcessException
{
private:
	int subjecttime; // 수업 시간
	int time; // 예외의 원인이 되는 시간
public:
	ExcessException(int st, int t)
		: subjecttime(st), time(t)
	{  }

	void ShowExceptionInfo() const
	{
		cout << "수업시간에서 " << time-subjecttime << "분 초과했습니다!" << endl;
	}
};

#endif