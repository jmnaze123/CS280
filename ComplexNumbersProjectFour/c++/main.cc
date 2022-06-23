/*
 *
 *  C++ version
 *
 */

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

    return 0;
}