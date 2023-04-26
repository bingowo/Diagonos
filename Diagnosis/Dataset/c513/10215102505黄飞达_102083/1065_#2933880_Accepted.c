#include<stdio.h>

int fibo[21]={1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765};
int proadd[21]={1,2,4,7,12,20,33,54,88,143,232,376,609,986,1596,2583,4180,6764,10945,17710,17710};


int main(){
    int a, n, m, x;
    scanf("%d %d %d %d", &a, &n, &m, &x);
    int arr[5]={0};arr[1]=arr[2]=a;arr[3]=2*a;
    if (x==n) printf("0\n");
    else if (x<4) printf("%d\n", arr[x]);
    else if (x==4){
        if (n==5) printf("%d\n", m);
        else {
            int p = (m-(2+proadd[n-6])*a)/(proadd[n-5]);
            int res = 2*a+p;
            printf("%d\n", res);
        }
    }
    else{
        int p = (m-(2+proadd[n-6])*a)/(proadd[n-5]);
        int res = (2+proadd[x-5])*a+(proadd[x-4])*p;
        printf("%d\n", res);
    }
    return 0;
}