#include<iostream>
using namespace std;

void selectionSort(int arr[] ,  int n){
    int i,j,index=0;
    for(i=0;i<n-1;i++){
        int min=arr[i];
        //finding minimum number
        for(j=i+1;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                index=j;
            }
        }
        //swapping the number
        int temp=arr[i];
        arr[i]=min;
        arr[index]=temp;
    }
}
int main(){
    int k,size;
    cin>>size;
    int arr[size];
    for(k=0;k<size;k++){
        cin>>arr[k];
    }
    int p = selectionSort(arr,size);
    for(k=0;k<size;k++){
        cout<<arr[k];
    }
}