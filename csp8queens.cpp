#include <iostream>
using namespace std;

const int N = 4;

void printBoard(char board[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(char board[N][N], int row, int col){
    //check left row
    for(int i=0;i<col;i++){
        if(board[row][i] == 'Q'){
            return false;
        }
    }

    //check upper left diagonal
    for(int i=row, j = col;i>=0 && j>=0;i--,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    //check lower left diagonal
    for(int i=row, j = col;i<=N && j>=0;i++,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

bool solveNQueens(char board[N][N], int col){
    if(col >= N){ //all queers are placed
        return true;
    }

    for(int i=0;i<N;i++){
        if(isSafe(board, i, col)){
            board[i][col] = 'Q';

            if(solveNQueens(board, col+1)){
                return true;
            }

            board[i][col] = '.'; //backtrack
        }
    }
    return false;
}

int main(){

    //initialize board
    char board[N][N]; 
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j] = '.';
        }
    }
    printBoard(board);

    if(solveNQueens(board, 0)){
        cout<< "Solution exists." <<endl;
        printBoard(board);
    }else{
        cout<< "Solution doesn't exist." <<endl;
    }
    return 0;
}