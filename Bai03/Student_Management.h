#pragma once
#include "Student.h"
#include "StudentNode.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Student_Management
{
private:
	StudentNode* DSSV; // DanhSachLienKet Only pHead
	int count;
public:
	Student_Management();
	~Student_Management();

	int getNumberStudent();
	float avgPoint();

	void readListOfStudentFromFile(string);
	void writeListOfStudentToFile(string);

	void add(Student&);
	void print();
	void update();
	void rating();
};

