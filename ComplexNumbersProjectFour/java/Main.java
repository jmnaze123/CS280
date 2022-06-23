package ComplexNumbersProjectFour.java;

public class Main {

    public static void main(String[] args) {

        Rational a = new Rational(1, 2);
        Rational b = new Rational(1, 3);

        int i = 5;

        System.out.println(a + " + " + b + " = " + a.add(b));
        System.out.println(a + " - " + b + " = " + a.sub(b));
        System.out.println(a + " * " + b + " = " + a.mul(b));
        System.out.println(a + " / " + b + " = " + a.div(b));

        System.out.println(a + " + " + i + " = " + a.add(i));
        System.out.println(a + " - " + i + " = " + a.sub(i));
        System.out.println(a + " * " + i + " = " + a.mul(i));
        System.out.println(a + " / " + i + " = " + a.div(i));
    }
}

class Rational {

    public Rational() {

        this(0);
    }

    public Rational(int num) {

        this(num, 1);
    }

    public Rational(int num, int den) {

        this.num = num;
        this.den = den;
    }

    public Rational add(Rational o) {

        return new Rational(num * o.den + o.num * den, den * o.den);
    }

    public Rational add(int n) {

        return new Rational(num + n * den, den);
    }

    public Rational div(Rational o) {

        return new Rational(num * o.den, den * o.num);
    }

    public Rational div(int n) {

        return new Rational(num, den * n);
    }

    public Rational mul(Rational o) {

        return new Rational(num * o.num, den * o.den);
    }

    public Rational mul(int n) {

        return new Rational(num * n, den);
    }

    public Rational sub(Rational o) {

        return new Rational(num * o.den - o.num * den, den * o.den);
    }

    public Rational sub(int n) {

        return new Rational(num - n * den, den);
    }

    public String toString() {

        return "(" + num + " / " + den + ")";
    }

    private int den;
    private int num;
}