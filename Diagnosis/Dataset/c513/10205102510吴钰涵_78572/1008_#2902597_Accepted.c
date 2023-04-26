#include <stdio.h>

int trans(int num,int s[]) {
    int i;
    for(i=0;num/2!=0;i++) {
        s[i]=num%2;
        num=num/2;
    }
    s[i]=num;
    return i;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int I=0;I<T;I++) {
        int x,y;
        scanf("%d %d",&x,&y);
        int a[20]={0};
        int b[20]={0};
        int num1=trans(x,a);
        int num2=trans(y,b);
        int len;
        if(num1-num2>0) len=num1;
        else len=num2;
        int cnt=0;
        for(;len>=0;len--) {
            if(a[len]!=b[len])
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
