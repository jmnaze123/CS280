import java.util.Scanner;

public class Main{


    private static int size = 8;
    private static int[][] board = new int[size][size];
    private static String ans;


    public static boolean solve() {
        System.out.println();
        System.out.println("Solution:");

        for (int x = 0; x < size; x++) {

            for (int y = 0; y < size; y++) {

                board[x][y] = -1;
            }
        }

        int xMoves[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
        int yMoves[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
        board[0][0] = 1;
        
        if (!move(0, 0, 1, xMoves, yMoves)) {

            System.out.println("No solution.");
            return false;
        } else {
            
            printBoard();
        }

        return true;
    }


    private static boolean move(int x, int y, int moveNumber, int xMoves[],int yMoves[]) {

        int nextX, nextY;
        
        if (moveNumber == size * size) {

            return true;
        }
 
        for (int i = 0; i < size; i++) {

            nextX = x + xMoves[i];
            nextY = y + yMoves[i];
            
            if (valid(nextX, nextY)) {

                board[nextX][nextY] = moveNumber + 1;
                
                if (move(nextX, nextY, moveNumber + 1, xMoves, yMoves)) {

                    return true;
                } else {

                    board[nextX][nextY] = -1;
                }
            }
        }

        return false;
    }


    private static boolean valid(int x, int y) {

        if (x >= 0 && x < size && 
            y >= 0 && y < size && 
            board[x][y] == -1) {
            
            return true;
        }

        return false;
    }

    private static void printBoard() {

        if (ans.equalsIgnoreCase("y")) {

            for (int row = 0; row < size; row++) {

                for (int col = 0; col < size; col++) {

                    // nice formatting   :)
                    if(board[row][col] == 1){
                        System.out.print("\u001B[31m  0" + board[row][col] + "\u001B[0m");
                    } else if (board[row][col] <= 5){
                        System.out.print("\u001B[32m  0" + board[row][col] + "\u001B[0m");
                    } else if (board[row][col] < 10){
                        System.out.print("  0" + board[row][col]);
                    } else if (board[row][col] >= 59 && board[row][col] != 64){
                        System.out.print("\u001B[33m  " + board[row][col] + "\u001B[0m");
                    } else if (board[row][col] == 64){
                        System.out.print("\u001B[31m  " + board[row][col] + "\u001B[0m");
                    } else {
                        System.out.print("  " + board[row][col]);
                    }
                }

                System.out.println();System.out.println();
            }

        } else {

            for (int row = 0; row < size; row++) {

                for (int col = 0; col < size; col++) {

                    System.out.print("  " + board[row][col]);
                }

                System.out.println();
            }
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Nice formatting? (Y/N)");
        ans = sc.nextLine();
        solve();
        sc.close();
    }
}