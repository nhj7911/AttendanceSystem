#pragma once

#ifndef __ACCOUN_ARRAY_H__
#define __ACCOUN_ARRAY_H__

#include "Subject.h"

//typedef Subject * SUBJECT_PTR;

//class BoundCheckSubjectPtrArray
template <class T>
class BoundCheckArray
{
private:
	//SUBJECT_PTR * arr;
	T* arr;
	int arrlen;

	BoundCheckArray(const BoundCheckArray& arr) { }
	BoundCheckArray& operator=(const BoundCheckArray& arr) { }

public:
	BoundCheckArray(int len = 100) :arrlen(len) {
		arr = new T[len];
	}
	T& operator[] (int idx) {
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	T operator[] (int idx) const {
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const {
		return arrlen;
	}
	~BoundCheckArray() {
		delete[]arr;
	}
};
#endif