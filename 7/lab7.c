//Dias Karshal CSCI151 LAB7
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    size_t id;
    char firstname[20];
    char lastname[20];
    double paid;
    double *bills;
}Customer;

double AccountBalance(Customer cust[], size_t customer_id){
    FILE *file = fopen("customer_bills.txt", "r");
    double total_bills = 0;
    char ch;
    int number_of_customers = 0, number_of_tabs = 0, number_of_months = 0;
    file = fopen("customer_bills.txt", "r");    // we already read the file once, to count number of customers, now need to reopen it
    while((ch = (char) getc(file)) != '\n'){    // count the number of tabs to get the info about number of months
        if(ch == '\t')
            number_of_tabs++;
    }
    number_of_months = (number_of_tabs - 4) + 1;
    for (size_t i = 0; i<number_of_months; i++){
        total_bills += cust[customer_id].bills[i];
    }
    return cust[customer_id].paid - total_bills;
}

_Bool NegativeBalance(Customer cust[], size_t customer_id){
    return AccountBalance(cust, customer_id) < 0;
}

size_t CustomersWithWarnings(Customer cust[], size_t array_size){
    size_t c = 0;
    printf("\nCustomers with the negative balance:\n");
    printf("cust_id\tName\tSurname\tBalance\n");
    for(size_t i = 0; i < array_size; i++){
        if(NegativeBalance(cust, i)){
            double balance = AccountBalance(cust, i);
            printf("%06lu\t%s\t%s\t%.2f\n", cust[i].id, cust[i].firstname, cust[i].lastname, balance);
            c++;
        }
    }
    return c;
}

void AverageBill(Customer cust[], size_t array_size){
    FILE *file = fopen("customer_bills.txt", "r");
    double total_bills = 0;
    char ch;
    int number_of_customers = 0, number_of_tabs = 0, number_of_months = 0;
    file = fopen("customer_bills.txt", "r");    // we already read the file once, to count number of customers, now need to reopen it
    while((ch = (char) getc(file)) != '\n'){    // count the number of tabs to get the info about number of months
        if(ch == '\t')
            number_of_tabs++;
    }
    number_of_months = (number_of_tabs - 4) + 1;
    printf("\ncust_id\tName\tSurname\tAverage Bill\n");
    for (size_t i=0; i<array_size; i++){
        double sum = 0;
        for (size_t j =0; j<number_of_months; j++){
            sum+=cust[i].bills[j];
        }
        double average = sum / number_of_months;
        printf("%06lu\t%s\t%s\t%.3f\n", cust[i].id, cust[i].firstname, cust[i].lastname, average);
    }
}
Customer CustomerWithMaxDebt(Customer cust[], size_t array_size){
    Customer max_debt_customer = cust[0];
    double max_debt = AccountBalance(cust, 0);
    for(size_t i=1; i<array_size; i++){
        double balance = AccountBalance(cust, i);
        if (balance<max_debt){
            max_debt = balance;
            max_debt_customer = cust[i];
        }
    }
    return max_debt_customer;
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

    AverageBill(customers, number_of_customers);

    printf("\nThere are %lu customers who have a negative balance.\n", CustomersWithWarnings(customers, number_of_customers));

    Customer max_debt_customer = CustomerWithMaxDebt(customers, number_of_customers);
    printf("Customer %s %s has the maximum negative balance. It is %.2f.", max_debt_customer.firstname, max_debt_customer.lastname, AccountBalance(customers, max_debt_customer.id-1));

    // memory deallocation
    for(i = 0; i < number_of_customers; i++){
        free(customers[i].bills);
    }
    fclose(file);
    return 0;

}
