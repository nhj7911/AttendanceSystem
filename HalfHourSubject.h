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
		int subjecttime = 90; //�����ð� 1�ð� 30��
		if (time < 0)
			throw MinusException(time);
		if (subjecttime < time)
			throw ExcessException(subjecttime, time);

		// 1�ð� 30�м��� ����
		// 5�� ���� -> ����
		// ���� 3�� -> �Ἦ 1��
		// ������ 30%(27��) ���� -> �Ἦ
		if (time <= 5) {
			progresscount += 1;
			attendcount += 1;
			cout << "�⼮�Ϸ�" << endl << endl;
		}
		else if (time <= 27) {
			progresscount += 1;
			attendcount += 1;
			late += 1;
			cout << "�����Դϴ�." << endl << endl;
			if (late == 3) {
				late = 0;
				attendcount -= 1;
			}
		}
		else {
			progresscount += 1;
			cout << "�Ἦ�Դϴ�." << endl << endl;
		}
	}
};

#endif