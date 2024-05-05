// Add brief description here

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMROWS	 9    // map size
#define NUMCOLS  9    // map size
#define NUMWALKS 1000 // number of random walks
#define NUMSTEP  10   // number of steps in each walk

#define INPUT_FILE_NAME "island_map.txt"

char MAP[NUMROWS][NUMCOLS] = { 0 }; // 2D array to store the map
double Probability[NUMROWS][NUMCOLS] = { 0 }; // Probability of escaping from each cell
double MeanPath[NUMROWS][NUMCOLS] = { 0 }; // Mean path length from each cell
double StandardDeviation[NUMROWS][NUMCOLS] = { 0 }; // Standard deviation of path length from each cell

// Function to load the map from file
void load_map() {
    FILE* fp = NULL;
    char ch;
    int read_cnt;
    fp = fopen(INPUT_FILE_NAME, "rt");
    if (!fp) {
        printf("Error!");
        exit(0);
        return;
    }
    for (int i = 0; i < NUMROWS; i++) {
        for (int j = 0; j < NUMCOLS; j++) {
            read_cnt = fscanf(fp, "%c ", &ch);
            if (read_cnt != 1 || (ch != 'W' && ch != 'L' && ch != 'B' && ch != 'D' && ch != 'V')) {
                fclose(fp);
                printf("Error!");
                exit(0);
            }
            MAP[i][j] = ch;
        }
    }
    fclose(fp);
}

// Function to print the loaded map
void print_map() {
    printf("Map:\n");
    for (int i = 0; i < NUMROWS; i++) {
        for (int j = 0; j < NUMCOLS; j++) {
            printf("%c", MAP[i][j]);
            if (j == NUMCOLS - 1) {
                printf("\n");
            }
            else {
                printf(" ");
            }
        }
    }
}

// Function to print the results
void print_results() {
    printf("\nProbability of escape:\n");
    for (int i = 0; i < NUMROWS; i++) {
        for (int j = 0; j < NUMCOLS; j++) {
            printf("%.2lf", Probability[i][j]);
            if (j == NUMCOLS - 1) {
                printf("\n");
            }
            else {
                printf(" ");
            }
        }
    }

    printf("\nMean path length:\n");
    for (int i = 0; i < NUMROWS; i++) {
        for (int j = 0; j < NUMCOLS; j++) {
            printf("%.2lf", MeanPath[i][j]);
            if (j == NUMCOLS - 1) {
                printf("\n");
            }
            else {
                printf(" ");
            }
        }
    }

    printf("\nStandard deviation of path length:\n");
    for (int i = 0; i < NUMROWS; i++) {
        for (int j = 0; j < NUMCOLS; j++) {
            printf("%.2lf", StandardDeviation[i][j]);
            if (j == NUMCOLS - 1) {
                printf("\n");
            }
            else {
                printf(" ");
            }
        }
    }
}

// Function to attempt a move based on a random step
void try_move(int* i, int* j, int random_step) {
    switch (random_step) {
    default:
        break;
        return;
    case 0:
        if ((*i) - 1 >= 0) {
            *i = (*i) - 1;
        }
        break;
    case 1:
        if ((*i) - 1 >= 0) {
            *i = (*i) - 1;
        }
        if ((*j) + 1 < NUMROWS) {
            *j = (*j) + 1;
        }
        break;
    case 2:
        if ((*j) + 1 < NUMROWS) {
            *j = (*j) + 1;
        }
        break;
    case 3:
        if ((*i) + 1 < NUMROWS) {
            *i = (*i) + 1;
        }
        if ((*j) + 1 < NUMROWS) {
            *j = (*j) + 1;
        }
        break;
    case 4:
        if ((*i) + 1 < NUMROWS) {
            *i = (*i) + 1;
        }
        break;
    case 5:
        if ((*i) + 1 < NUMROWS) {
            *i = (*i) + 1;
        }
        if ((*j) - 1 >= 0) {
            *j = (*j) - 1;
        }
        break;
    case 6:
        if ((*j) - 1 >= 0) {
            *j = (*j) - 1;
        }
        break;
    case 7:
        if ((*i) - 1 >= 0) {
            *i = (*i) - 1;
        }
        if ((*j) - 1 >= 0) {
            *j = (*j) - 1;
        }
        break;
    }
}

// Function to perform a random walk
int perform_random_walks(int i, int j, int steps) {
    if (MAP[i][j] == 'B') {
        return steps;
    }
    if (steps >= NUMSTEP) {
        return -1;
    }
    if (MAP[i][j] == 'L') {
        int random_step = rand() % 8;
        try_move(&i, &j, random_step);
        return perform_random_walks(i, j, steps + 1);
    }
    return -1;
}

// Function to calculate standard deviation
double calcu_standard_deviation(double* arr, double mean_value, int length) {
    if (length == 0) {
        return 0;
    }
    double std_value = 0;
    for (int i = 0; i < length; i++) {
        std_value += pow(mean_value - arr[i], 2);
    }
    return sqrt(std_value / length);
}

// Main function
int main(void) {
    srand(123456);
    double steps_length;
    // Load the map
    load_map();
    print_map();

    // Perform random walks and calculate results
    for (int i = 0; i < NUMROWS; i++) {
        for (int j = 0; j < NUMCOLS; j++) {
            double sum_length = 0;
            double path_length[NUMWALKS] = { 0 };
            int n = 0;
            for (int walk = 0; walk < NUMWALKS; walk++) {
                steps_length = perform_random_walks(i, j, 0);
                if (steps_length >= 0) {
                    path_length[n++] = steps_length;
                    sum_length += steps_length;
                }
            }
            if (n > 0) {
                MeanPath[i][j] = sum_length / n;
            }
            StandardDeviation[i][j] = calcu_standard_deviation(path_length, MeanPath[i][j], n);
            Probability[i][j] = 100.0 * n / NUMWALKS;
        }
    }

    // Print results
    print_results();

    return 0;
}
