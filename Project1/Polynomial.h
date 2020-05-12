#pragma once
#include <iostream>
#include "Monomial.h"

class Polynomial {
private:
	Monomial* head;

public:
	Polynomial();
	Polynomial(Monomial& monomial);

	void print();
	void add(Monomial other);

};