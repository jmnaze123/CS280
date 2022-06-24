package ComplexNumbersProjectFour.java;
//
//
//  Java Version
//
//


import java.text.DecimalFormat;

public class Main {

    public static void main(String[] args) {


        //RATIONAL NUMBER TESTING
        System.out.println("RATIONAL NUMBER TESTING");

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


        //COMPLEX NUMBER TESTING
        System.out.println("COMPLEX NUMBER TESTING");

        Complex y = new Complex(0, 1);
        Complex z = new Complex(3, 2);

        double d = 5.99;

        System.out.println(y + " + " + z + " = " + y.add(z));
        System.out.println(y + " - " + z + " = " + y.sub(z));
        System.out.println(y + " * " + z + " = " + y.mul(z));
        System.out.println(y + " / " + z + " = " + y.div(z));

        System.out.println(y + " + " + d + " = " + y.add(d));
        System.out.println(y + " - " + d + " = " + y.sub(d));
        System.out.println(y + " * " + d + " = " + y.mul(d));
        System.out.println(y + " / " + d + " = " + y.div(d));
    }
}

class Complex {
    
        private Rational real;
        private Rational imag;

        public String toString() {
            
            return "(" + real + " + " + imag + "i)";
        }

        public Complex(int real, int imag) {

            this.real = new Rational(real);
            this.imag = new Rational(imag);
        }
    
        public Complex(Rational real, Rational imag) {

            this.real = real;
            this.imag = imag;
        }

        public Complex(Rational real) {

            this.real = real;
            this.imag = new Rational(0);
        }

        public Complex(int real) {

            this.real = new Rational(real);
            this.imag = new Rational(0);
        }

        public Complex add(Complex c) {

            return new Complex(this.real.add(c.real), this.imag.add(c.imag));
        }

        public Complex sub(Complex c) {

            return new Complex(this.real.sub(c.real), this.imag.sub(c.imag));
        }

        public Complex mul(Complex c) {

            return new Complex(this.real.mul(c.real).sub(this.imag.mul(c.imag)), this.real.mul(c.imag).add(this.imag.mul(c.real)));
        }

        public Complex div(Complex c) {

            return new Complex(this.real.mul(c.real).add(this.imag.mul(c.imag)).div(c.real.mul(c.real).add(c.imag.mul(c.imag))), this.imag.mul(c.real).sub(this.real.mul(c.imag)).div(c.real.mul(c.real).add(c.imag.mul(c.imag))));
        }

        public Complex add(double d){

            //Converting double to Rational
            DecimalFormat df = new DecimalFormat("#.###############"); //Formats the double to a string with up to 15 decimal places
            String dfd = df.format(d); //does the formatting
            int indexOfDot = dfd.indexOf("."); //finds the index of the decimal
            int numOfDecimals = dfd.substring(indexOfDot+1, dfd.length()).length(); //finds the number of decima places (cut off everything before the decimal point)
            Rational doubleTRational = new Rational((int)(d * (Math.pow(10, numOfDecimals))),(int) (Math.pow(10, numOfDecimals))); //creates a rational from the double
            
            return new Complex(this.real.add(doubleTRational), this.imag);
        }

        public Complex sub(double d){
                
            //Converting double to Ration
            DecimalFormat df = new DecimalFormat("#.###############"); //Formats the double to a string with up to 15 decimal places
            String dfd = df.format(d); //does the formatting
            int indexOfDot = dfd.indexOf("."); //finds the index of the decimal
            int numOfDecimals = dfd.substring(indexOfDot+1, dfd.length()).length(); //finds the number of decima places (cut off everything before the decimal point)
            Rational doubleTRational = new Rational((int)(d * (Math.pow(10, numOfDecimals))),(int) (Math.pow(10, numOfDecimals))); //creates a rational from the double
                
            return new Complex(this.real.sub(doubleTRational), this.imag);
        }

        public Complex mul(double d){
               
            //Converting double to Ration
            DecimalFormat df = new DecimalFormat("#.###############"); //Formats the double to a string with up to 15 decimal places
            String dfd = df.format(d); //does the formatting
            int indexOfDot = dfd.indexOf("."); //finds the index of the decimal
            int numOfDecimals = dfd.substring(indexOfDot+1, dfd.length()).length(); //finds the number of decima places (cut off everything before the decimal point)
            Rational doubleTRational = new Rational((int)(d * (Math.pow(10, numOfDecimals))),(int) (Math.pow(10, numOfDecimals))); //creates a rational from the double
                
            return new Complex(this.real.mul(doubleTRational), this.imag.mul(doubleTRational));
        }

        public Complex div(double d){
                
            //Converting double to Ration
            DecimalFormat df = new DecimalFormat("#.###############"); //Formats the double to a string with up to 15 decimal places
            String dfd = df.format(d); //does the formatting
            int indexOfDot = dfd.indexOf("."); //finds the index of the decimal
            int numOfDecimals = dfd.substring(indexOfDot+1, dfd.length()).length(); //finds the number of decima places (cut off everything before the decimal point)
            Rational doubleTRational = new Rational((int)(d * (Math.pow(10, numOfDecimals))),(int) (Math.pow(10, numOfDecimals))); //creates a rational from the double
                
            return new Complex(this.real.div(doubleTRational), this.imag.div(doubleTRational));
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