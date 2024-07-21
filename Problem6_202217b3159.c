#include <stdio.h>

int main() {
    int n, a[10], b[10], t[10], w[10], g[10], i;
    float att = 0, awt = 0;

    // Clear screen is optional, and not using conio.h for compatibility
    // printf("\033[H\033[J");

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    printf("Enter the arrival times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Calculate the completion time
    g[0] = a[0] + b[0];
    for (i = 1; i < n; i++) {
        if (a[i] <= g[i - 1]) {
            g[i] = g[i - 1] + b[i];
        } else {
            g[i] = a[i] + b[i];
        }
    }

    // Calculate waiting time and turnaround time
    for (i = 0; i < n; i++) {
        w[i] = g[i] - a[i] - b[i];
        t[i] = g[i] - a[i];
        awt += w[i];
        att += t[i];
    }

    awt = awt / n;
    att = att / n;

    printf("\n\tProcess\tWaiting Time\tTurn Around Time\n");
    for (i = 0; i < n; i++) {
        printf("\tp%d\t\t%d\t\t%d\n", i, w[i], t[i]);
    }

    printf("The average waiting time is %.6f\n", awt);
    printf("The average turn around time is %.6f\n", att);

    return 0;
}
