#pragma once
#ifndef __ATTENDANCECOMMON_H_
#define __ATEENDANCECOMMON_H_

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
const int NAME_LEN = 20;

//나혜지 : 명령어 명칭으로 줌
enum { MAKE = 1, ATTEND, ABSENT, INQUIRE, EXIT };

//수업시간 종류
enum { NORMAL=1, HALF=2 };

#endif