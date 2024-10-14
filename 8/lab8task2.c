//Dias Karshal CSCI151 LAB8
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    char boss[50];
    char position[50];
    int phone;
    int office;
} Employee;

Employee emp[88];
int n = 0;

int findid(char name[]) {
    for(int i = 0; i < n; i++){
        if(strcmp(emp[i].name, name)==0)
            return i;
    }
    return -1;
}

void call(int id){
    printf("The boss of %s is %s.\n", emp[id].name, emp[id].boss);
    int bossid=findid(emp[id].boss);
    if(bossid!=-1)
        call(bossid);
}

int main(){

    FILE *file = fopen("employees.txt", "r");
    if (file == NULL) {
        printf("cannot open the file.\n");
        return 1;
    }

    while(fscanf(file, "%s %s %s %d %d", emp[n].name, emp[n].boss, emp[n].position, &emp[n].phone, &emp[n].office) == 5)
        n++;

    char person[50];
    printf("Type a name of the staff member: ");
    scanf("%s", person);

    int id=findid(person);

    printf("%s's position title: %s. %s's phone and office: %d %d\n", emp[id].name, emp[id].position, emp[id].name, emp[id].phone, emp[id].office);

    call(id);

    fclose(file);
    return 0;
}