#include<iostream>
using namespace std;
class ArrayOps
{
    private:
        int size;
        int ar[100];  
    public:
        int sortedArr[100]; 
        ArrayOps(int a){
            size=a;
            cout<<"Add elements to array: "<<endl;
            for(int i=0;i<size;i++){
                cin>>ar[i];
            }
        }
        void originalArray(void){
            cout<<"Original Array: ";
            for(int i=0;i<size;i++){
                cout<<ar[i]<<"\t";
            }
            cout<<endl;
        }
        void sorted(void){
            for (int i = 0; i < size; i++) {
                sortedArr[i] = ar[i];
            }
            int i,j;
            for(i=0;i<size-1;i++){
                for(j=0;j<size-i-1;j++){
                    if(sortedArr[j]>sortedArr[j+1]){
                        int t=sortedArr[j];
                        sortedArr[j]=sortedArr[j+1];
                        sortedArr[j+1]=t;
                    }
                }
            }
        }
        void printSorted(){
            sorted();
            cout<<"Sorted Array: ";
            for(int i=0;i<size;i++){
                cout<<sortedArr[i]<<"\t";
            }
            cout<<endl;
        }
        void sum(void){
            int s=0;
            for(int i=0;i<size;i++){
                s+=ar[i];
            }
            cout<<"Sum: "<<s<<endl;
        }
        void search(){
            int a;
            cout<<"Enter a value to Search: "<<endl;
            cin>>a;
            for(int i=0;i<size;i++){
                if(ar[i]==a){
                    cout<<a<<" Found at "<<i+1<<endl;
                    return;
                }
            }
            cout<<a<<" not found in the array"<<endl;
        }
        void max(){
            sorted();
            cout<<sortedArr[size-1]<<" Is the max value in the array"<<endl;
        }

};
main(){
    ArrayOps a(5);
    a.originalArray();
    a.max();
    a.printSorted();
    a.sum();
    a.search();
    return 0;   
}
