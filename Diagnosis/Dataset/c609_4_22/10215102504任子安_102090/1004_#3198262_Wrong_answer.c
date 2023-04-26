#include<stdio.h>
//#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    int A,B;
    char in[100];
    scanf("%d %s %d",&A,&in,&B);
    long long tmp=0,weight=1;
    for(int i=strlen(in)-1;i>=0;i--)
    {
        int x;
        if(isdigit(in[i])) x=in[i]-'0';
        else if(isupper(in[i])) x=in[i]-'A'+10;
        else if(islower(in[i])) x=in[i]-'a'+10;
        tmp+=x*weight;
        weight*=A;
    }
    char res[100]={'\0'};
    int cnt=0;
    while(tmp>0)
    {
        int x=tmp%B;
        tmp/=B;
        if(x>=0 && x<=9) res[cnt++]=x+'0';
        else res[cnt++]=x-10+'A';
    }
    for(int i=strlen(res)-1;i>=0;i--) printf("%c",res[i]);
    return 0;   
}