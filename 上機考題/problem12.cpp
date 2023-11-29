#include<iostream>
#include<new>
using namespace std;

void input_matrix(int **matrix,int row,int colum){
    for(int i=0;i<row;i++){
        for(int j=0;j<colum;j++)
            cin>>matrix[i][j];
    }
    return;
}

void muti_matrix(int **matrix1,int **matrix2,int **matrix3,int M,int N,int L){
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            matrix3[i][j]=0;
            for(int k=0;k<L;k++)
                matrix3[i][j] += matrix1[i][k]*matrix2[k][j];
        }
    }
    return;
}

void print_matrix(int **matrix,int row,int colum){
    for(int i=0;i<row;i++){
        for(int j=0;j<colum;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return;
}

int main(){
    int M,N,L;
    cin>>M>>N>>L;
    int **matrix1= new int*[M];
    for(int i=0;i<M;i++)
        matrix1[i] = new int[L];

    int **matrix2= new int*[L];
    for(int i=0;i<L;i++)
        matrix2[i] = new int[N];
    
    int **matrix3= new int*[M];
    for(int i=0;i<M;i++)
        matrix3[i] = new int[N];

    input_matrix(matrix1,M,L);
    input_matrix(matrix2,L,N);
    muti_matrix(matrix1,matrix2,matrix3,M,N,L);
    print_matrix(matrix1,M,N);
    cout<<"x"<<endl;
    print_matrix(matrix2,M,N);
    cout<<"="<<endl;
    print_matrix(matrix3,M,N);
    return 0;
}