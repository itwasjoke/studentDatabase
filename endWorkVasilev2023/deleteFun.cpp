#include "deleteFun.h"
#include "findFun.h"
#include "genFunctions.h"
#include <iostream>
using namespace std;

void deleteThisStudent(Student* student) {
	if (student) {
		deleteThisStudent(student->next_student);
		delete student;
	}
}

Group* deleteDatabase(Group* firstGroup) {
	return nullptr;
}

Group* deleteGroup(Group* firstGroup, int numberGroup) {
	Group* deletedGroup=nullptr;
	Group* firstG = firstGroup;
	deletedGroup = findGroup(firstGroup, numberGroup);
	if (deletedGroup == nullptr) return firstGroup;
	if (deletedGroup == firstGroup) {
		if (firstGroup->next_group == nullptr) {
			firstG = nullptr;
		}
		else {
			firstG = firstGroup->next_group;
		}
	}
	else {
		if (deletedGroup->next_group == nullptr) {
			deletedGroup->prev_group->next_group = nullptr;
		}
		else {
			deletedGroup->next_group->prev_group = deletedGroup->prev_group;
			deletedGroup->prev_group->next_group = deletedGroup->next_group;
		}
	}
	Student* thisStudent = deletedGroup->first_student;
	deleteThisStudent(thisStudent);
	delete deletedGroup;
	printDatabase(firstG);
	return firstG;
}



void deleteStudent(Group* firstGroup, int numberGroup, char studentName) {

}