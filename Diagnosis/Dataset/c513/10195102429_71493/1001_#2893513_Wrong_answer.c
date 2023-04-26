#include<stdio.h>
int cnt=0;                             //用来记录每一个进制存放的位置
char num[20];    //用来存放每一个进制的数   


void fun(int a,int b)
{
if(a==0)    //递归的终止条件
return;
fun(a/b,b);                        //顺序递归
num[cnt++] = a%b;                  //逆序递归
} 


int main()
{
int a,b;
while(scanf("%d%d",&a,&b)!=EOF)
{
if(a<0)
{
a = -a;
fun(a,b);
printf("-");
for(int i=0;i<cnt;i++)
{
if(num[i]<10)
printf("%d",num[i]);
else
printf("%c",num[i]+'A'-10);
}
}
else
{
fun(a,b);
for(int i=0;i<cnt;i++)
{
if(num[i]<10)
printf("%d",num[i]);
else
printf("%c",num[i]+'A'-10);
}
}
printf("\n");
cnt = 0;


}
} 
