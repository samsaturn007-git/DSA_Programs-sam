
#include <stdio.h>


struct time_struct {
    int hour;
    int minute;
    int second;
};


void inputTime(struct time_struct *time) {
    printf("Enter hour: ");
    scanf("%d", &time->hour);
    printf("Enter minute: ");
    scanf("%d", &time->minute);
    printf("Enter second: ");
    scanf("%d", &time->second);
}


void displayTime(struct time_struct time) {
    printf("Time: %02d:%02d:%02d\\n", time.hour, time.minute, time.second);
}


void updateTime(struct time_struct *time) {
    time->second++;

    if (time->second == 60) {
        time->second = 0;
        time->minute++;

        if (time->minute == 60) {
            time->minute = 0;
            time->hour++;

            if (time->hour == 24) {
                time->hour = 0;
            }
        }
    }
}

int main() {
    struct time_struct currentTime;

    printf("Input new time:\n");
    inputTime(&currentTime);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Display time\n");
        printf("2. Update time by one second\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
\
        switch (choice) {
            case 1:
                displayTime(currentTime);
                break;
            case 2:
                updateTime(&currentTime);
                printf("Time updated by one second.\n");
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}
