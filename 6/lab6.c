//Dias Karshal CSCI151 LAB6
#include <stdio.h>

struct Book {
        int book_id;
        float price;
        int num_pages;
        int year_published;
    };

struct Attraction {
        int attraction_id;
        char name[30];
        char location[30];
        float rating;
    };

int main() {
    printf("==========================================\n");
    printf("==                 TASK 1:              ==\n");
    printf("==========================================\n");

    FILE *in;
    in = fopen("books.txt", "r");

    if (in == NULL) {
        printf("Problem opening files.\n");
        return 1;
    }
    printf("File opened successfully.\n");
    
    int booksNum = 0;
    struct Book books[100];

    while ((fscanf(in, "%d %f %d %d", &books[booksNum].book_id, &books[booksNum].price, &books[booksNum].num_pages, &books[booksNum].year_published))==4) {
        booksNum++;
    }

    int choice;
    do{
        printf("Menu:\n");
        printf("1. Display all books\n");
        printf("2. Search for a book by ID\n");
        printf("3. Find the most expensive book\n");
        printf("4. Find the least expensive book\n");
        printf("5. Display total number of books\n");
        printf("6. Display average book price\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Book Collection:\n");
                for(int i = 0; i<booksNum; i++){
                    printf("ID: %d, Price: %.2f, Pages: %d, Year: %d\n", 
                           books[i].book_id, books[i].price, books[i].num_pages, books[i].year_published);
                }
                break;
            case 2:
                int ID;
                printf("Enter book ID to search for: ");
                scanf("%d", &ID);
                int found = 0;
                for(int i = 0; i < booksNum; i++){
                    if(books[i].book_id == ID){
                        printf("Book found:\n");
                        printf("ID: %d, Price: %.2f, Pages: %d, Year: %d\n", books[i].book_id, books[i].price, books[i].num_pages, books[i].year_published);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("No book found with ID %d.\n", ID);
                }
                break;
            case 3:
                int expensiveID = 0;
                for (int i = 1; i < booksNum; i++) {
                    if (books[i].price > books[expensiveID].price) {
                        expensiveID = i;
                    }
                }
                printf("Most expensive book: \n");
                printf("ID: %d, Price: %.2f, Pages: %d, Year: %d\n", books[expensiveID].book_id, books[expensiveID].price, books[expensiveID].num_pages, books[expensiveID].year_published);
                break;
            case 4:
                int cheapID = 0;
                for (int i = 1; i < booksNum; i++) {
                    if (books[i].price < books[cheapID].price) {
                        cheapID = i;
                    }
                }   
                printf("Least expensive book: \n");
                printf("ID: %d, Price: %.2f, Pages: %d, Year: %d\n", books[cheapID].book_id, books[cheapID].price, books[cheapID].num_pages, books[cheapID].year_published);
                break;
            case 5:
                printf("Total number of books: %d\n", booksNum);
                break;
            case 6:
                float booksSum = 0;
                    for(int i=0; i<booksNum; i++){
                        booksSum+=books[i].price;
                    }
                printf("Average book price: %.2f\n", (booksSum/(double)booksNum));
                
                break;
            case 7:
                printf("Exiting program.");
                break;
            default:
                printf("Incorrect input!\n");
        }
    }while (choice != 7);


    fclose(in);
    
    
    printf("\n==========================================\n");
    printf("==                 TASK 2:              ==\n");
    printf("==========================================\n");
    
    

    int n;
    float totalRating=0;
    printf("Enter number of attractions: ");
    scanf("%d", &n);

    struct Attraction attr[n];
    
    for(int i = 0; i<n; i++){
        printf("Enter attraction ID: ");
        scanf("%i", &attr[i].attraction_id);
        printf("Enter attraction name: ");
        scanf("%s", &attr[i].name);
        printf("Enter location: ");
        scanf("%s", &attr[i].location);
        printf("Enter rating: ");
        scanf("%f", &attr[i].rating);

    }
     
    for(int i=0; i<n; i++){
        totalRating+=attr[i].rating;
    }

    float avgR = (float) totalRating/n;

    printf("Average rating: %.2f\n", avgR);
    int highestID = 0;
    for(int i = 1; i<n; i++){
        if(attr[i].rating>attr[highestID].rating)
            highestID = i;
    }
    printf("Highest-rated attraction: %s (Rating: %.1f)\n", attr[highestID].name, attr[highestID].rating);

    printf("Tourist Attractions:\n");
    for(int i=0; i<n; i++){
        printf("%d. %s, Location: %s, Rating: %.1f\n", i, attr[i].name, attr[i].location, attr[i].rating);

    }

    return 0;

}