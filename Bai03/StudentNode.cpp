#include "StudentNode.h"

StudentNode::StudentNode(Student& value) {
	this->value = new Student(value);
	this->pNext = NULL;
}

StudentNode::~StudentNode() {
	delete this->value;
}

Student* StudentNode::getValue() {
	return this->value;
}

StudentNode* StudentNode::getPNext() {
	return this->pNext;
}

void StudentNode::setValue(Student* value) {
	this->value = value;
}

void StudentNode::setPNext(StudentNode*& student) {
	this->pNext = student;
}