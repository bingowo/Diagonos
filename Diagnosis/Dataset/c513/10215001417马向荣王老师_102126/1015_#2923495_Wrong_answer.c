#include<stdio.h>
#include<string.h>
int sushu[26] = {97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
void readnumber(int *s1,int *s2)
{
   int i=0,m=0,j=1;
   for(i=0;i<strlen(s1);i++)
   {
       if(s1[i]!=',')
       {
           s2[m]=s1[i];
           m++;
       }
       else
       {
           i++;
           continue;
       }
   }
}
void ADD(int *a,int *b,int *plus)
{
    int i=0;
    for(i=25;i>=0;i--)
    {
        plus[i]=a[i]+b[i];
        if(plus[i]>=sushu[i])
        {
            plus[i+1]=plus[i+1]+plus[i]/sushu[i];
            plus[i]%=sushu[i];
        }
    }
}
void output(int *plus)
{
    int i=25;
    while(plus[i]==0)
    {
        i--;
    }
    for(;i>0;i--)
    {
        printf("%d,",plus[i]);
    }
    printf("%d\n",plus[0]);
}
int main(void)
{
    int T=0;
    int i=0;
    scanf("%d\n",&T);
    for(i=0;i<T;i++)
    {
        char s[100];
        int a[26]={0},b[26]={0},plus[26]={0};
        scanf("%s",s);
        readnumber(s,a);
        scanf("%s",s);
        readnumber(s,b);
        ADD(a,b,plus);
        printf("case #%d:\n",i);
        output(plus);
    }
    return 0;
}