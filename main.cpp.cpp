#include<iostream>
#include <vector>
using namespace std;

int currentPlayer; 
char currentMarker;
int boardSize;
vector<vector<char>> board;

void drawboard(){
    int boardNumber = 1;

    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){

            if(board[i][j] == 0){
                if(boardNumber < 10)
                    cout << " " << boardNumber << "  | ";
                else
                    cout << " " << boardNumber << " | ";
            }
            else{
                cout << " " << board[i][j] << "  | ";
            }

            boardNumber++;
        }
        cout << endl;
    }
}

bool placeMarker(int slot){
    int row = (slot-1)/boardSize;
    int col = (slot-1)%boardSize;
    if(board[row][col]!='X' && board[row][col] != 'O'){
        board[row][col] = currentMarker;
        return true;
    }
    else return false;
    
}

int winner() {
    for(int i = 0; i < boardSize; i++) {
    int c = 0;
        for(int j = 0; j < boardSize - 1; j++) {
            if(board[i][j] != board[i][j+1] || board[i][j]==0) {
                c = 1;
                break;
            }
        }
        if(c == 0) {
            return currentPlayer;
        }
    }
    for(int i = 0; i < boardSize; i++) {
    int c = 0;
        for(int j = 0; j < boardSize - 1; j++) {
            if(board[j][i] != board[j+1][i] || board[i][j]==0) {
                c = 1;
                break;
            }
        }
        if(c == 0) {
            return currentPlayer;
        }
    }
    int c=0;
    for(int i=0 ; i< boardSize-1 ; i++){
        
        if(board[i][i] != board[i+1][i+1] || board[i][i]==0){
            c=1;
            break;
        }

    }
    if(c==0) return currentPlayer;
    int t=0;
    for(int i=0 ; i< boardSize-1 ; i++){
        
        if(board[i][boardSize - 1 - i] != board[i][boardSize - 2 - i] || board[i][i]==0){
            t=1;
            break;
        }

    }
    if(t==0) return currentPlayer;
    return 0;
}

void swapPlayerandMarker(){
    if(currentMarker =='X') currentMarker = 'O';
    else currentMarker ='X';
    if (currentPlayer == 1) currentPlayer = 2;
    else currentPlayer = 1;
}



void game(){
    string player1 , player2;
    cout << "Enter the size of board(3-10) :";
    cin >> boardSize;
    board.assign(boardSize, vector<char>(boardSize, 0));
    cout << "Enter Player 1's name :";
    cin >> player1;
    cout << "Enter Player 2's name :";
    cin >> player2;
    cout << player1 <<" , choose between X or O :";
    char markerp1;
    cin >> markerp1;
    currentPlayer = 1;
    currentMarker = markerp1;
    drawboard();
    int playerwon = 0;
    for(int i=0 ; i<boardSize*boardSize ; i++){
        
        cout << "Its " << ((currentPlayer == 1) ? player1:player2) << "'s turn ("<< currentMarker <<").\nChoose an empty slot :";
        int slot;
        cin >> slot;
        if(slot >boardSize*boardSize || slot < 1){
            cout << "Please enter a number between 1 and " << boardSize*boardSize;
            i--;
            continue;
        }
        if(placeMarker(slot) == false){
            cout << "That slot is already occupied. Try again.";
            i--;
            continue;
        }
        drawboard();
        playerwon = winner();
        if(playerwon == 1){
            cout << player1 <<" wins !";
            break;
        }
        if(playerwon == 2){
            cout << player2 <<" wins !";
            break;
        }
        swapPlayerandMarker();
        

    }
    if(playerwon == 0) {
            cout << "Its a tie  between " << player1 << " and " << player2 ;
    }
    string playAgain;
    cout << "\nDo you wanna play again (Yes/No) ?";
    cin >> playAgain;
    if(playAgain == "Yes"){
        game();
    }
    else{
        cout << "\nThank you for playing Tic Tac Toe .";
    }
}
int main(){
    game();
    return 0;
}

