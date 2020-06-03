#pragma once
#ifndef __HALFHOURSUBJECT_H_
#define __HALFHOURSUBJECT_H_

#include "NormalHourSubject.h"
#include "String.h"

class HalfHourSubject :public NormalHourSubject {
public:
	//HalfHourSubject(int ID, int progresscount, char * name)
	HalfHourSubject(int ID, int progresscount, String name)
		:NormalHourSubject(ID, progresscount, name) {}
	virtual void Attendhandling(int time) {
		int subjecttime = 90; //수업시간 1시간 30분
		if (time < 0)
			throw MinusException(time);
		if (subjecttime < time)
			throw ExcessException(subjecttime, time);

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
				late = 0;
				attendcount -= 1;
			}
		}
		else {
			progresscount += 1;
			cout << "결석입니다." << endl << endl;
		}
	}
};

#endif