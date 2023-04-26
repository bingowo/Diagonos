#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char prime[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};

int main()
{
    int N,R,i=0,j,k,digit;char s[40];
    scanf("%d %d",&N,&R);
    if(N==0)printf("0");
    while(N!=0)
    {
        if(N<0){if(N%R!=0)k=(N/R)+1;else k=N/R;s[i]=prime[N-k*R];N=k;}
        else {s[i]=prime[N%R];N=N/R;}
        i++;
    }s[i]='\0';
    for(j=strlen(s)-1;j>=0;j--)printf("%c",s[j]);
}
