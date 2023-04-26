#include<stdio.h>
#include<string.h>
int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
void Readnumber(char s[],int a[])
{
    int i,j=25,k=0,l;
    for(i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]!=',')
        {
            int x=s[i]-'0';
            for(l=0;l<k;l++)
            {
                x*=10;
            }
            a[j]+=x;
            k++;
        }
        else
        {
            j--;
            k=0;
        }
    }
}
void ADD(int a[],int b[],int c[])
{
    int i,d=0;
    for(i=25;i>=0;i--)
    {
        if(a[i]+b[i]+d>=prime[i])
        {
            c[i]=a[i]+b[i]+d-prime[i];
            d=1;
        }
        else
        {
            c[i]=a[i]+b[i]+d;
            d=0;
        }
    }
}
void output(int c[])
{
    int i,k;
    k=0;
    for(i=0;i<25;i++)
    {
        if(k==0)
        {
            if(c[i]!=0)
            {
                k=1;
                printf("%d,",c[i]);
            }
        }
        else
            printf("%d,",c[i]);
    }
    printf("%d\n",c[25]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a[26]={0},b[26]={0},c[26]={0};
        char s[100];
        scanf("%s",&s);
        Readnumber(s,a);
        scanf("%s",&s);
        Readnumber(s,b);
        ADD(a,b,c);
        printf("case #%d:\n",i);
        output(c);
    }
    return 0;
}
