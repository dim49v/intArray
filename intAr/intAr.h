#pragma once
#include <iostream>
using namespace std;
class intAr
{
private:
	int* array_;
	int size_;
public:
	intAr();
	intAr(int*, int);
	intAr(int);
	intAr(const intAr &Array);
	intAr operator+(const intAr&);
	bool operator>(const intAr&);
	bool operator<(const intAr&);
	bool operator==(const intAr&);
	intAr operator=(const intAr&);
	intAr operator+(int);
	intAr operator-(int);
	intAr operator++();
	intAr operator--();
	int& operator[](int index);
	friend ostream &operator<<(ostream&,const intAr&);
	~intAr();
};

