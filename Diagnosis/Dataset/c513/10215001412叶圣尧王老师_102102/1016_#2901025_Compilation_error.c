#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char prime={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N'}
int main()
{
    int N,R,i=0,k,digit;char s[40];
    scanf("%d %d",&N,&R);
    while(N!=0)
    {
        if(N<0){k=(N%R)+1;s[i]=prime[N-k*R];N=k;}
        else {s[i]=N%R;N=N/R;}
        i++;
    }
    for(j=strlen(s)-1;j>=0;j--)printf("%c",s[j]);
}