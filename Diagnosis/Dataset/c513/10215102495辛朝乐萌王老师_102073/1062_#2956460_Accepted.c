#include <stdio.h>
typedef long long int lli;
lli map[51];

lli solve(int n)
{
    lli ret;
    if (n==1) {
        ret=1;
        map[1]=ret;
    }
    else if(n==2){
        ret=2;
        map[2]=ret;
    }
    else if(n==3){
        ret=4;
        map[3]=ret;
    }
    else if(n==4){
        ret=8;
        map[4]=ret;
    }
    else{
        if(map[n] != 0){
            ret = map[n];
        }
        else{
            ret=solve(n-1)+solve(n-2)+solve(n-3)+solve(n-4);
            map[n]=ret;
        }
    }
    return ret;
}



int main(void) {
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        lli step;
        int n;
        scanf("%d",&n);
        step = solve(n);
        printf("case #%d:\n",i);
        printf("%lli\n",step);
    }
    return 0;
}
