#include "deleteFun.h"
#include "findFun.h"
#include <iostream>
using namespace std;

Group* deleteDatabase(Group* firstGroup) {
	return nullptr;
}
Group* deleteGroup(Group* firstGroup, int numberGroup) {
	Group* deletedGroup;
	Group* firstG = firstGroup;
	deletedGroup = findGroup(firstGroup, numberGroup);
	cout << "hi!";
	if (deletedGroup == firstGroup) {
		if (firstGroup->next_group == nullptr) {
			firstG = nullptr;
		}
		else {
			firstG = firstGroup->next_group;
		}
	}
	for (Student* i = deletedGroup->first_student; i != nullptr; i = i->next_student) {
		Student* currentDeletedStudent = i;
		delete currentDeletedStudent;
	}
	delete deletedGroup;
	return firstG;
}


void deleteStudent(Group* firstGroup, int numberGroup, char studentName) {

}