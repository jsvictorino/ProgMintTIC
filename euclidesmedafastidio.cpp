#include<iostream>
#include<stdlib.h>
#define NC 20

using namespace std;

void hacermatriz(int m, int n,int A[][NC]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
                        cout<<"Ingresa la componente "<<i<<" , "<<j<<" : ";
                        cin>>A[i][j];
                        cout<<endl;
        }
    }
}

void imprimirmatriz(int m, int n,int A[][NC]){
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++)
                cout<<A[i][j]<<" \t ";
            cout<<endl;
        }
        cout<<endl;
}

void sumatrices(int m, int n, int A[][NC],int B[][NC],int C[][NC]){
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            C[i][j]=A[i][j]+B[i][j];
}


void productmatrix(int m, int n, int p,int A[][NC],int B[][NC],int C[][NC]){
    for (int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            C[i][j]=0;
            for (int k=0;k<p;k++)
                C[i][j]=C[i][j]+A[i][k]*B[k][j];
        }
}

void imprimirarreglo(int n, int F[]){
    for(int i=0;i<n;i++)
        cout<<F[i]<<" , ";
}

int main(void){

    int m=2;
    int p=3;
    int n=4;
    int A[m][NC]={{1,2,3},{6,7,0}};
    int B[p][NC]={{0,2,-1,1},{-3,5,2,0},{2,1,-2,3}};
    int C[m][NC];

    imprimirmatriz(m,p,A);
    imprimirmatriz(p,n,B);

    //Producto de A*B

    productmatrix(m,p,n,A,B,C);

    imprimirmatriz(m,n,C);

    //Linealización de la Matriz A

    int y=m*p;

    int H[y];
    int t=0;
    for (int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            H[t]=A[i][j];
            t++;
        }

    imprimirarreglo(y,H);

    return 0;
}




















