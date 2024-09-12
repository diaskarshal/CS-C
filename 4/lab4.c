//Dias Karshal CSCI151 LAB4
#include <stdio.h>

int main() {
    printf("==========================================\n");
    printf("==                 TASK 1:              ==\n");
    printf("==========================================\n");

    FILE *in, *out;
    in = fopen("input.csv", "r");
    out = fopen("summary.txt", "w");

    int productsNum = 0;
    double avg, price, productsSum = 0, totalVal = 0, expensive = 0, cheap = 1000000;
    char product[100], expensiveName[100], cheapName[100];
    int quantity;

    if (in == NULL || out == NULL) {
        printf("Problem opening files.\n");
        return 1;
    }
    
    printf("Files opened successfully.\n");
    fscanf(in, "%*[^\n]\n");
    
    while (!feof(in)) {
        fscanf(in, "%[^,],%lf,%d", product, &price, &quantity);
        productsNum++;
        productsSum+=price;
        totalVal += (price*quantity);

        if (price>expensive) {
            int i = 0;
            while(i != sizeof(product)) {
                expensiveName[i] = product[i];
                i++;
            }
            expensive = price;
        }
        else if(price<cheap) {
            int i = 0;
            while(i != sizeof(product)) {
                cheapName[i] = product[i];
                i++;
            }
            cheap = price;
        }
    }

    avg = (double)(productsSum/productsNum);

    fprintf(out, "Total number of products: %i\n", productsNum);
    fprintf(out, "Total value of all products: %.2lf\n", totalVal);
    fprintf(out, "Most expensive product: %s ($%.2lf)\n", expensiveName, expensive);
    fprintf(out, "Least expensive product: %s ($%.2lf)\n", cheapName, cheap);
    fprintf(out, "Average price of products: $%0.2lf\n", avg);

    fclose(in);
    fclose(out);

    printf("==========================================\n");
    printf("==                 TASK 2:              ==\n");
    printf("==========================================\n");

    FILE *input, *output;
    input = fopen("text.txt", "r");
    output = fopen("text_summary.txt", "w");

    if (input == NULL || output == NULL) {
        printf("Problem opening files.\n");
        return 1;
    }
    
    printf("Files opened successfully.\n");
    
    int totalLines = 0, totalWords = 0, longestLineChars = 0, mostWords = 0, longestLine = 0, mostWordsLine = 0, currentLineLength = 0, currentWordCount = 0, inWord = 0, c;

    while((c=getc(input)) != EOF){

        if(c=='\n'){
            totalLines++;
            
            if(currentLineLength>longestLineChars){
                longestLineChars = currentLineLength;
                longestLine = totalLines;
            }
            
            if(currentWordCount>mostWords){
                mostWords = currentWordCount;
                mostWordsLine = totalLines;
            }
            totalWords+=currentWordCount;
            currentLineLength = 0;
            currentWordCount = 0;
            inWord = 0;
        } 
        else{
            currentLineLength++;
            if(c==' '){
                inWord = 0;
            } 
            else if(!inWord){
                inWord = 1;
                currentWordCount++;
            }
        }
    }

    if(currentLineLength>0){
        totalLines++;
        totalWords += currentWordCount;
        if(currentLineLength>longestLineChars){
            longestLineChars = currentLineLength;
            longestLine = totalLines;
        }
        if(currentWordCount>mostWords){
            mostWords = currentWordCount;
            mostWordsLine = totalLines;
        }
    }

    fprintf(output, "Total number of lines: %i\n", totalLines);
    fprintf(output, "Total number of words: %i\n", totalWords);
    fprintf(output, "The longest line (by characters): Line %i (%i characters).\n", longestLine, longestLineChars);
    fprintf(output, "The line with the most words: Line %i (%i words).\n", mostWordsLine, mostWords);

    fclose(input);
    fclose(output);

    return 0;

}