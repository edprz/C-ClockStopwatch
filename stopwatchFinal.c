#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>

int main() {
    time_t startTime, currentTime, pausedTime;
    time(&startTime);
    int elapsedTime = 0, key, stop=0;

    printf("Press 's' key to start the stopwatch\n");
    char c = getch();

    if(c == 's') {
	    time(&startTime);
    } else {
	    printf("Invalid option.");
        return 1;
    }   

    printf("Press 'p' key to pause the stopwatch\n");
    printf("Press 'r' key to resume the stopwatch\n");
    printf("Press 's' key to stop the stopwatch\n");

    while (stop == 0) {

        time(&currentTime);
        int elapsedTime = (int) difftime(currentTime, startTime);
        int hours = elapsedTime / 3600;
        int minutes = (elapsedTime % 3600) / 60;
        int seconds = elapsedTime % 60;

        printf("Elapsed time: %02d:%02d:%02d\r", hours, minutes, seconds);
        sleep(1);

        if (_kbhit()){
            key = _getch(); //watches for keypress
            if (key == 'p'){
                time(&pausedTime);
                printf("\nStopwatch Paused\n");
                while (key != 'r'){
                    if (_kbhit()){
                        key = _getch();
                    }
                }
                startTime = startTime + (time(NULL) - pausedTime);
                printf("Stopwatch Resumed\n");
            }
            else if (key == 's'){
                stop = 1;
                printf("\nYou pressed stop\n");
            }
        }
    }
    return 0;
}