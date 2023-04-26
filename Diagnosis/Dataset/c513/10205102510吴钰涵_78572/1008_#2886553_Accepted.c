#include <stdio.h>

void num(int m,int n) {
    long long int tmp=(long long int)m^n;
    int cnt=0;
    while(tmp) {
        tmp=tmp&(tmp-1);
        cnt++;
    }
    printf("%d\n",cnt);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int I=0;I<T;I++) {
        int x,y;
        scanf("%d %d",&x,&y);
        num(x,y);
    }
    return 0;
}
