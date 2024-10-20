//Dias Karshal PA Task 2

#include <stdio.h>
int main(){

    FILE *file;
    file = fopen("input.txt", "r");

    if(file == NULL){
        printf("Problem opening files.\n");
        return 1;
    }

    int n;

    fscanf(file, "%d", &n);

    for(int i = 0; i<n; i++){
        int p1, p2, p3, p4;
        fscanf(file, "\n%d %d %d %d", &p1, &p2, &p3, &p4);
        if((((p1>p2 && p1>p3 && p1>p4) && (p3>p4 && p3>p2)) || ((p1>p2 && p1>p3 && p1>p4) && (p4>p3 && p4>p2))) 
        || (((p2>p1 && p2>p3 && p2>p4) && (p4>p3 && p4>p1)) || ((p2>p1 && p2>p3 && p2>p4) && (p3>p4 && p3>p1)))
        || (((p3>p1 && p3>p2 && p3>p4) && (p1>p2 && p1>p4)) || ((p3>p1 && p3>p2 && p3>p4) && (p2>p1 && p2>p4)))
        || (((p4>p1 && p4>p2 && p4>p2) && (p1>p2 && p1>p3)) || ((p4>p1 && p2>p2 && p2>p3) && (p2>p1 && p2>p3)))
        )
            printf("YES\n");
        else
            printf("NO\n");
    }
    fclose(file);
    return 0;
}