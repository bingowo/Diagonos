#include <stdio.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int k=0;k<cnt;k++)
    {
        int num=0;
        scanf("%d",&num);
        int res=0;
        if(num<5) res=0;
        else{
            int temp=1;
            for(int i=5;i<=num;i=i*5){res+=temp;temp++;}
        }
        printf("case #%d:\n",k);
        printf("%d",res);
    }
    return 0;
}