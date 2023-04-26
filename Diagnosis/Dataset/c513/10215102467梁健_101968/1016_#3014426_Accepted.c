#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int n,r;scanf("%d %d",&n,&r);
    char res[40],t=0;
    if(n==0)printf("0");
    while(n!=0){
        int c=n%r;
        if(c<0){
            c-=r;
            n=n/r+1;
        }
        else n/=r;
        if(c<10) res[t++]=c+48;
        else res[t++]=c-10+65;
    }
    for(int i=t-1;i>=0;i--)printf("%c",res[i]);
}

