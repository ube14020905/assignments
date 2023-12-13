#include<iostream>
using namespace std;
class DynamicArray
{
    private:
        int *drr;
        int size;
    public:
        DynamicArray(){
            cout << "Enter the Size of array"<<endl;
            cin >> size;
            drr=new int[size];
            cout << "Enter Integers to array: "<<endl;
            for(int i=0;i<size;i++){
                cin >> drr[i];
            }
        }
        ~DynamicArray(){
            delete[] drr;
            cout << "The memory allocated for Array is now free"<<endl;
        }
        void display(){
            for (int i = 0; i < size; i++)
            {
                cout << *(drr+i)<<"  ";
            }
            cout << endl;
        }
        void sum(){
            int s=0;
            for (int i = 0; i < size; i++)
            {
                s+=*(drr+i);
            }
            cout <<"Sum of the Integers: " << s << endl;
        }
};
main(){
    DynamicArray dr;
    dr.display();
    dr.sum();
}
