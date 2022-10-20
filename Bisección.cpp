#include<iostream>
#include<math.h>

using namespace std;

double f(double x){
    return 3*pow(x,3)+4*pow(x,2);
}

double biseccion(double a, double b, double T,int N){
    
    double FA;
    double FP;
    double p;
    int i=1;

    while(i<=N){
        p=(a+b)/2;
        FA=f(a);
        FP=f(p);
        if ((FP==0)||(((b-a)/2)<T)){
            break;
        }
        i=i++;
        if (FA*FP>0){
            a=p;
            FA=FP;
        } else {
            b=p;
        }
    }

    cout<<p;

    return p;
}

int main(void){

    double a=-2;
    double b=-1;
    double N=1000;
    double T=0.0001;

    biseccion(a,b,T,N);

    return 0;
}