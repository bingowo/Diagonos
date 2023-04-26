#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};

void Readnumber(char s[],int a[])
{
    int l = strlen(s)-1;
    int j=25,i=0;
    while(l>=0)
    {
        int temp=1;
        while(l>=0 && s[l] != ',')
        {
            a[j] += (s[l]-'0')*temp;
            temp*=10;
            l--;
        }
        j--;      
        l--;
    }
}

void ADD(int a[], int b[], int c[])
{
    int i=0;
    int temp=0;
    for(i=25;i>=0;i--)
    {
        c[i] = (temp + a[i] + b[i] ) % prime[i];
        temp = (temp + a[i]+b[i]) /prime[i];
    }
}

void output(int c[])
{
    int i=0,t=0;
    while(c[t] == 0) t++;
    for(i=t-1;i<25;i++)
    {
        printf("%d,",c[i]);
    }
    printf("%d\n",c[i]);
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        char s[100]={0};
        int a[26]={0};
        int b[26]={0};
        int c[26]={0};
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