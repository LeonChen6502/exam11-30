#include<iostream>
using namespace std;

double e_pow_x(double ans,double adder, int x,int i, int n){
    return (i++ == n) ? ans : e_pow_x(ans+adder,adder*x/i,x,i,n);
}
int main(){
    for(int x=1;x<=10;x++)
        cout<<e_pow_x(0,1,x,0,20)<<endl;        //n=20
    return 0;
}