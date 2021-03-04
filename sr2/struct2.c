#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct date {
  int year;
  int month;
  int day;
};

const int monthdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

struct products {
    char name[50];
    double price;
    struct date relTime;
};

int GetLineAmount(char *);
void ReadFile(struct products[], int, char *);
void Print(struct products[], int);
void SortByDate(struct products[], int);
void PrintNeeded(struct products [], int, struct date);

int lineAmount;

int main() {
    setlocale(LC_ALL, "Russian");
    char filename[50];
    printf("Введите имя файла для чтения: ");
    scanf("%s", filename);
    lineAmount = GetLineAmount(filename);

    struct products ProductList[lineAmount];
    struct date currDate;

    printf("Введите дату (дд.мм.гггг): ");
    scanf("%d.%d.%d", &(currDate.day), &(currDate.month), &(currDate.year));

    ReadFile(ProductList, lineAmount, filename);
    Print(ProductList, lineAmount);
    SortByDate(ProductList, lineAmount);
    printf("%s", "\nПосле сортировки:\n");
    PrintNeeded(ProductList, lineAmount, currDate);
    getchar(); getchar();
    return 0;
}

void Print(struct products exp[], int n) {
    int i;
    printf("%s", "\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%.0lf\t%02d.%02d.%d\n", exp[i].name, exp[i].price, exp[i].relTime.day,
                                    exp[i].relTime.month, exp[i].relTime.year);
    }
}

int GetDiff(struct date dt1, struct date dt2) {
    long int n1, n2;
    int i;
    n1 = dt1.year * 365 + dt1.day;
    for(i = 0; i < dt1.month - 1; i++)
        n1 += monthdays[i];
    n2 = dt2.year * 365 + dt2.day;
    for (i = 0; i < dt2.month - 1; i++) 
        n2 += monthdays[i];
    // printf("d1:%d d2:%d\tdiff:%ld\n", dt1.day, dt2.day, n2-n1);
    return (n2-n1);
}

void PrintNeeded(struct products p[], int n, struct date currDate) {
    int i;
    for (i = 0; i < n; i++) {
        if ((GetDiff(currDate, p[i].relTime) <= 30) && (GetDiff(currDate, p[i].relTime) >= 0)) {
            printf("%s\t%.0lf\t%02d.%02d.%d\n", p[i].name, p[i].price, p[i].relTime.day,
                                    p[i].relTime.month, p[i].relTime.year);
        }
    }
}

void SortByDate(struct products p[], int n) {
    int i, j;
    struct products temp;
    for(i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if ((p[j].relTime.year > p[j+1].relTime.year) || (p[j].relTime.year == p[j+1].relTime.year && p[j].relTime.month > p[j+1].relTime.month) || 
                (p[j].relTime.year == p[j+1].relTime.year && p[j].relTime.month == p[j+1].relTime.month && p[j].relTime.day > p[j+1].relTime.day)) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

int GetLineAmount(char *filename) {
    int c;
    int count = 1;
    FILE *fileLen = fopen(filename, "r");

    if (fileLen == NULL)
        return 0;
    for (c = getc(fileLen); c != EOF; c = getc(fileLen)) {
        if (c == '\n')
            count++;
    }

    fclose(fileLen);
    return count;
}

void ReadFile(struct products exp[], int lineAmount, char *filename) {
    int i = 0;
    FILE *data = fopen(filename, "r");
    while(fscanf(data, "%s %lf %d.%d.%d", exp[i].name, &(exp[i].price), &(exp[i].relTime.day),
                                    &(exp[i].relTime.month), &(exp[i].relTime.year)) != EOF) {
        i++;
    }

    fclose(data);
}
