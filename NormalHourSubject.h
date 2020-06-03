#pragma once
#ifndef __NORMALHOURSUBJECT_H_
#define __NORMALHOURSUBJECT_H_

#include "Subject.h"
#include "String.h"
#include "SubjectException.h"

class NormalHourSubject :public Subject {
public:
	//NormalHourSubject(int ID, int progresscount, char * name)
	NormalHourSubject(int ID, int progresscount, String name)
		:Subject(ID, progresscount, name) {}
	virtual void Attendhandling(int time) {
		int subjecttime = 180; //수업시간 3시간
		if (time < 0)
			throw MinusException(time);
		if (subjecttime < time)
			throw ExcessException(subjecttime, time);

		// 3시간수업기준
		// 10분 이후 -> 지각
		// 지각 3번 -> 결석 1번
		// 수업의 30%(54분) 이후 -> 결석
		if (time <= 10) {
			progresscount += 1;
			attendcount += 1;
			cout << "출석완료" << endl << endl;
		}
		else if (time <= 54) {
			progresscount += 1;
			attendcount += 1;
			late += 1;
			cout << "지각입니다." << endl << endl;
			if (late == 3) {
				attendcount -= 1;
				late = 0;
			}
		}
		else {
			progresscount += 1;
			cout << "결석입니다." << endl << endl;
		}
	}

};

#endif