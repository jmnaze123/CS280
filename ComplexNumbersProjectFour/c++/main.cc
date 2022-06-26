/*
 *
 *  C++ version
 *
 */


/* complex.h */

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

struct complex {

    complex(double = 0, double = 0);

    complex operator+(const complex &) const;
    complex operator-(const complex &) const;
    complex operator*(const complex &) const;
    complex operator/(const complex &) const;

    complex operator+(double) const;
    complex operator-(double) const;
    complex operator*(double) const;
    complex operator/(double) const;

    friend complex operator+(double, const complex &);
    friend complex operator-(double, const complex &);
    friend complex operator*(double, const complex &);
    friend complex operator/(double, const complex &);

    friend ostream &operator<<(ostream &, const complex &);

private:

    double real;
    double imag;
};


/* complex.cc */

complex::complex(double real, double imag) : real(real), imag(imag) {}

complex complex::operator+(const complex &o) const {

    return complex(real + o.real, imag + o.imag);
}

complex complex::operator+(double d) const {

    return complex(real + d, imag);
}

complex complex::operator-(const complex &o) const {

    return complex(real - o.real, imag - o.imag);
}

complex complex::operator-(double d) const {

    return complex(real - d, imag);
}

complex complex::operator*(const complex &o) const {

    return complex(real * o.real - imag * o.imag, real * o.imag + imag * o.real);
}

complex complex::operator*(double d) const {

    return complex(real * d, imag * d);
}

complex complex::operator/(const complex &o) const {

    return complex((real * o.real + imag * o.imag) / (o.real * o.real + o.imag * o.imag), (imag * o.real - real * o.imag) / (o.real * o.real + o.imag * o.imag));
}

complex complex::operator/(double d) const {

    return complex(real / d, imag / d);
}

complex operator+(double d, const complex &o) {

    return complex(d + o.real, o.imag);
}

complex operator-(double d, const complex &o) {

    return complex(d - o.real, -o.imag);
}

complex operator*(double d, const complex &o) {

    return complex(d * o.real, d * o.imag);
}

complex operator/(double d, const complex &o) {

    return complex(d / (o.real * o.real + o.imag * o.imag), -d * o.imag / (o.real * o.real + o.imag * o.imag));
}

ostream &operator<<(ostream &out, const complex &o) {

    out << o.real;
    if (o.imag < 0)
        out << " - " << -o.imag << "i";
    else if (o.imag > 0)
        out << " + " << o.imag << "i";
    return out;
}


/* main.cc */

int main(void) {

    complex a(1.0, 2.0);
    complex b(1.0, 3.0);

    double d = 5.0;

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    cout << a << " + " << d << " = " << a + d << endl;
    cout << a << " - " << d << " = " << a - d << endl;
    cout << a << " * " << d << " = " << a * d << endl;
    cout << a << " / " << d << " = " << a / d << endl;

    cout << d << " + " << a << " = " << d + a << endl;
    cout << d << " - " << a << " = " << d - a << endl;
    cout << d << " * " << a << " = " << d * a << endl;
    cout << d << " / " << a << " = " << d / a << endl;

    return 0;
}