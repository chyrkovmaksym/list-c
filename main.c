#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    float price;
    int pages;
    char language[50];
    float weight;
    int year;
    struct Book* next;
};

struct Book* createBook(char title[], float price, int pages, char language[], float weight, int year) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    if (newBook == NULL) {
        printf("Помилка виділення пам'яті для нової книги.\n");
        exit(1);
    }

    strcpy(newBook->title, title);
    newBook->price = price;
    newBook->pages = pages;
    strcpy(newBook->language, language);
    newBook->weight = weight;
    newBook->year = year;
    newBook->next = NULL;

    return newBook;
}

int main() {
    struct Book* firstBook = createBook("Гарі Поттер і філософський камінь", 19.99, 309, "Українська", 0.5, 1997);

    struct Book* secondBook = createBook("Гарі Поттер і таємна кімната", 21.99, 360, "Українська", 0.6, 1998);

    firstBook->next = secondBook;

    struct Book* currentBook = firstBook;
    while (currentBook != NULL) {
        printf("Назва книги: %s\n", currentBook->title);
        printf("Ціна: %.2f грн\n", currentBook->price);
        printf("Число сторінок: %d\n", currentBook->pages);
        printf("Мова: %s\n", currentBook->language);
        printf("Вага: %.2f кг\n", currentBook->weight);
        printf("Рік видання: %d\n", currentBook->year);
        printf("\n");

        currentBook = currentBook->next;
    }

    currentBook = firstBook;
    while (currentBook != NULL) {
        struct Book* nextBook = currentBook->next;
        free(currentBook);
        currentBook = nextBook;
    }

    return 0;
}

