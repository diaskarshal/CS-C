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
    
    return count;
}

bool readTheTextFromFile(const char* filename, char* str){
    
}

int main(){
    char strtext[2500] = {'\0'};
    if(readTheTextFromFile("academic_integrity.txt", strtext) == false){
        puts("Can't open the file.");
        return -1;
    }

    printf ("\nIn total, %zu occurrences from \"assignment\".\n", countOccurrenceOfAWord(strtext, "assignment"));
    printf("\nThe text is:\n%s\n", strtext);
    return 0;
}