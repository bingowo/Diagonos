#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#define MAX_LEN 501    //定义竖式运算的精度，数值可改变
#define INT(x) int x[MAX_LEN] = {0}     //高精度数的定义方式

void sassign(int* x,char* s)    //针对字符串的assign操作
{
    int len = strlen(s);
    int i,j;
    if(s[0] == '-') x[0] = 0;
    else x[0] = 1;

    for(i=MAX_LEN-1,j=len-1;i>=1&&isdigit(s[j]);i--,j--)
        x[i] = s[j]-'0';
}
void print(int* x)
{
    int flag = 0;
    if(!x[0])   printf("-");
    for(int i=1;i<MAX_LEN;i++)
    {
        if(!flag && !x[i])  continue;
        flag = 1;
        printf("%d",x[i]);
    }
    if(!flag)   printf("0");
    printf("\n");
    //return 0;
}
int IsEmpty(int* x)
{
    for(int i=1;i<MAX_LEN;i++)
    {
        if(x[i])    return 0;
    }
    return 1;
}
void add(int* x,int* y)
{
    int r=0;
    for(int i=MAX_LEN-1;i>=1;i--)
    {
        int tmp = x[i]+y[i]+r;
        r = tmp/10;
        x[i] = tmp%10;
    }
}
void mul(int* x,int y)
{
    int r=0;
    if((!x[0]&&y<=0) || (x[0]&&y<0))
    {
        x[0]=!x[0];
        y=-y;
    }
    for(int i=MAX_LEN-1;i>=1;i--)
    {
        int tmp = x[i]*y +r;
        r = tmp/10;
        x[i] = tmp%10;
    }
}
void cpy(int* x,int* y)
{
    for(int i=0;i<MAX_LEN;i++)
            x[i] = y[i];
}

void divid(int* x,int y)    //除法，高精除以低精(整除)
{
    INT(s);

    if((!x[0]&&y<=0) || (x[0]&&y<0))
    {
        x[0]=!x[0];
        y=-y;
    }
    int i=1;
    s[0] = x[0];
    while(!x[i])    i++;

    int r;
    int yu=0;
    for(;i<MAX_LEN;i++)
    {
        r = yu*10+x[i];
        s[i] = r/y;
        yu = r%y;
    }

    cpy(x,s);
}

int main()
{
    char input[12][MAX_LEN];
    char a[MAX_LEN];
   // vector<int> binary;
    INT(x);                      //两个高精度数字x和y的定义
    INT(y);

    int t,i,j;
    int top;
    scanf("%d",&t);
    for(i=0;i<t;i++)
        scanf("%s",input[i]);          //string形式输入高精度数字

    for(i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        strcpy(a,input[i]);
        //a = input[i];
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));      //高精度数组清零
        sassign(x,a);
        y[0] = 1;                 //首位为1，表示该数为正数
        INT(tem);
        tem[0] = 1;    


        while(!IsEmpty(x))
        {
            int g = x[MAX_LEN-1]%2;       //判断是否为正数，看末位数值就可以了
            
            if(g)   tem[MAX_LEN-1] = 1;
            else tem[MAX_LEN-1] = 0;
                   
            mul(y,2);  
            add(y,tem);       //相当于y = y*2+tem
            divid(x,2);  
        }

        print(y);
        
    }
} 
