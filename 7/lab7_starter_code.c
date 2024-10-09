#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    size_t id;
    char firstname[20];
    char lastname[20];
    double paid;
    double *bills; // array of doubles
} Customer;



double AccountBalance(Customer Customer, size_t customer_id){
    // You can pass size_t array_size as well if you think you need it

    // Write your code here

    return 0.0; // change the return if necessary
}

_Bool NegativeBalance(Customer cust[], size_t customer_id){
    // You can pass size_t array_size as well if you think you need it

    // Write your code here

    return 0; // change the return if necessary
}

// prints the list of customers with a negative balance, must call functions AccountBalance() and NegativeBalance()
// returns the number of customers with a negative balance.
size_t CustomersWithWarnings(Customer cust[], size_t array_size){
    
    // Write your code here
    
    return 0; // change the return if necessary
}

void AverageBill(Customer cust[], size_t array_size){
    // printf("\ncust_id\tName\tSurname\tAverage Bill\n");
    
    // Write your code here
    
}

// this function must call AccountBalance() 
Customer CustomerWithMaxDebt(Customer cust[], size_t array_size){
    
    // Write your code here
    
    return cust[-1]; // change the return if necessary
}



int main(){
    FILE *file = fopen("customer_bills.txt", "r");
   
    if(file == NULL){
        printf("can't open the file");
        return 1;
    }

    char ch;
    int number_of_customers = 0, number_of_tabs = 0, number_of_months = 0;
    while((ch = (char) getc(file)) != EOF){
        if(ch == '\n')
            number_of_customers++;
    }
    printf("%i\n", number_of_customers);

    file = fopen("customer_bills.txt", "r");    // we already read the file once, to count number of customers, now need to reopen it
    while((ch = (char) getc(file)) != '\n'){    // count the number of tabs to get the info about number of months
        if(ch == '\t')
            number_of_tabs++;
    }
    printf("%i\n", number_of_tabs);

    char cust_id[20] = {0}, fname[20] = {0}, lname[20] = {0}, paidtitle[20] = {0};
    number_of_months = (number_of_tabs - 4) + 1;
    printf("%i\n", number_of_months);
    
    Customer customers[number_of_customers];

    for(int i = 0; i < number_of_customers; i++){ // this method of initialization doesn't work if some struct elements are constants
        customers[i] = (Customer) {.id = 0, .firstname = "\0", .lastname = "\0", .paid = 0};
        customers[i].bills = malloc(number_of_months * sizeof(double));
    }
    
    char month_names[number_of_months][20];
    file = fopen("customer_bills.txt", "r");

    fscanf(file, "%s %s %s %s", cust_id, fname, lname, paidtitle); // reading the first four elements - id, name, surname and the amount paid on the top row
    printf("\ncust_id\tName\tSurname\tPaid\t");
    for(int i = 0; i < number_of_months; i++){ // reading the month names
        fscanf(file, "%s", month_names[i]);
        printf("%s\t", month_names[i]);
    }
    printf("\n");
    
    int i = 0;
    while(!feof(file)){ // checking if we did read them correctly
        fscanf(file, "%lu %s %s %lf", &customers[i].id, customers[i].firstname, customers[i].lastname, &customers[i].paid);
        printf("%06lu\t%s\t%s\t%.2lf\t", customers[i].id, customers[i].firstname, customers[i].lastname, customers[i].paid);
        for(int j = 0; j < number_of_months; j++){ // reading the month names
            fscanf(file, "%lf", &customers[i].bills[j]);
            printf("%.2lf\t", customers[i].bills[j]);
        }
        printf("\n");
        i++;
    }

    /*
    Write your code that will call the required functions here
    */

    // memory deallocation
    for(i = 0; i < number_of_customers; i++){
        free(customers[i].bills);
    }

    return 0;
}