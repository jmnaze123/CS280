package KnightsTourProjectOne.ProjectOne;

public class Main {
    private static int[][] board = new int[8][8];
    private static int xMoves[] = {2,1,-1,-2,-2,-1,1,2}, yMoves[] = {1,2,2,1,-1,-2,-2,-1};
    public static void main(String[] args) {
        board[0][0] = 1;
        solve();
    }
    private static void solve() {
        if(!move(0,0,1)){
            System.err.println("No solution.");
        } else {
            printBoard();
        }
    }
    private static boolean move(int x, int y, int number) {
        int nextX, nextY;
        if (number == 64) return true;
        for (int i = 0; i < 8; i++) {
            nextX = xMoves[i] + x;
            nextY = yMoves[i] + y;
            if (valid(nextX, nextY)) {
                board[nextX][nextY] = number + 1;
                if (move(nextX, nextY, number + 1)) return true; 
                else board[nextX][nextY] = 0;
            }
        }
        return false;
    }
    private static boolean valid(int x, int y) {
        return x >= 0 && y >= 0 && x < 8 && y < 8 && board[x][y] == 0;
    }
    private static void printBoard() {
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++)
                System.out.print(board[row][col] + "     ");
            System.out.println();
        }
    }
}