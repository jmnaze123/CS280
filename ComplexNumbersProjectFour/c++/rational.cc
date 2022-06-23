/* rational.cc */

#include <iostream>
#include "rational.h"

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