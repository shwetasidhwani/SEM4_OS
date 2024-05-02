#include<stdio.h>

#define MAX_PAGES 100
#define MAX_FRAMES 100

void printFrames(int frames[], int nf) {
    for (int i = 0; i < nf; i++) {
        printf("%d ", frames[i]);
    }
    printf("\n");
}

int isPageInFrames(int frames[], int nf, int page) {
    for (int i = 0; i < nf; i++) {
        if (frames[i] == page) {
            return 1;
        }
    }
    return 0;
}

int getLRUIndex(int frames[], int nf, int last_used[]) {
    int min_index = 0;
    for (int i = 1; i < nf; i++) {
        if (last_used[i] < last_used[min_index]) {
            min_index = i;
        }
    }
    return min_index;
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
    int frames[MAX_FRAMES];
    int last_used[MAX_FRAMES] = {0}; // Array to track the time of the last access for each frame
    int page_faults = 0;

    for (int i = 0; i < nf; i++) {
        frames[i] = -1; // Initialize all frames to -1 (empty)
    }

    for (int i = 0; i < npg; i++) {
        // Check if the page is already in frames
        if (isPageInFrames(frames, nf, pages[i])) {
            // Update the time of last access for the page
            for (int j = 0; j < nf; j++) {
                if (frames[j] == pages[i]) {
                    last_used[j] = i;
                    break;
                }
            }
        }
    }
}