#include <stdio.h>
#include <stdlib.h>

// Structure to store car details
typedef struct {
    int position;
    double time;
} Car;

// Comparator function to sort cars by position in descending order
int compareCars(const void *a, const void *b) {
    return ((Car *)b)->position - ((Car *)a)->position;
}

// Function to calculate the number of car fleets
int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    if (positionSize == 0) return 0;

    // Allocate memory for the cars array
    Car *cars = (Car *)malloc(positionSize * sizeof(Car));
    
    // Calculate time to reach target for each car
    for (int i = 0; i < positionSize; i++) {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // Sort cars by starting position in descending order
    qsort(cars, positionSize, sizeof(Car), compareCars);

    int fleets = 0;
    double maxTime = 0.0;

    // Traverse cars from closest to furthest from target
    for (int i = 0; i < positionSize; i++) {
        // If current car takes longer than the fleet leader ahead, it forms a new fleet
        if (cars[i].time > maxTime) {
            fleets++;
            maxTime = cars[i].time; // Update current fleet leader's time
        }
    }

    free(cars);
    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int size = sizeof(position) / sizeof(position[0]);

    int result = carFleet(target, position, size, speed, size);
    printf("Number of car fleets: %d\n", result);

    return 0;
}
