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

string Student::toStr()
{
	stringstream builder;
	builder << _name << "," << _id << "," << _dateOfBirth << ",";
	builder << _mark[0] << "," << _mark[1] << "," << _mark[2];

	return builder.str();
}

void Student::setName(string name)
{
	stringstream builder;
	builder << name;
	builder.getline(_name, name.size());
}
void Student::setId(string id)
{
	stringstream builder;
	builder << id;
	builder.getline(_id, id.size());
}

void Student::setDateOfBirth(string dateOfBirth)
{
	stringstream builder;
	builder << dateOfBirth;
	builder.getline(_dateOfBirth, dateOfBirth.size());
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

Student Student::copy(const Student &a)
{
	strcpy(_name, a._name);
	strcpy(_id, a._id);
	strcpy(_dateOfBirth, a._dateOfBirth);

	_mark[0] = a._mark[0];
	_mark[1] = a._mark[1];
	_mark[2] = a._mark[2];

	_avgMark = a._avgMark;
}

Student Student::create(string name, string id, string dateOfBirth, float* mark)
{
	
}