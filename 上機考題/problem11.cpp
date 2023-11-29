#include<iostream>
#include<string>
#include<cmath>
using namespace std;

bool is_num(int n){
    string str_n = to_string(n);
    int sum=0,i=0,l=str_n.length();
    do{
        sum += pow(str_n[i]-'0',l);
    }while (str_n[++i]);
    return (sum==n)? true : false;
}

int main(){
    for(int i=101;i<100000;i++){
        if(is_num(i))
            cout<<i<<" ";
    }
    return 0;
}