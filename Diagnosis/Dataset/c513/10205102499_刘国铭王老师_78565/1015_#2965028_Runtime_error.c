#include <stdio.h>
#include <stdlib.h>

const int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,19,17,13,11,7,5,3,2};
int a[26]={0},b[26]={0},c[26]={0};
char s[100];
void Readnumber(char *s,int *a)
{
        int j=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]==',')
                j=i;
            else
            {
                j=i;
                a[25-j]=s[i]-'0';
            }
        }
}

void add(int *a,int *b,int *c)
{
    for(int i=25;i>=0;i--)
    {
        int temp=0;
        temp=(a[i]+b[i])%prime[i-1];
        c[i]=(a[i]+b[i]+temp)/prime[i-1];
    }
}

void output(int *a)
{
    int flag=0;
    for(int i=0;i<26;i++)
        if(a[i]==1)
            flag=i;
    for(int j=flag;j<25;j++)
    {
        printf("%d,",a[j]);
    }
    printf("%d",a[25]);
    printf("\n");
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%s",&a);
        Readnumber(s,a);
        scanf("%s",&b);
        Readnumber(s,b);
        add(a,b,c);
        printf("case #%d:\n",i);
        output(c);
    }
    return 0;
}
