/*
Version 1.1 
Written by: Christopher Cruz
This program is free to distribute and you are welcome to improve on or change
anything as long as you give me credit.
Also this program can not be sold.
*/
/*
Different views for the Menu System
Each view returns the option chosen by the user. Takes the answer as a string and returns it
as a int value
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <string.h>

using namespace std;

class view{
public:
	int mainMenu(){
		int choice;
		string answer;
		
		cout<<"FLL Scoring System"<<endl;
		cout<<"Please make a selection"<<endl;
		cout<<"1) Project Rankings"<<endl;
		cout<<"2) Core Values Rankings"<<endl;
		cout<<"3) Robot Design Rankings"<<endl;
		cout<<"4) Exit"<<endl;
		
		cin>>answer;
		istringstream(answer) >>choice;
		
		return choice;
		
	}//mainMenu	
	
	
	int projectMenu(){
		int choice;
		string answer;
		
		cout<<"Project Menu"<<endl;
		cout<<"1) Research Rankings"<<endl;
		cout<<"2) Innovative Solutions Rankings"<<endl;
		cout<<"3) Presentation Rankings"<<endl;
		cout<<"4) Overall Project Rankings"<<endl;
		cout<<"5) Main Menu"<<endl;
		cin>>answer;
		istringstream(answer) >> choice;
		
		return choice;
	}//coreMenu
	
	
	int coreMenu(){
		int choice;
		string answer;
		
		cout<<"Core Values Menu"<<endl;
		cout<<"1) Inspiration Rankings"<<endl;
		cout<<"2) Teamwork Rankings"<<endl;
		cout<<"3) Gracious Professionalism Rankings"<<endl;
		cout<<"4) Overall Core Values Rankings"<<endl;
		cout<<"5) Main Menu"<<endl;
		cin>>answer;
		istringstream(answer) >> choice;
		
		return choice;
	}//coreMenu
	
	
	int robotMenu(){
		int choice;
		string answer;
		
		cout<<"Robot Design Menu"<<endl;
		cout<<"1) Mechanical Design Rankings"<<endl;
		cout<<"2) Programming Rankings"<<endl;
		cout<<"3) Stategy & Innovation Rankings"<<endl;
		cout<<"4) Overall Robot Design Rankings"<<endl;
		cout<<"5) Main Menu"<<endl;
		cin>>answer;
		istringstream(answer) >> choice;
		
		return choice;
	}//robotMenu
	
	
	
};