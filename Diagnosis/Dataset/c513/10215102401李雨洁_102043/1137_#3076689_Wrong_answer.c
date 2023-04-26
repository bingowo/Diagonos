#include<stdio.h>
#include<string.h>
char s1[10005],s2[10005],s3[10005];
int num1[10005],num2[10005];
int len1,len2,i,j;
//当s1与s2同号，利用flag标志结果的符号（0为正，1为负）
void Plus(int flag)
{
    len1=strlen(s1);
    len2=strlen(s2);
    for(i=len1-1,j=0; i>=0 ; i--)
    {
        num1[j]=s1[i]-48;
        j++;
        if(i==flag) break; //如果s1与s2同负，flag=1，则不进行下一次循环赋值字符串第0位
    }
    for(i=len2-1,j=0; i>=0 ; i--)
    {
        num2[j]=s2[i]-48;
        j++;
        if(i==flag) break; //如果s1与s2同负，flag=1，则不进行下一次循环赋值字符串第0位
    }
    int len;
    if(flag==0) len=len2>len1?len2:len1;
    else len=len2>len1?(len2-1):(len1-1); //如果s1与s2同负，flag=1，len值应为长度减1
    for(i=0; i<len; i++)
    {
        num1[i]+=num2[i];
        if(num1[i]>9)
        {
            num1[i+1]+=1;
            num1[i]-=10;
        }
    }
    if(flag==1) printf("-"); //如果s1与s2同负，flag=1，结果的符号位为负
    if(num1[i]) //最高位进位
    {
        for(j=i; j>=0; j--)
            printf("%d",num1[j]);
        printf("\n");
    }
    else        //最高位未进位
    {
        for(j=i-1; j>=0; j--)
            printf("%d",num1[j]);
        printf("\n");
    }
}
//对异号的s1和s2处理成“大数-小数”形式后调用该函数进行减计算并显示，利用flag标志结果的符号（0为正，1为负）
void Minus_show(int flag,int len,int num1[],int num2[])
{
    //进行减计算及借位
    for(i=0; i<len; i++)
    {
        if(num1[i]>=num2[i])
        {
            num1[i]-=num2[i];
        }
        else
        {
            num1[i]=num1[i]+10-num2[i];
            num1[i+1]-=1;
        }
    }
    while(num1[--i]==0)
    {
        if(i==0) break;
    }
    if(flag==1) printf("-");  //flag=1，结果的符号位为负
    for(j=i; j>=0; j--)
        printf("%d",num1[j]);
    printf("\n");
}
//当s1与s2异号，以正数-负数顺序传递实参给形参
void Minus(char s1[],char s2[])
{
    len1=strlen(s1);
    len2=strlen(s2);
    for(i=len1-1,j=0; i>=0 ; i--) 
    {
        num1[j]=s1[i]-48;
        j++;
    }
    for(i=len2-1,j=0; i>0 ; i--) 
    {
        num2[j]=s2[i]-48;
        j++;
    }
    memset(s3,0,sizeof(s3)); 
    for(i=1,j=0; i<len2; i++)
    {
        s3[j++]=s2[i];
    }
    if(len1>(len2-1)||(len1==(len2-1)&&strcmp(s1,s3)==0)||len1==(len2-1)&&strcmp(s1,s3)==1)
    {
        Minus_show(0,len1,num1,num2);
    }
    else if((len2-1)>len1||(len1==(len2-1)&&strcmp(s1,s3)==-1))
    {
        Minus_show(1,len2-1,num2,num1);
    }
}
int main()
{
    scanf("%s%s",s1,s2);
    memset(num1,0,sizeof(num1));
    memset(num2,0,sizeof(num2));
    if(s1[0]!='-'&&s2[0]!='-')
    {
        Plus(0); //s1与s2同正，设置flag=0
    }
    else if(s1[0]=='-'&&s2[0]=='-')
    {
        Plus(1); //s1与s2同负，设置flag=1
    }
    else if(s1[0]!='-'&&s2[0]=='-')
    {
        Minus(s1,s2); //s1为正，s2为负，传递s1,s2顺序，实现一个正数减一个负数
    }
    else
    {
        Minus(s2,s1); //s1为正，s2为负，传递s2,s1顺序，实现一个正数减一个负数
    }
     return 0;
}

