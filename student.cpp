#include "student.h"

Student::Student(const unsigned long long int fac_num, const string first_name, const string last_name, const unsigned int grade)
{
	fac_num_ = fac_num;
	first_name_ = first_name;
	last_name_ = last_name;
	grade_ = grade;
}

unsigned long long int Student::GetFacNum() const
{
	return fac_num_;
}

string Student::GetFirtsName() const
{
	return first_name_;
}

string Student::GetLastName() const
{
	return last_name_;
}

unsigned int Student::GetGrade() const
{
	return grade_;
}

void Student::SetGrade(const unsigned int new_grade)
{
	grade_ = new_grade;
}

istream& operator>>(istream& is, Student & st)
{
	is >> st.fac_num_ >> st.first_name_ >> st.last_name_ >> st.grade_;
	return is;
}

ostream & operator<<(ostream & os, Student & st)
{
	os << st.fac_num_ << " " << st.first_name_ << " " << st.last_name_ << " " << st.grade_ << endl;
	return os;
}
