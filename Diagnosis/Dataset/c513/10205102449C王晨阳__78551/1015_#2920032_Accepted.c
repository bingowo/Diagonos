#include <stdio.h>
#include <string.h>

void Readnumbers(char *s, int *a);
void ADD(int *a, int *b, int *c);
void output(int *c);

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[100];
        int a[26]={0},b[26]={0},c[26]={0};
        scanf("%s",s);
        Readnumbers(s,a);
        scanf("%s",s);
        Readnumbers(s,b);
        ADD(a,b,c);
        printf("case #%d:\n",i);
        output(c);
    }
    return 0;
}

void Readnumbers(char *s, int *a)
{
    int n,m=25,num=0,j=1;
    n=strlen(s);
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]>47 && s[i]<58)
        {
            num=(s[i]-48)*j+num;
            j=j*10;
            if(i==0)
                a[m]=num;
        }
        else
        {
            a[m]=num;
            m--;
            num=0;
            j=1;
        }
    }
}

void ADD(int *a, int *b, int *c)
{
    int temp=0;
    char number[25]={97,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    for(int i=25;i>0;i--)
    {
        c[i]=(a[i]+b[i]+temp)%number[i-1];
        temp=(a[i]+b[i]+temp)/number[i-1];
    }
}

void output(int *c)
{
    int i=0;
    while(c[i]==0)
        i++;
    for(;i<25;i++)
        printf("%d,",c[i]);
    printf("%d\n",c[25]);
}