#include<iostream>
using namespace std;

int f(int n,int l){
	if (n==1)
        return l;
    l++;
	return (n%2) ? f(3*n+1,l) : f(n/2,l);
}

int main(){
	int max_l=0,l,num,i;
	for(i=1;i<=10000;i++){
		l=f(i,1);
		if(max_l < l){
			max_l = l;
			num=i;
        }
	}
	cout<<num<<" "<<max_l<<endl;
}