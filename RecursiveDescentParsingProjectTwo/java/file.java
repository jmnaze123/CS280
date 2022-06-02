package RecursiveDescentParsingProjectTwo.java;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class file {
    public static void main(String[] args) {
        File fin = new File("/Users/johnnymayo/Documents/GitHub/CS280/RecursiveDescentParsingProjectTwo/java/input.txt");
        File fout = new File("/Users/johnnymayo/Documents/GitHub/CS280/RecursiveDescentParsingProjectTwo/java/output.txt");

        try (PrintWriter pw = new PrintWriter(fout);
             Scanner sc = new Scanner(fin)){
                while (sc.hasNext()){
                    pw.println(sc.next());
                }
        } 
        catch (IOException e) {
            System.err.println("\u001B[31m" + e);
        }
    }
}
