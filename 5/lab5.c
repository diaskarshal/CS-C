#include <stdio.h>

int main() {
    
    int n, sum=0, max=-100000, min=100000, uniqueNum=0;

    printf("==========================================\n");
    printf("==                 TASK 1:              ==\n");
    printf("==========================================\n");

    printf("Enter the number of elements: ");
    scanf("%i", &n);
    int arr[n];

    printf("ENter the elements: ");

    for(int i = 0; i<n; i++){
        scanf("%i", &arr[i]);
        if(arr[i]>max){
            max = arr[i];
        }
        if(arr[i]<min){
            min = arr[i];
        }
        sum+=arr[i];
    }
    
    double avg = (double) sum/n;

    printf("Sum: %i\n", sum);
    printf("Average: %.2lf\n", avg);
    printf("Maximum: %i\n", max);
    printf("Minimum: %i\n", min);
    printf("Reversed array: ");

    for(int i = n-1; i>=0; i--){
        printf("%i ", arr[i]);
    }
    
    for(int i = 0; i<n; i++){
        int unique = 1;
        for(int j = 0; j<n; j++)
            if(i!=j && arr[j]==arr[i]){
                unique = 0;
                break;
            }
        if(unique)
            uniqueNum++;
    }

    printf("\nNumber of unique elemtnts: %i\n", uniqueNum);

    printf("==========================================\n");
    printf("==                 TASK 2:              ==\n");
    printf("==========================================\n");

    int num, realN=0;
    
    printf("Enter the number of different items: ");
    scanf("%i", &num);
    
    int ids[100], quantities[100];
    double totalWeight[100];
    
    printf("Enter item ID, quantity, and weight per unit (separated by spaces): \n");
    for(int i = 0; i<num; i++){
        int id, quantity;
        double weight;
        scanf("%i %i %lf", &id, &quantity, &weight);
        int duplicate = 0;
        for(int j = 0; j<realN; j++){
            if(ids[j]==id){
                printf("Item ID %i was elready entered. Quantities combined\n", id);
                duplicate = 1;
                quantities[j]+=quantity;
                totalWeight[j]+= (quantity*weight);
                break;
            }
        }
        if(duplicate==0){
            ids[realN]=id;
            quantities[realN]=quantity;
            totalWeight[realN]=weight*quantity;
            realN++;
        }
    }
    
    double totalSum = 0;

    printf("Printing items: \n");
    printf("—-------------------------------------------------------------\n");
    for(int i = 0; i<realN; i++){
        printf("Item ID: %i, Total Quantity: %i, Total Weight: %.2lf\n", ids[i], quantities[i], totalWeight[i]);
        totalSum+=totalWeight[i];
    }
    printf("—-------------------------------------------------------------\n");
    printf("Total Weight of All Items: %.2lf\n", totalSum);
    
    return 0;
}