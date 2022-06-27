#
#
# Python Version
#
#

if __name__ == '__main__':
    
    a = complex(1.0, 2.0)
    b = complex(1.0, 3.0)

    i = 5.0

    print('%s + %s = %s' % (a, b, a + b))
    print('%s - %s = %s' % (a, b, a - b))
    print('%s * %s = %s' % (a, b, a * b))
    print('%s / %s = %s' % (a, b, a / b))

    print('%s + %i = %s' % (a, i, a + i))
    print('%s - %i = %s' % (a, i, a - i))
    print('%s * %i = %s' % (a, i, a * i))
    print('%s / %i = %s' % (a, i, a / i))

    print('%i + %s = %s' % (i, a, i + a))
    print('%i - %s = %s' % (i, a, i - a))
    print('%i * %s = %s' % (i, a, i * a))
    print('%i / %s = %s' % (i, a, i / a))

class complex:
    def __init__(self, real, imaginary):
        self.real = real
        self.imaginary = imaginary

    def __str__(self):
        if self.imaginary == 0:
            return '%s' % self.real
        elif self.real == 0:
            return '%si' % self.imaginary
        elif self.imaginary > 0:
            return '%s + %si' % (self.real, self.imaginary)
        else:
            return '%s - %si' % (self.real, abs(self.imaginary))

    def __radd__(self, other):
        return self + other

    def __add__(self, other):
        if isinstance(other, float):
            return complex(self.real + other, self.imaginary)
        elif isinstance(other, complex):
            return complex(self.real + other.real, self.imaginary + other.imaginary)
        else:
            raise TypeError

    def __rsub__(self, other):
        return self - other
    
    def __sub__(self, other):
        if isinstance(other, float):
            return complex(self.real - other, self.imaginary)
        elif isinstance(other, complex):
            return complex(self.real - other.real, self.imaginary - other.imaginary)
        else:
            raise TypeError

    def __rmul__(self, other):
        return self * other

    def __mul__(self, other):
        if isinstance(other, float):
            return complex(self.real * other, self.imaginary * other)
        elif isinstance(other, complex):
            return complex(self.real * other.real - self.imaginary * other.imaginary, self.real * other.imaginary + self.imaginary * other.real)
        else:
            raise TypeError

    def __rtruediv__(self, other):
        return self / other

    def __truediv__(self, other):
        if isinstance(other, float):
            return complex(self.real / other, self.imaginary / other)
        elif isinstance(other, complex):
            return complex(self.real / other.real, self.imaginary / other.imaginary)
        else:
            raise TypeError