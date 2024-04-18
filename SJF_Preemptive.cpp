#include <stdio.h>
int main() {
    int at[10], bt[10], rt[10], endTime, i, smallest;
    int remain = 0, n, time, sum_wait = 0, sum_turnaround = 0;
    printf("Enter number of Processes: ");
    scanf("%d", &n);
    printf("Enter Arrival times:\n");
    for (i = 0; i < n; i++) {
        printf("AT(%d): ", i + 1);
        scanf("%d", &at[i]);
    }
    printf("Enter Burst times:\n");
    for (i = 0; i < n; i++) {
        printf("BT(%d): ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
    rt[9] = 9999;
    printf("\nProcess\tTurnaround Time\tWaiting Time\n");
    for (time = 0; remain != n; time++) {
        smallest = 9;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0) {
                smallest = i;
            }
        }
        rt[smallest]--;
        if (rt[smallest] == 0) {
            remain++;
            endTime = time + 1;
            printf("P%d\t%d\t\t%d\n", smallest + 1, endTime - at[smallest], endTime -bt[smallest] - at[smallest]);
            sum_wait += endTime - bt[smallest] - at[smallest];
            sum_turnaround += endTime - at[smallest];
        }
    }
    printf("\nAverage waiting time = %.2f\n", (float)sum_wait / n);
    printf("Average Turnaround time = %.2f\n", (float)sum_turnaround / n);
    return 0;
}
