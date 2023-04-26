#include<stdio.h>
#include<string.h>
void readnumber(int s1[];int s2[])
{
   int j=0,m=0;
   for(j=0;j<strlen(s1);j++)
   {
       if(s1[j]!=',') s2[m++]=s1[j];
       else j+=1;
   }
}
void ADD(int a[],int b[],int plus[])
{
    
}
void output(int a[])
{
    
}
int main(void)
{
    int sushu[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    int T=0;
    scanf("%d\n",T);
    for(int i=0;i<T;i++)
    {
        char s[40];
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