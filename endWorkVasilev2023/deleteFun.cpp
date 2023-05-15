#include "deleteFun.h"
#include "findFun.h"
#include "genFunctions.h"
#include <iostream>
using namespace std;

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
	Student* nextStudent = nullptr;
	Student* currentDeletedStudent = thisStudent;
	if (thisStudent != nullptr) {
		while (currentDeletedStudent) {
			nextStudent = currentDeletedStudent->next_student;
			//delete currentDeletedStudent;
			currentDeletedStudent = nextStudent;
		}
		//for (Student* i = thisStudent; i != nullptr; i = i->next_student) {
		//	Student* currentDeletedStudent = i;
		//	delete currentDeletedStudent;
		//}
	}
	
	//delete deletedGroup;
	printDatabase(firstG);
	return firstG;
}


void deleteStudent(Group* firstGroup, int numberGroup, char studentName) {

}