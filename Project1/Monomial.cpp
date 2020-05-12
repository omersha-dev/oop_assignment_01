#include "Monomial.h"

Monomial::Monomial() {
	this->coefficient = 1;
	this->exponent = 0;
	this->next = this->prev = NULL;
	numberOfMonomials++;
}

Monomial::Monomial(int coefficient) {
	this->coefficient = coefficient;
	this->exponent = 0;
	this->next = this->prev = NULL;
	numberOfMonomials++;
}

Monomial::Monomial(int coefficient, int exponent) {
	this->coefficient = coefficient;
	this->exponent = exponent;
	this->next = this->prev = NULL;
	numberOfMonomials++;
}

Monomial::Monomial(const Monomial& other) {
	this->coefficient = other.coefficient;
	this->exponent = other.exponent;
	this->next = this->prev = NULL;
	numberOfMonomials++;
}

Monomial::~Monomial() {
	numberOfMonomials--;
}

int Monomial::getCoefficient() {
	return this->coefficient;
}

int Monomial::getExponent() {
	return this->exponent;
}

int Monomial::getNumberOfMonomials() {
	return numberOfMonomials;
}

void Monomial::print() {
	if (this->coefficient != 1) {
		cout << this->coefficient;
	}
	else {
		if (this->exponent == 0) {
			cout << this->coefficient;
		}
	}
	if (this->exponent != 0) {
		if (this->coefficient != 1 && this->coefficient != 0) {
			cout << "*";
		}
		if (this->exponent == 1) {
			cout << "x";
		}
		else {
			cout << "x^" << this->exponent;
		}
	}
}

bool Monomial::add(const Monomial& other) {
	if (this->exponent != other.exponent) {
		return false;
	}
	this->coefficient += other.coefficient;
	return true;
}

Monomial* Monomial::getNextMonomial() {
	return next;
}

void Monomial::setNextMonomial(Monomial* other) {
	this->next = other;
}

Monomial* Monomial::getPrevMonomial() {
	return prev;
}

void Monomial::setPrevMonomial(Monomial* other) {
	this->prev = other;
}

int Monomial::numberOfMonomials = 0;