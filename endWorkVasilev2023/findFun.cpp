#include "findFun.h"

bool groupExist(Group* firstGroup, int number) {
	if (firstGroup == nullptr) return false;
	bool exist = false;
	for (Group* i = firstGroup; i != nullptr; i = i->next_group) {
		if (i->number == number) {
			exist = true;
			break;
		}
	}
	return exist;
}

Student* findStudent(Group* firstGroup, int numberGroup, char studentName[SIZE_NAME]) {
	if (firstGroup == nullptr) return nullptr;
	Student* foundStudent = nullptr;
	bool find = true;
	for (Group* i = firstGroup; i != nullptr; i = i->next_group) {
		if (i->number == numberGroup) {
			if (i->first_student == nullptr) return nullptr;
			for (Student* j = i->first_student; j != nullptr; j = j->next_student) {
				find = true;
				for (int i = 0; i < SIZE_NAME; i++) {
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
	if (firstGroup == nullptr) return nullptr;
	Group* foundGroup = nullptr;
	for (Group* i = firstGroup; i != nullptr; i = i->next_group) {
		if (i->number == numberGroup) {
			foundGroup = i;
			break;
		}
	}
	return foundGroup;
}