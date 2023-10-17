#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of tracks on the disk
#define MAX_TRACKS 200

// Function to sort an array of integers in ascending order
void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to simulate the C-SCAN disk scheduling algorithm
void cscanDisk(int tracks[], int n, int start) {
    int seekSequence[MAX_TRACKS];
    int seekCount = 0;
    int currentTrack = start;
    
    sort(tracks, n); // Sort the tracks in ascending order

    // Move towards higher track numbers
    for (int i = currentTrack; i <= MAX_TRACKS; i++) {
        for (int j = 0; j < n; j++) {
            if (tracks[j] == i) {
                seekSequence[seekCount++] = i;
                currentTrack = i;
            }
        }
    }

    // Move to the beginning of the disk and continue in the same direction
    for (int i = 0; i <= currentTrack; i++) {
        for (int j = 0; j < n; j++) {
            if (tracks[j] == i) {
                seekSequence[seekCount++] = i;
                currentTrack = i;
            }
        }
    }

    // Display the seek sequence
    printf("Seek Sequence: ");
    for (int i = 0; i < seekCount; i++) {
        printf("%d ", seekSequence[i]);
    }
    printf("\n");

    printf("Total seek operations: %d\n", seekCount);
}

int main() {
    int tracks[MAX_TRACKS];
    int n, start;

    // Input the number of tracks
    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    // Input the track positions
    printf("Enter the track positions: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tracks[i]);
    }

    // Input the initial position of the disk arm
    printf("Enter the initial position of the disk arm: ");
    scanf("%d", &start);

    // Simulate the C-SCAN disk scheduling algorithm
    cscanDisk(tracks, n, start);

    return 0;
}

