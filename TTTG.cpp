
//                              MINI PROJECT ON TIC TAC TOE GAME

//            Summary : In this project,  I used if-else and Loops control flow statements ,functions,string and Array .



#include <iostream>



#include <conio.h>
#include <cstring>
using namespace std;

void printBoard();
int addMark();
int check();

char board[3][3] = {' ',' ',' ',
					' ',' ',' ',
					' ',' ',' '};
int turn = 1;        // 1-Player 1 | 0-Player 2
char mark = 'O';     // O-Player 1 | X-Player 2
int input;

int main(){
       system("cls");

	
    string Name1;
     cout<<"Enter Name Player 1  :       ";
     getline(cin,Name1);
     cout<<endl;
     string Name2;
     cout<<"Enter Name Player 2  :       ";
     getline(cin,Name2);
     cout<<endl;

	int won = 0;
	int validInput = 0;
    char choice;
    do{
	for(int i=0; i<9; i++){
		system("cls");
		printBoard();
		if(turn)
         cout<<Name1<<"  Turn (Symbol: O)"<<endl<<endl;
		else 
        cout<<Name2<<" Turn (Symbol: X)"<<endl<<endl;

		cout<<"Enter The Position(1 to 9) :     ";
		cin>>input;
		while(input<0 || input>9){
			cout<<"Invalid Input. Please Re-Enter input: ";
			cin>>input;
		}
		if(turn)
         mark = 'O';
		else 
         mark = 'X';

		validInput = addMark();
		if( !validInput ){
			i--;
			continue;
		}
		won = check();
		if(won){
			system("cls");
			printBoard();
			if(turn) 
			cout<<endl<<"***"<<Name1<<" - You Won ***";
			else 
			cout<<endl<<"***"<<Name2 <<" - You Won ***";
			getch();
			break;
		}
		if(i==8){
			system("cls");
			printBoard();
			cout<<endl<<"*** MATCH DRAW ***";
		}
		turn = !turn;
	}
		cout<<"\n\nDo you want to play again(y/n) :    ";
		cin>>choice;
	}while(choice == 'y');
    

	return 0;
}

void printBoard(){
	cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" "<<endl;
	cout<<"------------"<<endl;
	cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" "<<endl;
	cout<<"------------"<<endl;
	cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" "<<endl;
}
int addMark(){
	for(int i=0,k=1; i<3; i++ ){
		for(int j=0; j<3; j++,k++){
			if( k==input )
				if(board[i][j] == ' '){
					board[i][j] = mark;
					return 1;
				}
				else{
					cout<<"Invalid Input";
					getch();
					return 0;
				}
		}
	}
}
int check(){
	//checking rows
	if(board[0][0]==mark && board[0][1]==mark && board[0][2]==mark)
		return 1;
	if(board[1][0]==mark && board[1][1]==mark && board[1][2]==mark)
		return 1;
	if(board[2][0]==mark && board[2][1]==mark && board[2][2]==mark)
		return 1;
	//checking Columns
	if(board[0][0]==mark && board[1][0]==mark && board[2][0]==mark)
		return 1;
	if(board[0][1]==mark && board[1][1]==mark && board[2][1]==mark)
		return 1;
	if(board[0][2]==mark && board[1][2]==mark && board[2][2]==mark)
		return 1;

	//checking diagonals
	if(board[0][0]==mark && board[1][1]==mark && board[2][2]==mark)
		return 1;
	if(board[0][2]==mark && board[1][1]==mark && board[2][0]==mark)
		return 1;

	return 0;
}