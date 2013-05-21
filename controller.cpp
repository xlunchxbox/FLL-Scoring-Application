/*
Version 1.1 
Written by: Christopher Cruz
This program is free to distribute and you are welcome to improve on or change
anything as long as you give me credit.
Also this program can not be sold.
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

#include "model.cpp"
#include "view.cpp"

#define MAX 200				//MAX SIZE FOR ARRAYS/TEAMS

using namespace std;


class controller{
public:	

	Project projectArray[MAX];			
	coreValues coreArray[MAX];			
	robotDesign robotArray[MAX];
	bool flag;
	
	int teamCounter;				//keep track of total number of teams in competition
	int pCount;						//counter for project file
	int cvCount;					//counter for corevalues file
	int rdCount;					//counter for robotdesign file
	
	
	void startProgram(){
		int choice;
		
		view options;
		flag = false;				//csv are generated auto. at start, flag is set to false
									//to not print display functions to console
		readProcessFile();				
		startPrint();
			flag = true;			//after files are generated printing to console is
									//allowed


//take return value from menu and decide which submenu to call
//submenus are broken with option 5, main with option 4			
		while(choice != 4){
			choice = options.mainMenu();
			
			switch(choice){
				case 1:
					while(choice != 5){
						choice = options.projectMenu();
						
						switch(choice){
							case 1:
								pResearch();
							break;
							case 2:
								pInnovative();
							break;
							case 3:
								pPresentation();
							break;
							case 4:
								pProject();
							break;
							case 5:
							break;
						}//switch
					}//while
					break;
					
					
				case 2:
					while(choice != 5){
						choice = options.coreMenu();
						
						switch(choice){
							case 1:
								cvInspiration();
							break;
							case 2:
								cvTeamwork();
							break;
							case 3:
								cvGraciousP();
							break;
							case 4:
								cvCore();
							break;
							case 5:
							break;
						}//switch
					}//while
					break;
				case 3:
				
				
					while(choice != 5){
						choice = options.robotMenu();
						
						switch(choice){
							case 1:
								rdMechanical();
							break;
							case 2:
								rdProgramming();
							break;
							case 3:
								rdStrategy();
							break;
							case 4:
								rdRobot();	
							break;
							case 5:
							break;
						}//switch
					}//while
					break;	
					
					
				case 4:
					while(choice != 5){
						cout<<"Thank you for using the FLL Scoring System"<<endl;
						exit(0);
				}//while
				break;
			}//switch
		}//while

	}//startProgram
	

/*
The following functions sort by desired sort, and print to file with desired sorts. Also there
are printing functions for displaying to console.
User can not call print functions, those are executed automatically when program starts
Generated csv files are stored in printsouts folder and within their respective rubric folder
*/

	void readProcessFile(){
		ifstream project;
		project.open("project.csv");
		ifstream corevalues;
		corevalues.open("corevalues.csv");
		ifstream robotdesign;
		robotdesign.open("robotdesign.csv");
		
		teamCounter = 0;
		pCount = 0;
		cvCount = 0;
		rdCount = 0;
		
		string temp;
		string temp1;
		string tempArray[MAX];
		int argArray[11];
		int argCount = 0;
		int tempCount = 0;
		
		if(!project){
			exit(1);
		}//if
		
		if(!corevalues){
			exit(1);
		}//if
		
		if(!robotdesign){
			exit(1);
		}//if


		while(!project.eof()){
			project >> tempArray[tempCount];
			tempCount++;
		}	
		project.close();
		

		for(int i=0; i<tempCount; i++){
			temp = tempArray[i];
			temp.append(",");
			temp1 = "";
			for(int j=0; j<temp.length(); j++){
				if(temp[j] == ','){
					argArray[argCount] = ::atof(temp1.c_str());
					argCount++;
					temp1.clear();

					if(argCount == 11){
						projectArray[pCount].teamName = argArray[0];
						projectArray[pCount].ProblemIdentification = argArray[1];
						projectArray[pCount].SourcesofInformation = argArray[2];
						projectArray[pCount].ProblemAnalysis = argArray[3];
						projectArray[pCount].ReviewExistingSolutions = argArray[4];
						projectArray[pCount].TeamSolution = argArray[5];
						projectArray[pCount].Innovation = argArray[6];
						projectArray[pCount].Implementation = argArray[7];
						projectArray[pCount].Sharing = argArray[8];
						projectArray[pCount].Creativity = argArray[8];
						projectArray[pCount].PresentationEffectiveness = argArray[10];
						
						projectArray[pCount].section1 = 
							projectArray[pCount].ProblemIdentification +
							projectArray[pCount].SourcesofInformation +
							projectArray[pCount].ProblemAnalysis +
							projectArray[pCount].ReviewExistingSolutions;
							
						projectArray[pCount].section2 = 
							projectArray[pCount].TeamSolution +
							projectArray[pCount].Innovation +
							projectArray[pCount].Implementation;
							
						projectArray[pCount].section3 = 
							projectArray[pCount].Sharing + 
							projectArray[pCount].Creativity +
							projectArray[pCount].PresentationEffectiveness;
						
						projectArray[pCount].total = 
							projectArray[pCount].section1 +
							projectArray[pCount].section2 +
							projectArray[pCount].section3;
							
						
						teamCounter++;
						pCount++;
						
						argCount= 0;
					}//if	
				}//if
				else{
					temp1 += temp[j];	
				}//else
			}//for
		}//for

		argCount = 0;
		tempCount = 0;
		for(int i=0; i<tempCount; i++){
		tempArray[i] = "";
		}
	
		while(!corevalues.eof()){
			corevalues >> tempArray[tempCount];
			tempCount++;
		}
		corevalues.close();

		for(int i=0; i<tempCount; i++){
			temp = tempArray[i];
			temp.append(",");
			temp1 = "";
			for(int j=0; j<temp.length(); j++){
				if(temp[j] == ','){
					argArray[argCount] = ::atof(temp1.c_str());
					argCount++;
					temp1.clear();

					if(argCount == 10){
						coreArray[cvCount].teamName = argArray[0];
						coreArray[cvCount].Discovery = argArray[1];
						coreArray[cvCount].TeamSpirit = argArray[2];
						coreArray[cvCount].Integration = argArray[3];
						coreArray[cvCount].Effectiveness = argArray[4];
						coreArray[cvCount].Efficiency = argArray[5];
						coreArray[cvCount].KidsDoTheWork = argArray[6];
						coreArray[cvCount].Inclusion = argArray[7];
						coreArray[cvCount].Respect = argArray[8];
						coreArray[cvCount].Coopertition = argArray[9];

						coreArray[cvCount].section1 = 
							coreArray[cvCount].Discovery +
							coreArray[cvCount].TeamSpirit +
							coreArray[cvCount].Integration;
						coreArray[cvCount].section2 = 
							coreArray[cvCount].Effectiveness +
							coreArray[cvCount].Efficiency +
							coreArray[cvCount].KidsDoTheWork;
						coreArray[cvCount].section3 = 
							coreArray[cvCount].Inclusion +
							coreArray[cvCount].Respect +
							coreArray[cvCount].Coopertition;
						coreArray[cvCount].total = 
							coreArray[cvCount].section1 +
							coreArray[cvCount].section2 +
							coreArray[cvCount].section3;
						
						cvCount++;
						
						argCount= 0;
					}//if	
				}//if
				else{
					temp1 += temp[j];	
				}//else
			}//for
		}//for


	argCount = 0;
	tempCount = 0;
	for(int i=0; i<tempCount; i++){
		tempArray[i] = "";
	}
	
	while(!robotdesign.eof()){
		robotdesign >> tempArray[tempCount];
		tempCount++;
	}
	robotdesign.close();

		for(int i=0; i<tempCount; i++){
			temp = tempArray[i];
			temp.append(",");
			temp1 = "";
			for(int j=0; j<temp.length(); j++){
				if(temp[j] == ','){
					argArray[argCount] = ::atof(temp1.c_str());
					argCount++;
					temp1.clear();

					if(argCount == 10){
						robotArray[rdCount].teamName = argArray[0];
						robotArray[rdCount].Durability = argArray[1];
						robotArray[rdCount].MechanicalEfficiency = argArray[2];
						robotArray[rdCount].Mechanization = argArray[3];
						robotArray[rdCount].ProgrammingQuality = argArray[4];
						robotArray[rdCount].ProgrammingEfficiency = argArray[5];
						robotArray[rdCount].AutomationNavigation = argArray[6];
						robotArray[rdCount].DesignProcess = argArray[7];
						robotArray[rdCount].MissionStrategy = argArray[8];
						robotArray[rdCount].Innovation = argArray[9];

						robotArray[rdCount].section1 = 
							robotArray[rdCount].Durability +
							robotArray[rdCount].MechanicalEfficiency +
							robotArray[rdCount].Mechanization;
						robotArray[rdCount].section2 = 
							robotArray[rdCount].ProgrammingQuality +
							robotArray[rdCount].ProgrammingEfficiency +
							robotArray[rdCount].AutomationNavigation;
						robotArray[rdCount].section3 = 
							robotArray[rdCount].DesignProcess +
							robotArray[rdCount].MissionStrategy +
							robotArray[rdCount].Innovation;
						robotArray[rdCount].total =
							robotArray[rdCount].section1 +
							robotArray[rdCount].section2 +
							robotArray[rdCount].section3;
						
						rdCount++;
						
						argCount= 0;
					}//if	
				}//if
				else{
				temp1 += temp[j];	
			}//else
		}//for
		}//for

		//displayProject();		
		//displayCore();
		//displayRobot();
				
	}//readProcessFile
	
	void pResearch(){
		Project temp;
		
		for(int i=0; i<teamCounter; i++){
			for(int j=i+1; j<teamCounter; j++){
				if(projectArray[i].section1 < projectArray[j].section1){
					temp = projectArray[i];
					projectArray[i] = projectArray[j];
					projectArray[j] = temp;
				}//if
			}//for
		}//for
		
		
		if(flag == true){
			cout<<"Rankings by Research:"<<endl;
			displayProject();
		}//if
			
	}//pResearch
	
	
	void pInnovative(){
		Project temp;
		
		for(int i=0; i<teamCounter; i++){
			for(int j=i+1; j<teamCounter; j++){
				if(projectArray[i].section2 < projectArray[j].section2){
					temp = projectArray[i];
					projectArray[i] = projectArray[j];
					projectArray[j] = temp;
				}//if
			}//for
		}//for
		
	
		if(flag == true){
			cout<<"Rankings by Innovation Solution:"<<endl;
			displayProject();
		}//if
			
	}//pInnovation
	
	
	void pPresentation(){
		Project temp;
		
		for(int i=0; i<teamCounter; i++){
			for(int j=i+1; j<teamCounter; j++){
				if(projectArray[i].section3 < projectArray[j].section3){
					temp = projectArray[i];
					projectArray[i] = projectArray[j];
					projectArray[j] = temp;
				}//if
			}//for
		}//for
		
		
		if(flag == true){
			cout<<"Rankings by Presentation:"<<endl;	
			displayProject();
		}//if
			
	}//pPresentation
	
	
	void pProject(){
		Project temp;
		
		for(int i=0; i<teamCounter; i++){
			for(int j=i+1; j<teamCounter; j++){
				if(projectArray[i].total < projectArray[j].total){
					temp = projectArray[i];
					projectArray[i] = projectArray[j];
					projectArray[j] = temp;
				}//if
			}//for
		}//for
		
		
		if(flag == true){
			cout<<"Overall Project Rankings"<<endl;
			displayProject();
		}//if	
			
	}//pProject
	
	void cvInspiration(){
		coreValues temp;
		
		for(int i=0; i<teamCounter; i++){
			for(int j=i+1; j<teamCounter; j++){
				if(coreArray[i].section1 < coreArray[j].section1){
					temp = coreArray[i];
					coreArray[i] = coreArray[j];
					coreArray[j] = temp;
				}//if
			}//for
		}//for
		
		
		if(flag == true){
			cout<<"Rankings by Inspiration:"<<endl;
			displayCore();
		}//if	

	}//cvInspiration
	
	
	void cvTeamwork(){
		coreValues temp;
		
		for(int i=0; i<teamCounter; i++){
			for(int j=i+1; j<teamCounter; j++){
				if(coreArray[i].section2 < coreArray[j].section2){
					temp = coreArray[i];
					coreArray[i] = coreArray[j];
					coreArray[j] = temp;
				}//if
			}//for
		}//for
		

		if(flag == true){
			cout<<"Rankings by Teamwork:"<<endl;
			displayCore();	
		}//if		
		
	}//cvTeamwork
	
	
	void cvGraciousP(){
		coreValues temp;
		for(int i=0; i<teamCounter; i++){
			for(int j=i+1; j<teamCounter; j++){
				if(coreArray[i].section3 < coreArray[j].section3){
					temp = coreArray[i];
					coreArray[i] = coreArray[j];
					coreArray[j] = temp;
				}//if
			}//for
		}//for

		
		if(flag == true){
			cout<<"Rankings by Gracious Professionalism:"<<endl;
			displayCore();
		}//if
			
	}//cvGracious
	
	
	void cvCore(){
		coreValues temp;
		for(int i=0; i<teamCounter; i++){
			for(int j=i+1; j<teamCounter; j++){
				if(coreArray[i].total < coreArray[j].total){
					temp = coreArray[i];
					coreArray[i] = coreArray[j];
					coreArray[j] = temp;
				}//if
			}//for
		}//for
	
		
		if(flag == true){
			cout<<"Overall Core Values Rankings"<<endl;
			displayCore();	
		}//if
		
	}//cvCore
	
	void rdMechanical(){
		robotDesign temp;
		
		for(int i=0; i<teamCounter; i++){
			for(int j=i+1; j<teamCounter; j++){
				if(robotArray[i].section1 < robotArray[j].section1){
					temp = robotArray[i];
					robotArray[i] = robotArray[j];
					robotArray[j] = temp;
				}//if
			}//for
		}//for
		
		
		if(flag == true){
			cout<<"Rankings by Mechanical Design:"<<endl;
			displayRobot();
		}//if	
			
	}//rdMechanical
	
	
	void rdProgramming(){
		robotDesign temp;
		
		for(int i=0; i<teamCounter; i++){
			for(int j=i+1; j<teamCounter; j++){
				if(robotArray[i].section2 < robotArray[j].section2){
					temp = robotArray[i];
					robotArray[i] = robotArray[j];
					robotArray[j] = temp;
				}//if
			}//for
		}//for

		
		if(flag == true){
			cout<<"Rankings by Programming:"<<endl;
			displayRobot();
		}//if
			
	}//rdProgramming
	
	
	void rdStrategy(){
		robotDesign temp;
		
		for(int i=0; i<teamCounter; i++){
			for(int j=i+1; j<teamCounter; j++){
				if(robotArray[i].section3 < robotArray[j].section3){
					temp = robotArray[i];
					robotArray[i] = robotArray[j];
					robotArray[j] = temp;
				}//if
			}//for
		}//for
		
		
		if(flag == true){
			cout<<"Rankings by Strategy & Innovation:"<<endl;
			displayRobot();
		}//if
			
	}//rdStrategy
	
	
	void rdRobot(){
		robotDesign temp;
		
		for(int i=0; i<teamCounter; i++){
			for(int j=i+1; j<teamCounter; j++){
				if(robotArray[i].total < robotArray[j].total){
					temp = robotArray[i];
					robotArray[i] = robotArray[j];
					robotArray[j] = temp;
				}//if
			}//for
		}//for
		
		
		if(flag == true){
			cout<<"Overall Robot Design Rankings: "<<endl;
			displayRobot();
		}//if	
			
	}//rdRobot
	
	
	void displayProject(){
		cout<<endl;
		cout.width(8); cout<<left<<"Team#";
		cout.width(6); cout<<left<<"PI";
		cout.width(6); cout<<left<<"SOI";
		cout.width(6); cout<<left<<"PA";
		cout.width(6); cout<<left<<"RES";
		cout.width(6); cout<<left<<"TS";
		cout.width(6); cout<<left<<"I";
		cout.width(6); cout<<left<<"I";
		cout.width(6); cout<<left<<"S";
		cout.width(6); cout<<left<<"C";
		cout.width(10); cout<<left<<"PE";
		cout.width(17); cout<<left<<"ResTotal";
		cout.width(17); cout<<left<<"InnoSolTotal";
		cout.width(17); cout<<left<<"PresTotal";
		cout.width(17); cout<<left<<"PGrandTotal"<<endl;

		for(int i=0; i<teamCounter; i++){			
			cout.width(8); cout<<left<<projectArray[i].teamName;
			cout.width(6); cout<<left<<projectArray[i].ProblemIdentification;
			cout.width(6); cout<<left<<projectArray[i].SourcesofInformation;
			cout.width(6); cout<<left<<projectArray[i].ProblemAnalysis;
			cout.width(6); cout<<left<<projectArray[i].ReviewExistingSolutions;
			cout.width(6); cout<<left<<projectArray[i].TeamSolution;
			cout.width(6); cout<<left<<projectArray[i].Innovation;
			cout.width(6); cout<<left<<projectArray[i].Implementation;
			cout.width(6); cout<<left<<projectArray[i].Sharing;
			cout.width(6); cout<<left<<projectArray[i].Creativity;
			cout.width(10); cout<<left<<projectArray[i].PresentationEffectiveness;
			cout.width(17); cout<<left<<projectArray[i].section1;
			cout.width(17); cout<<left<<projectArray[i].section2;
			cout.width(17); cout<<left<<projectArray[i].section3;
			cout.width(17); cout<<left<<projectArray[i].total<<endl;
		}//for
		
		cout<<endl<<endl;
	}//displayInfo
	
	
	void displayCore(){
		cout.width(8); cout<<left<<"Team#";
		cout.width(6); cout<<left<<"D";
		cout.width(6); cout<<left<<"TS";
		cout.width(6); cout<<left<<"I";
		cout.width(6); cout<<left<<"E";
		cout.width(6); cout<<left<<"E";
		cout.width(6); cout<<left<<"KDTW";
		cout.width(6); cout<<left<<"I";
		cout.width(6); cout<<left<<"R";
		cout.width(10); cout<<left<<"C";
		cout.width(17); cout<<left<<"InsTotal";
		cout.width(17); cout<<left<<"TeamWTotal";
		cout.width(17); cout<<left<<"GProfTotal";
		cout.width(17); cout<<left<<"CVGrandTotal"<<endl;
		
		for(int i=0; i<teamCounter; i++){
			cout.width(8); cout<<left<<coreArray[i].teamName;
			cout.width(6); cout<<left<<coreArray[i].Discovery;
			cout.width(6); cout<<left<<coreArray[i].TeamSpirit;
			cout.width(6); cout<<left<<coreArray[i].Integration;
			cout.width(6); cout<<left<<coreArray[i].Effectiveness;
			cout.width(6); cout<<left<<coreArray[i].Efficiency;
			cout.width(6); cout<<left<<coreArray[i].KidsDoTheWork;
			cout.width(6); cout<<left<<coreArray[i].Inclusion;
			cout.width(6); cout<<left<<coreArray[i].Respect;
			cout.width(10); cout<<left<<coreArray[i].Coopertition;
			cout.width(17); cout<<left<<coreArray[i].section1;
			cout.width(17); cout<<left<<coreArray[i].section2;
			cout.width(17); cout<<left<<coreArray[i].section3;
			cout.width(17); cout<<left<<coreArray[i].total<<endl;
		}//for
		
		cout<<endl<<endl;
	}//displayCore
	
	
	void displayRobot(){
		cout.width(8); cout<<left<<"Team#";
		cout.width(6); cout<<left<<"D";
		cout.width(6); cout<<left<<"ME";
		cout.width(6); cout<<left<<"M";
		cout.width(6); cout<<left<<"PQ";
		cout.width(6); cout<<left<<"PE";
		cout.width(6); cout<<left<<"A/N";
		cout.width(6); cout<<left<<"DP";
		cout.width(6); cout<<left<<"MS";
		cout.width(10); cout<<left<<"I";
		cout.width(17); cout<<left<<"MDTotal";
		cout.width(17); cout<<left<<"ProgTotal";
		cout.width(17); cout<<left<<"S&ITotal";
		cout.width(17); cout<<left<<"RDGrandTotal"<<endl;
		
		for(int i=0; i<teamCounter; i++){
			cout.width(8); cout<<left<<robotArray[i].teamName;
			cout.width(6); cout<<left<<robotArray[i].Durability;
			cout.width(6); cout<<left<<robotArray[i].MechanicalEfficiency;
			cout.width(6); cout<<left<<robotArray[i].Mechanization;
			cout.width(6); cout<<left<<robotArray[i].ProgrammingQuality;
			cout.width(6); cout<<left<<robotArray[i].ProgrammingEfficiency;
			cout.width(6); cout<<left<<robotArray[i].AutomationNavigation;
			cout.width(6); cout<<left<<robotArray[i].DesignProcess;
			cout.width(6); cout<<left<<robotArray[i].MissionStrategy;
			cout.width(10); cout<<left<<robotArray[i].Innovation;
			cout.width(17); cout<<left<<robotArray[i].section1;
			cout.width(17); cout<<left<<robotArray[i].section2;
			cout.width(17); cout<<left<<robotArray[i].section3;
			cout.width(17); cout<<left<<robotArray[i].total<<endl;
		}//for
		
		cout<<endl<<endl;
		
	}
	
	void startPrint(){
		pResearchPrint();
		pInnovativePrint();
		pPresentationPrint();
		pProjectPrint();
		pProjectPrint();
		cvInspirationPrint();
		cvTeamworkPrint();
		cvGraciousPPrint();
		cvCorePrint();
		rdMechanicalPrint();
		rdProgrammingPrint();
		rdStrategyPrint();
		rdRobotPrint();	
	}//startPrint
	
	void pResearchPrint(){
		
		std::ofstream output("printouts/project/researchsort.csv", ios::app);
	
		pResearch();

		output<<"Team Number, Problem Identification, Sources of Information,"
		"Problem Analysis, Review Existing Solutions, Team Solutions, Innovation,"
		"Implementation, Sharing, Creativity, Presentation Effectiveness, Research Total,"
		"Innovative Solutions Total, Presentation Total, Project Grand Total"<<endl;

		for(int i=0; i<teamCounter; i++){
			output<<projectArray[i].teamName<<",";
			output<<projectArray[i].ProblemIdentification<<",";
			output<<projectArray[i].SourcesofInformation<<",";
			output<<projectArray[i].ProblemAnalysis<<",";
			output<<projectArray[i].ReviewExistingSolutions<<",";
			output<<projectArray[i].TeamSolution<<",";
			output<<projectArray[i].Innovation<<",";
			output<<projectArray[i].Implementation<<",";
			output<<projectArray[i].Sharing<<",";
			output<<projectArray[i].Creativity<<",";
			output<<projectArray[i].PresentationEffectiveness<<",";
			output<<projectArray[i].section1<<",";
			output<<projectArray[i].section2<<",";
			output<<projectArray[i].section3<<",";
			output<<projectArray[i].total<<endl; 
		}//for
	}//pResearchPrint
	
		
	void pInnovativePrint(){
		
		std::ofstream output("printouts/project/innovativesort.csv", ios::app);
		
		pInnovative();

		output<<"Team Number, Problem Identification, Sources of Information,"
		"Problem Analysis, Review Existing Solutions, Team Solutions, Innovation,"
		"Implementation, Sharing, Creativity, Presentation Effectiveness, Research Total,"
		"Innovative Solutions Total, Presentation Total, Project Grand Total"<<endl;

		for(int i=0; i<teamCounter; i++){
			output<<projectArray[i].teamName<<",";
			output<<projectArray[i].ProblemIdentification<<",";
			output<<projectArray[i].SourcesofInformation<<",";
			output<<projectArray[i].ProblemAnalysis<<",";
			output<<projectArray[i].ReviewExistingSolutions<<",";
			output<<projectArray[i].TeamSolution<<",";
			output<<projectArray[i].Innovation<<",";
			output<<projectArray[i].Implementation<<",";
			output<<projectArray[i].Sharing<<",";
			output<<projectArray[i].Creativity<<",";
			output<<projectArray[i].PresentationEffectiveness<<",";
			output<<projectArray[i].section1<<",";
			output<<projectArray[i].section2<<",";
			output<<projectArray[i].section3<<",";
			output<<projectArray[i].total<<endl; 
		}//for
	}//pInnovationPrint
	
	
	void pPresentationPrint(){
		
		std::ofstream output("printouts/project/presentationsort.csv", ios::app);
		
		pPresentation();

		output<<"Team Number, Problem Identification, Sources of Information,"
		"Problem Analysis, Review Existing Solutions, Team Solutions, Innovation,"
		"Implementation, Sharing, Creativity, Presentation Effectiveness, Research Total,"
		"Innovative Solutions Total, Presentation Total, Project Grand Total"<<endl;

		for(int i=0; i<teamCounter; i++){
			output<<projectArray[i].teamName<<",";
			output<<projectArray[i].ProblemIdentification<<",";
			output<<projectArray[i].SourcesofInformation<<",";
			output<<projectArray[i].ProblemAnalysis<<",";
			output<<projectArray[i].ReviewExistingSolutions<<",";
			output<<projectArray[i].TeamSolution<<",";
			output<<projectArray[i].Innovation<<",";
			output<<projectArray[i].Implementation<<",";
			output<<projectArray[i].Sharing<<",";
			output<<projectArray[i].Creativity<<",";
			output<<projectArray[i].PresentationEffectiveness<<",";
			output<<projectArray[i].section1<<",";
			output<<projectArray[i].section2<<",";
			output<<projectArray[i].section3<<",";
			output<<projectArray[i].total<<endl; 
		}//for
	}//pPresentationPrint
	
	
	void pProjectPrint(){
		
		std::ofstream output("printouts/project/ProjectGrandTotalsort.csv", ios::app);
		
		pProject();

		output<<"Team Number, Problem Identification, Sources of Information,"
		"Problem Analysis, Review Existing Solutions, Team Solutions, Innovation,"
		"Implementation, Sharing, Creativity, Presentation Effectiveness, Research Total,"
		"Innovative Solutions Total, Presentation Total, Project Grand Total"<<endl;

		for(int i=0; i<teamCounter; i++){
			output<<projectArray[i].teamName<<",";
			output<<projectArray[i].ProblemIdentification<<",";
			output<<projectArray[i].SourcesofInformation<<",";
			output<<projectArray[i].ProblemAnalysis<<",";
			output<<projectArray[i].ReviewExistingSolutions<<",";
			output<<projectArray[i].TeamSolution<<",";
			output<<projectArray[i].Innovation<<",";
			output<<projectArray[i].Implementation<<",";
			output<<projectArray[i].Sharing<<",";
			output<<projectArray[i].Creativity<<",";
			output<<projectArray[i].PresentationEffectiveness<<",";
			output<<projectArray[i].section1<<",";
			output<<projectArray[i].section2<<",";
			output<<projectArray[i].section3<<",";
			output<<projectArray[i].total<<endl; 
		}//for
	}//pProjectPrint
	
	
	void cvInspirationPrint(){
		
		std::ofstream output("printouts/corevalues/inspirationsort.csv", ios::app);
		
		cvInspiration();

		output<<"Team Number, Discovery, Team Spirit,"
		"Integration, Efficiency, Effectivness,"
		"Kids Do The Work, Inclusion, Respect, Coopertition, Inspiration Total,"
		"Teamwork Total, Gracious Professionalism Total, Core Values Grand Total"<<endl;

		for(int i=0; i<teamCounter; i++){
			output<<coreArray[i].teamName<<",";
			output<<coreArray[i].Discovery<<",";
			output<<coreArray[i].TeamSpirit<<",";
			output<<coreArray[i].Integration<<",";
			output<<coreArray[i].Effectiveness<<",";
			output<<coreArray[i].Efficiency<<",";
			output<<coreArray[i].KidsDoTheWork<<",";
			output<<coreArray[i].Inclusion<<",";
			output<<coreArray[i].Respect<<",";
			output<<coreArray[i].Coopertition<<",";
			output<<coreArray[i].section1<<",";
			output<<coreArray[i].section2<<",";
			output<<coreArray[i].section3<<",";
			output<<coreArray[i].total<<endl; 
		}//for
	}//cvInnovationPrint
	
	
	void cvTeamworkPrint(){
		
		std::ofstream output("printouts/corevalues/teamworksort.csv", ios::app);
		
		cvTeamwork();

		output<<"Team Number, Discovery, Team Spirit,"
		"Integration, Efficiency, Effectivness,"
		"Kids Do The Work, Inclusion, Respect, Coopertition, Inspiration Total,"
		"Teamwork Total, Gracious Professionalism Total, Core Values Grand Total"<<endl;

		for(int i=0; i<teamCounter; i++){
			output<<coreArray[i].teamName<<",";
			output<<coreArray[i].Discovery<<",";
			output<<coreArray[i].TeamSpirit<<",";
			output<<coreArray[i].Integration<<",";
			output<<coreArray[i].Effectiveness<<",";
			output<<coreArray[i].Efficiency<<",";
			output<<coreArray[i].KidsDoTheWork<<",";
			output<<coreArray[i].Inclusion<<",";
			output<<coreArray[i].Respect<<",";
			output<<coreArray[i].Coopertition<<",";
			output<<coreArray[i].section1<<",";
			output<<coreArray[i].section2<<",";
			output<<coreArray[i].section3<<",";
			output<<coreArray[i].total<<endl; 
		}//for
	}//cvTeamworkPrint
	
	
	void cvGraciousPPrint(){
		
		std::ofstream output("printouts/corevalues/graciouspsort.csv", ios::app);
		
		cvGraciousP();

		output<<"Team Number, Discovery, Team Spirit,"
		"Integration, Efficiency, Effectivness,"
		"Kids Do The Work, Inclusion, Respect, Coopertition, Inspiration Total,"
		"Teamwork Total, Gracious Professionalism Total, Core Values Grand Total"<<endl;

		for(int i=0; i<teamCounter; i++){
			output<<coreArray[i].teamName<<",";
			output<<coreArray[i].Discovery<<",";
			output<<coreArray[i].TeamSpirit<<",";
			output<<coreArray[i].Integration<<",";
			output<<coreArray[i].Effectiveness<<",";
			output<<coreArray[i].Efficiency<<",";
			output<<coreArray[i].KidsDoTheWork<<",";
			output<<coreArray[i].Inclusion<<",";
			output<<coreArray[i].Respect<<",";
			output<<coreArray[i].Coopertition<<",";
			output<<coreArray[i].section1<<",";
			output<<coreArray[i].section2<<",";
			output<<coreArray[i].section3<<",";
			output<<coreArray[i].total<<endl; 
		}//for
	}//cvGracousPPrint
	
	
	void cvCorePrint(){
		
		std::ofstream output("printouts/corevalues/corevaluesgrandtotalsort.csv", ios::app);
		
		cvCore();

		output<<"Team Number, Discovery, Team Spirit,"
		"Integration, Efficiency, Effectivness,"
		"Kids Do The Work, Inclusion, Respect, Coopertition, Inspiration Total,"
		"Teamwork Total, Gracious Professionalism Total, Core Values Grand Total"<<endl;

		for(int i=0; i<teamCounter; i++){
			output<<coreArray[i].teamName<<",";
			output<<coreArray[i].Discovery<<",";
			output<<coreArray[i].TeamSpirit<<",";
			output<<coreArray[i].Integration<<",";
			output<<coreArray[i].Effectiveness<<",";
			output<<coreArray[i].Efficiency<<",";
			output<<coreArray[i].KidsDoTheWork<<",";
			output<<coreArray[i].Inclusion<<",";
			output<<coreArray[i].Respect<<",";
			output<<coreArray[i].Coopertition<<",";
			output<<coreArray[i].section1<<",";
			output<<coreArray[i].section2<<",";
			output<<coreArray[i].section3<<",";
			output<<coreArray[i].total<<endl; 
		}//for
	}//cvCorePrint
	
	
	void rdMechanicalPrint(){
		
		std::ofstream output("printouts/robotdesign/mechanicalsort.csv", ios::app);
		
		rdMechanical();

		output<<"Team Number, Durability, Mechanical Efficiency,"
		"Mechanization, Programming Quality,Programming Efficiency,"
		"Automation/Navigation, Design Process, Mission Strategy, Innovation,"
		"Mechanical Design Total, Programming Total, Strategy & Innovation Total,"
		"Core Values Grand Total"<<endl;

		for(int i=0; i<teamCounter; i++){
			output<<robotArray[i].teamName<<",";
			output<<robotArray[i].Durability<<",";
			output<<robotArray[i].MechanicalEfficiency<<",";
			output<<robotArray[i].Mechanization<<",";
			output<<robotArray[i].ProgrammingQuality<<",";
			output<<robotArray[i].ProgrammingEfficiency<<",";
			output<<robotArray[i].AutomationNavigation<<",";
			output<<robotArray[i].DesignProcess<<",";
			output<<robotArray[i].MissionStrategy<<",";
			output<<robotArray[i].Innovation<<",";
			output<<robotArray[i].section1<<",";
			output<<robotArray[i].section2<<",";
			output<<robotArray[i].section3<<",";
			output<<robotArray[i].total<<endl; 
		}//for
	}//rdMechanicalPrint
	
	
	void rdProgrammingPrint(){
		
		std::ofstream output("printouts/robotdesign/programmingsort.csv", ios::app);
		
		rdProgramming();

		output<<"Team Number, Durability, Mechanical Efficiency,"
		"Mechanization, Programming Quality,Programming Efficiency,"
		"Automation/Navigation, Design Process, Mission Strategy, Innovation,"
		"Mechanical Design Total, Programming Total, Strategy & Innovation Total,"
		"Core Values Grand Total"<<endl;

		for(int i=0; i<teamCounter; i++){
			output<<robotArray[i].teamName<<",";
			output<<robotArray[i].Durability<<",";
			output<<robotArray[i].MechanicalEfficiency<<",";
			output<<robotArray[i].Mechanization<<",";
			output<<robotArray[i].ProgrammingQuality<<",";
			output<<robotArray[i].ProgrammingEfficiency<<",";
			output<<robotArray[i].AutomationNavigation<<",";
			output<<robotArray[i].DesignProcess<<",";
			output<<robotArray[i].MissionStrategy<<",";
			output<<robotArray[i].Innovation<<",";
			output<<robotArray[i].section1<<",";
			output<<robotArray[i].section2<<",";
			output<<robotArray[i].section3<<",";
			output<<robotArray[i].total<<endl; 
		}//for
	}//rdProgrammingPrint
	
	
	void rdStrategyPrint(){
		
		std::ofstream output("printouts/robotdesign/strategysort.csv", ios::app);
		
		rdStrategy();

		output<<"Team Number, Durability, Mechanical Efficiency,"
		"Mechanization, Programming Quality,Programming Efficiency,"
		"Automation/Navigation, Design Process, Mission Strategy, Innovation,"
		"Mechanical Design Total, Programming Total, Strategy & Innovation Total,"
		"Core Values Grand Total"<<endl;

		for(int i=0; i<teamCounter; i++){
			output<<robotArray[i].teamName<<",";
			output<<robotArray[i].Durability<<",";
			output<<robotArray[i].MechanicalEfficiency<<",";
			output<<robotArray[i].Mechanization<<",";
			output<<robotArray[i].ProgrammingQuality<<",";
			output<<robotArray[i].ProgrammingEfficiency<<",";
			output<<robotArray[i].AutomationNavigation<<",";
			output<<robotArray[i].DesignProcess<<",";
			output<<robotArray[i].MissionStrategy<<",";
			output<<robotArray[i].Innovation<<",";
			output<<robotArray[i].section1<<",";
			output<<robotArray[i].section2<<",";
			output<<robotArray[i].section3<<",";
			output<<robotArray[i].total<<endl; 
		}//for
	}//rdStrategyPrint
	
	
	void rdRobotPrint(){
		
		std::ofstream output("printouts/robotdesign/robotdesigngrandtotalsort.csv", ios::app);
		
		rdRobot();

		output<<"Team Number, Durability, Mechanical Efficiency,"
		"Mechanization, Programming Quality,Programming Efficiency,"
		"Automation/Navigation, Design Process, Mission Strategy, Innovation,"
		"Mechanical Design Total, Programming Total, Strategy & Innovation Total,"
		"Core Values Grand Total"<<endl;

		for(int i=0; i<teamCounter; i++){
			output<<robotArray[i].teamName<<",";
			output<<robotArray[i].Durability<<",";
			output<<robotArray[i].MechanicalEfficiency<<",";
			output<<robotArray[i].Mechanization<<",";
			output<<robotArray[i].ProgrammingQuality<<",";
			output<<robotArray[i].ProgrammingEfficiency<<",";
			output<<robotArray[i].AutomationNavigation<<",";
			output<<robotArray[i].DesignProcess<<",";
			output<<robotArray[i].MissionStrategy<<",";
			output<<robotArray[i].Innovation<<",";
			output<<robotArray[i].section1<<",";
			output<<robotArray[i].section2<<",";
			output<<robotArray[i].section3<<",";
			output<<robotArray[i].total<<endl; 
		}//for
	}//rdRobotPrint
};


