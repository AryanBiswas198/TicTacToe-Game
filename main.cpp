#include<iostream>
using namespace std;

void drawline(int n, char ch){

    for(int i=0; i<n; i++){
        cout<<ch;
    }
    cout<<endl;
}

void drawboard(char board[3][3]){

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<board[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool checkmove(char board[3][3], char player){

    for(int i=0; i<3; i++){
        if((board[i][0] == player && board[i][1] == player && board[i][2] == player) || (board[0][i] == player && board[1][i] == player && board[2][i] == player)){
            return true;
        }
    }

    if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return true;
    }

    if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
        return true;
    }
    return false;
}

int main(){

    char player = 'X';
    int row = 0, col = 0, turn;

    char board[3][3] = {{' ', ' ', ' '}, 
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};

    
    drawline(70, '-');
    cout<<"\n";

    for(turn=0; turn<9; turn++){

        drawboard(board);

        while(true){
            cout<<"Player "<<player<<" , enter row (0-2) and column (0-2)\n\n\n";
            cin>>row>>col;

            if(board[row][col] != ' ' || row<0 || row>2 || col<0 || col>2){
                cout<<"Invalid Move !! Try Again !! \n";
            }
            else{
                break; //Assuming Player inserted valid move, go out of loop
            }
        }

        board[row][col] = player;

        if(checkmove(board, player)){
            drawboard(board);
            cout<<"\nPlayer "<<player<<" has won the game\n";
            break;
        }

        // or else, switch the player
        player = (player == 'X') ? 'O' : 'X';
    }

    // End of game
    drawboard(board);


    if(turn == 9 && !checkmove(board, 'X') && !checkmove(board, 'O')){
        cout<<"It's a draw !!\n";
    }
    return 0;
}