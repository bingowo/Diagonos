#include <stdio.h>
int count=0;
void func(int j,int k,int num)
{
    num=num-j*k;
    if(k==2 && num%2==0) {count++; return;}
    else if(k==2 && num%2!=0) return;
    else{
        for(int i=0;i<=num/(k-1);i++)
        {
            func(i,k-1,num);
        }
        return;
    }
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        int num=0;
        scanf("%d",&num);
        for(int j=0;j<=num/4;j++)
        {
            func(j,4,num);
        }
        printf("%d\n",count);
        count=0;
    }
    return 0;
}