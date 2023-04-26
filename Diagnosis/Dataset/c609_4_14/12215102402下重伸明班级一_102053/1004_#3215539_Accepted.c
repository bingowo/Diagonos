#include<stdio.h>
char s[]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
void mingg(long long int x,int y)
{
    if(x>0)
    {
        mingg(x/y,y);
        putchar(s[x%y]);
    }
}
int main()
{
    int a,z;  // a是输入进制 z是输出进制
    char num[100],c,b;
    int ming[100];
    long long int g=0;   //zhongjianzhi
    scanf("%d",&a);
    int i=0;
    b=getchar();  //跳过空格
    while((c=getchar())!=' ')
    {
        num[i]=c;
        i++;
    }
    scanf("%d",&z);
    for(int m=0;m<i;m++)
    {
        if(num[m]>='0'&&num[m]<='9')
        {
            ming[m]=num[m]-'0';
        }
        if(num[m]>='a'&&num[m]<='z')
        {
            ming[m]=num[m]-'a'+10;
        }
        if(num[m]>='A'&&num[m]<='Z')
        {
            ming[m]=num[m]-'A'+10;
        }
    }     //meiwenti 
    int n=1;
    for(int s=--i;s>=0;s--)
    {
        g=g+ming[s]*n;
        n=n*a;
    }
      //meiwenti 
    
    
    if(g==0)
    {
        printf("0");
    }
    else
    {
        mingg(g,z);
    }
    
    
}