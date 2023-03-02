#include <stdbool.h>
#include "timeFunctions.h"

time_t start, end, paused, unpaused, dateTime;
struct tm* timeInfo;
bool isStarted, isPaused;
char buffer[80];
char str[30];
float losttime = 0;
float stopWatchTimer;


char* getTimeAndDate()
{
    time(&dateTime);
    timeInfo = localtime(&dateTime);
    strftime(buffer, 80, "%I:%M%p", timeInfo);
    return buffer;
}

void stopWatchStart()
{
    if(isStarted == false) {
        start = time(NULL);
        end = time(NULL);
        stopWatchTimer = 0;
        isStarted = true;
    }
}

void stopWatchPause()
{
    if(isPaused == false) {
        isPaused = true;
        paused = time(NULL);
    }
}

void stopWatchUnpause()
{
    if(isPaused == true) {
        isPaused = false;
        unpaused = time(NULL);
        losttime += difftime(unpaused, paused);
    }
}

void stopWatchStop()
{
    if(isStarted == true) {
        isStarted = false;
        isPaused = false;
        end = time(NULL);
    }
}

char* stopWatchUpdate()
{
    if ((isStarted)&& !(isPaused)) {
        end = time(NULL);
    }
    stopWatchTimer = difftime(end, start) - losttime;
    sprintf(str, "%.2f", stopWatchTimer);
    return str;
}