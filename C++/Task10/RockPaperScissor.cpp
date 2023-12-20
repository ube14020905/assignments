#include<iostream>
#include<cstdlib>
#include<cctype>
#include<ctime>
using namespace std;
string systemChoice(){
	srand(static_cast<unsigned int>(time(nullptr)));
	int choice=rand()%3;
	switch(choice){
		case 0:{
			       return "rock";
		       }break;
		case 1:{
			       return "paper";
		       }break;
		case 2:{
			       return "scissor";
		       }break;
		default:{
				return "Error";
			}break;
	}
}
string userChoice(){
	string choice;
	cout<<"Enter Your Choice (rock,paper,scissor) in either case: ";
	cin>>choice;
	for(char& c:choice){
		c=tolower(c);
	}
	return choice;
}
string result(string usrChoice,string sysChoice){
	if(usrChoice==sysChoice){
		return "it's tie";
	}
	else if((usrChoice == "rock" && sysChoice == "scissor")||(usrChoice == "scissor" && sysChoice == "paper")||(usrChoice =="paper" && sysChoice == "rock")){
		return "You Win!";
	}
	else{
		return "Computer Wins!";
	}
}
main(){
	int rounds,usr_res=0,sys_res=0;
	cout<<"Welcome to the game Rock,Paper,Scissor!"<<endl;
	cout<<"Enter number of games in the series:";
	cin>>rounds;
	for(int i=0;i<rounds;i++){
		string user=userChoice();
		string system=systemChoice();
		cout<<"Computer choice:"<<system<<endl;
		string res=result(user,system);
		cout<<res<<endl;
		if(res=="You Win!"){
			usr_res++;
		}
		else if(res=="Computer Wins!"){
	 		sys_res++;
		}
		cout<<"Current Scores:\nUser: "<<usr_res<<endl<<"Computer: "<<sys_res<<endl;
	}
	if(usr_res==sys_res){
		cout<<"Series Draw"<<endl;
	}
	else if(usr_res>sys_res){
		cout<<"You Won the series with "<<(usr_res-sys_res)<<" Win(s) Lead"<<endl;
	}
	else{
		cout<<"Computer Won the series with "<<(sys_res-usr_res)<< " Win(s) Lead" <<endl;
	}
	return 0;
}
