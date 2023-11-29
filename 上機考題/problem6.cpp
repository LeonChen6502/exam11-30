#include<iostream>
#include <algorithm>
using namespace std;

int find_gcd(int n,int m){
    return (m == 0) ? n : find_gcd(m, n % m);
}

int main(){
    int n,m;
    cin>>n>>m;
    cout<<find_gcd(n,m)<<" "<<n*m/find_gcd(n,m);
}