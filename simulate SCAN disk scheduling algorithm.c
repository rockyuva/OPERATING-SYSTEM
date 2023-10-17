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

// Function to simulate the SCAN disk scheduling algorithm
void scanDisk(int tracks[], int n, int start, int direction) {
    int seekSequence[MAX_TRACKS];
    int seekCount = 0;
    int currentTrack = start;
    int maxTrack = MAX_TRACKS - 1;
    
    sort(tracks, n); // Sort the tracks in ascending order
    
    if (direction == 1) {
        // Move towards higher track numbers
        for (int i = currentTrack; i <= maxTrack; i++) {
            for (int j = 0; j < n; j++) {
                if (tracks[j] == i) {
                    seekSequence[seekCount++] = i;
                    currentTrack = i;
                }
            }
        }

        // Continue in the same direction until the end
        for (int i = maxTrack; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (tracks[j] == i) {
                    seekSequence[seekCount++] = i;
                    currentTrack = i;
                }
            }
        }
    } else {
        // Move towards lower track numbers
        for (int i = currentTrack; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (tracks[j] == i) {
                    seekSequence[seekCount++] = i;
                    currentTrack = i;
                }
            }
        }

        // Continue in the same direction until the beginning
        for (int i = 0; i <= maxTrack; i++) {
            for (int j = 0; j < n; j++) {
                if (tracks[j] == i) {
                    seekSequence[seekCount++] = i;
                    currentTrack = i;
                }
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
    int n, start, direction;

    // Input the number of tracks
    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    // Input the tracks
    printf("Enter the track positions: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tracks[i]);
    }

    // Input the initial position of the disk arm
    printf("Enter the initial position of the disk arm: ");
    scanf("%d", &start);

    // Input the direction (1 for towards higher track numbers, -1 for lower track numbers)
    printf("Enter the direction (1 for towards higher track numbers, -1 for lower track numbers): ");
    scanf("%d", &direction);

    // Simulate the SCAN disk scheduling algorithm
    scanDisk(tracks, n, start, direction);

    return 0;
}

