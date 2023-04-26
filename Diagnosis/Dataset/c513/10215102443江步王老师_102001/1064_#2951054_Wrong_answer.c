#include<stdio.h>
#include<math.h>

float count(float *n, char *s , int n1, int n2);


int main()
{
    int T;
    float z,f,res;
    int n1,n2,n;
    int i;
    char prev,*p=NULL;
    //

    scanf("%d",&T);
    getchar();

    for (i=0;i<T;i++)
    {
        float value[100];
        char sign[100];
        char s[101];
        gets(s);
        p=s;
        prev=*p;
        z=0;f=0;n1=0;n2=0;
        res=0;
        
        //读取当前行中的浮点数与符号
        while (*p)
        {
            if (prev ==' ' && *p >='0' && *p<='9')//发现数字
            {
                while (*p >='0' && *p <='9')//保存整数部分
                {
                    z=z*10+*p-'0';
                    prev=*p;
                    p++;
                }

                if (*p == '.')
                {
                    p++;
                    n=0;
                    while (*p >= '0' && *p <= '9')//保存小数部分
                    {
                        n++;
                        prev=*p;
                        p++;
                        f=f*10+(*p-'0');
                    }
                    
                    f=f/pow(10,n);
                }

                value[n1++]=z+f;
            }

            else if (*p == '+' || *p == '-' || *p == '*' || *p == '/')
            {
                sign[n2++]=*p;
            }
            
            prev=*p;
            p++;
        }

        //计算表达式的值（n1，n2分别代表浮点数个数与符号个数）
        res=count(value, sign, n1, n2);

        printf("case #%d:\n",i);
        printf("%.6f",res);
    }
    return 0;
}


float count(float *n, char *s, int n1, int n2)
{
    int i=0;
    float t1=n[i],t2=n[i+1];
    char ch;
    while (i<n2-1)
    {
        ch=s[n2-1-i];
        if (ch == '+')
        {
            t1=t1+t2;
            i++;
            t2=n[i+1];
        }
        else if (ch == '-')
        {
            t1=t1-t2;
            i++;
            t2=n[i+1];
        }
        else if (ch == '*')
        {
            t1=t1*t2;
            i++;
            t2=n[i+1];
        }
        else if (ch == '/')
        {
            t1=t1/t2;
            i++;
            t2=n[i+1];
        }
    }

    ch=s[n2-1-i];
    if (ch == '+')
    {
        t1=t1+t2;
    }
    else if (ch == '-')
    {
        t1=t1-t2;
    }
    else if (ch == '*')
    {
        t1=t1*t2;
    }
    else if (ch == '/')
    {
        t1=t1/t2;
    }
    
    
    return t1;
}



