#include<iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

int main(){
    srand(time(NULL));
    int arr[12];
    for(int i=0;i<100000;i++)
        arr[rand()%6+1+rand()%6]++;
    for(int i=0;i<12;i++)
        cout<<arr[i]<<" ";
    return 0;
}
