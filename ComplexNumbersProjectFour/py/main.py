class rational:
    
    def __init__(self, num=0, den=1):

        self.num = num
        self.den = den

    def __add__(self, other):
        
        if isinstance(other, int):
            return rational(self.num + other * self.den, self.den)
        
        elif isinstance(other, rational):
            return rational(self.num * other.den + other.num * self.den, self.den * other.den)
        
        else:
            raise TypeError

    def __truediv__(self, other):

        if isinstance(other, int):
            return rational(self.num, self.den * other)

        elif isinstance(other, rational):
            return rational(self.num * other.den, self.den * other.num)

        else:
            raise TypeError

    def __float__(self):

        return float(self.num) / self.den

    def __int__(self):

        return self.num / self.den

    def __mul__(self, other):

        if isinstance(other, int):
            return rational(self.num * other, self.den)
        
        elif isinstance(other, rational):
            return rational(self.num * other.num, self.den * other.den)
        
        else:
            raise TypeError

    def __radd__(self, other):

        return self + other

    def __rtruediv__(self, other):
        
        return rational(other) / self

    def __rmul__(self, other):
        
        return self * other

    def __rsub__(self, other):
        
        return rational(other) - self

    def __str__(self):
        
        return '(' + str(self.num) + ' / ' + str(self.den) + ')'

    def __sub__(self, other):
        
        if isinstance(other, int):
            return rational(self.num - other * self.den, self.den)
        
        elif isinstance(other, rational):
            return rational(self.num * other.den - other.num * self.den, self.den * other.den)
        
        else:
            raise TypeError