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
	cout<<"Enter Your Choice:";
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
	cout<<"Enter number of games in the series:";
	cin>>rounds;
	for(int i=0;i<rounds;i++){
		string user=userChoice();
		string system=systemChoice();
		string res=result(user,system);
		cout<<res<<endl;
		if(res=="You Win!"){
			usr_res++;
		}
		else if(res=="It's tie"){
		       continue;
		}
		else{
	 		sys_res++;
		}
	}
	if(usr_res==sys_res){
		cout<<"Series Draw"<<endl;
	}
	else if(usr_res>sys_res){
		cout<<"User Wins the series"<<endl;
	}
	else{
		cout<<"Computer Wins the series"<<endl;
	}
	return 0;
}
