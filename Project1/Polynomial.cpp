#include "Polynomial.h"

Polynomial::Polynomial() {
	this->head = NULL;
}

Polynomial::Polynomial(Monomial& monomial) {
	this->head = &monomial;
}

void Polynomial::print() {
	Monomial *curr;
	curr = this->head;
	if (curr == NULL) {
		cout << 0;
		return;
	}
	curr->print();
	curr = curr->getNextMonomial();
	while (curr != NULL) {
		if (curr->getCoefficient() > 0) {
			cout << "+";
		}
		curr->print();
		curr = curr->getNextMonomial();
	}
}

void Polynomial::add(Monomial other) {
	Monomial *curr, *prev, *temp = new Monomial(other);
	curr = prev = this->head;
	if (curr == NULL) {
		this->head = temp;
		return;
	}
	curr = curr->getNextMonomial();
	while (curr != NULL && curr->getExponent() > temp->getExponent()) {
		prev = curr;
		curr = curr->getNextMonomial();
	}
	if (prev->getExponent() > temp->getExponent()) {
		prev->setNextMonomial(temp);
		temp->setPrevMonomial(prev);
	}
	else if (prev->getExponent() < temp->getExponent()) {
		temp->setNextMonomial(prev);
		prev->setPrevMonomial(temp);
		this->head = temp;
	}
	else { // if (curr->getExponent() == temp->getExponent())
		prev->add(*temp);
		if (prev->getCoefficient() == 0) {
			if (prev->getPrevMonomial() == NULL) {
				this->head = prev->getNextMonomial();
			}
			else {
				prev->getPrevMonomial()->setNextMonomial(curr);
			}
			delete(prev);
		}
		delete(temp);
	}
}