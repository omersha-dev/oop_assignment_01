#include <iostream>
#include <iomanip>
#include "Monomial.h"
#include "Polynomial.h"
using namespace std;
Monomial one;

void testMonomial() {
    // Prints 1 for the global object
    cout << "Number of Monomials=" << Monomial::getNumberOfMonomials() << endl;
    static Monomial two(2);
    Monomial x(1, 1);
    Monomial xsquare(1, 2);
    cout << "Number of Monomials=" << Monomial::getNumberOfMonomials() << endl; // prints 4
    Monomial* m32 = new Monomial(3, 2);
    cout << "Number of Monomials=" << Monomial::getNumberOfMonomials() << endl; // prints 5
    Monomial* m43 = new Monomial(4, 3);
    cout << "Number of Monomials=" << Monomial::getNumberOfMonomials() << endl; // prints 6
    Monomial* m52 = new Monomial(5, 2);
    cout << "Number of Monomials=" << Monomial::getNumberOfMonomials() << endl; // prints 7
    one.print(); cout << endl; // 1
    two.print(); cout << endl; // 2
    x.print(); cout << endl; // x
    xsquare.print(); cout << endl; // x^2
    m32->print(); cout << endl; // 3*x^2
    m43->print(); cout << endl; // 4*x^3
    m52->print(); cout << endl; // 5*x^2
    delete m43;
    cout << "Number of Monomials=" << Monomial::getNumberOfMonomials() << endl; // prints 6
    // Impossible to add different degrees
    cout << "Adding xsquare to x:" << x.add(xsquare) << endl; // Adding xsquare to x:false
    x.print(); cout << endl; // x
    xsquare.print(); cout << endl; // x^2
    cout << "Adding m32 to xsquare:" << xsquare.add(*m32) << endl; // Adding m32 to xsquare:true
    xsquare.print(); cout << endl; // 4*x^2
    m32->print(); cout << endl; // 3*x^2
    // An intentional memory leak of two dynamic allocations
}
void testPolynomial() {
    Polynomial p;
    p.print(); cout << endl; // 0
    p.add(one);
    p.print(); cout << endl; // 1
    cout << "Number of Monomials=" << Monomial::getNumberOfMonomials() << endl; // prints 5
    p.add(Monomial(1, 2));
    p.print(); cout << endl; // x^2+1
    cout << "Number of Monomials=" << Monomial::getNumberOfMonomials() << endl; // prints 6
    p.add(Monomial(-1, 2));
    p.print(); cout << endl; // 1
    cout << "Number of Monomials=" << Monomial::getNumberOfMonomials() << endl; // prints 5
}
int main() {
    cout << boolalpha;
    testMonomial();
    // This prints 4: 1 global + 1 local static + 2 memory leaked
    cout << "Number of Monomials=" << Monomial::getNumberOfMonomials() << endl;
    testPolynomial();
    return 0;
}