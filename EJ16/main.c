#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

int main() {

    Point (*array)[4][3] = malloc(5 * sizeof(*array));

    array[2][3][1].x = 3;
    array[2][3][1].y = 4;

    printf("array[2][3][1] = (%d, %d)\n", array[2][3][1].x, array[2][3][1].y);

    free(array);

    return 0;
}

