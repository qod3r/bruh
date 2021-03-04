#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
 
FILE *arrayFile;
FILE *sortedArrayFile;
 
void CreateArrayFile(void);
void BubbleSort(void);
void SelectionSort(void);
void InsertionSort(void);
int ElementsCount(char *);
 
 
 
int main() {
    setlocale(LC_ALL, "Russian");
    
    int menu_choice;
    
      do {
        printf("\n------------- \n");
        printf("1 - Создать массив \n");
        printf("2 - Сортировка обменом \n");
        printf("3 - Сортировка выбором \n");
        printf("4 - Сортировка вставками \n");
        printf("0 - Выйти \n");
        printf("------------- \n");
 
        scanf("%d",&menu_choice);
 
        switch(menu_choice) {
          case 1:
                CreateArrayFile();
           break;
          case 2:
                BubbleSort();
           break;
          case 3:
                SelectionSort();
           break;
          case 4:
                InsertionSort();
           break;
          case 0:
            printf("Пока!\n");
            break;
          default:
            printf("Что-то пошло не так, попробуйте снова\n");
            break;
        }
      } while(menu_choice);
    
    return 0;
}
 
void CreateArrayFile() {
    int n = 0;
    char filename[50];
    
    printf("Введите имя файла(*.txt) ");
    scanf("%s", filename);
    
    arrayFile = fopen(filename, "w");
    printf("Введите размерность массива\n");
    scanf("%d",&n);
    
    for (int i = 0; i < n; i++) {
        int element = (rand() % 201) - 100;
        fprintf(arrayFile, "%d ", element);
    }
    
    fclose(arrayFile);
}
 
int ElementsCount(char *filename) {
    int c;
    int count = 0;
    arrayFile = fopen(filename, "r");
 
    if (arrayFile == NULL)
        return 0;
    for (c = getc(arrayFile); c != EOF; c = getc(arrayFile)) {
        if (c == ' ')
            count++;
    }
    fclose(arrayFile);
    return count;
}
 
void BubbleSort() {
    char filename[50];
    
    printf("Введите имя файла для чтения(*.txt) ");
    scanf("%s", filename);
    int n = ElementsCount(filename);
    arrayFile = fopen(filename, "r");
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(arrayFile, "%d", &arr[i]);
    }
    fclose(arrayFile);
    
    //Сортирвока обменами
    for (int i = 0; i < n - 1; i++)
     {
       for (int j = (n - 1); j > i; j--){
         if (arr[j - 1] > arr[j]){
           int temp = arr[j - 1];
           arr[j - 1] = arr[j];
           arr[j] = temp;
         }
       }
     }
    
    sortedArrayFile = fopen("sortedArray_Bubble.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(sortedArrayFile, "%d ", arr[i]);
    }
    fclose(sortedArrayFile);
}
 
void SelectionSort() {
    char filename[50];
    
    printf("Введите имя файла для чтения(*.txt) ");
    scanf("%s", filename);
    int n = ElementsCount(filename);
    arrayFile = fopen(filename, "r");
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(arrayFile, "%d", &arr[i]);
    }
    fclose(arrayFile);
    
    //Сортирвока выбором
    int min, temp;
      for (int i = 0; i < n - 1; i++){
        min = i;
        for (int j = i + 1; j < n; j++){
          if (arr[j] < arr[min])
            min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
      }
    
    sortedArrayFile = fopen("sortedArray_Selection.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(sortedArrayFile, "%d ", arr[i]);
    }
    fclose(sortedArrayFile);
}
 
void InsertionSort(){
    char filename[50];
    
    printf("Введите имя файла для чтения(*.txt) ");
    scanf("%s", filename);
    int n = ElementsCount(filename);
    arrayFile = fopen(filename, "r");
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(arrayFile, "%d", &arr[i]);
    }
    fclose(arrayFile);
    
    //Сортирвока вставками
    for (int i = 1; i < n; i++){
       int value = arr[i];
       int index = i;
       while ((index > 0) && (arr[index - 1] > value)){
         arr[index] = arr[index - 1];
         index--;
       }
       arr[index] = value;
     }
    
    sortedArrayFile = fopen("sortedArray_Insertion.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(sortedArrayFile, "%d ", arr[i]);
    }
    fclose(sortedArrayFile);
}