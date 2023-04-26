#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
    long long int r;
    long long int h;
    long long int floor;
    long long int lateral;
    long long int s;
}Circle;

int ComByL(const void *p1, const void *p2){
    return ((*(Circle*)p1).lateral > (*(Circle*)p2).lateral)? -1: 1;
}

int ComByS(const void *p1, const void *p2){
    return ((*(Circle*)p1).s > (*(Circle*)p2).s)? -1: 1;
}

int ComByR(const void *p1, const void *p2){
    return ((*(Circle*)p1).r > (*(Circle*)p2).r)? -1: 1;
}

void exch(Circle *item, int i, int j){
    Circle temp = item[i];
    item[i] = item[j];
    item[j] = temp;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    Circle *circles = (Circle*)malloc(sizeof(Circle)*n);
    for (int i = 0; i != n; i++){
        scanf("%lld%lld", &circles[i].r, &circles[i].h);
        circles[i].floor = circles[i].r * circles[i].r;
        circles[i].lateral = circles[i].r * circles[i].h * 2;
        circles[i].s = circles[i].floor + circles[i].lateral;
    }
    qsort(circles, n, sizeof(circles[0]), ComByL);
    
    Circle *res = (Circle*)malloc(sizeof(Circle)*m);
    for (int i = 0; i != m; i++)
        res[i] = circles[i];
    
    qsort(circles + m, n - m, sizeof(circles[0]), ComByS);
    qsort(circles, m, sizeof(res[0]), ComByR);
    
    int index = 0;
    while(circles[m + index].s > circles[0].s){
        if (circles[m + index].r >= circles[0].r){
            exch(res, 0, m-1);
            res[0] = circles[m+index];
            break;
        }
        index++;
    }
    
    qsort(res, m, sizeof(res[0]), ComByR);
    long long int sum = res[0].s;
    for (int i = 1; i != m; i++)
        sum += res[i].lateral;
    printf("%lld\n", sum);
    free(res), free(circles);
    return 0;
}