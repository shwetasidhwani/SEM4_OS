
#include <stdio.h>
#include <stdlib.h>

struct Process {
    char name[10];
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

void swap(struct Process* a, struct Process* b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

int partition(struct Process arr[], int low, int high, int sortBy) {
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

void quickSort(struct Process arr[], int low, int high, int sortBy) {
    if (low < high) {
        int pi = partition(arr, low, high, sortBy);
        quickSort(arr, low, pi - 1, sortBy);
        quickSort(arr, pi + 1, high, sortBy);
    }
}

void calculateCompletionTime(struct Process processes[], int n) {
    // Sort processes based on arrival time
    quickSort(processes, 0, n - 1, 0);

    // Calculate Completion Time
    int completionTime = 0;
    for (int i = 0; i < n; i++) {
        completionTime += processes[i].bt;
        processes[i].ct = completionTime;
    }
}

void calculateTurnAroundTime(struct Process processes[], int n) {
    // Calculate Turn Around Time
    for (int i = 0; i < n; i++) {
        processes[i].tat = processes[i].ct - processes[i].at;
    }
}

void calculateWaitingTime(struct Process processes[], int n) {
    // Calculate Waiting Time
    for (int i = 0; i < n; i++) {
        processes[i].wt = processes[i].tat - processes[i].bt;
    }
}

int main() {
    int n;
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];

    // Input process names, arrival time, and burst time
    for (int i = 0; i < n; i++) {
        printf("\nEnter name of process %d: ", i);
        scanf("%s", processes[i].name);
        printf("Enter arrival time of process %s: ", processes[i].name);
        scanf("%d", &processes[i].at);
        printf("Enter burst time of process %s: ", processes[i].name);
        scanf("%d", &processes[i].bt);
    }

    // Calculate Completion Time
    calculateCompletionTime(processes, n);

    // Calculate Turn Around Time
    calculateTurnAroundTime(processes, n);

    // Calculate Waiting Time
    calculateWaitingTime(processes, n);

    // Calculate and display the average TAT and WT
    float avgTAT = 0, avgWT = 0;
    for (int i = 0; i < n; i++) {
        avgTAT += processes[i].tat;
        avgWT += processes[i].wt;
    }
    avgTAT /= n;
    avgWT /= n;
    printf("\nAverage TAT: %.2f", avgTAT);
    printf("\nAverage WT: %.2f", avgWT);

    // Display the table
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", processes[i].name, processes[i].at, processes[i].bt, processes[i].ct,
               processes[i].tat, processes[i].wt);
    }

    return 0;
}
