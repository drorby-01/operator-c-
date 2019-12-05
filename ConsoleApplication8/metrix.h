#pragma once
#pragma once
#include <iostream>




class metrix
{
private:

	int row;
	int col;
	int **arr;


public:


	metrix(int rows, int cols);//constructor
	metrix(const metrix &other);//copy constructor
	~metrix();//destructor
	int* & operator[](const int &index) const;// returns number from the metrix in a index 
	void operator=(const metrix &other)const; //assignment operator
	metrix  operator -()const; //the opposite metrix
	metrix  operator -(const metrix &other)const;//sub between two metrix
	metrix  operator +(const metrix &other)const;//add between two metrix
	metrix  operator *(const metrix &other)const;//multiplax between two metrix
	metrix  operator *(const int &num)const;//multiplax between  metrix and integer
	friend  metrix operator *(const int & num, const metrix &m);//friend function multiplax between integer and metrix 


																//print metrix
	friend std::ostream &operator<<(std::ostream &os, const metrix &m) {
		for (int i = 0; i < m.row; ++i) {
			for (int j = 0; j < m.col; ++j) {
				os << m.arr[i][j] << "  ";
			}
			os << '\n';
		}
		return os;
	}


};
