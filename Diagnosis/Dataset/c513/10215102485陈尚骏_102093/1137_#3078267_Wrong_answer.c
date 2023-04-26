#include <stdio.h>
#include <stdlib.h>
#include<string.h>

const int LEN=101;

void add(char*a,char*b,char*res)
{
    int temp[101]={0};
    int i,j,cry=0,len_t=0,len_c=0;
    int len_a=strlen(a),len_b=strlen(b);
    for(i=len_a-1,j=len_b-1;i>=0&&j>=0;i--,j--)
    {
        temp[len_t++]=(a[i]-'0'+b[j]-'0'+cry)%10;
        cry=(a[i]-'0'+b[j]-'0'+cry)/10;
    }
    while(i>=0)
    {
        temp[len_t++]=(a[i]-'0'+cry)%10;
        cry=(a[i--]-'0'+cry)/10;
    }
    while(j>=0)
    {
        temp[len_t++]=(b[j]-'0'+cry)%10;
        cry=(b[j--]-'0'+cry)/10;
    }
    if(cry>0)
    {
        temp[len_t++]=1;
    }
    len_t--;
    while(len_t>=0)
    {
        res[len_c++]=temp[len_t--]+'0';
    }
}

void minus(char*a,char*b,char*res)
{
    int temp[101]={0};
    int i,j,brw=0,len_t=0,len_c=0,flag;
    int len_a=strlen(a);
    int len_b=strlen(b);
    if(len_a>len_b||((len_a==len_b)&&strcmp(a,b)>=0)) flag=0;
    else
    {
        flag=1;
        char*t=a;
        a=b;
        b=t;
    }
    len_a=strlen(a);
    len_b=strlen(b);
    for(i=len_a-1,j=len_b-1;i>=0&&j>=0;i--,j--)
    {
        temp[len_t++]=(a[i]-b[j]-brw+10)%10;
        if(a[i]-b[j]-brw<0) brw=0;
    }
    while(i>=0)
    {
        temp[len_t++]=(a[i]-'0'-brw+10)%10;
        if(a[i]-'0'-brw<0) brw=1;
        else brw=0;
        i--;
    }
    len_t--;
    if(flag==1)
    {
        res[len_c++]='-';
    }
    while(temp[len_t]==0&&len_t>0)
    {
        len_t--;
    }
    while(len_t>=0)
    {
        res[len_c++]=temp[len_t--]+'0';
    }
}

void bigsum(char*a,char*b,char*res)
{
    if(a[0]=='-'&&b[0]!='-')
        minus(b,&a[1],res);
    else if(a[0]!='-'&&b[0]=='-')
    {
        minus(a,&b[1],res);
    }
    else if(a[0]!='-'&&b[0]!='-')
    {
        add(a,b,res);
    }
    else
    {
        add(&a[1],&b[1],res);
        int len_r=strlen(res);
        for(int k=len_r-1;k>=0;k--)
        {
            res[k+1]=res[k];
        }
        res[0]='-';
    }
}

int main()
{
    char a[LEN-1];
    char b[LEN-1];
    char res[LEN];
    while(scanf("%s %s",a,b)!=EOF)
    {
        memset(res,0,sizeof(res));
        bigsum(a,b,res);
        printf("%s\n",res);
    }
    return 0;
}
