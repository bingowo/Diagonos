#include<stdio.h>
#include<string.h>
#include<math.h>
int isdigit(char c)
{
    if(c>='0'&&c<='9')
    {
        return 1;
    }
    return 0;
}

void take(char *c,int* a)
{
    while(*c)
    {
        int sig=1,xi=0,d=0;//符号位，系数，幂数
        if(*c=='+') c++;//判断+-号
        else if(*c=='-')
        {
            sig=-1;
            c++;
        }

        while(isdigit(*c))//如果是数字，计入系数
        {
            xi=xi*10+*c-'0';
            c++;
        }

        if(*c!='x')//下一位非x，即幂数为0
        {
            a[0]=xi*sig;
            return;//结束
        }
        else c++;//读到x的话，开始计算幂数
        if(xi==0) xi=1;//之前没读到数字，说明系数为1
        if(*c=='^') c++;//读到^开始计算幂数
        while(isdigit(*c))//如果是数字，计入幂数
        {
            d=d*10+*c-'0';
            c++;
        }
        if(d==0) d=1;//之前没读到数字，说明幂数为1
        a[d]=sig*xi;//系数写入相应幂数

    }
}

int main()
{
    char s1[100],s2[100];
    while(scanf("%s %s",s1,s2)==2)
    {
        int xi1[100]={0},xi2[100]={0};
        take(s1,xi1);
        take(s2,xi2);
        int temp[100]={0};
        for(int i=0;i<=50;i++)
        {
            for(int j=0;j<=50;j++)
            {
                temp[i+j]=temp[i+j]+xi1[i]*xi2[j];
            }
        }
        int ans[100]={0};
        int n=0;
        for(int i=0;i<100;i++)
        {
            if(temp[i]!=0)
            {
                ans[n]=temp[i];
                n++;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            printf("%d",ans[i]);
            if(i!=0) printf(" ");
            else printf("\n");
        }
    }
}
