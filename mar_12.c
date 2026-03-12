#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_HOPS 10

// Function to simulate delay
void simulateDelay() {
    int delay = rand() % 100 + 1; // delay between 1–100 ms
    printf("Reply received in %d ms\n", delay);
}

// Function to simulate Ping
void simulatePing(char destination[]) {
    printf("\n--- PING Simulation ---\n");

    for(int i = 1; i <= 4; i++) {
        printf("Sending packet %d to %s...\n", i, destination);
        simulateDelay();
    }

    printf("\nPing statistics for %s:\n", destination);
    printf("Packets: Sent = 4, Received = 4, Lost = 0 (0%% loss)\n");
}

// Function to simulate Traceroute
void simulateTraceroute(char destination[]) {
    printf("\n--- TRACEROUTE Simulation ---\n");

    for(int hop = 1; hop <= MAX_HOPS; hop++) {
        int delay = rand() % 100 + 1;

        printf("Hop %d -> Router_%d ", hop, hop);
        printf("Delay = %d ms\n", delay);

        // Assume destination reached at random hop
        if(rand() % 5 == 0) {
            printf("Destination %s reached at hop %d\n", destination, hop);
            break;
        }
    }
}

int main() {
    char destination[100];
    int choice;

    srand(time(NULL));

    printf("Enter destination host (example: google.com): ");
    scanf("%s", destination);

    printf("\n1. Simulate Ping\n");
    printf("2. Simulate Traceroute\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            simulatePing(destination);
            break;

        case 2:
            simulateTraceroute(destination);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}
