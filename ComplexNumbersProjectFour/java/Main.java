package ComplexNumbersProjectFour.java;
//
//
//  Java Version
//
//

public class Main {

    public static void main(String[] args) {

        Complex a = new Complex(1.0, 2.0);
        Complex b = new Complex(1.0, 3.0);

        double i = 5.0;

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

class Complex {
    
        private double real;
        private double imag;

        public String toString() {
            return "(" + real + " + " + imag + "i)";
        }

        public Complex(int real, int imag) {

            this.real = real;
            this.imag = imag;
        }
    
        public Complex(double real, double imag) {

            this.real = real;
            this.imag = imag;
        }

        public Complex(double real) {

            this.real = real;
            this.imag = 0;
        }

        public Complex(int real) {

            this.real = real;
            this.imag = 0;
        }

        public Complex add(Complex c) {

            return new Complex(this.real + c.real, this.imag + c.imag);
        }

        public Complex sub(Complex c) {

            return new Complex(this.real - c.real, this.imag - c.imag);
        }

        public Complex mul(Complex c) {

            return new Complex(this.real * c.real - this.imag * c.imag, this.real * c.imag + this.imag * c.real);
        }

        public Complex div(Complex c) {

            return new Complex((this.real * c.real + this.imag * c.imag) / (c.real * c.real + c.imag * c.imag), (this.imag * c.real - this.real * c.imag) / (c.real * c.real + c.imag * c.imag));
        }

        public Complex add(double d){
            
            return new Complex(this.real + d, this.imag);
        }

        public Complex sub(double d){
                
            return new Complex(this.real - d, this.imag);
        }

        public Complex mul(double d){

            return new Complex(this.real* d, this.imag * d);
        }

        public Complex div(double d){

            return new Complex(this.real / d, this.imag / d);
        }
}