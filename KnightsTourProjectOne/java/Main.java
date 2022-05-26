import java.util.Scanner;

public class Main {

    private static int x1, y1, size, recurCalls;
    private static int[][] board;
    private static int xMoves[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    private static int yMoves[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    private static String formatRequest;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
       
        System.out.print("\nEnter a board size (1,7, or 8): ");
        size = Integer.parseInt(sc.nextLine());

        if (!(size == 1 || size == 7 || size == 8)) {

            sc.close();
            System.err.println("Please rerun and enter a valid board size.");
            System.exit(0);
        }
        
        System.out.println("\nEnter starting X and Y (1-" + size + ") ");
        System.out.print("X: ");
        x1 = Integer.parseInt(sc.nextLine());
        System.out.print("Y: ");
        y1 = Integer.parseInt(sc.nextLine());

        if (x1 < 1 || x1 > size ||
            y1 < 1 || y1 > size) {

                sc.close();
                System.err.println("Please rerun and enter a valid starting position.");
                System.exit(0);
        }
        
        System.out.println("\nNice formatting? (Y/N) ");
        formatRequest = sc.nextLine();
        sc.close();
        System.out.println();

        x1--; y1--;
        board = new int[size][size];
        board[x1][y1] = 1;
        solve();
    }


    private static void solve() {
        System.out.println("Solution:");
        if(!move(x1,y1,1)){

            System.err.println("No solution.");
        } else {
            printBoard();
        }
    }


    private static boolean move(int x, int y, int number) {
        int nextX, nextY;
        
        if (number == size * size){
            return true;
        }

        for (int i = 0; i < size; i++) {
            nextX = xMoves[i] + x;
            nextY = yMoves[i] + y;

            if (valid(nextX, nextY)) {

                board[nextX][nextY] = number + 1;

                recurCalls++;
                if (move(nextX, nextY, number + 1)) {

                    return true;
                } else {

                    board[nextX][nextY] = 0;
                }
            }
        }

        return false;
    }


    private static boolean valid(int x, int y) {

        if (x >= 0 && y >= 0 &&
            x < size && y < size &&
            board[x][y] == 0) {

                return true;
            }

        return false;
    }


    private static void printBoard() {
        if (formatRequest.equalsIgnoreCase("y")) {
            for (int row = 0; row < size; row++) {

                for (int col = 0; col < size; col++) {

                    // nice formatting   :)
                    if(board[row][col] == 1){
                        System.out.print("\u001B[31m  0" + board[row][col] + "\u001B[0m");
                    } else if (board[row][col] <= 5){
                        System.out.print("\u001B[32m  0" + board[row][col] + "\u001B[0m");
                    } else if (board[row][col] < 10){
                        System.out.print("  0" + board[row][col]);
                    } else if (board[row][col] >= size*size-5 && board[row][col] != size*size){
                        System.out.print("\u001B[33m  " + board[row][col] + "\u001B[0m");
                    } else if (board[row][col] == size*size){
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

        String rc = String.format("%,d", recurCalls);

        System.out.println("\nRecursive calls: " + rc + "\n\n");
        System.out.println("Project One: Knight's Tour\nBy: John Mayo\n");
    }
}
