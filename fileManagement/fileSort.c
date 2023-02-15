#include <stdio.h>

void wArrTXT(char *filename){
    int i, size;

    FILE *dataFile;
    dataFile = fopen(filename, "w");

    if(dataFile == NULL){
        printf("Unable to create or open file\n");
    } else{
        printf("File opened succesfully\n");
    }

    printf("\nHow many numbers do you want to enter into the array?\n");
    scanf("%d", &size);
    int arr[size];

    for(i = 0; i < size; i++){
        printf("\nEnter number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < size; i++) {
        fprintf(dataFile, "%d ", arr[i]);
    }
    fclose(dataFile);

}

int main(){
    int option;
    char *filename = "data.txt";

    printf("Welcome to file management\nPlease select an option:\n");
    printf("\n1) Write an array into the 'data.txt' document.\n");
    scanf("%d", &option);

    switch(option){
        case 1:
            wArrTXT(filename);
            break;
        default:
            printf("\nInvatlid option\n");
    }
    /*WIP, have to add mode to read the contents of txt file,
    append and mode to sort the contents using a sorting algorithm*/
}