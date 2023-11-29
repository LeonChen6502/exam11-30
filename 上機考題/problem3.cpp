#include<iostream>
#include<string>
using namespace std;

void str_reverse(string &str){
	string str2;
	int i=0;
	do{
		str2[i]=str[i];
	}while(str[++i]);
	i--;
	for(int j=i;j>=0;j--){
		str[j]=str2[i-j];
	}

}

int main(){
	string str;
	while(cin>>str){
		str_reverse(str);
		cout<<str<<endl;
	}
	return 0;
}