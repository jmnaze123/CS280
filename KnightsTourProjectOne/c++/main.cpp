#include <iostream>
#include <iomanip>

using namespace std;
#define size 8

void print(int [][size]);
bool solve(int[][size],int,int,int);

int main(){

    int i,j,row,col;
    int board[size][size];

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            board[i][j]=0;
        }
    }

    move(board,0,0,0);

    return 0;
}
void print(int board[][size]){

    int i,j;
    
    for (i=0;i<size;i++){

        for(j=0;j<size;j++){

            cout<<setw(4)<<board[i][j];
        }

        cout<<endl;
        cout<<endl;
    }
}

bool move(int board[][8],int m,int n,int last){

    int i,j,mpi,npj;
    board[m][n]=++last;
    
    if(last==size*size){

        print(board);
        return true;
    }

    for(i=-2;i<=2;i++){
        if(i!=0){
            for(j=-2;j<=2;j++){
                if(j!=0&&(i+j)%2!=0){
                    mpi=m+i;
                    npj=n+j;

                    if( mpi >= 0 && mpi < size && 
                        npj >= 0 && npj < size &&
                        board[mpi][npj] == 0 && move(board,mpi,npj,last)){

                        return true;
                    }
                }
            }
        }
    }
    board[m][n]=0;
    return false;
}