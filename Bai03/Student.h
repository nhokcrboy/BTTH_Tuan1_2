#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

class Student
{
private:
	map<string, int> score = {
		{"BT", 1},
		{"GK", 2},
		{"CK", 2}
	};

	char* _name;		// 30 kí tự
	char* _id;			// 8 kí tự
	char* _dateOfBirth;	// 8 kí tự
	float _mark[3];		// BT - GK - CK
	float _avgMark;		// stdAvg = baitap*0.25 + giuaky*0.25 + cuoiky*0.5
public:
	Student();
	~Student();
public:
	string getName();
	string getId();
	string getDateOfBirth();
	string toStr();

	void setName(string);
	void setId(string);
	void setDateOfBirth(string);
public:
	void input();
	void print();
public:
	Student copy(const Student& a);
	Student create(string name, string id, string dateOfBirth, float* mark);
};