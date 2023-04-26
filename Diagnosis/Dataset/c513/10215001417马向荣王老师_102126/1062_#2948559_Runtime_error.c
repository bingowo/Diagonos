#include<stdio.h>
int main()
{
    int t=0;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d\n",&n);
        long long step[51];
        step[1]=1,step[2]=2,step[3]=4,step[4]=8;
        for(int m=5;m<51;m++)
        {
            step[m]=step[m-1]+step[m-2]+step[m-3]+step[m-4];
        }
        printf("case #%d:\n",i);
        printf("%s\n",step[n]); 
    }
    return 0;
}