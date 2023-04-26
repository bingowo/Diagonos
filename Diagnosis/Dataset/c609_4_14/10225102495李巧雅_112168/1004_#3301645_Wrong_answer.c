#include <stdio.h>
#include <string.h>
long kto10(char s[],int k)
{
    long m=0;
    long p=1;
    int i;
    i=strlen(s)-1;
    while(i>=0)
    {
        if(s[i]>='0'&&s[i]<='9') m+=(s[i]-'0')*p;
        else m+=(s[i]-'A'+10)*p;
        i--;
        p*=k;
    }
    return m;
}
void tentok(long m,int k,char d[])
{
    char dfan[30];
    int i,j,n;
    i=0;
    while(m!=0)
    {
        n=m%k;
        m/=k;
        if(n>0&&n<10) dfan[i]=n+'0';
        else dfan[i]=n-10+'A';
        i++;
    }
    j=0;
    i--;
    while(i>=0)
    {
        d[j++]=dfan[i--];
    }
}
int main()
{
    char s1[30],s2[30];
    int A,B;
    long r;
    scanf("%d %s %d",&A,s1,&B);
    r=kto10(s1,A);
    tentok(r,B,s2);
    printf("%s",s2);
    return 0;
}
