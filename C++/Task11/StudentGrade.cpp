#include<iostream>
using namespace std;
class student{
	private:
		int subs=6;
		int marks[10];
		int total;
	public:
		student(){
			total=0;
			cout<<"Enter the marks of the student: "<<endl;
			for(int i=0;i<subs;i++){
				cin>>marks[i];
				total+=marks[i];
			}
		}
		string grade(){
			double avg=(double)total/(double)subs;
			if(avg>=90){
				return "Grade A";
			}
			else if(avg>=80){
				return "Grade B";
			}
			else if(avg>=70){
				return "Grade C";
			}
			else if(avg>=60){
				return "Grade D";
			}
			else{
				return "Grade F";
			}
		}
};
main(){
	student std;
	cout<<"Result of the student: "<<std.grade()<<endl;
	return 0;
}
