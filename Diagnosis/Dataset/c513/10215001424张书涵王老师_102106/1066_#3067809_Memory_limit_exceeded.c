#include <stdio.h>
#include <stdlib.h>

void walk(int ahead,int down,int* type_num,int p,int n)
{
    int i;
    if(p==1)
        walk(ahead-1,down,type_num,p+1,n);
    else
    {
        if(p==n)
            walk(ahead,down-1,type_num,p-1,n);
        else
        {
            if(ahead==0&&down==0)
                type_num[0]++;
            else
            {
                for(i=0;i<2;i++)
                {
                    if(i==0)
                        walk(ahead-1,down,type_num,p+1,n);
                    else
                        walk(ahead,down-1,type_num,p-1,n);
                }
            }
        }
    }
}

int main()
{
    int cas,question_num;
    scanf("%d",&cas);
    for(question_num=0;question_num<cas;question_num++)
    {
        int n,p,m,t,type_num[1]={0};
        scanf("%d %d %d %d",&n,&p,&m,&t);
        int tall,shortt,ahead,down;
        if(p>t)
        {
            tall=p;shortt=t;
            ahead=(m-(tall-shortt))/2;
            down=(m-(tall-shortt))/2+tall-shortt;
        }
        else
        {
            tall=t;shortt=p;
            ahead=(m-(tall-shortt))/2+tall-shortt;
            down=(m-(tall-shortt))/2;
        }
        if((m-(tall-shortt))%2!=0||(m<(tall-shortt)))
            type_num[0]=0;
        else
        {
            if(m==(tall-shortt))
                type_num[0]=1;
            else
                walk(ahead,down,type_num,p,n);
        }
        printf("%d\n",type_num[0]);
    }
}