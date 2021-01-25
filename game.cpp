#include <iostream>
#include <conio.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
using namespace std;

int main()
{
	
	char ch;
	
	back:
		
		//Clear Buffer
		fflush(stdin);
		
		//All Data members
		string name;
		int index = 0;
		srand(time(NULL));
		int number_of_attemp = rand() % 10 + 1;
		int counter = 0;
		char key;
		char *input = new char[number_of_attemp];
		
		//display title
		system("title Win-Predict Game");
		
		cout << "Enter You Name : ";
		getline(cin,name);
		
		cout<< "Press any keys : ";
		
		while(1)
		{
			 key = getch();
			 input[index++] = key;
			 cout << "*";
			 counter++;
			 if (counter == number_of_attemp)
			 	break;
		}
		
		//Add NULL char at end of charector array
		input[index] = '\0'; 
		
		//Clear Screen
		system("cls");
		
		//Board Initialize //
		int row,column;
		int board_rand,display;
		row = 12;
		column = 4;
		srand(time(NULL));
		char design[12][4]; //Board
		
		//Board Creation
		for(index = 0; index < 10; index++)
			{
				board_rand = rand() % 10;
				if (board_rand % 2 == 0)
					{
						design[index][0] = 'X';
						design[index][1] = '|';
						design[index][2] = ' ';
						design[index][3] = '|';
	
					}
				else
					{
						design[index][0] = 'O';
						design[index][1] = '|';
						design[index][2] = ' ';
						design[index][3] = '|';
					}
			}
			
		//Board Display	
		for (display = 0; display < number_of_attemp; display++)
		{
			cout << "Player Name : " << name<<endl;
			cout << "Count : " << display+1<< endl << "Destination Row : " << number_of_attemp << endl;
			
			cout <<"\t-------------"<<endl;
			design[display][2] = '*';
			for(index = 0; index < 10; index++)
				{
				 	cout << "\t| " <<design[index][0] << " " << design[index][1] << " " << design[index][2] << " " << design[index][3] << " " << design[index][0]<< " |" << endl; 
				}
			cout <<"\t-------------"<<endl;
			
		sleep(1);
		if(display+1 == number_of_attemp)
			break;
		else
			system("cls");
		}
	
	
	//Result Declearation//
	if (design[number_of_attemp][0] == 'O')
		cout << "Conglatunation " <<name << "!! You are Win :)" <<endl <<endl;
	else
		cout << "Aww " <<name << "!! You are loss :(" <<endl <<endl;
		
	
	//Replay or Not
	cout << "Do you want to play again ? (y/n)";
	ch = getch();
	if (ch == 'y') 
		{
			system("cls");
			goto back;
		}
	else
		{
			system("cls");
			cout << "Good Bye " << name << ". See you again :)";
		}
		
	return 0;
}
