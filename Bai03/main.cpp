#include <iostream>
#include <cassert>
#include"Student_Management.h"


int main()
{
	Student_Management List;
	List.readListOfStudentFromFile("input.txt");
	List.print();
	List.writeListOfStudentToFile("output.txt");
	//assert(true);
	return 0;
}