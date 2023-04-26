#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void approxi(int *a,int *b)
{
    for(int i=2;i<=a;i++)
    {
        if((*a % i==0)&&(*b % i==0))
        {
            *a=*a/i;
            *b=*b/i;
            i=i-1;
        }
    }
}
int main()
{
        char c[100]={'\0'};
        scanf("%s",&c);
        int b=strlen(c);
        int sum=0;
        int point=b;
        for(int j=0;j<b;j++)
        {
            if(c[j]=='.')
                point=j;
        }
        for(int j=0;j<point;j++)
        {
            if(c[j]=='2')
                sum=sum-pow(3,point-j-1);
            else if(c[j]=='1')
                sum=sum+pow(3,point-j-1);
        }
        if(point==b)
        printf("%d",sum);
        else if(point<b)
        {
            int nume=0;
            for(int j=point+1;j<strlen(c);j++)
            {
            if(c[j]=='2')
                nume=nume-pow(3,strlen(c)-j);
            else if(c[j]=='1')
                nume=nume+pow(3,strlen(c)-j);
            }
            int deno=abs(pow(3,strlen(c)-point));
            if((nume<0)&&(sum>0))
            {
                nume=deno+nume;
                sum=sum-1;
            }
            if((nume>0)&&(sum<0))
            {
                nume=deno-nume;
                sum=sum+1;
            }
            for(int i=2;i<=nume;i++)
            {
                if((nume % i==0)&&(deno % i==0))
                {
                    nume=nume/i;
                    deno=deno/i;
                    i=i-1;
                }
            }
            printf("%d %d %d",sum,nume,deno);
        }
    return 0;
}
