#include <stdio.h>
#include <stdlib.h>
int count25[1001][3]={0};
int count2(int num)
{
    if(num==1)
        return 0;
    return(count25[num][0]+count2(num-1));
}

int count5(int num)
{
    if(num==1)
        return 0;
    return(count25[num][1]+count5(num-1));
}
int count0(int num)
{
    return count2(num)<count5(num)? count2(num):count5(num);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:",i);
        int num;
        scanf("%d",&num);
        for(int i=1;i<1001;i++)
        {
            while(i%2==0)
            {
                count25[i][0]++;
                i=i/2;
            }
            while(i%5==0)
            {
                count25[i][1]++;
                i=i/5;
            }
        }
        printf("%d\n",count0(num));
    }
    return 0;
}
