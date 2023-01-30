#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

char square[10] = { '0','1','2','3','4','5','6','7','8','9'} ; // Array to store X and O in board
int win();  		 		// 1. Checks win condition with 3 matching X or O
void board_bg (); 			//  2. Displays board background
void reset_board();         //  3. Resets board background

int player = 1;
int main()
{
	int n,choice;
    char mark , again = 'Y';
	do
	{
		do
		{
			system("CLS");
			board_bg();
			player = (player % 2)?1:2;                        // Selection of player.
			cout<<"\n Player "<<player<<" Enter a number : ";
			cin>>choice;
			mark = (player == 1)? 'X':'O';
			
			if(choice == 1 && square[1] == '1')        
				square[1] = mark;
			else if(choice == 2 && square[2] == '2')
				square[2] = mark;
			else if(choice == 3 && square[3] == '3')
				square[3] = mark;
			else if(choice == 4 && square[4] == '4')
				square[4] = mark;
			else if(choice == 5 && square[5] == '5')
				square[5] = mark;
			else if(choice == 6 && square[6] == '6')
				square[6] = mark;
			else if(choice == 7 && square[7] == '7')
				square[7] = mark;
			else if(choice == 8 && square[8] == '8')
				square[8] = mark;
			else if(choice == 9 && square[9] == '9')
				square[9] = mark;
			else 
			{
				cout<<"Invalid move!!!";
				player--;
				getch();
			}
			n = win();								//Check whether player won or not
			player++;								//Chance for the next player
		}	while(n == -1);
		               board_bg();
	
			if(n==1)
				cout<<"\n\n\t\a***** PLAYER "<<--player<<" WINS *****!!!";
			else 
				cout<<"\n\n\t\a GAME DRAW";
				cout<<"\n\n Do you want to play again? (Y/N)";
				cin>>again;
				if(again!='n'||again!='N')
				cout<<"\n\n See you soon.\n Thank you.";
				reset_board();
    }   	while(again == 'Y'|| again =='y');
			
			return 0;	
}

int win()           // Function to check if a player has won using 3 matching X or O condition.
{
		if(square[1] == square[2] && square[2] == square[3])
			return 1;	
		else if(square[1] == square[4] && square[4] == square[7])
			return 1;		
		else if(square[1] == square[5] && square[5] == square[9])
			return 1;
		else if(square[2] == square[5] && square[5] == square[8])
			return 1;
		else if(square[3] == square[6] && square[6] == square[9])
			return 1;	
		else if(square[3] == square[5] && square[5] == square[7])
			return 1;	
		else if(square[4] == square[5] && square[5] == square[6])
			return 1;
   		else if (square[7] == square[8] && square[8] == square[9])
			return 1;
		else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
}

void board_bg (void)      //Function to display board.
{
		system("CLS");
		cout<<"\n\n\t\t  TIC-TAC-TOE\n\t\t *************\n";
		cout<<"     Player 1 -> 'X'    vs    Player 2 -> 'O'\n\n\n";
		cout<<"\t    _____ _____ _____ \n";
		cout<<"\t   |     |     |     |\n";
		cout<<"\t   |  "<<square[1]<<"  |"<<"  "<<square[2]<<"  |"<<"  "<<square[3]<<"  |\n";
		cout<<"\t   |_____|_____|_____|\n";
		cout<<"\t   |     |     |     |\n";
		cout<<"\t   |  "<<square[4]<<"  |"<<"  "<<square[5]<<"  |"<<"  "<<square[6]<<"  |\n";
		cout<<"\t   |_____|_____|_____|\n";
		cout<<"\t   |     |     |     |\n";
		cout<<"\t   |  "<<square[7]<<"  |"<<"  "<<square[8]<<"  |"<<"  "<<square[9]<<"  |\n";
		cout<<"\t   |_____|_____|_____|\n"; 
}

void reset_board()     // Function to reset board.
{
		square[0] = '0';
		square[1] = '1';
		square[2] = '2';
		square[3] = '3';
		square[4] = '4';
		square[5] = '5';
		square[6] = '6';
		square[7] = '7';
		square[8] = '8';
		square[9] = '9';
		player = 1;
}  
