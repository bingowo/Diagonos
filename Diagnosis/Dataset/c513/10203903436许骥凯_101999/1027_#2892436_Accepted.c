#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
    double x, y;
}Point;

int compare(const void *p1, const void *p2){
    Point point1 = *(Point*)p1, point2 = *(Point*)p2;
    if (fabs(point1.y - point2.y) < 1e-10) return (point2.x > point1.x)? 1: -1;
    return (point1.y > point2.y)? 1: -1;
}

void output(Point* points, int len, int times){
    printf("case #%d:\n", times);
    for (int i = 0; i != len; i++)
        printf("(%.4f,%.4f)\n", points[i].x, points[i].y);
    free(points);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; i++){
        int pairs;
        scanf("%d", &pairs);
        Point *points = (Point*)malloc(sizeof(Point)*pairs); 
        for (int j = 0; j != pairs; j++){
            double x, y;
            scanf("%lf %lf", &x, &y);
            points[j].x = fabs(sqrt(pow(x, 2) + pow(y, 2)));
            points[j].y = atan(y / x);
            if (x < 0) points[j].y = acos(-1.0) + points[j].y;
            else if (y < 0) points[j].y = 2 * acos(-1.0) + points[j].y; 
        }
        qsort(points, pairs, sizeof(points[0]), compare);
        output(points, pairs, i);
    }
    return 0;
}