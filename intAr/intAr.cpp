#include <iostream>
#include "intAr.h"
using namespace std;

intAr::intAr()
{
	size_ = 1; //
	try{
		array_ = new int[size_]{0}; //
		if (array_ == NULL){
			throw "Error. Memory not allocated";
		}
	}
	catch (char* err){
		cout << err << endl;
		system("pause");
		exit(1);
	}
}
intAr::intAr(int* Array, int size)
{
	size_ = size; //
	try{
		if (size_ <= 0){
			throw "Error. Size of array <=0";
		}
		else
		{
			array_ = new int[size]; //
			if (array_ == NULL){
				throw "Error. Memory not allocated";
			}
			for (int i = 0; i < size; i++) {
				array_[i] = Array[i];
			}
		}
	}
	catch(char* err){
		cout << err << endl;
		system("pause");
		exit(1);
	}
}
intAr::intAr(int size) {
	try{
		if (size <= 0){
			throw "Error. Size of array <=0";
		}
		else{
			size_ = size;
			array_ = new int[size]{0};
			if (array_ == NULL){
				throw "Error. Memory not allocated";
			}
		}
	}
	catch (char* err){
		cout << err << endl;
		system("pause");
		exit(1);
	}
}
intAr::intAr(const intAr &Array) {
	size_ = Array.size_;
	try{
		array_ = new int[size_]; //
		if (array_ == NULL){
			throw "Error. Memory not allocated";
		}
		for (int i = 0; i < size_; i++) {
			array_[i] = Array.array_[i];
		}
	}
	catch (char* err){
		cout << err << endl;
		system("pause");
		exit(1);
	}
}
intAr intAr::operator+(const intAr &Array)
{
	int newSize = size_ + Array.size_;
	int i;
	intAr newArray(newSize);
	for (i = 0; i < size_; i++) {
		newArray[i] = array_[i];
	}
	for (i; i < newSize; i++) {
		newArray[i] = Array.array_[i - size_];
	}
	return newArray;
}
bool intAr::operator>(const intAr &Array)
{
	return size_ > Array.size_;
}
bool intAr::operator==(const intAr &Array)
{
	if (size_ == Array.size_){
		for (int i = 0; i < size_; i++){
			if (array_[i] != Array.array_[i]){
				return false;
			}
		}
	}
	else{
		return false;
	}
	return true;
}
bool intAr::operator<(const intAr &Array)
{
	return size_ < Array.size_;
}
intAr intAr::operator=(const intAr &Array){
	int* arr = new int[Array.size_];
	size_ = Array.size_;
	for (int i = 0; i < size_; i++) {
		arr[i] = Array.array_[i];
	}
	delete[] array_; //
	array_ = arr;
	return  *this;
}
intAr intAr::operator+(int a)
{
	intAr temp(size_);
	for (int i = 0; i < size_; i++) {
		temp.array_[i] = array_[i] + a;
	}
	return temp;
}
intAr intAr::operator-(int a)
{
	intAr temp(size_);
	for (int i = 0; i < size_; i++) {
		temp.array_[i] = array_[i] - a;
	}
	return temp;
}
intAr intAr::operator++()
{
	for (int i = 0; i < size_; i++) {
		array_[i]++;
	}
	return *this;
}
intAr intAr::operator--()
{
	for (int i = 0; i < size_; i++) {
		array_[i]--;
	}
	return *this;
}
ostream &operator<<(ostream& out, const intAr& Array){
	if (Array.size_>0){
		for (int i = 0; i < Array.size_ - 1; i++){
			out << Array.array_[i] << ", ";
		}
		out << Array.array_[Array.size_ - 1] << endl;
		return out;
	}
}
istream &operator>>(istream& in, intAr& Array){
	cout << "Enter " << Array.size_ << " elements:" << endl;
	for (int i = 0; i < Array.size_; i++){
		in >> Array[i];
		if (!in){
			cout << "Error in" << endl;
			system("pause");
			exit(1);
		}
	}
}

int& intAr::operator[](int index){ // 
	try{
		if (index < 0 || index >= size_){
			throw "Index exceeds the bounds";
		}
		else{
			return array_[index];
		}
	}
	catch (char* err){
		cout << err << endl;
		system("pause");
		exit(1);
	}
}
intAr::~intAr()
{
	if (array_){
		delete[] array_;
	}
}