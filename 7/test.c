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

double AccountBalance(Customer cust[], size_t customer_id, size_t num_months) {
    double total_bills = 0;
    for (size_t i = 0; i < num_months; i++) {
        total_bills += cust[customer_id].bills[i];
    }
    return cust[customer_id].paid - total_bills;
}

_Bool NegativeBalance(Customer cust[], size_t customer_id, size_t num_months) {
    return AccountBalance(cust, customer_id, num_months) < 0;
}

size_t CustomersWithWarnings(Customer cust[], size_t array_size, size_t num_months) {
    size_t count = 0;
    printf("\nCustomers with the negative balance:\n");
    printf("cust_id\tName\tSurname\tBalance\n");
    for (size_t i = 0; i < array_size; i++) {
        if (NegativeBalance(cust, i, num_months)) {
            double balance = AccountBalance(cust, i, num_months);
            printf("%06lu\t%s\t%s\t%.2f\n", cust[i].id, cust[i].firstname, cust[i].lastname, balance);
            count++;
        }
    }
    return count;
}

void AverageBill(Customer cust[], size_t array_size, size_t num_months) {
    printf("\ncust_id\tName\tSurname\tAverage Bill\n");
    for (size_t i = 0; i < array_size; i++) {
        double sum = 0;
        for (size_t j = 0; j < num_months; j++) {
            sum += cust[i].bills[j];
        }
        double average = sum / num_months;
        printf("%06lu\t%s\t%s\t%.3f\n", cust[i].id, cust[i].firstname, cust[i].lastname, average);
    }
}

Customer CustomerWithMaxDebt(Customer cust[], size_t array_size, size_t num_months) {
    Customer max_debt_customer = cust[0];
    double max_debt = AccountBalance(cust, 0, num_months);
    for (size_t i = 1; i < array_size; i++) {
        double balance = AccountBalance(cust, i, num_months);
        if (balance < max_debt) {
            max_debt = balance;
            max_debt_customer = cust[i];
        }
    }
    return max_debt_customer;
}

int main() {
    FILE *file = fopen("customer_bills.txt", "r");
   
    if(file == NULL) {
        printf("can't open the file");
        return 1;
    }

    char ch;
    int number_of_customers = 0, number_of_tabs = 0, number_of_months = 0;
    while((ch = (char) getc(file)) != EOF) {
        if(ch == '\n')
            number_of_customers++;
    }
    number_of_customers--; // Subtract 1 to account for the header line
    printf("Number of customers: %d\n", number_of_customers);

    file = fopen("customer_bills.txt", "r");
    while((ch = (char) getc(file)) != '\n') {
        if(ch == '\t')
            number_of_tabs++;
    }
    printf("Number of tabs: %d\n", number_of_tabs);

    char cust_id[20] = {0}, fname[20] = {0}, lname[20] = {0}, paidtitle[20] = {0};
    number_of_months = (number_of_tabs - 4) + 1;
    printf("Number of months: %d\n", number_of_months);
    
    Customer *customers = malloc(number_of_customers * sizeof(Customer));
    
    char month_names[20][20];
    rewind(file);

    fscanf(file, "%s %s %s %s", cust_id, fname, lname, paidtitle);
    printf("\ncust_id\tName\tSurname\tPaid\t");
    for(int i = 0; i < number_of_months; i++) {
        fscanf(file, "%s", month_names[i]);
        printf("%s\t", month_names[i]);
    }
    printf("\n");
    
    int i = 0;
    while(i < number_of_customers && fscanf(file, "%lu %s %s %lf", &customers[i].id, customers[i].firstname, customers[i].lastname, &customers[i].paid) == 4) {
        customers[i].bills = malloc(number_of_months * sizeof(double));
        printf("%06lu\t%s\t%s\t%.2lf\t", customers[i].id, customers[i].firstname, customers[i].lastname, customers[i].paid);
        for(int j = 0; j < number_of_months; j++) {
            fscanf(file, "%lf", &customers[i].bills[j]);
            printf("%.2lf\t", customers[i].bills[j]);
        }
        printf("\n");
        i++;
    }

    fclose(file);

    // Call the required functions

    // AccountBalance(customers, 234451, 5);
    AverageBill(customers, number_of_customers, number_of_months);
    
    size_t warnings = CustomersWithWarnings(customers, number_of_customers, number_of_months);
    printf("\nThere are %zu customers who have a negative balance.\n", warnings);

    Customer max_debt = CustomerWithMaxDebt(customers, number_of_customers, number_of_months);
    printf("\nCustomer %s %s has the maximum negative balance. It is %.2f.\n", 
           max_debt.firstname, max_debt.lastname, AccountBalance(customers, max_debt.id - 1, number_of_months));

    // Memory deallocation
    for(i = 0; i < number_of_customers; i++) {
        free(customers[i].bills);
    }
    free(customers);

    return 0;
}