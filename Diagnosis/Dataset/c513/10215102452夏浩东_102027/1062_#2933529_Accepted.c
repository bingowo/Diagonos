#include <stdio.h>
long long int Step(int num)
{
    if(num==4) return 8;
    else if(num==3) return 4;
    else if(num==2) return 2;
    else if(num==1) return 1;
    else if(num==0) return 1;
    else if(num<0) return 0;
    else
    {
        return Step(num/2)*Step(num-num/2)+Step(num/2-1)*Step(num-num/2-1)+
        Step(num-num/2-2)*Step(num/2-1)+Step(num-num/2-1)*Step(num/2-2)+
        Step(num/2-3)*Step(num-num/2-1)+Step(num/2-1)*Step(num-num/2-3)+
        Step(num/2-2)*Step(num-num/2-2);
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
        long long int sum=0;
        sum=Step(num);
        printf("case #%d:\n",i);
        printf("%lld\n",sum);
    }
    return 0;
}