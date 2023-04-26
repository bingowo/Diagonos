#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
long long int map[51];

long long int count(int x)
{
    long long int num=0;
    if (x==1){
        num=1;
        map[1]=num;
    }
    else if(x==2){
        num=2;
        map[2]=num;
    }
    else if(x==3){
        num=4;
        map[3]=num;
    }
    else if(x==4){
        num=8;
        map[4]=num;
    }
    else{
        if(map[x]!=0){ num= map[x];}
        else {
            num = count(x - 1) + count(x - 2) + count(x - 3) + count(x - 4);
            map[x] = num;
        }
    }
    return num;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d",&t);
        printf("case #%d:\n",i);
        printf("%lld\n",count(t));

    }
    return 0;
}