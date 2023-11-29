#include<iostream>
using namespace std;

int d(int n){
    int sum=0;
    for(int i=1;i<n;i++){
        sum += (n%i) ? 0 : i;
    }
    return sum;
}

int main(){
    int sum=0;
    for(int i=2;i<=10000;i++){
        if( i==d(d(i)) and i<d(i))
            sum+=i;
    }
    cout<<sum;
}