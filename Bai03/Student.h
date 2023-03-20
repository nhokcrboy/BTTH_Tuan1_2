#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

class Student
{
private:
	map<string, int> score = {
		{"BT", 0},
		{"GK", 1},
		{"CK", 2}
	};

	char* _name;		// 30 kí tự
	char* _id;			// 8 kí tự
	char* _dateOfBirth;	// 8 kí tự
	float _mark[3];		// BT - GK - CK
	float _avgMark;		// stdAvg = baitap*0.25 + giuaky*0.25 + cuoiky*0.5
public:
	Student();
	Student(const Student&);
	~Student();
public:
	string getName();
	string getId();
	string getDateOfBirth();
	string toStr();
	float getAvgPoint();
	float getMarkBT();
	float getMarkGK();
	float getMarkCK();

	void setName(string);
	void setId(string);
	void setDateOfBirth(string);
	void setMarkBT(float);
	void setMarkGK(float);
	void setMarkCK(float);
	void setAvgMark(float);
public:
	void input();
	void print();
public:
	void operator= (const Student&);
	void copy(Student& a);
	//Student create(string name, string id, string dateOfBirth, float* mark);
};