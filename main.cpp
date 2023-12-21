#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
// function defination so i can call it before in the reset function 
void startGame();

// Enums 

enum Options {Stone=1,Paper=2,Scissors=3};

//Struct 

struct Player {
	Options Playeropt;
	int numOfwinning=0;
	int numOfdrwaing=0;
};

//Functions 

int numOfrounds()
{
	int num;
	cout << "Enter how many rounds : ";
	cin >> num;

	return num;
}
Options chooseOption() // function promt the option and return it as  an enum 
{
	int opt;
	cout << "Your choice: [1] stone ,[2] Paper , [3] Scissors ?";
	cin >> opt;

	return Options(opt);
}

Options chooseCompOption() // function promt the option and return it as  an enum 
{
	return Options(((rand() % 3 ) + 1));
}

string CheckWinner(Player &p, Player &com)
{

	
	if (p.Playeropt == Options::Scissors && com.Playeropt == Options::Paper)
	{
		p.numOfwinning++;

		system("color 2F");

		return "Player1";

	}
	else if (p.Playeropt == Options::Paper && com.Playeropt == Options::Stone)
	{
		p.numOfwinning++;

		system("color 2F");

		return "Player1";

	}
	else if (com.Playeropt == Options::Scissors && p.Playeropt == Options::Paper)
	{
		com.numOfwinning++;
		system("color 4F");
		return "Computer";
	}
	else if (com.Playeropt == Options::Paper && p.Playeropt == Options::Stone)
	{
		com.numOfwinning++;
		system("color 4F");
		return "Computer";
	}
	else {
		com.numOfdrwaing++;
		system("color 6F");
		return "No winner";
	}
}
void displayRoundinfo(int round, Player &p, Player &com)
{
	cout << "--------------- Round[" << round << "]------------------\n";
	string playerOption;
	string computerOption;
	switch (p.Playeropt)
	{
	case Options::Paper:
		playerOption = "Paper";
		break;
	case Options::Stone:
		playerOption = "Stone";
		break;
	case Options::Scissors:
		playerOption = "Scissors";
		break;


	}
	switch (com.Playeropt)
	{
	case Options::Paper:
		computerOption = "Paper";
		break;
	case Options::Stone:
		computerOption = "Stone";
		break;
	case Options::Scissors:
		computerOption = "Scissors";
		break;


	}
	cout << "Player1 Choice : " << playerOption << endl;
	cout << "Computer Choice :" << computerOption << endl;
	cout << "Round Winner :[" << CheckWinner(p, com)<<"]" << endl;
}

void displayGameinfo(int rounds, Player &p, Player &com)
{
	cout << "\n\n\n\n";
	cout << "\t\t----------G A M E O V E R----------\n ";
	cout << "\t\t------------Game Results---------------\n";
	cout << "Game rounds :" << rounds << endl;
	cout << "player1 won times " << p.numOfwinning << endl;
	cout << "Computer won times " << com.numOfwinning << endl;
	cout << "Draw times " << com.numOfdrwaing << endl;
	if (p.numOfwinning > com.numOfwinning)
		cout << "Final winner : Player1 \n";
	else if (com.numOfwinning > p.numOfwinning)
		cout << "Final winner : computer\n";
	else
		cout << "Final winner : No winner\n";

}


void resetGame()
{
	char c;
	cout << "Do you want to play again Y / N ";
	cin >> c;
	if (c=='Y' || c == 'y')
	{
		system("color 0F");
		system("CLS");
		startGame();

	}
	else
	{
		cout << "Thank you";
	}
}


void startGame()
{
	
	int num = numOfrounds(); // number of rounds will be returned
	Player player1;
	Player computer;
	computer.numOfwinning = 0;
	player1.numOfwinning = 0;
	computer.numOfdrwaing = 0;
	for (int i = 0; i < num; i++)
	{
		cout << "Round [" << i + 1 << "] begins :";
		player1.Playeropt = chooseOption();
		computer.Playeropt = chooseCompOption();
		displayRoundinfo(i+1,player1,computer);

	}
	displayGameinfo(num, player1, computer);
	resetGame();

}




int main()
{

	srand(time(0));

	startGame();

}