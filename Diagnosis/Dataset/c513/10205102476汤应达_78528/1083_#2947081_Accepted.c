#include<stdio.h>

int solve(int num)
{
    int cnt=0,mid;
    while(num>0)
    {
        mid=num;
        while(mid%5==0) {cnt++;mid/=5;}
        num--;
    }
    return cnt;
}

int main()
{
    int t,i=0,num,cnt;scanf("%d",&t);
    while(i<t)
    {
        scanf("%d",&num);cnt=solve(num);
        printf("case #%d:\n%d\n",i++,cnt);
    }

    return 0;
}