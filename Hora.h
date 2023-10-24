#pragma once
#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;

class Hora {
private:
	int H;
	int M;
public:
	Hora(int , int );
	virtual ~Hora();

	void setHora(int);
	void setMinutos(int);
	int getHora();
	int getMinutos();

	string toString();
};