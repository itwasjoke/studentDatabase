#include "findFun.h"
Student* findStudent(Group* firstGroup, int numberGroup, char* studentName) {
	Student* foundStudent = nullptr;
	for (Group* i = firstGroup; i != nullptr; i = i->next_group) {
		if (i->number == numberGroup) {
			for (Student* j = i->first_student; j != nullptr; j = j->next_student) {
				if (j->name == studentName) {
					foundStudent = j;
					break;
				}
			}
			break;
		}
	}
	return foundStudent;
}

Group* findGroup(Group* firstGroup, int numberGroup) {
	Group* foundGroup = nullptr;
	for (Group* i = firstGroup; i != nullptr; i = i->next_group) {
		if (i->number == numberGroup) {
			foundGroup = i;
			break;
		}
	}
	return foundGroup;
}