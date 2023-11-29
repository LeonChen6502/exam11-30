#include<iostream>
#include <algorithm>
using namespace std;

void sort_arr(int arr[15]){
    sort(arr,arr+15);
}
int main(){
    int arr[15]={3, 8, 10, 30, 2, 16, 27, 13, 22, 17, 42, 33, 38, 29, 14};
    sort_arr(arr);
    for(int i=0;i<15;i++)
        cout<<arr[i]<<" ";
}