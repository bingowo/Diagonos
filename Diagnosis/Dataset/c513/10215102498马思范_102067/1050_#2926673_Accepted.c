#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Lookfor_max(char s[],char m[])
{
    int a,b,flag;
    int max=0;
    a=strlen(s);
    b=strlen(m);
    int i,j=0,trace=0;
    for(i=0;i<b;++i)
    {
        trace=i; flag=i;
        while(m[trace]==s[j])
        {
            ++trace;++j;
            if(j==a)
            { max=flag+1;
                break;
            }
        }
        j=0;
    }

    return max;
}
int Lookfor_min(char s[],char m[])
{
    int a,b,flag;
    int min=0;
    a=strlen(s);
    b=strlen(m);
    int i,j=0,trace=0;
    for(i=0;i<b;++i)
    {
        trace=i; flag=i;
        while(m[trace]==s[j])
        {
            ++trace;++j;
            if(j==a)
            {
                min=flag+1;
                break;
            }
        }
        if(j==a)
        {
            break;
        }
        j=0;
    }
    return min;
}

void solve(int i)
{
    char s1[500],s2[500],s[500];
    scanf("%s",s1);
    scanf("%s",s2);
    scanf("%s",s);

    int max1=Lookfor_max(s1,s);
    int max2=Lookfor_max(s2,s);
    int min1=Lookfor_min(s1,s);
    int min2=Lookfor_min(s2,s);

    printf("case #%d:\n",i);
    if(max1!=0&&min1!=0&&max2!=0&&min2!=0)
    {
        if(max1==min1&&max2==min2&&max1==max2)
        {
            printf("0\n");
        }
        else{
            int flag1=max1-min2-strlen(s2);
            int flag2=max2-min1-strlen(s1);
            if(flag1>=flag2)
            {
                printf("%d\n",flag1);
            }
            else
            {
                printf("%d\n",flag2);
            }
        }
    }
    else
    {
        printf("0\n");
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;++i)
    {
        solve(i);
    }
    return 0;
}