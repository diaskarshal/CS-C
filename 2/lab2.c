//Dias Karshal CSCI151 LAB2
#include <stdio.h>
int main(){
    printf("==========================================\n");
    printf("==                 TASK 1:              ==\n");
    printf("==========================================\n");

    int n, iter;
    printf("Enter starting number n: ");
    scanf("%d", &n);
    printf("Enter number of iterations: ");
    scanf("%d", &iter);
    
    printf("%d", n);
    for(int i = 1; i<=iter; i++){
        int copy = n;
        while(copy>0){
            n+=copy%10;
            copy/=10;
        }
        printf(" -> %d", n);
    }

    printf("\n==========================================\n");
    printf("==                 TASK 2:              ==\n");
    printf("==========================================\n");
    
    double x, ans, sqrtPI = 1.77245385091;
    printf("Enter x: ");
    scanf("%lf", &x);

    for(int k = 0; k<50; k++){
        
        double kfact = 1;
        for(int i = 1; i<=k; i++){
            kfact*=i;
        }
        
        double minus1pk = 1.0; 
        for(int i = 0; i<k;i++){
            minus1pk*=-1.0;
        }
        
        double xp2k = 1.0;
        for(int i = 0; i<(2*k+1); i++){
            xp2k*=x;
        }
        ans+=(minus1pk*xp2k/(kfact*(2*k + 1)));
        
    }
    ans*=(double)(2/sqrtPI);
    printf("erf(%0.1lf) = %lf\n", x, ans);

    printf("==========================================\n");
    printf("==                 TASK 3:              ==\n");
    printf("==========================================\n");

    int rows;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    for(int i = 1; i<=rows; i++){
        for(int j = 1; j<=rows-i; j++){
            printf(" ");
        }
        for(int j = 1; j<=i; j++){
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}