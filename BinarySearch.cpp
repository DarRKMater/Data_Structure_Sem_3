#include <iostream>
using namespace std;

template <class T>
class BinarySearch{
    int n;
    T arr[];
    public:
    BinarySearch(){
        cout<<"Enter the length of Array :- ";
        cin>>n;
        arr[n];
        for(int j=1;j<=n;j++){
            cin>>arr[j];
        }
        int result = binary(arr, n);
        if (result == -1)
            cout<<"Not found";
        else
            cout<<"Element is found at position "<<result<<endl;
    }
    int binary(T arr[],int n);
};

template <class T>
int BinarySearch<T>::binary(T arr[],int n){
    int beg=0;
    int f=0;
	int end=n-1;
    T a;
	cout<<"Enter the object to search in Array :- ";
    cin>>a;
	while(beg<=end){
		int mid=(beg+end)/2;
		if(a==arr[mid])
    		return mid;
		else if(a>arr[mid])	
			beg=mid+1;
		else	
			end=mid-1;
	}
	if(f==0)
    	return -1;
}

int main(){
    BinarySearch<int> a;
}
