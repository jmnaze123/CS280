package RecursiveDescentParsingProjectTwo.java;

import java.io.File;
import java.io.IOException;
// import java.io.PrintWriter;
import java.util.Scanner;

//      A -> I = E
//      E -> P O P | P
//      O -> + | - | * | / | **
//      P -> I | L | UI | UL | (E)
//      U -> + | - | !
//      I -> C | CI
//      C -> a | b | ... | y | z
//      L -> D | DL
//      D -> 0 | 1 | ... | 8 | 9

public class Main {
    public static void main(String[] args) {
        File fin = new File("/Users/johnnymayo/Documents/GitHub/CS280/RecursiveDescentParsingProjectTwo/java/input.txt");
        // File fout = new File("/Users/johnnymayo/Documents/GitHub/CS280/RecursiveDescentParsingProjectTwo/java/output.txt");

        try (//PrintWriter pw = new PrintWriter(fout);
             Scanner sc = new Scanner(fin)){
                while (sc.hasNext()){
                    String next = sc.next();
                    System.out.println(next);
                    checkGrammar(next);
                }
        } 
        catch (IOException e) {
            System.err.println("\u001B[31m" + e);
        }
    }

    public static void checkGrammar(String text){
        int valid = 0;

        for (int i = 0; i < text.length(); i++) {
            char temp = text.charAt(i);
            if (A(temp)) {
                valid = 1;
            } else {
                valid = 0;
                break;
            }
        }

        if (valid == 1) {
            System.out.println("\u001B[32m is in the language.\u001B[37m	");
        } else {
            System.out.println("\u001B[31m is not in the language.\u001B[37m	");
        }
    }

    public static boolean A(char text){
        return P(text);
    }
    public static boolean E(char text){

        return false;
    }
    public static boolean EP(String text){
        
        return false;
    }
    public static boolean O(char text){

        return false;
    }
    public static boolean P(char text){
        return I(text) || L(text);
    }
    public static boolean U(char text){

        return false;
    }
    public static boolean I(char text){

        if (C(text)) {
            return true;
        } else if (C(text)&&I(text)) {
            return true;
        }

        return false;
    }
    public static boolean C(char text){
        if ('a' <= text && text <= 'z') {
            return true;
        }

        return false;
    }
    public static boolean L(char text){
        if (D(text)) {
            return true;
        } else if (D(text)&&L(text)) {
            return true;
        }
        return false;
    }
    public static boolean D(char text){
        if ('0' <= text && text <= '9') {
            return true;
        }
        return false;
    }
}