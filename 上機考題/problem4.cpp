#include<iostream>
using namespace std;

void find_lucky(int lucky){
    cout<<lucky;
    return;
}

int main(){
	int M,N,lucky= NULL;
	cin>>M>>N;
	int arr[M][N],arr2[M][N];
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin>>arr[i][j];
            arr2[i][j]=0;
		}
	}
	int Max,Min,R,C;
	for(int i=0;i<M;i++){
		Min = arr[i][0];
		for(int j=0;j<N;j++){
 			if(Min>arr[i][j]){
				Min = arr[i][j];
				R = j;
			}
			Max = arr[0][j];
			for(int k=0;k<M;k++){
				if(Max<arr[k][j]){
					Max = arr[k][j];
					C = k;
				}
			}
			arr2[C][j] += 1;
		}
		arr2[i][R] += 1;
	}
    Max=0;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
            cout<<arr2[i][j]<<" ";
			if(arr2[i][j]>Max){
				lucky = arr[i][j];
                Max = arr2[i][j];
			}
		}
        cout<<endl;
	}
    find_lucky(lucky);	
	return 0;
}