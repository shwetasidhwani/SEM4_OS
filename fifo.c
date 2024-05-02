#include<stdio.h>

#define MAX_PAGES 100
#define MAX_FRAMES 100

int rear = -1;
int front = -1;

void enqueue(int arr[], int num, int nf) {
    rear = (rear + 1) % nf;
    arr[rear] = num;
    if (front == -1) {
        front = 0;
    }
}

void dequeue(int arr[], int nf) {
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % nf;
    }
}

int isFull(int nf) {
    return ((rear + 1) % nf == front);
}

int isEmpty() {
    return (front == -1);
}

void printQueue(int arr[], int nf) {
    int i;
    for (i = front; i != rear; i = (i + 1) % nf) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[i]);
}

int main() {
    int npg, nf;
    printf("Enter the number of pages: ");
    scanf("%d", &npg);
    int pages[MAX_PAGES];
    printf("Enter all the pages: ");
    for (int i = 0; i < npg; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter frame size: ");
    scanf("%d", &nf);
    int frame[MAX_FRAMES];
    int hit = 0;

    for (int i = 0; i < nf; i++) {
        frame[i] = -1; // Initialize all frames to -1 (empty)
    }

    for (int i = 0; i < npg; i++) {
        int page_fault = 1; // Assume page fault
        for (int j = 0; j < nf; j++) {
            if (frame[j] == pages[i]) {
                page_fault = 0; // Page hit
                hit++;
                break;
            }
        }
        if (page_fault) {
            if (isFull(nf)) {
                dequeue(frame, nf);
            }
            enqueue(frame, pages[i], nf);
        }
    }
    printf("\nThe number of page hits: %d\n", hit);
    printf("The number of page faults: %d\n", npg - hit);
    printf("Contents of the frame: ");
    printQueue(frame, nf);

    return 0;
}
