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
          cout<<setw(15)<<A[i][j]<<setw(15);
        }
      cout<<endl;
    }
}


void CapturarMatriz(int m, int n, double A[][NC]){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout<<"Digita el número de la posición  "<<i<<" , "<<j<<": ";
            cin>>A[i][j];
            cout<<endl;
        }
    }
}


void GaussJordan(int m,double V[], double A[][NC]){
    for(int i=0;i<=m-1;i++)
        if (A[i][i]!=0)
        for(int r=0; r<=m-1;r++){
            if(r!=i){
                double t=A[r][i];
                for(int j=i;j<=m;j++)
                A[r][j]-=t*A[i][j]/A[i][i];
            }
        }

    for(int i=0;i<=m-1;i++){
        A[i][m]=A[i][m]/A[i][i];
        A[i][i]=1;
    }

    for (int j=0;j<m;j++)
        V[j]=A[j][m];

    cout<<"La solución del Sietema de Ecuaciones Lineales es: ";
    cout<<endl;
    for(int k=0;k<m;k++)
        cout<<"X"<<k<<"= "<<V[k]<<" , ";
}



int main(void){

    int m;

    cout<<"Inserta el número de ecuaciones y de Incógnitas; ";
    cin>>m;

    double A[m][NC];
    double V[m];

    CapturarMatriz(m,m+1,A);

    cout<<"En forma de Matriz extendida el Sistema de Ecuciones queda de la Forma: ";

     cout<<endl,

    ImprimirMatriz(m,m+1,A);

    cout<<endl;

    GaussJordan(m,V,A);


    return 0;
}