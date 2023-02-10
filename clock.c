#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {

    while(1){

        time_t currentTime;
        time(&currentTime);
        struct tm *localTime = localtime(&currentTime);
        printf("Current time: %02d:%02d:%02d\r", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
        sleep(1);
    }
}
