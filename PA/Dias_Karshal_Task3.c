//Dias Karshal PA Task 3

#include <stdio.h>

void decode_string(char encoded[], int length){
    for(int i = 0; i<length; i++){
        if(i+2<length && encoded[i+2]=='0'){
            if(i+3<length && encoded[i+3]=='0'){
                if(encoded[i+1]=='1'){
                    printf("%cj", (48+(int)encoded[i]));
                    i+=3;
                    continue;
                }
                else if(encoded[i+1]=='2'){
                    printf("%ct", (48+(int)encoded[i]));
                    i+=3;
                    continue;
                }
            }
            printf("%c", (96+10*((int)encoded[i]-48)+(int)encoded[i+1]-48));
            i+=2;
            continue;
        }
        printf("%c", (48+(int)encoded[i]));
    }
    printf("\n");
}

void decode_from_file(char filename[]){

    FILE *file;
    file = fopen(filename, "r");

    int n;

    fscanf(file, "%d", &n);

    for(int i = 0; i<n; i++){
        int len;
        char code[100];

        fscanf(file, "\n%d %s", &len, code);
        decode_string(code, len);
    }

    fclose(file);
}

int main(){

    decode_from_file("input.txt");

    return 0;
}