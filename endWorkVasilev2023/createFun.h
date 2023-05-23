#pragma once
#include "structures.h"
Student* createStudentList(Group* firstGroup, int numberGroup);
Group* createGroup(Group* firstGroup, int numberGroup);
void createStudent(Group* firstGroup, int numberGroup, char name[SIZE_NAME]);
Group* getDatabaseFromFile();