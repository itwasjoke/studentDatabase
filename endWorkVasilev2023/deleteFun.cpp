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

void deleteThisGroup(Group* group) {
	if (group) {
		deleteThisStudent(group->first_student);
		delete group;
	}
}

Group* deleteDatabase(Group* firstGroup) {
	deleteThisGroup(firstGroup);
	cout << "\n Database deleted.\n ";
	return nullptr;
}

Group* deleteGroup(Group* firstGroup, int numberGroup) {
	Group* deletedGroup=nullptr;
	Group* firstG = firstGroup;
	deletedGroup = findGroup(firstGroup, numberGroup);
	if (deletedGroup == nullptr) {
		cout << "\n Group did not found.\n ";
		return firstGroup;
	}
	if (deletedGroup) {
		if (deletedGroup == firstGroup) {
			if (firstGroup->next_group) {
				firstG = firstGroup->next_group;
			}
			else {
				firstG = nullptr;
			}
		}
		else {
			if (deletedGroup->next_group) {
				deletedGroup->next_group->prev_group = deletedGroup->prev_group;
				deletedGroup->prev_group->next_group = deletedGroup->next_group;
			}
			else {
				deletedGroup->prev_group->next_group = nullptr;
			}
		}
		Student* thisStudent = deletedGroup->first_student;
		deleteThisStudent(thisStudent);
		delete deletedGroup;
		return firstG;
	}
	else {
		cout << "\n Not found.\n ";
		return firstGroup;
	}
	
}

void deleteStudent(Group* firstGroup, int numberGroup, char studentName[SIZE_NAME]) {
	Group* studentGroup = findGroup(firstGroup, numberGroup);
	Student* deletedStudent = findStudent(firstGroup, numberGroup, studentName);
	if (deletedStudent == nullptr) {
		cout << "\n Student did not found.\n ";
		return;
	}
	if (deletedStudent) {
		if (studentGroup->first_student == deletedStudent) {
			studentGroup->first_student = deletedStudent->next_student;
			if (deletedStudent->next_student) deletedStudent->next_student->prev_student = nullptr;
		}
		else {
			if (deletedStudent->next_student) {
				deletedStudent->next_student->prev_student = deletedStudent->prev_student;
				deletedStudent->prev_student->next_student = deletedStudent->next_student;
			}
			else {
				deletedStudent->prev_student->next_student = nullptr;
			}
		}
		delete deletedStudent;
	}
	else {
		cout << "\n Not found.\n ";
	}
}