#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
#define NC 20


void ImprimirMatriz(int m, int n, double A[][NC]){
    for(int i=0; i<m; i++){
        cout.precision(7);
        cout.fixed;
        for(int j=0; j<n; j++){
          cout<<setw(15)<<A[i][j]<<setw(15)<<"\t";
        }
      cout<<endl;
    }
}


void Gauss(int m, int n, double A[][NC]){
    for(int i=0;i<=m-2;i++)
        if (A[i][i]!=0)
            for(int r=i+1;r<=m-1;r++){
                double t=A[r][i];
                for(int j=i;j<=m;j++)
                    A[r][j]=A[r][j]-(t/A[i][i])*A[i][j];
            }
     ImprimirMatriz(m,n,A);
}


void GaussJordan(int m, int n, double A[][NC]){
    for(int i=0;i<=m-1;i++)
        if (A[i][i]!=0)
        for(int r=0; r<=m-1;r++){
            if(r!=i){
                double t=A[r][i];
                for(int j=i;j<=m;j++)
                A[r][j]-=t*A[i][j]/A[i][i];
            }
        }
    ImprimirMatriz(m,n,A);
}



int main(void){

    int m=3;
    double A[][NC]={{3,-2,1,-4},{1,1,2,2},{-1,-1,1,-5}};

    ImprimirMatriz(3,4,A);

    cout<<endl;

    Gauss(3,4,A);

    cout<<endl;

    GaussJordan(3,4,A);


    return 0;
}