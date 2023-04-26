#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num 20

void add(int *p1,const int *p2)
{
    int carry = 0;
    int res[20] = {0};
    for(int i=0;i<num;i++)
    {
        int p = p1[i]+p2[i]+carry;
        res[i] += p%10;
        carry = p/10;
    }
    for(int i =0;i<num;i++)
        p1[i] = res[i];
}

int main()
{
    int t;
    scanf("%d",&t);
    int s[75][20];
    memset(s,0,sizeof(s));
    s[0][0] = 0;s[1][0] = 1;s[2][0] = 1;
    for(int i =3;i<74;i++)
    {
        add(s[i],s[i-1]);
        add(s[i],s[i-2]);
        add(s[i],s[i-3]);
    }
    for(int i =0;i<t;i++)
    {
        int j;scanf("%d",&j);
        printf("case #%d:\n",i);
        int po = num-1;
        if(j==0)printf("0\n");
        else
        {
            while(s[j][po]==0)po--;
            while(po>=0)printf("%d",s[j][po--]);
            printf("\n");
        }
    }
}



