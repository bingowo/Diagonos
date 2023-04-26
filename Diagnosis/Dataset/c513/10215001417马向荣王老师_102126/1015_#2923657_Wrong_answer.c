#include<stdio.h>
#include<string.h>
int sushu[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
void Readnumber(char *s,int *a)
{
    int len=strlen(s);
    int j=0,p=1;
    for(int i=len-1;(i+1)!=0;i--)
    {
        if(s[i]==',')
        {
            p=1;
            j++;
        }
        else
        {
            a[j]=a[j]+(s[i]-'0')*p;
            p*=10;
        }
    }
}
void ADD(int *a,int *b,int *c)
{
    for(int i=0;i<25;i++)
    {
        c[i]=a[i]+b[i];
        if(c[i]>=sushu[i])
        {
            c[i+1]+=c[i]/sushu[i];
            c[i]%=sushu[i];
        }
    }
}
void output(int *c)
{
    int q=25;
    for(q=25;q>0;q--)
    {
        if(c[q]!=0) break;
    }
    for(;q;q--)
    {
        printf("%d,",c[q]);
    }
    printf("%d\n",c[q]);
}
int main()
{
    int T =0;
    int i=0;
    scanf("%d\n",&T);
    for(i=0;i<T;i++)
    {
        char s[100];
        int a[26]={0},b[26]={0},c[26]={0};
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