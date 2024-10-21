// #include <stdio.h>
// #include <string.h>
// #include <stdbool.h>
// #include <strings.h>

// size_t countOccurrenceOfAWord(const char* str1, const char* str2) {
//     size_t count = 0;
//     const char* ptr = str1;
//     size_t len = strlen(str2);
    
//     // We can't use position = 1 as array index starts from 0
//     size_t position = -1;
    
//     while (*ptr) {
//         // Use strcasecmp for case-insensitive comparison of n characters
//         if (strncasecmp(ptr, str2, len) == 0) {
//             count++;
//             // Print position (adding 1 to convert from 0-based to 1-based indexing)
//             printf("Found at position %zu: ", position + 1);
            
//             // Print the matched word
//             size_t i = 0;
//             while (ptr[i] && (ptr[i] >= 'a' && ptr[i] <= 'z' || 
//                              ptr[i] >= 'A' && ptr[i] <= 'Z' ||
//                              ptr[i] >= '0' && ptr[i] <= '9')) {
//                 putchar(ptr[i]);
//                 i++;
//             }
//             printf("\n");
//         }
//         ptr++;
//         position++;
//     }
    
//     return count;
// }

// bool readTheTextFromFile(const char* filename, char* str) {
//     FILE* file = fopen(filename, "r");
//     if (file == NULL) {
//         return false;
//     }
    
//     // Read the entire file
//     size_t i = 0;
//     int ch;
//     while ((ch = fgetc(file)) != EOF && i < 2499) { // Leave space for null terminator
//         str[i++] = (char)ch;
//     }
//     str[i] = '\0';  // Null terminate the string
    
//     fclose(file);
//     return true;
// }

// int main(){
//     char strtext[2500] = {'\0'};
//     if(readTheTextFromFile("academic_integrity.txt", strtext) == false){
//         puts("Can't open the file.");
//         return -1;
//     }

//     printf ("\nIn total, %zu occurrences from \"assignment\".\n", countOccurrenceOfAWord(strtext, "assignment"));
//     printf("\nThe text is:\n%s\n", strtext);
//     return 0;
// }


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <strings.h>

size_t countOccurrenceOfAWord(const char* str1, const char* str2) {
    size_t count = 0;
    size_t str1_len = strlen(str1);
    size_t str2_len = strlen(str2);
    
    for (size_t i = 0; i < str1_len; i++) {
        bool match = true;
        
        // Check if we have enough characters left to match
        if (i + str2_len > str1_len) {
            continue;
        }
        
        // Compare each character ignoring case
        for (size_t j = 0; j < str2_len; j++) {
            char c1 = str1[i + j];
            char c2 = str2[j];
            
            // Convert uppercase to lowercase for comparison
            if (c1 >= 'A' && c1 <= 'Z') {
                c1 = c1 + ('a' - 'A');
            }
            if (c2 >= 'A' && c2 <= 'Z') {
                c2 = c2 + ('a' - 'A');
            }
            
            if (c1 != c2) {
                match = false;
                break;
            }
        }
        
        if (match) {
            count++;
            printf("Found at position %zu: ", i + 1);
            
            // Print the matching word (including any following letters/numbers)
            size_t k = i;
            while (k < str1_len && 
                   ((str1[k] >= 'a' && str1[k] <= 'z') || 
                    (str1[k] >= 'A' && str1[k] <= 'Z') ||
                    (str1[k] >= '0' && str1[k] <= '9'))) {
                printf("%c", str1[k]);
                k++;
            }
            printf("\n");
        }
    }
    
    return count;
}

bool readTheTextFromFile(const char* filename, char* str) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return false;
    }
    
    size_t index = 0;
    int c;
    
    // Read file character by character
    while ((c = fgetc(file)) != EOF && index < 2499) {
        str[index] = (char)c;
        index++;
    }
    
    str[index] = '\0';  // Null terminate the string
    fclose(file);
    return true;
}

// #include <stdio.h>
// #include <string.h>
// #include <stdbool.h>
// #include <strings.h>

// // Reads the content of the file into the given string
// bool readTheTextFromFile(const char* filename, char* str) {
//     FILE* file = fopen(filename, "r");
//     if (file == NULL) {
//         return false;  // File couldn't be opened
//     }

//     // Read the entire file content into the string buffer
//     fread(str, sizeof(char), 2499, file);
//     str[2499] = '\0';  // Ensure null termination
//     fclose(file);
//     return true;
// }

// // Counts the occurrences of a word, ignoring case
// size_t countOccurrenceOfAWord(const char* str1, const char* str2) {
//     size_t count = 0;
//     const char* pos = str1;

//     // Loop through the main text to search for the word (case-insensitively)
//     while ((pos = strcasestr(pos, str2)) != NULL) {
//         count++;
//         pos++;  // Move the pointer forward to search for the next occurrence
//     }

//     return count;
// }

int main() {
    char strtext[2500] = {'\0'};
    if (readTheTextFromFile("academic_integrity.txt", strtext) == false) {
        puts("Can't open the file.");
        return -1;
    }

    printf("\nIn total, %zu occurrences from \"assignment\".\n", 
           countOccurrenceOfAWord(strtext, "assignment"));
    printf("\nThe text is:\n%s\n", strtext);
    return 0;
}
