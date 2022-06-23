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