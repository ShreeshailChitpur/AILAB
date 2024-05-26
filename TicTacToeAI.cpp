#include <bits/stdc++.h>
using namespace std;

vector<char> board(9, ' ');
int player;

bool checkWin(char p){
    for(int i=0;i<3;i++){
        if((board[i*3] == p && board[i*3+1] == p && board[i*3+2] == p) || (board[i] == p && board[i+3] == p && board[i+6] == p)){
            return true;
        }
    }
    if((board[0] == p && board[4] == p && board[8] == p) || (board[2] == p && board[4] == p && board[6] == p)){
        return true;
    }
    return false;
}

bool isFull(){
    for(int i=0;i<9;i++){
        if(board[i] == ' '){
            return false;
        }
    }
    return true;
}


int evaluateBoard(){
    if(checkWin('X')){
        return 10;
    }
    if(checkWin('O')){
        return -10;
    }
}

int minimax(int maxi){
    int score = evaluateBoard();
    if(score == 10 || score == -10){
        return score;
    }

    if(isFull()){
        return 0;
    }

    if(maxi){
        int bestscore = -1000;
        for(int i=0;i<9;i++){
            if(board[i]==' '){
            board[i] = 'X';
            bestscore = max(bestscore, minimax(!maxi));
            board[i] = ' ';
        }
        }
        return bestscore;
    }else{
        int bestscore = 1000;
        for(int i=0;i<9;i++){
            if(board[i]==' '){
            board[i] = '0';
            bestscore = min(bestscore, minimax(!maxi));
            board[i] = ' ';
        }
        }
        return bestscore;
    }
}


int bestMove(){
    int bestscore = -1000;
    int pos = -1;
    for(int i=0;i<9;i++){
        if(board[i]==' '){
            board[i] == 'X';
            int movescore = minimax(false);
            board[i] = ' ';
            if(movescore > bestscore){
                bestscore = movescore;
                pos = i;
            }
        }
    }
    return pos;
}

void printBoard(){
    for (int i = 0; i < 3; i++)
    {
        for (int j = i * 3; j < i * 3 + 3; j++)
            cout << board[j] << " ";
        cout << endl;
    }
    cout << endl;
}


int main(){
    player = 1;
    while(!checkWin('X') && !checkWin('O') && !isFull()){
        if(player == 1){
            int best = bestMove();
            board[best] = 'X';
            player = 2;
        }else{
            int pos;
            cout << "Enter move position: "<<endl;
            cin >> pos;
            if(board[pos] == ' '){
                board[pos] = 'O';
                player = 1;
            }else{
                cout << "Enter valid kahitari bhai" <<endl;
            }
        }
        printBoard();
        if(checkWin('X')){
            cout << "lmaooo loser" << endl;
            break;
        }
        if(checkWin('O')){
            cout<< "You win!"<<endl;
            break;
        }
    }
    return 0;
}