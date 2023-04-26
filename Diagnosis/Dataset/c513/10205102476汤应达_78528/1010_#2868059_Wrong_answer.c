#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[500];scanf("%s",s);
    char res[2000];
    int l=strlen(s),group=l/3,remain=l%3,l0=l,l1=10*(group+1);
    int t=9;
    while(t>=0)
    {
        if(l0==0) res[t--]=0;
        else {res[t--]=l0%2;l0>>=1;}
    }//数字个数转化为十位二进制码
    for(int i=0;i<group;i++)
    {
        char num[3]={s[3*i],s[3*i+1],s[3*i+2]};
        int tmp=atoi(num),t=9,p=10*(i+2)-1;
        while (t>=0)
        {
            if(tmp==0) {res[p--]=0;t--;}
            else {res[p--]=tmp%2;tmp>>=1;t--;}
        }        
    }
    if(remain==1)
    {
        char num=s[l-1];
        int tmp=num-'0',t=4,p=10*(1+group)+3;
        l1+=4;
        while (t>0)
        {
            if(tmp==0) {res[p--]=0;t--;}
            else {res[p--]=tmp%2;tmp>>=1;t--;}
        }        
    }
    else if(remain==2)
    {
        int tmp=(s[l-2]-'0')*10+s[l-1]-'0',t=7,p=10*(1+group)+6;
        printf("%d\n",tmp);
        l1+=7;
        while (t>0)
        {
            if(tmp==0) {res[p--]=0;t--;}
            else {res[p--]=tmp%2;tmp>>=1;t--;}
        }        
    }
    printf("0001");
    for(int i=0;i<l1;i++) printf("%d",res[i]);

    return 0;
}