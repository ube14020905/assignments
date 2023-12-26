#include <iostream>
#include <string>
using namespace std;
const int Max_students = 100;
struct student
{
	int sid;
	string name;
	int age;
	float grade;
};
void addStudent(student data[], int &count)
{
	if (count < Max_students)
	{
		cout << "Enter student Id, Name, Age, Grade :" << endl;
		cin >> data[count].sid >> data[count].name >> data[count].age >> data[count].grade;
		count++;
	}
	else
	{
		cout << "Reached maximum student count!" << endl;
	}
}
void searchById(const student data[], int id, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (data[i].sid == id)
		{
			cout << "Student Found!" << endl;
			cout << "Student Id" << data[i].sid << endl
				 << "Student Name: " << data[i].name << endl
				 << "Student Age: " << data[i].age << endl
				 << "Student Grade: " << data[i].grade << endl;
			return;
		}
	}
	cout << "No record found with that ID!" << endl;
}
void AverageGrade(const student data[], int count)
{
	if (count > 0)
	{
		float total = 0.0;
		for (int i = 0; i < count; i++)
		{
			total += data[i].grade;
		}
		cout << "The Average grade of All Student: " << (total / (float)count) << endl;
	}
	else
	{
		cout << "The is no student data exist to calculate Avg!" << endl;
	}
}
void DisplayAll(const student data[], int count)
{
	cout << "Displaying all the student data" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "Student Id: " << data[i].sid << endl
			 << "Student Name: " << data[i].name << endl
			 << "Student Age: " << data[i].age << endl
			 << "Student Grade: " << data[i].grade << endl;
	}
}
int main()
{
	int count = 0;
	int choice;
	student data[Max_students];
	while (true)
	{
		cout << "1.Add Student" << endl
			 << "2.Search by ID" << endl
			 << "3.Average grade of all students" << endl
			 << "4.Display all students" << endl
			 << "5.Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			addStudent(data, count);
			break;
		case 2:
		{
			cout << "Enter Student Id to Search: ";
			int sid;
			cin >> sid;
			searchById(data, sid, count);
		}
		break;
		case 3:
			AverageGrade(data, count);
			break;
		case 4:
			DisplayAll(data, count);
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
