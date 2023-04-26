#include<stdio.h>
#include<stdlib.h>

int calc(int x)
{
    int cnt=0;
    while(x)
    {
        cnt++;
        x/=10;
    }
    return cnt;
}

int cmp(const void*a,const void*b)
{
    int xa=*((int*)a),xb=*((int*)b);
    int ca=calc(xa),cb=calc(xb);
    if(ca!=cb)
        return ca<cb;
    else return xa>xb;
}
int main()
{
    int s[1000001];
    int i=0;
    while(scanf("%d",&s[i])!=EOF)
    {
        i++;
    }
    qsort(s,i+1,sizeof(int),cmp);
    printf("%s",s);
    return 0;
}