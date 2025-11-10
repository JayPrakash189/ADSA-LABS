#include <stdio.h>
#include <string.h>

typedef struct
{
    char title[150];
    char author[100];
    double price;
} Book;

int main()
{
    int n;
    printf("Enter number of books: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 0;
    Book books[n];
    for (int i = 0; i < n; ++i)
    {
        printf("Book %d title: ", i + 1);

        scanf(" ");
        fgets(books[i].title, sizeof(books[i].title), stdin);

        size_t len = strlen(books[i].title);
        if (len && books[i].title[len - 1] == '\n')
            books[i].title[len - 1] = 0;

        printf("Author: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        len = strlen(books[i].author);
        if (len && books[i].author[len - 1] == '\n')
            books[i].author[len - 1] = 0;
        printf("Price: ");
        scanf("%lf", &books[i].price);
    }

    double threshold;
    printf("Enter price threshold: ");
    scanf("%lf", &threshold);

    printf("Books with price > %.2f:\n", threshold);
    for (int i = 0; i < n; ++i)
    {
        if (books[i].price > threshold)
        {
            printf("Title: %s, Author: %s, Price: %.2f\n", books[i].title, books[i].author, books[i].price);
        }
    }
    return 0;
}
