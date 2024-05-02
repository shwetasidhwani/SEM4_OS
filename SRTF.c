#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5000

struct Process {
    char name[10];
    int at;
    int bt;
    int rt; // Remaining time
    int ct;
    int tat;
    int wt;
};

void swap(struct Process* a, struct Process* b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

int partition(struct Process arr[], int low, int high) {
    int pivot = arr[high].at;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].at < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(struct Process arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void calculateCompletionTime(struct Process processes[], int n) {
    // Sort processes based on arrival time
    quickSort(processes, 0, n - 1);

    // Calculate Completion Time
    int currentTime = 0;
    int completed = 0;
    while (completed < n) {
        int minRemainingTime = MAX;
        int shortestIndex = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].at <= currentTime && processes[i].rt < minRemainingTime && processes[i].rt > 0) {
                minRemainingTime = processes[i].rt;
                shortestIndex = i;
            }
        }

        if (shortestIndex == -1) {
            currentTime++;
        } else {
            processes[shortestIndex].rt--;
            currentTime++;

            if (processes[shortestIndex].rt == 0) {
                completed++;
                processes[shortestIndex].ct = currentTime;
            }
        }
    }
}

void calculateTurnAroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].tat = processes[i].ct - processes[i].at;
    }
}

void calculateWaitingTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].wt = processes[i].tat - processes[i].bt;
    }
}

int main() {
    int n;
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter name of process %d: ", i);
        scanf("%s", processes[i].name);
        printf("Enter arrival time of process %s: ", processes[i].name);
        scanf("%d", &processes[i].at);
        printf("Enter burst time of process %s: ", processes[i].name);
        scanf("%d", &processes[i].bt);
        processes[i].rt = processes[i].bt; 
    }

    calculateCompletionTime(processes, n);

    calculateTurnAroundTime(processes, n);

    calculateWaitingTime(processes, n);

    float avgTAT = 0, avgWT = 0;
    for (int i = 0; i < n; i++) {
        avgTAT += processes[i].tat;
        avgWT += processes[i].wt;
    }
    avgTAT /= n;
    avgWT /= n;
    printf("\nAverage TAT: %.2f", avgTAT);
    printf("\nAverage WT: %.2f", avgWT);

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", processes[i].name, processes[i].at, processes[i].bt, processes[i].ct,
               processes[i].tat, processes[i].wt);
    }

    return 0;
}
