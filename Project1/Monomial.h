#pragma once
#include <iostream>
using namespace std;

class Monomial {
private:
	static int numberOfMonomials;
	int coefficient, exponent;
	Monomial *next, *prev;

public:
	Monomial();
	Monomial(int coefficient);
	Monomial(int coefficient, int exponent);
	Monomial(const Monomial& other);
	~Monomial();
	int getCoefficient();
	int getExponent();
	static int getNumberOfMonomials();
	void print();
	bool add(const Monomial& other);
	Monomial* getNextMonomial();
	void setNextMonomial(Monomial* other);
	Monomial* getPrevMonomial();
	void setPrevMonomial(Monomial* other);
};