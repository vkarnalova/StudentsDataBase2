#ifndef HOMEWORK2_HOMEWORK2_STUDENT_H_
#define HOMEWORK2_HOMEWORK2_STUDENT_H_
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	unsigned long long int fac_num_;
	string first_name_;
	string last_name_;
	unsigned int grade_;
public:
	//Constructor
	Student(const unsigned long long int = 0, const string = "", const string = "", const unsigned int = 0);

	//Getters that return the value of all Student's variables
	unsigned long long int	GetFacNum() const;
	string GetFirtsName() const;
	string GetLastName() const;
	unsigned int GetGrade() const;

	//Setter 
	void SetGrade(const unsigned int);

	//Overloaded operators
	friend istream& operator>>(istream&, Student&);
	friend ostream& operator<<(ostream&, Student&);
};

#endif



