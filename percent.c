#include <stdio.h>
void percentage(int arr[], float percentage[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (percentage[j] < percentage[j + 1]) {
                float tempPercentage = percentage[j];
                percentage[j] = percentage[j + 1];
                percentage[j + 1] = tempPercentage;
                int tempRoll = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tempRoll;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    int rollNumbers[n];
    float percentages[n];

    for (int i = 0; i < n; i++) {
        printf("Enter Roll Number for student %d: ", i + 1);
        scanf("%d", &rollNumbers[i]);

        printf("Enter Percentage for student %d: ", i + 1);
        scanf("%f", &percentages[i]);
    }
    percentage(rollNumbers, percentages, n);

    printf("\nRoll Number\tPercentage\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%.2f\n", rollNumbers[i], percentages[i]);
    }

    return 0;
}

