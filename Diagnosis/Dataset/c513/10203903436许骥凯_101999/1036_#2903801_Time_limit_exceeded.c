#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ll long long int
#define ull unsigned ll

typedef struct{
    ll x, y;
    ull dis;
}Mht;

ull Init(ll x1, ll y1, ll x2, ll y2){
    return llabs(x1 - x2) + llabs(y1 - y2);
}


int cmp(const void *p1, const void *p2){
    Mht m1 = *(Mht*)p1, m2 = *(Mht*)p2;
    return (m1.dis > m2.dis)? -1: 1;
}

int calStep(Mht*points, int n){
    int step = 0;
    for (int i = 1; i != n; i++){
        ll x0 = points[i-1].x, y0 = points[i-1].y;
        ull d = Init(points[i].x, x0, points[i].y, y0);
        ull dx = llabs(points[i].x - x0), dy = llabs(points[i].y - y0);

        if (d % 2){
            int s1 = 0, s2 = 0, flag = 0, j = 1;
            while(flag != 2){
                if (dx >= pow(j-1, 2) && dx < pow(j, 2)) {s1 = j, flag++;}
                if (dy >= pow(j-1, 2) && dy < pow(j, 2)) {s2 = j, flag++;}
                j++;
            }
            step += (s1 > s2)? s1: s2;
            if (s1 == s2) step++;
        }
        else {step = 0; break;}

    }
    return step;
}


int main(){
    int pro;
    scanf("%d", &pro);
    Mht* points = (Mht*)malloc(sizeof(Mht) * pro);
    for (int i = 0; i != pro; i++){
        scanf("%lld %lld", &points[i].x, &points[i].y);
        points[i].dis = Init(points[i].x, points[i].y, 0, 0);
    }
    qsort(points, pro, sizeof(points[0]), cmp);

    printf("%lld\n", Init(points[0].x, points[0].y, points[1].x, points[1].y));
    printf("%d\n", calStep(points, pro));
    free(points);
    return 0;
}
