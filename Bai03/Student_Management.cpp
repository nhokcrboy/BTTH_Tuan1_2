#include "Student_Management.h"

Student_Management::Student_Management() {
	DSSV = NULL;
	count = 0;
}

Student_Management::~Student_Management() {

}

void Student_Management::readListOfStudentFromFile(string filename) {
	ifstream fin(filename);
	Student temp;
	string tempString;

	while (getline(fin, tempString)) {
		stringstream builder(tempString);
		
		// getName
		getline(builder, tempString, ',');
		temp.setName(tempString);
		
		// getId
		getline(builder, tempString, ',');
		temp.setId(tempString);

		//getDateOfBirth
		getline(builder, tempString, ',');
		temp.setDateOfBirth(tempString);

		//getDiemBT
		getline(builder, tempString, ',');
		temp.setMarkBT(stof(tempString));;

		//getDiemGK
		getline(builder, tempString, ',');
		temp.setMarkGK(stof(tempString));

		//getDiemCK
		getline(builder, tempString, ',');
		temp.setMarkCK(stof(tempString));

		//getDiemTB
		getline(builder, tempString);
		temp.setAvgMark(stof(tempString));

		this->add(temp);
	}
}

void Student_Management::writeListOfStudentToFile(string filename) {
	ofstream fout(filename, ios::app);
	StudentNode* pCur = this->DSSV;

	while (pCur != NULL) {
		Student* temp = pCur->getValue();
		fout << temp->getName() << "," << temp->getId() << ","
			<< temp->getDateOfBirth() << "," << temp->getMarkBT() << ","
			<< temp->getMarkGK() << "," << temp->getMarkCK() << ","
			<< temp->getAvgPoint();

		pCur = pCur->getPNext();
	}

	fout.close();
}

void Student_Management::add(Student& student) {
	StudentNode* newNode = new StudentNode(student);
	if (this->DSSV == NULL) {
		this->DSSV = newNode;
	}
	else {
		StudentNode* pCur = this->DSSV;
		while (pCur->getPNext() != NULL) {
			pCur = pCur->getPNext();
		}
		pCur->setPNext(newNode);
	}
}

void Student_Management::print() {
	StudentNode* pCur = this->DSSV;
	while (pCur != NULL) {
		(pCur->getValue())->print();
		cout << endl;
		pCur = pCur->getPNext();
	}
}