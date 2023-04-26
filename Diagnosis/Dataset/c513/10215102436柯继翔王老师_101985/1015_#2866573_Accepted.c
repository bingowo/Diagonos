#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Readnumber(char x[],int y[])
{
    int index = 25,n=1;
    for(int i=strlen(x)-1; i>=0; i--)
    {
        if(x[i]>='0' && x[i]<='9')
        {
            y[index] += (x[i]-'0')*n;
            n*=10;
        }
        else
        {
            index--;
            n=1;
        }
    }
}
void ADD(int a[],int b[],int c[])
{
    int prime[26]= {97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    int x=0;
    for(int i = 25; i>=0; i--)
    {
        c[i]=(a[i]+b[i]+x)%prime[i];
        x = (a[i]+b[i]+x)/prime[i];
    }
}
void output(int a[])
{
    int i = 0;
    while(a[i]==0 && i<=24)
    {
        i++;
    }
    for(; i<=25; i++)
    {
        if(i == 25)printf("%d\n",a[i]);
        else printf("%d,",a[i]);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        char s[100];
        int a[26]= {0},b[26]= {0},c[26]= {0};
        scanf("%s",s);
        Readnumber(s,a);
        scanf("%s",s);
        Readnumber(s,b);
        ADD(a,b,c);
        printf("case #%d:\n",i);
        output(c);
    }
    return 0;

}
