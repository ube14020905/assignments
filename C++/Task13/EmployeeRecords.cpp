#include<iostream>
#include<string>
using namespace std;
const int Max_Emp=100;
struct Employee
{
	int empId;
	string name;
	double salary;
	string dept;
};
void addEmployee(Employee database[],int& count){
	if(count<Max_Emp){
		cout<<"Enter the Details of Employee(Id, name, salary, department): ";
		cin>>database[count].empId>>database[count].name>>database[count].salary>>database[count].dept;
		cout<<"One Employee is Add to the Database"<<endl;
		count++;
	}
	else{
		cout<<"The DataBase is Full!"<<endl;
	}
}
void searchById(Employee database[],int count){
	int id;
	cout<<"Enter the Id of employee: "<<endl;
	cin>>id;
	for(int i=0;i<count;i++){
		if(database[i].empId==id){
			cout<<"Employee found!!"<<endl;
			cout<<"Employee id: "<<database[i].empId<<endl
				<<"Employee name: "<<database[i].name<<endl
				<<"Employee Salary: "<<database[i].salary<<endl
				<<"Department: "<<database[i].dept<<endl;
			return;
		}
	}
	cout<<"No Record found with that ID!!!"<<endl;
}
void updateSalary(Employee database[],int count){
	int id;
	cout<<"Enter the Id of Employee to Update Salary: ";
	cin>>id;
	for(int i=0;i<count;i++){
		if(database[i].empId==id){
			cout<<"Enter the Salary to Update: ";
			cin>>database[i].salary;
			return;
		}
	}
	cout<<"No Employee found with that ID!!!"<<endl;
}
void displayAllEmployees(Employee database[],int count){
	cout<<"Employee Database!!"<<endl;
	for(int i=0;i<count;i++){
		cout<<"Employee id: "<<database[i].empId<<endl
			<<"Employee name: "<<database[i].name<<endl
			<<"Employee Salary: "<<database[i].salary<<endl
			<<"Department: "<<database[i].dept<<endl<<endl;
	}
}
int main(){
	
	int count = 0;
	int choice;
	Employee database[Max_Emp];
	while (true)
	{
		cout << "1.Add Employee" << endl
			 << "2.Search by ID" << endl
			 << "3.Update Salary" << endl
			 << "4.Display all Employees" << endl
			 << "5.Exit" << endl;
		cout<<"Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			addEmployee(database, count);
			break;
		case 2:
		{
			searchById(database, count);
		}
		break;
		case 3:
			updateSalary(database, count);
			break;
		case 4:
			displayAllEmployees(database, count);
			break;
		case 5:
			cout << "Exiting the Program!!!" << endl;
			return 0;
			break;
		default:
			cout << "Invalid Input" << endl;
			break;
		}
	}
	return 0;
}
