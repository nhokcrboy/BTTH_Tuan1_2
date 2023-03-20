#include <iostream>
#include <cassert>
#include"Student_Management.h"


int main()
{
	Student_Management List;
	List.readListOfStudentFromFile("input.txt");
	List.print();
	List.writeListOfStudentToFile("output.txt");
	List.printWithRating();
	List.findStudentAvgLessThanClassAvg("output2.txt");
	//assert(true);
	return 0;
}