#include<iostream>
using namespace std;

int main(){
	int i,min,half_hour,fee=0;
	cin>>min;
	if(min>30){
		half_hour=min/30;
		half_hour+=(min%30==0)?0:1;
		if(half_hour>=48){
			fee+=240;
			half_hour-=48;
		}
		fee+=half_hour*20;
	}
	cout<<min<<"min is "<<fee<<" NT dollars";
}
