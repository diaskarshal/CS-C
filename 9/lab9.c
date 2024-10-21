//Dias Karshal CSCI 151 Lab9
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <strings.h>

//about strings.h
//https://stackoverflow.com/questions/4291149/difference-between-string-h-and-strings-h
//https://pubs.opengroup.org/onlinepubs/7908799/xsh/strings.h.html

// tolower and toupper are not allowed, because they belong to <ctype.h>

size_t countOccurrenceOfAWord(const char* str1, const char* str2){
    size_t count = 0;
    size_t s1len = strlen(str1);
    size_t s2len = strlen(str2);

    printf("The word \"assignment\" is mentioned:\n");
    for(size_t i = 0; i<s1len; i++){
        bool f = true;

        if(i+s2len>s1len)
            break;
        
        for(size_t j = 0; j<s2len; j++){
            char c1 = str1[i+j];
            char c2 = str2[j];
            if(c1>='A' && c1<='Z')
                c1+=32;
            
            if(c2>='A' && c2<='Z')
                c2+=32;
            
            if(c1!=c2){
                f = false;
                break;
            }
        }
        
        if(f){
            count++;
            size_t k = i;
            while(k<s1len &&((str1[k] >= 'a' && str1[k] <= 'z') 
                          || (str1[k] >= 'A' && str1[k] <= 'Z') 
                          || (str1[k] >= '0' && str1[k] <= '9')))
                printf("%c", str1[k++]);
            printf(" at pos %zu", i);
            printf("\n");
        }
    }
    return count;
}

bool readTheTextFromFile(const char* filename, char* str){
    
    FILE *in;
    in = fopen(filename, "r");

    if(in == NULL)
        return false;

    size_t i = 0;
    char c;
    
    while((c = fgetc(in))!=EOF)
        str[i++]=c;
    
    fclose(in);
    return true;
}

int main(){
    char strtext[2500] = {'\0'};

    if(readTheTextFromFile("academic_integrity.txt", strtext) == false){
        puts("Can't open the file.");
        return -1;
    }
    
    printf("In total, %zu occurrences from \"assignment\".\n", countOccurrenceOfAWord(strtext, "assignment"));
    printf("\nThe text is:\n%s\n", strtext);

    return 0;
}