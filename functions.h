#ifndef HOMEWORK2_HOMEWORK2_FUNCTIONS_H_
#define HOMEWORK2_HOMEWORK2_FUNCTIONS_H_
#include <iostream>
#include <fstream>
#include "student.h"

using namespace std;

//function that finds student with a given faculty number
void SequentialSearch() {
	fstream file;
	file.open("StudentsGrades.db", ios::in);
	if (!file) {
		cerr << "File couldn't be opened! \n";
	}
	unsigned long long int fac_num;
	cin >> fac_num;
	Student temp_student;
	file.seekg(0, ios::beg);
	while (file >> temp_student) {
		if (temp_student.GetFacNum() == fac_num) {
			cout << temp_student;
			break;
		}
	}
	if (temp_student.GetFacNum() != fac_num) {
		cout << "Record not found! \n";
	}
	file.close();
}

//function that updates the information of a student's grade
void Update() {
	fstream ifile;
	ifile.open("StudentsGrades.db", ios::in | ios::out);
	if (!ifile) {
		cerr << "File couldn't be opened! \n";
	}
	unsigned long long int fac_num;
	unsigned int grade;
	cin >> fac_num >> grade;
	Student temp_student;
	ifile.seekg(0, ios::beg);
	streampos pos_put = ifile.tellg();
	char temp_ch;
	while (ifile >> temp_student) {
		ifile.clear();
		if (temp_student.GetFacNum() == fac_num) {
			temp_student.SetGrade(grade);
			ifile.seekp(pos_put, ios::beg);
			//here I don't use the overloaded operator << because I don't want new line at the end;
			ifile << temp_student.GetFacNum()<< " " << temp_student.GetFirtsName()<< " " << temp_student.GetLastName()<< " " << temp_student.GetGrade();
			cout << "Record saved! \n";
			break;
		}
		//temp_ch is used in order to place the put pointer at the beginning of the new line;
		ifile.get(temp_ch);
		pos_put = ifile.tellg(); 
	}
	if (temp_student.GetFacNum() != fac_num) {
		cout << "Record not found! \n";
	}
	ifile.close();
}

//function that deletes the information of a student
void Delete() {
	ifstream ifile;
	ifile.open("StudentsGrades.db", ios::in);
	if (!ifile) {
		cerr << "File couldn't be opened! \n";
	}
	ofstream ofile;
	ofile.open("StudentsGradesTemp.db", ios::out);
	if (!ofile) {
		cerr << "File couldn't be opened! \n";
	}
	unsigned long long int fac_num;
	cin >> fac_num;
	Student temp_student;
	bool flag_found = false;
	ofile.seekp(0, ios::beg);
	while (ifile >> temp_student) {
		if (temp_student.GetFacNum() != fac_num) {
			ofile << temp_student;
		}
		else {
			flag_found = true;
		}
	}
	ifile.close();
	ofile.close();

	remove("StudentsGrades.db");
	rename("StudentsGradesTemp.db", "StudentsGrades.db");

	if (flag_found) {
		cout << "Record deleted! \n";
	}
	else {
		cout << "Record not found! \n";
	}
}

#endif

