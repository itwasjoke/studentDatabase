#pragma once
#include "globals.h"

struct Student {
	char name[SIZE_NAME];
	int grant;
	int marks[COUNT_MARKS];
	Student* next_student;
	Student* prev_student;
};

struct Group {
	int number;
	Student* first_student;
	Group* next_group;
	Group* prev_group;
};