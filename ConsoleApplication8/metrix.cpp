#include<iostream>
#include<cassert>
#include "metrix.h"
using namespace std;




metrix::metrix(int row, int col)//constructor
{
	this->row = row;
	this->col = col;
	arr = new int*[this->row];
	assert(arr);
	for (int i = 0; i<this->col; i++)
	{
		arr[i] = new int[this->col];
		assert(arr[i]);
	}
	for (int i = 0; i<this->row; i++)
		for (int j = 0; j<this->col; j++)
			arr[i][j] = 0;
}


metrix::metrix(const metrix &other)  //copy constructor
{
	col = other.col;
	row = other.row;
	arr = new int*[other.row];
	assert(arr);
	for (int i = 0; i<other.row; i++)
	{
		arr[i] = new int[other.col];
		assert(arr[i]);
	}
	for (int i = 0; i<other.row; i++)
		for (int j = 0; j<other.col; j++)
			arr[i][j] = other[i][j];
}


metrix::~metrix()//destructor
{
	for (int i = 0; i<this->col; i++)
		delete[] arr[i];
	delete[]arr;
}


int* & metrix::operator[](const int &index) const// returns number from the metrix in a index
{
	return arr[index];
}


void metrix::operator =(const metrix &other)const //assignment operator
{
	for (int i = 0; i<this->row; i++)
		for (int j = 0; j<this->col; j++)
		{
			this->arr[i][j] = other.arr[i][j];
		}

}


metrix metrix:: operator -()const//the opposite metrix
{

	metrix tmp(*this);
	for (int i = 0; i<this->row; i++)
		for (int j = 0; j<this->col; j++)
			tmp.arr[i][j] = tmp.arr[i][j] * -1;
	return tmp;

}


metrix metrix :: operator -(const metrix &other)const//sub between two metrix
{
	metrix tmp(*this);
	for (int i = 0; i<this->row; i++)
		for (int j = 0; j<this->col; j++)
			tmp.arr[i][j] = tmp.arr[i][j] - other.arr[i][j];
	return tmp;
}


metrix metrix::  operator +(const metrix &other)const //add between two metrix
{
	metrix tmp(*this);
	for (int i = 0; i<this->row; i++)
		for (int j = 0; j<this->col; j++)
			tmp[i][j] = tmp[i][j] + other[i][j];
	return tmp;

}


metrix metrix::  operator *(const metrix &other) const//multiplax between two metrix
{
	metrix tmp(*this);
	for (int i = 0; i < this->row; i++)
		for (int j = 0; j<this->col; j++)
			tmp[i][j] = tmp[i][j] * other[i][j];
	return tmp;
}


metrix metrix:: operator *(const int &num) const //multiplax between  metrix and integer
{
	metrix tmp(*this);
	for (int i = 0; i < this->row; i++)
		for (int j = 0; j<this->col; j++)
			tmp[i][j] = tmp[i][j] * num;
	return tmp;
}


metrix  operator *(const int & num, const metrix &m)//friend function multiplax between integer and metrix
{
	return (m*num);
}




void main()
{
	metrix m(2, 2);
	m[0][0] = 2;
	m[1][1] = 2;
	cout << m << endl;
	m = m;
	const metrix s = -m;
	cout << m << endl << s << endl;
	m = s + 2 * -m * m * 2 - s;
	cout << m << endl << s << endl;
	cout << s[1][1] << endl;

}
