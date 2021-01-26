#include <iostream>
#include <conio.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <fstream>
using namespace std;

//Count Score
static int score;

//Save name in file 
void create(const string name)
{
  ofstream MyFile("name.txt");
  MyFile << name;
  MyFile.close();
}

int main()
{
	
	char ch;
		
		int choice;
		cout << "*************** \t Welcome to Win-Predict \t ***************** "<<endl;
		cout << "Developed By : Soujatya Bhattacharya" <<endl;
			
		//Clear Buffer
		fflush(stdin);
		
		game:
		//All Data members
		string name;
		int index = 0;
		srand(time(NULL));
		int number_of_attemp = rand() % 10 + 1;
		int counter = 0;
		char key;
		char *input = new char[number_of_attemp];
		
		
		//Display title
		system("title Win-Predict Game");
		
			
		//Check name is in file or not
		if (ch != 'y')
			{
				cout << "Enter You Name : ";
				getline(cin,name);
				create(name);
				
			}
		else
			{
				ifstream MyFile("name.txt");
				getline (MyFile, name);	
				cout << "Player Name : " << name << endl;
				MyFile.close();
			}
			
		
		//Get Keys
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
		int board_rand,display;
		srand(time(NULL));
		
		//Board column create
		char **design = new char*[12];
		for(int i = 0; i < 12; ++i)
   			 design[i] = new char[4];
   		
		
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
			
			
		for (display = 0; display < number_of_attemp; display++)
		{
			cout << "Player Name : " << name<<endl;
			cout << "Count : " << display+1<< endl << "Destination Row : " << number_of_attemp << endl;
			cout << "Score : " << score <<endl;
			
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
	
	//clear buffer
	fflush(stdin);
			
	//Result Declearation//
	if (design[number_of_attemp - 1][0] == 'O')
		{
			//Count Score
			score++;
			cout << "Conglatunation " <<name << "!! You Win :)" <<endl <<endl;
		}
	else
		cout << "Aww " <<name << "!! You lose :(" <<endl <<endl;
		
	

	//Replay or Not
	cout << "Do you want to play again ? (y/n)";
	cin >> ch;
	if (ch == 'y') 
		{
			system("cls");
			goto game;
		}
	else
		{
			system("cls");
			cout << "Good Bye " << name << ". See you again :)";
		}
		
	//Dealocate table
	delete[] design;
	
	return 0;
}
