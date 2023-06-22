#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time getTime();
void printTime(struct Time time);
struct Time calculateDifference(struct Time start, struct Time end);

int main() {
    struct Time startTime, endTime, difference;

    printf("Enter the start time:\n");
    startTime = getTime();

    printf("Enter the end time:\n");
    endTime = getTime();

    difference = calculateDifference(startTime, endTime);

    printf("Difference between the two time periods:\n");
    printTime(difference);

    return 0;
}

struct Time getTime() {
    struct Time time;

    printf("Enter hours: ");
    scanf("%d", &time.hours);

    printf("Enter minutes: ");
    scanf("%d", &time.minutes);

    printf("Enter seconds: ");
    scanf("%d", &time.seconds);

    return time;
}

void printTime(struct Time time) {
    printf("%02d:%02d:%02d\n", time.hours, time.minutes, time.seconds);
}

struct Time calculateDifference(struct Time start, struct Time end) {
    struct Time difference;

    int startTotalSeconds = start.hours * 3600 + start.minutes * 60 + start.seconds;
    int endTotalSeconds = end.hours * 3600 + end.minutes * 60 + end.seconds;
    int totalSeconds = endTotalSeconds - startTotalSeconds;

    difference.hours = totalSeconds / 3600;
    totalSeconds %= 3600;

    difference.minutes = totalSeconds / 60;
    totalSeconds %= 60;

    difference.seconds = totalSeconds;

    return difference;
}

