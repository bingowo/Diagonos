#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(const void *a,const void*b)
{
    return  *((char*)a)-*((char*)b);
}
int Turn2(char s[])
{
    int i,y = 1,x = 0;
    for(i = strlen(s)-1;i>=0;i--)
    {
        x = x+y;
        y*=2;
    }
    return x;
}
long long int Turn1(char s[])
{
    int a[61],i;
    long long int y = 1,x = 0;
    a[0] = 1;
    for(i=1;i<strlen(s);i++)
    {
        if(s[i]!=s[0])a[i] = 0;
        else a[i] = 1;
    }
    for(i =strlen(s)-1;i>=0;i--)
    {
        x = x+a[i]*y;
        y*=2;
    }
    return x;
}
long long int Turn3(char s[],int n)
{
    long long int i,j,k = 1,m = 0,x = 0,y = 1;
    int b[60];
    char a[60],p;
    a[0] = s[0];
    for(i = 0;i<strlen(s)-1;i++)
    {
        for(j = 0;j<i+1;j++)
        {
            if(s[i+1] == a[j])
            {
                i++;
                break;
            }
        }
            if(s[i]!=s[i+1])
        {
            a[k] = s[i+1];
            k++;
        }

    }
        p = a[0];
        a[0] = a[1];
        a[1] = p;
        a[k] = '\0';

        for(i =0;i<strlen(s);i++,m++)
        {
            for(j = 0;j<strlen(a);j++)
            {
                if(s[i] ==a[j] )b[m] = j;
            }
        }
   for(i = m-1;i>=0;i--)
        {
            x = x+b[i]*y;
            y*=n;
        }
    return x;
}
int Num( char s[])
{
    int i;
    int n = 1;
    for(i = 0;i<strlen(s)-1;i++)
    {
        if(s[i] !=s[i+1])n++;
    }
    return n;
}
int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    char s[n][61];
    char c[n][61];
    for(i = 0;i<n;i++)
    {
        scanf("%s",s[i]);
        strcpy(c[i],s[i]);
    }
    int a[n];
    long long int b[n];
    for(i = 0;i<n;i++)
    {
        qsort(s[i],strlen(s[i]),sizeof(s[0][0]),cmp);
        a[i] = Num(s[i]);
        if(a[i] == 2)b[i] = Turn1(c[i]);
        else if(a[i] ==1)b[i] = Turn2(c[i]);
        else b[i] = Turn3(c[i],a[i]);

    }
    for(i = 0;i<n;i++)
    {
        printf("case #%d:\n%lld\n",i,b[i]);
    }
    return 0;
}
