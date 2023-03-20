#pragma once
#include"Student.h"

class StudentNode{
private:
	Student* value;
	StudentNode* pNext;
public:
	StudentNode(Student&);
	~StudentNode();

	Student* getValue();
	StudentNode* getPNext();

	void setValue(Student*);
	void setPNext(StudentNode*&);
};

