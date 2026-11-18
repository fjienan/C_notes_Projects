#include <stdio.h>
#define BOOKS_NUM 5

typedef struct book{
    char title[100];
    char author[100];
    int year;
} Book;

int saveLibrary(Book library[], int n);
int printBook(int index);

int main(void){
    static Book library[BOOKS_NUM] = {
        {"The Great Gatsby", "F. Scott Fitzgerald", 1925},
        {"1984", "George Orwell", 1949},
        {"To Kill a Mockingbird", "Harper Lee", 1960},
        {"Moby-Dick", "Herman Melville", 1851},
        {"Pride and Prejudice", "Jane Austen", 1813}
    };
    if (saveLibrary(library, BOOKS_NUM) != 0){
        return 1;
    }

    for (int i = 0; i < 3; i++){
        int index;
        printf("Enter book index %d (0-%d): ", i + 1, BOOKS_NUM - 1);
        if (scanf("%d", &index) != 1){
            printf("Invalid input. Please enter an integer.\n");
            return 1;
        }
        if (printBook(index) != 0){
            return 1;
        }
    }
    return 0;
}

int saveLibrary(Book library[], int n){
    FILE *fp = fopen("library.bin", "wb");
    if (fp == NULL){
        perror("library.bin");
        return 1;
    }
    if (fwrite(library, sizeof(Book), n, fp) != (size_t)n){
        perror("Write library");
        fclose(fp);
        return 1;
    }
    if (fclose(fp) != 0){
        perror("Close library.bin");
        return 1;
    }
    return 0;
}

int printBook(int index){
    if (index < 0 || index >= BOOKS_NUM){
        printf("Invalid index. Please enter a number from 0 to %d.\n", BOOKS_NUM - 1);
        return 0;
    }

    FILE *fp = fopen("library.bin", "rb");
    if (fp == NULL){
        perror("library.bin");
        return 1;
    }
    // 每本书占 sizeof(Book) 个字节，跳到对应的位置。
    if (fseek(fp, (long)index * (long)sizeof(Book), SEEK_SET) != 0){
        perror("Find book");
        fclose(fp);
        return 1;
    }
    Book book;
    if (fread(&book, sizeof(Book), 1, fp) != 1){
        printf("Failed to read book from library.bin\n");
        fclose(fp);
        return 1;
    }
    if (fclose(fp) != 0){
        perror("Close library.bin");
        return 1;
    }
    printf("Title: %s\nAuthor: %s\nYear: %d\n\n", book.title, book.author, book.year);
    return 0;
}
