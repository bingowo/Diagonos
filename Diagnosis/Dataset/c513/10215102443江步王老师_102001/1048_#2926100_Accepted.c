#include<stdio.h>
#include<ctype.h>

#define N 100 

void multi(char *s1, char *s2, int *co);
void read_data(char *p, int *co);
int main()
{
    char s1[N+1];
    char s2[N+1];
    int i;
    while ((scanf("%s %s",s1,s2)) == 2)
    {
        int n=0;
        int co[N]={0};//储存系数
        int out[N]={0};
        multi(s1,s2,co);//完成多项式乘法并将结果的每一项系数存入co数组
        for (i=N-1;i>=0;i--)
        {
            if (co[i] != 0)
            {
                out[n]=co[i];
                n++;
            }
        }
        for (i=0;i<n;i++)
        {
            printf("%d",out[i]);
            if (i != n-1)
            {
                putchar(' ');
            }
            else
            {
                putchar('\n');
            }
        }
    }
    return 0;
}

void multi(char *s1, char *s2, int *co)
{
    int co1[N]={0};
    int co2[N]={0};
    int i,j;
    
    read_data(s1,co1);
    read_data(s2,co2);
    //s1，s2中每一项的系数分别存入co1，co2中
    for (i=0;i<N/2;i++)
    {
        for (j=0;j<N/2;j++)
        {
            co[i+j]=co[i+j]+co1[i]*co2[j];
        }
    }
    return;
}

void read_data(char *p, int *co)
{
    
    while (*p)
    {
        int sign=1,c=0,d=0;
        if (*p == '+')
        {
            sign=1;
            p++;
        }
        else if (*p == '-')
        {
            sign=-1;
            p++;
        }

        while (isdigit(*p))
        {
            c=c*10+*p-'0';
            p++;
        }

        if (*p != 'x')//判断该项的指数是否是0
        {
            co[0]=sign*c;
            return;
        }

        if (*p == 'x')
        {
            if (!c)
                c=1;
            p++;
        }
        
        if (*p == '^')
        {
            p++;
        }

        

        while (isdigit(*p))
        {
            d=d*10+*p-'0';
            p++;
        }
        if (d==0){
            d=1;
        }
        co[d]=c*sign;
    }
    return;
}