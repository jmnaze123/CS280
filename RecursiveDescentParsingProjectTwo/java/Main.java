package RecursiveDescentParsingProjectTwo.java;

import java.io.*;
import java.lang.String;

public class Main {
    public static String text = "";
    public static int i;

    public static void main(String[] args) {

        String fin = "/Users/johnnymayo/Documents/GitHub/CS280/RecursiveDescentParsingProjectTwo/java/input.txt";
        // String fin = "input.txt";
        String tempText;

        try {
            FileReader fr = new FileReader(fin);
            BufferedReader br = new BufferedReader(fr);

            while((tempText = br.readLine()) != null) {
                text = tempText;
                i = 0;

                if(A ()) {
                    System.out.println(text + "\u001B[32m is in the language.\u001B[37m	");
                } else if (!text.equals("")){
                    System.out.println(text + "\u001B[31m is not in the language.\u001B[37m	");
                }
            }
            br.close();
        }

        catch(IOException e) {
            System.err.println("\u001B[31m" + e);
        }
    }

    private static boolean A() {

        if (I()) {
            if(i<text.length() && (text.charAt(i) == '=')) {
                ++i;
                if(E ()) {
                    return true;
                }
            }
        }

        return false;
    }

    private static boolean E() {

        if (P()) {
            if (O ()) {
                if (P()) {
                    return true;
                }
            } else {
                return true;
            }
        }
        
        return false;

    }

    private static boolean O() {

        if(i<text.length() && (text.charAt(i) == '+')) {
            ++i;
            return true;

        } else if(i<text.length() && (text.charAt(i) == '-')) {
            ++i;
            return true;

        } else if(i<text.length() && (text.charAt(i) == '/')) {
            ++i;
            return true;

        } else if(i<text.length() && (text.charAt(i) == '*')) {
            ++i;
            if(i<text.length() && (text.charAt(i) == '*')) {
                ++i;
                return true;
            }

            return true;
        }

        return false;
    }

    private static boolean P(){

        if(I()){
            return true;

        }else if(L()){
            return true;

        }else if(U() && I()){
            return true;

        }else if(U() && L()){
            return true;

        }else if(i<text.length() && (text.charAt(i) == '(')){
            ++i;
            
            if(E()){
                if(i<text.length() && (text.charAt(i) == ')')){
                    ++i;
                    return true;
                }
            }
        }

        return false;

    }

    private static boolean U(){

        if(i<text.length() && (text.charAt(i) == '+' || text.charAt(i) == '-' || text.charAt(i) == '!')) {
            ++i;
            return true;
        }

        return false;

    }

    private static boolean I(){

        if(C()) {
            return true;

        } else if(C() && I()) {
            return true;
        }

        return false;

    }

    private static boolean C(){

        if(i<text.length() && (text.charAt(i) >= 'a' && text.charAt(i) <= 'z')) {
            ++i;
            return true;
        }

        return false;

    }

    private static boolean L (){

        if(D()) {
            return true;

        } else if(D() && L()) {
            return true;
        }

        return false;
    }

    private static boolean D(){

        if(i<text.length() && (text.charAt(i) >= '0' && text.charAt(i) <= '9')) {
            ++i;
            return true;
        }

        return false;
    }

}