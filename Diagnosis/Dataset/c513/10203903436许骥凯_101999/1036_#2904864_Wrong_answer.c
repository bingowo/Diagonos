#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define LL long long int 
#define ULL unsigned LL 

typedef struct{
    LL x, y;
    ULL dis;
}Point;

ULL init(LL x, LL y, LL x0, LL y0){
    ULL s1 = x - x0 > 0? x - x0: x0 - x;
    ULL s2 = y - y0 > 0? y - y0: y0 - y;
    return  s1 + s2;
}

ULL sigInit(LL x, LL x0){
    return init(x, 0ULL, x0, 0ULL);
}

int cmp(const void *p1, const void *p2){
    Point point1 = *(Point*)p1, point2 = *(Point*)p2;
    if (point1.dis == point2.dis){
        if (point1.x == point2.x)
            return point1.y > point2.y? 1: -1;
        return point1.x > point2.x? 1: -1;
    }
    return point1.dis > point2.dis? -1: 1;
}

void Input(Point* points, int n){
    for (int i = 0; i != n; i++){
        scanf("%lld %lld", &points[i].x, &points[i].y);
        points[i].dis = init(points[i].x, points[i].y, 0ULL, 0ULL);
    }
}

int calStep(Point * points, int n){
    int step = 0;
    for (int i = 0; i != n - 1; i++){
        ULL dx = sigInit(points[i].x, points[i+1].x);
        ULL dy = sigInit(points[i].y, points[i+1].y);
        ULL d = dx + dy;

        if (dx > d) printf("18446744073709551616\n");
        else printf("%llu\n", init(points[0].x, points[0].y, points[1].x, points[1].y));
        if (d == 0) continue;
        if(dx % 2 != dy % 2){
            if (dx >= (1ULL << 63) || dy >= (1ULL << 63)){step += 64; continue;}
            
            int flag = 0;
            if (dx == 0) flag++;
            if (dy == 0) flag++;

            int j = 1, st1 = 0, st2 = 0;
            while (flag != 2){
                if (dx >= (1ULL << j - 1) && dx < (1ULL << j)) {st1 = j; flag++;}
                if (dy >= (1ULL << j - 1) && dy < (1ULL << j)) {st2 = j; flag++;}
                j++;
            }
            step += st1 > st2? st1: st2;
            if (d >= (1ULL << j - 1)) step++;
        }
        else break;
    }
    return step;
}

int main(){
    int pro;
    scanf("%d", &pro);
    Point *points = (Point*)malloc(sizeof(Point) * pro);
    Input(points, pro);
    qsort(points, pro, sizeof(points[0]), cmp);
    printf("%d\n", calStep(points, pro));
    free(points);
}
