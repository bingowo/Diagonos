#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void ADD(int *a,int *b,int *answer)
{
    int p[26]={101,97,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    int last=0;
    for(int j=25;j>=0;j--)
    {
        int x=a[j]+b[j]+last;
        if(x>=p[j]) {last=1;answer[j]=x-p[j];}
        else if(x<p[j]) {last=0;answer[j]=x;}
    }
}
void Readnumber(char *s,int *a)
{
    int len=strlen(s);int j=25;
    for(int i=len-1;i>=0;i--)
    {
        int num=0;
        if(s[i]!=',') {num++;}
        else if(s[i]==','||i==0)
        {
            int x=0;
            for(int k=1;k<=num;k++) {x+=s[i+k]*10;}
            a[j]=x;j--;continue;
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[100];
        int a[26]={0},b[26]={0},answer[26]={0};
        scanf("%s",s);Readnumber(s,a);
        scanf("%s",s);Readnumber(s,b);
        printf("case #%d:\n",i);
        ADD(a,b,answer);
        int j=0;
        for(;j<26;j++) {if(answer[j]!=0) break;}
        for(int k=j;k<26;k++)
        {
            if(k!=25) printf("%d,",answer[k]);
            else printf("%d\n",answer[k]);
        }
    }
    return 0;
}
