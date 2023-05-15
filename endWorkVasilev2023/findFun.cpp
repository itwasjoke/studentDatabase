#include "findFun.h"
Student* findStudent(Group* firstGroup, int numberGroup, char studentName[50]) {
	Student* foundStudent = nullptr;
	bool find = true;
	for (Group* i = firstGroup; i != nullptr; i = i->next_group) {
		if (i->number == numberGroup) {
			for (Student* j = i->first_student; j != nullptr; j = j->next_student) {
				find = true;
				for (int i = 0; i < 50; i++) {
					if (j->name[i] != studentName[i]) {
						find = false;
						break;
					}
				}
				if (find) {
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