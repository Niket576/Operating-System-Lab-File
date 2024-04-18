#include <stdio.h>
int main() {
    int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, pos, temp, flag;
    float awt, atat;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1; // Contains process IDs
    }
    // Sort burst time in ascending order with bubble sort
    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < n - 1; j++) {
            if (bt[j + 1] < bt[j]) {
                flag = 1;
                // Swap burst time
                temp = bt[j + 1];
                bt[j + 1] = bt[j];
                bt[j] = temp;
                // Swap process IDs
                temp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = temp;
            }
        }
        if (flag == 0) break;
    }
    wt[0] = 0; // Waiting time for the first process will be zero
    // Calculate waiting time
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
        total += wt[i];
    }
    awt = (float)total / n;
    total = 0;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    atat = (float)total / n;
    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", atat);
    return 0;
}
