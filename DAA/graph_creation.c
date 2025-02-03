#include <stdio.h>
#include <stdlib.h>

int count(int** arr, int n) {
    int edgeCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", arr[i][j]);
            if (arr[i][j] == 1) {
                edgeCount++;
            }
        }
        printf("\n");
    }
    return edgeCount / 2;
}

int** read2(int n) {
    int** adjMat = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        adjMat[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            adjMat[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        int choice = 0;
        printf("Enter the adjacent nodes of vertex %d and -1 to stop: ", i);
        while (1) {
            scanf("%d", &choice);
            if (choice == -1) {
                break;
            }
            if (choice >= 0 && choice < n) {
                adjMat[i][choice] = 1;
            } else {
                printf("Invalid adjacent node. Enter a valid node between 0 and %d.\n", n - 1);
            }
        }
    }

    printf("Adjacency matrix of your graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", adjMat[i][j]);
        }
        printf("\n");
    }
    return adjMat;
}

int main() {
    int n;
    printf("Enter the number of nodes in your graph: ");
    scanf("%d", &n);
    int** mat = read2(n);
    int result = count(mat, n);
    printf("\nTotal edges in the graph: %d\n");

    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
    return 0;
}