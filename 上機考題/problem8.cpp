#include<iostream>
using namespace std;
bool is_prime(int n){
    for(int i=2;i<n;i++){
        if(n%i == 0)
            return false;
    }
    return true;
}
int main(){
    for(int i=2;i<=998;i++){
        if(is_prime(i) and is_prime(i+2)){
            cout<<"("<<i<<","<<i+2<<")";
        }
    }
}