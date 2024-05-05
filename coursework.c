// Add brief description here

#include <stdio.h>
// Enter any other #includes that you deem necessary below
#include <stdlib.h>
#include <math.h>

#define NUMROWS	 9    // map size
#define NUMCOLS  9    // map size
#define NUMWALKS 1000 // number of random walks
#define NUMSTEP  10   // number of steps in each walk
// Enter any other #defines as you deem necessary below

#define INPUT_FILE_NAME "island_map.txt"

char MAP[NUMROWS][NUMCOLS] = { 0 };
double Probability[NUMROWS][NUMCOLS] = { 0 };
double MeanPath[NUMROWS][NUMCOLS] = { 0 };
double StandardDeviation[NUMROWS][NUMCOLS] = { 0 };

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
            for (int walk = 0; walk < NUMWALKS; walk++) {
                steps_length = perform_random_walks(i, j, 0);
                if (steps_length >= 0) {
                    Probability[i][j] += 1;
                    path_length[walk] = steps_length;
                    sum_length += steps_length;
                }
            }
            if (Probability[i][j] > 0) {
                MeanPath[i][j] = sum_length / Probability[i][j];
            }
            double top = 0;
            for (int walk = 0; walk < NUMWALKS; walk++) {
                top += (MeanPath[i][j] - path_length[walk]) * (MeanPath[i][j] - path_length[walk]);
            }
            StandardDeviation[i][j] = sqrt(top / NUMWALKS);
            Probability[i][j] = 100.0 * Probability[i][j] / NUMWALKS;
        }
    }

    // Print results
    print_results();

    return 0;
}
