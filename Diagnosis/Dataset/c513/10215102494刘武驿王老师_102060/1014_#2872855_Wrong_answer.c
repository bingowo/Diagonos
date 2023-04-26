#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int inty[100],flt[100];
    for(int l=0;l<100;l++)
    {
        inty[l]=0;
        flt[l]=0;
    }
        int tmp=a/b;
        int i=99;
        while(tmp)
        {
            inty[i]=tmp%3;
            i--;
            tmp/=3;
        }
        tmp=a%b;
        int j=0;
        if(tmp!=0)
        {
            while(tmp)
            {
                flt[j++]=(tmp*3)/b;
                tmp=(tmp*3)%b;
            }
        }
        int next=0;
        for(int x=j-1;x>=0;x--)
        {
            tmp=(flt[x]+1+next)%3;
            next=(1+flt[x]+next)/3;
            flt[x]=tmp;
        }
        int x;
        for(x=99;x>i;x--)
        {
            tmp=(inty[x]+1+next)%3;
            next=(1+inty[x]+next)/3;
            inty[x]=tmp;
        }
        while(next)
        {
            inty[i--]=(next+1)%3;
            next=(next+1)/3;
        }
        for(x=0;x<j;x++) flt[j]=(flt[x]-1==-1)?2:flt[x]-1;
        for(x=i+1;x<100;x++) inty[x]=(inty[x]-1==-1)?2:inty[x]-1;
        for(x=i+1;x<100;x++) printf("%d",inty[x]);
        printf(".");
        for(x=0;x<j;x++) printf("%d",flt[x]);
    }

