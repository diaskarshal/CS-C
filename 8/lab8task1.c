//Dias Karshal CSCI151 LAB8
#include <stdio.h>

int gcd(int n1, int n2){

    if(n2==0)
        return n1;
    else if(n1==0)
        return n2;    
    else if(n2>n1)
        return gcd(n2%n1, n1);
    else if(n1>n2)
        return gcd(n1%n2, n2);

}

int fact(int n){

    if(n>=1)
        return n*fact(n-1);
    else
        return 1;

}

int fibo(int n){

    if(n == 0)
        return 0;

    else if(n == 1)
        return 1;

    else
        return(fibo(n-1)+fibo(n-2));

}

int digitssum(int n){
    int sum = 0;
    while(n!=0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int main(){

    FILE *in;
    in = fopen("numbers.txt", "r");

    if(in == NULL){
        printf("Problem opening files.\n");
        return 1;
    }
    
    int n1, n2, i = 1;

    while(fscanf(in, "%d %d", &n1, &n2)==2){
        
        printf("\nThe pair of numbers #%d: %d and %d.", i, n1, n2);
        int gcdd = gcd(n1,n2);
        printf("\nThe greatest common divisor for these two numbers is %d.", gcdd);
        printf("\n%d! = %d.", gcdd, fact(gcdd));
        int fibon = fibo(gcdd);
        printf("\nElement #%d in the Fibonacci sequence is %d.", gcdd, fibon);
        printf("\nThe sum of digits of the number %d is %d.\n", fibon, digitssum(fibon));
        
        i++;    
    }
    
    return 0;
}