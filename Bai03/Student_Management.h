#pragma once
#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

class Student_Management
{
private:
	Student* DSSV;
	int count;
public:
	Student_Management();
	~Student_Management();

	int getNumberStudent();
	float avgPoint();

	void readListOfStudentFromFile();
	void writeListOfStudentToFile();

	void add();
	void update();
	void rating();
};

