#include <stdbool.h>
#include "timeFunctions.h"

time_t start, end, pause, unpause, stopWatchTimer, dateTime;
struct tm* timeInfo;
bool isStarted, isPaused;
char buffer[80];
char str[30];
float losttime = 0;

char* getTimeAndDate()
{
    time(&dateTime);
    timeInfo = localtime(&dateTime);
    strftime(buffer, 80, "%I:%M%p", timeInfo);
    return buffer;

}

int stopWatchStart()
{
    if(isStarted == false)
    {
        start = time(NULL);
        isStarted = true;
    }
    return 0;
}

int stopWatchPause()
{
    if(isPaused == false)
    {
        isPaused = true;
        pause = time(NULL);
    }
    return 0;
}

int stopWatchUnpause()
{
    if(isPaused == true)
    {
        isPaused = false;
        unpause = time(NULL);
        losttime += difftime(unpause, pause);
    }
    return 0;
}

int stopWatchEnd()
{
    if(isStarted == true)
    {
        isStarted = false;
        isPaused = false;
        losttime = 0;
    }
    return 0;
}

char* stopWatchUpdate()
{
    if(isStarted && !isPaused)
        end = time(NULL);
    stopWatchTimer = difftime(end, start) - losttime;
    sprintf(str, "%.2fs", stopWatchTimer);
    printf("%s", str);
}