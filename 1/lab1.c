//Dias Karshal CSCI151 LAB1
#include <stdio.h>
int main(){

    printf("==========================================\n");
    printf("==                 TASK 1:              ==\n");
    printf("==========================================\n");

    int Fahrenheit_start, Fahrenheit_end;
    
    printf("Enter the starting temperature (F): ");
    scanf("%d", &Fahrenheit_start);
    printf("Enter the ending temperature (F): ");
    scanf("%d", &Fahrenheit_end);
    
    /*if(Fahrenheit_start>Fahrenheit_end){
        printf("Ensure that the starting temperature is less than or equal to the ending temperature.");
        return 0;
    }*/

    int difference = (float)(Fahrenheit_end - Fahrenheit_start)/9;
    double Celsius1 = (float)(Fahrenheit_start-32)*5/9;

    printf("Fahrenheit                Celsius\n");//16 spaces
    printf("---------------------------------\n");

    printf("%d\t\t\t  %0.1lf\n", Fahrenheit_start, Celsius1);
    Fahrenheit_start+=difference;
    float Celsius2 = (float)(Fahrenheit_start-32)*5/9;
    printf("%d\t\t\t  %.1f\n", Fahrenheit_start, Celsius2);
    Fahrenheit_start+=difference;
    double Celsius3 = (float)(Fahrenheit_start-32)*5/9;
    printf("%d\t\t\t  %.1lf\n", Fahrenheit_start, Celsius3);
    Fahrenheit_start+=difference;
    double Celsius4 = (float)(Fahrenheit_start-32)*5/9;
    printf("%d\t\t\t  %0.1lf\n", Fahrenheit_start, Celsius4);
    Fahrenheit_start+=difference;
    double Celsius5 = (float)(Fahrenheit_start-32)*5/9;
    printf("%d\t\t\t  %0.1lf\n", Fahrenheit_start, Celsius5);
    Fahrenheit_start+=difference;
    double Celsius6 = (float)(Fahrenheit_start-32)*5/9;
    printf("%d\t\t\t  %0.1lf\n", Fahrenheit_start, Celsius6);
    Fahrenheit_start+=difference;
    double Celsius7 = (float)(Fahrenheit_start-32)*5/9;
    printf("%d\t\t\t  %0.1lf\n", Fahrenheit_start, Celsius7);
    Fahrenheit_start+=difference;
    double Celsius8 = (float)(Fahrenheit_start-32)*5/9;
    printf("%d\t\t\t  %0.1lf\n", Fahrenheit_start, Celsius8);
    Fahrenheit_start+=difference;
    double Celsius9 = (float)(Fahrenheit_start-32)*5/9;
    printf("%d\t\t\t  %0.1lf\n", Fahrenheit_start, Celsius9);
    Fahrenheit_start+=difference;
    double Celsius10 = (float)(Fahrenheit_start-32)*5/9;
    printf("%d\t\t\t  %0.1lf\n", Fahrenheit_start, Celsius10);

    

    /*----------------------------------------------------------------*/

    printf("==========================================\n");
    printf("==                 TASK 2:              ==\n");
    printf("==========================================\n");
    
    int first_real, first_imag, second_real, second_imag;
    printf("Enter the real part of the first complex number: ");
    scanf("%d", &first_real);
    printf("Enter the imaginary part of the first complex number: ");
    scanf("%d", &first_imag);
    printf("Enter the real part of the second complex number: ");
    scanf("%d", &second_real);
    printf("Enter the imaginary part of the second complex number: ");
    scanf("%d", &second_imag);

    printf("Sum: %d + %di\n", first_real+second_real, first_imag+second_imag);
    printf("Difference: %d + %di\n", first_real-second_real, first_imag-second_imag);
    printf("Product: %d + %di\n", first_real*second_real-first_imag*second_imag, first_real*second_imag+first_imag*second_real);

    return 0;
}