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
		int subjecttime = 180; //�����ð� 3�ð�
		if (time < 0)
			throw MinusException(time);
		if (subjecttime < time)
			throw ExcessException(subjecttime, time);

		// 3�ð���������
		// 10�� ���� -> ����
		// ���� 3�� -> �Ἦ 1��
		// ������ 30%(54��) ���� -> �Ἦ
		if (time <= 10) {
			progresscount += 1;
			attendcount += 1;
			cout << "�⼮�Ϸ�" << endl << endl;
		}
		else if (time <= 54) {
			progresscount += 1;
			attendcount += 1;
			late += 1;
			cout << "�����Դϴ�." << endl << endl;
			if (late == 3) {
				attendcount -= 1;
				late = 0;
			}
		}
		else {
			progresscount += 1;
			cout << "�Ἦ�Դϴ�." << endl << endl;
		}
	}

};

#endif