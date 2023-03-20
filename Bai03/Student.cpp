#include "Student.h"

Student::Student()
{
	_name = new char[31];
	_id = new char[9];
	_dateOfBirth = new char[9];

	// Gia tri mac dinh cho cac thuoc tinh
	_name[0] = _id[0] = _dateOfBirth[0] = '\0';

	_mark[score["BT"]] = 0;
	_mark[score["GK"]] = 0;
	_mark[score["CK"]] = 0;
	_avgMark = 0;
}

Student::Student(const Student& student) {
	char* temp = new char[strlen(student._name) + 1];
	strcpy(temp, student._name);
	delete[] this->_name;
	this->_name = temp;

	temp = new char[strlen(student._id) + 1];
	strcpy(temp, student._id);
	delete[] this->_id;
	this->_id = temp;

	temp = new char[strlen(student._dateOfBirth) + 1];
	strcpy(temp, student._dateOfBirth);
	delete[] this->_dateOfBirth;
	this->_dateOfBirth = temp;

	this->_mark[0] = student._mark[0];
	this->_mark[1] = student._mark[1];
	this->_mark[2] = student._mark[2];
	this->_avgMark = student._avgMark;
}

void Student::operator= (const Student & student) {
	char* temp = new char[strlen(student._name) + 1];
	strcpy(temp, student._name);
	delete[] this->_name;
	this->_name = temp;

	temp = new char[strlen(student._id) + 1];
	strcpy(temp, student._id);
	delete[] this->_id;
	this->_id = temp;

	temp = new char[strlen(student._dateOfBirth) + 1];
	strcpy(temp, student._dateOfBirth);
	delete[] this->_dateOfBirth;
	this->_dateOfBirth = temp;

	this->_mark[0] = student._mark[0];
	this->_mark[1] = student._mark[1];
	this->_mark[2] = student._mark[2];
	this->_avgMark = student._avgMark;
}

Student::~Student()
{
	delete[] _name;
	delete[] _id;
	delete[] _dateOfBirth;
}

string Student::getName()
{
	return _name;
}
string Student::getId()
{
	return _id;
}

string Student::getDateOfBirth()
{
	return _dateOfBirth;
}

float Student::getAvgPoint() {
	return this->_avgMark;
}

float Student::getMarkBT() {
	return this->_mark[score["BT"]];
}

float Student::getMarkGK() {
	return this->_mark[score["GK"]];
}

float Student::getMarkCK() {
	return this->_mark[score["CK"]];
}

string Student::toStr()
{
	stringstream builder;
	builder << _name << "," << _id << "," << _dateOfBirth << ",";
	builder << _mark[0] << "," << _mark[1] << "," << _mark[2];

	return builder.str();
}

void Student::setName(string name)
{
	char* temp = new char[name.length() + 1];
	strcpy(temp,name.c_str());
	delete[] this->_name;
	this->_name = temp;
}
void Student::setId(string id)
{
	char* temp = new char[id.length() + 1];
	strcpy(temp, id.c_str());
	delete[] this->_id;
	this->_id = temp;
}

void Student::setDateOfBirth(string dateOfBirth)
{
	char* temp = new char[dateOfBirth.length() + 1];
	strcpy(temp, dateOfBirth.c_str());
	delete[] this->_dateOfBirth;
	this->_dateOfBirth = temp;
}

void Student::input()
{
	string name;
	string id;
	string dateOfBirth;
	float mark[3];

	cout << "Nhap thong tin sinh vien. \n";
	cout << "Nhap Hoten: ";
	getline(cin, name);
	cout << "Nhap ID: ";
	getline(cin, id);
	cout << "Nhap Ngay Sinh: ";
	getline(cin, dateOfBirth);
	cout << "Nhap diem: \n";
	cout << "BT: ";
	cin >> mark[0];
	cout << "GK: ";
	cin >> mark[1];
	cout << "CK: ";
	cin >> mark[2];

	stringstream builder;

	try
	{
		if (name.size() > 30)
		{
			cout << "Student name must contain less than 30 characters...";
			throw exception();
		}
		else
		{
			builder << name;
			builder.getline(_name, name.size());
		}

		if (id.size() > 8)
		{
			cout << "Student ID must contain less than 8 characters...";
			throw exception();
		}
		else
		{
			builder << id;
			builder.getline(_id, id.size());
		}

		if (dateOfBirth.size() > 8)
		{
			cout << "Student Date of Birth must contain less than 8 characters...";
			throw exception();
		}
		else
		{
			builder << dateOfBirth;
			builder.getline(_dateOfBirth, dateOfBirth.size());
		}

		_mark[score["BT"]] = mark[0];
		_mark[score["GK"]] = mark[1];
		_mark[score["CK"]] = mark[2];

		_avgMark = (mark[score["BT"]] * 0.25 + mark[score["GK"]] * 0.25 + mark[score["CK"]] * 0.5);

	}
	catch (exception ex) {};
}

void Student::print()
{
	cout << "HoTen: " << _name;
	cout << " - ID: " << _id;
	cout << " - NgaySinh: " << _dateOfBirth;
	cout << " - Diem [BT GK CK]: ";
	cout << _mark[0] << " " << _mark[1] << " " << _mark[2];
}

void Student::setMarkBT(float mark) {
	this->_mark[0] = mark;
}

void Student::setMarkGK(float mark) {
	this->_mark[1] = mark;
}

void Student::setMarkCK(float mark) {
	this->_mark[2] = mark;
}

void Student::setAvgMark(float mark) {
	this->_avgMark = mark;
}

void Student::copy(Student &student)
{
	char* temp = new char[strlen(student._name) + 1];
	strcpy(temp, student._name);
	delete[] this->_name;
	this->_name = temp;

	temp = new char[strlen(student._id) + 1];
	strcpy(temp, student._id);
	delete[] this->_id;
	this->_id = temp;

	temp = new char[strlen(student._dateOfBirth) + 1];
	strcpy(temp, student._dateOfBirth);
	delete[] this->_dateOfBirth;
	this->_dateOfBirth = temp;

	this->_id = student._id;
	this->_dateOfBirth = student._dateOfBirth;
	this->_mark[0] = student._mark[0];
	this->_mark[1] = student._mark[1];
	this->_mark[2] = student._mark[2];
	this->_avgMark = student._avgMark;
}
//
//Student Student::create(string name, string id, string dateOfBirth, float* mark)
//{
//	
//}