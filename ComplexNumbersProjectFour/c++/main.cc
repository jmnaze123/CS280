/*
 *
 *  C++ version
 *
 */



/* complex.h */

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using std::ostream;

struct complex {

    complex(rational = 1, rational = 1);

    complex operator+(const complex &) const;
    complex operator-(const complex &) const;
    complex operator*(const complex &) const;
    complex operator/(const complex &) const;

    complex operator+(double) const;
    complex operator-(double) const;
    complex operator*(double) const;
    complex operator/(double) const;

    friend complex operator+(double, const complex &) const;
    friend complex operator-(double, const complex &) const;
    friend complex operator*(double, const complex &) const;
    friend complex operator/(double, const complex &) const;

    friend ostream &operator<<(ostream &, const complex &);

private: 
    rational real;
    rational imag;
};
}

#endif /* COMPLEX_H */


/* complex.cc */

#include <iostream>

complex::complex(rational r, rational i) : real(r), imag(i) {}

complex complex::operator+(const complex &c) const {
    return complex(real + c.real, imag + c.imag);
}

complex complex::operator-(const complex &c) const {
    return complex(real - c.real, imag - c.imag);
}








/* rational.h */

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using std::ostream;

struct rational {

    rational(int = 0, int = 1);

    rational operator+(const rational &) const;
    rational operator-(const rational &) const;
    rational operator*(const rational &) const;
    rational operator/(const rational &) const;

    rational operator+(int) const;
    rational operator-(int) const;
    rational operator*(int) const;
    rational operator/(int) const;

    friend rational operator+(int, const rational &);
    friend rational operator-(int, const rational &);
    friend rational operator*(int, const rational &);
    friend rational operator/(int, const rational &);

    friend ostream &operator<<(ostream &, const rational &);

private:

    int den;
    int num;
};

#endif /* RATIONAL_H */

/* rational.cc */

#include <iostream>


rational::rational(int num, int den) : num(num), den(den) {}

rational rational::operator+(const rational &o) const {

    return rational(num * o.den + o.num * den, den * o.den);
}

rational rational::operator+(int n) const {

    return rational(num + n * den, den);
}

rational rational::operator-(const rational &o) const {

    return rational(num * o.den - o.num * den, den * o.den);
}

rational rational::operator-(int n) const {

    return rational(num - n * den, den);
}

rational rational::operator*(const rational &o) const {

    return rational(num * o.num, den * o.den);
}

rational rational::operator*(int n) const {

    return rational(num * n, den);
}

rational rational::operator/(const rational &o) const {

    return rational(num * o.den, den * o.num);
}

rational rational::operator/(int n) const {

    return rational(num, den * n);
}

rational operator+(int n, const rational &o) {

    return o + n;
}

rational operator-(int n, const rational &o) {

    return rational(n) - o;
}

rational operator*(int n, const rational &o) {

    return o * n;
}

rational operator/(int n, const rational &o) {

    return rational(n) / o;
}

ostream &operator<<(ostream &out, const rational &o) {

    out << '(' << o.num << " / " << o.den << ')';
    return out;
}





/* main.cc */

#include <iostream>

using std::cout;
using std::endl;

int main(void) {

    cout << "Rational numbers tests:" << endl;

    rational a(1, 2);
    rational b(1, 3);

    int i = 5;

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    cout << a << " + " << i << " = " << a + i << endl;
    cout << a << " - " << i << " = " << a - i << endl;
    cout << a << " * " << i << " = " << a * i << endl;
    cout << a << " / " << i << " = " << a / i << endl;

    cout << i << " + " << a << " = " << i + a << endl;
    cout << i << " - " << a << " = " << i - a << endl;
    cout << i << " * " << a << " = " << i * a << endl;
    cout << i << " / " << a << " = " << i / a << endl;


    cout << "Complex numbers tests:" << endl;

    complex y(0, 1);
    complex z(3, 2);

    double d = 5.99;

    cout << y << " + " << z << " = " << y + z << endl;
    cout << y << " - " << z << " = " << y - z << endl;

    return 0;
}