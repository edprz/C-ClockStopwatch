#include <stdio.h>
#define MAXSIZE 100

void bubbleSort(int arr[], int size) {
    int i, j, n, temp;
    
    for(i = 0; i < size - 1; i++) {
        for(j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void wArrTXT(char *filename){
    int i, size;

    FILE *dataFile;
    dataFile = fopen(filename, "w");

    if(dataFile == NULL){
        printf("Unable to create or open file.\n");
    } else{
        printf("File opened succesfully.\n");
    }

    printf("\nHow many numbers do you want to enter into the array?\n");
    scanf("%d", &size);
    int arr[size];

    for(i = 0; i < size; i++){
        printf("\nEnter number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < size; i++){
        fprintf(dataFile, "%d ", arr[i]);
    }

    fclose(dataFile);

}

void rArrTXT(char *filename){
    int i = 0, size;
    char option;

    FILE *dataFile;
    dataFile = fopen(filename, "r+");

    if(dataFile == NULL ){
        printf("Unable to open file.\n");
    } else{
        printf("File opened succesfully.\n");
    }

    int arr[MAXSIZE];
    
    while(fscanf(dataFile, "%d", &arr[i]) != EOF){
        i++;
    }

    size = i;

    bubbleSort(arr, size);

    fprintf(dataFile, "\n");

    for(i = 0; i < size; i++){
        fprintf(dataFile, "%d ", arr[i]);
    }

    printf("Sorted array has been added to 'data.txt'.\n");
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    fclose(dataFile);

}

void apArrTXT(char *filename){
    int i, size;

    FILE *dataFile;
    dataFile = fopen(filename, "a");

    if(dataFile == NULL ){
        printf("Unable to open file.\n");
    } else{
        printf("File opened succesfully.\n");
    }

    printf("\nHow many numbers do you want to append into 'data.txt'?\n");
    scanf("%d", &size);
    int arr[size];

    for(i = 0; i < size; i++){
        printf("\nEnter number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < size; i++){
        fprintf(dataFile, "%d ", arr[i]);
    }

    fclose(dataFile);

}

int main(){
    int option;
    char *filename = "data.txt";

    printf("Welcome to file management\nPlease select an option:\n");
    printf("\n1) Write an array into 'data.txt'.\n2) Read an array from 'data.txt' and sort it using bubble sort.\n3) Append numbers into the array in 'data.txt'.\n");
    scanf("%d", &option);

    switch(option){
        case 1:
            wArrTXT(filename);
            break;
        case 2:
            rArrTXT(filename);
            break;
        case 3:
            apArrTXT(filename);
            break;
        default:
            printf("\nInvalid option.\n");
    }
    /*WIP, have to add mode to append and mode to sort the contents directly into the txt file not console*/
}