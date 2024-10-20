//Dias Karshal PA Task 1

#include <stdio.h>
int main(){

    FILE *file;
    file = fopen("input.txt", "r");

    if(file == NULL){
        printf("Problem opening files.\n");
        return 1;
    }

    int a = 0, n;

    fscanf(file, "%d", &n);

    for(int i = 0; i<n; i++){
        char c1, c2, c3;
        fscanf(file, "\n%c%c%c", &c1, &c2, &c3);
        
        if((c2=='+'&&c3=='+')||(c1=='+'&&c2=='+'))
            a++;
        else if((c2=='*'&&c3=='*')||(c1=='*'&&c2=='*'))
            a*=a;
        else if((c2=='-'&&c3=='-')||(c1=='-'&&c2=='-'))
            a--;
        else{
            printf("error");    
            fclose(file);
            return 0;
        }
    }

    printf("%d", a);

    fclose(file);
    return 0;
}