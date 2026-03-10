#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point;

Point p1 = {1,3};
Point p2 = {5,2};
Point p3 =  {2,6};

int main()
{
    Point puntos[] = {p1, p2, p3};
    int n = 3;
    FILE* f = fopen("puntos.bin", "wb");
    size_t escritos = fwrite(puntos, sizeof(Point), n, f);
    fclose(f);

    return 0;
}
//