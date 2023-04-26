#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char a[1000];
    for(int i=0;i<=1000;i++)
    a[i]=0;
    a['2']=-1;
    a['1']=1;
    char in[1000];
    scanf("%s",in);
    int len=strlen(in)-1;//len是所有数字的个数
    int z=0,cnt1=0,cnt2;//z是十进制整数部分，cnt1是三进制整数部分的数字个数
    char *p=in;
    for(;*p&&*p!='.';p++);
    p--;
    if(*p==in[len])
    {   p=in;
        while(*p)
    {
        z=z*3+a[*p];
        p++;
        cnt1++;
    }
    printf("%d",z);
    }
    else
   {   p=in;
       while(*p!='.')
    {
        z=z*3+a[*p];
        p++;
        cnt1++;
    }
    
    p++;
    cnt2=len-cnt1;
    int C=pow(3,cnt2);
    int B;
    while(*p)
    {
        B=B*3+a[*p];
        p++;
    }
    //接下来处理假分数
    if(B<0) 
    {
        z=z-1-(-B)/C;
        B=-(B-(-B)/C)-1;
    }
    if(B>0)
    {
        z=z+B/C;
        B=B-B/C;
        
    }
    if(z==0) printf("%d %d",B,C);
    else printf("%d %d %d",z,B,C);
   }
    return 0;
    
    
}