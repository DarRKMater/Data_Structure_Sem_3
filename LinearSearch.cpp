#include <iostream>
using namespace std;

template <class T>
class Linear{
    int n;
    T arr[];
    public:
    Linear(){
        cout<<"Enter the length of Array :- ";
        cin>>n;
        arr[n];
        for(int j=1;j<=n;j++){
            cin>>arr[j];
        }
        linear(arr,n);
    }
    void linear(T arr[],int n);
};

template <class T>
void Linear<T>::linear(T arr[],int n){
    int s=0;
    T ch;
    cout<<"Enter the object to search in Array :- ";
    cin>>ch;
        for(int i=0;i<n;++i){
            if(arr[i]==ch){
                cout<<"element "<<ch<<" Found at position "<<i<<endl;
                s+=1;
            }
            else{
                s+=0;
            }
        }
        if(s==0){
            cout <<"-1;"<<" Element not Found"<<endl;
        }
}

int main(){
    Linear<int> e;
}
