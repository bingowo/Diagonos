#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 501

void f(char *n, int *i, int *f, int pos);//f函数的作用是把n数组中的整数部分和小数部分分别保存至i数组和f叔祖中
void add(int *res, int n);
void add_i(int *res,int *a,int *b, int c);//实现a与b之间整数部分的加法运算,结果保存至res数组中
int add_f(int *res,int *a,int *b);//实现a与b之间小数部分的加法运算,返回个位部分的进位
int rounded(int *f, int n);//四舍五入函数，保留n位，返回个位的进位


int main()
{
    char a[N];
    char b[N];
    int n;
    int i;
    scanf("%s %s %d",a,b,&n);

    int ia[N]={0};//储存a的整数部分
    int ib[N]={0};//储存b的整数部分
    int fa[N]={0};//储存a的小数部分
    int fb[N]={0};//储存b的小数部分
    
    int pa=-1,pb=-1;
    int la=strlen(a);
    int lb=strlen(b);
    for (i=0;i<la;i++)
    {
        if (a[i]=='.')
        {
            pa=i;
        }
    }

    for (i=0;i<lb;i++)
    {
        if (b[i]=='.')
        {
            pb=i;
        }
    }

    //a,b数组中的整数部分与小数部分分别存入数组中
    f(a,ia,fa,pa);
    f(b,ib,fb,pb);

    //分别实现整数部分与小数部分的加法运算
    int res_i[N+1]={0};
    int res_f[N+1]={0};

    int c=add_f(res_f,fa,fb);
    add_i(res_i,ia,ib,c);
    
    //得到结果之后进行四舍五入
    c=rounded(res_f,n+1);
    if (c == 1)
    {
        add(res_i,1);
    }

    //输出部分
    int len1=1,len2=1;//len1保存整数部分的位数,len2保存小数部分的位数
    
    for (i=N;i>=0;i--)
    {
        if (res_i[i] != 0)
        {
            len1=i+1;break;
        }
    }
    
    
    for (i=0;i<len1;i++)
    {
        printf("%d",*(res_i+i));
    }
    putchar('.');
    for (i=0;i<n;i++)
    {
        printf("%d",*(res_f+i));
    }
    return 0;
}


void f(char *n, int *i, int *f, int pos)//f函数的作用是把n数组中的整数部分和小数部分分别保存至i数组和f叔祖中
{
    int len=strlen(n);
    int j=0;
    if (pos<0)//只有整数
    {
        char *p=n;
        while (*p)
        {
            if (isdigit(*p))
            {
                i[len-1-j]=*p-'0';
            }
            j++;
            p++;
        }
    }
    
    else if (!pos)//整数部分为0的小数
    {
        char *p=n+1;
        while (*p)
        {
            if (isdigit(*p))
            {
                f[len-1-j]=*p-'0';
            }
            j++;
            p++;
        }
    }
    
    else if (pos>0)//浮点数
    {
        char *p=n;
        int flag=0;

        while (*p)
        {
            
            if (*p == '.')
            {
                flag=1;
                j=0;
            }
            
            else if (!flag && isdigit(*p))//输入整数部分
            {
                i[j++]=*p-'0';
            }
            
            else if (flag && isdigit(*p))
            {
                f[j++]=*p-'0';
            }

            p++;
        }
    }
    return;
}

void add(int *res, int n)
{
    int i;
    int l=0;
    for (i=N;i>=0;i--)
    {
        if (res[i]!=0)
        {
            l=i;break;
        }
    }
    
    res[0]+=n;
    int c=res[0]/10;
    res[0]=res[0]%10;
    for (i=1;i<=l;i++)
    {
        res[i]+=c;
        c=res[i]/10;
        res[i]=res[i]%10;
    }
    if (c>0)
    {
        res[i]=c;
        l++;
    }

    for (i=0;i<=l;i++)
    {
        int t=res[l-i];
        res[l-i]=res[i];
        res[i]=t;
    }
}

void add_i(int *res,int *a,int *b, int c)//实现a与b之间整数部分的加法运算,结果保存至res数组中
{
    int posa=0,posb=0;
    int i;
    for (i=N-1;i>=0;i--)
    {
        if (a[i]!=0)
        {
            posa=i;
            break;
        }
    }
    
    for (i=N-1;i>=0;i--)
    {
        if(b[i]!=0)
        {
            posb=i;
            break;
        }
    }

    int na[N]={0};
    int nb[N]={0};
    i=0;
    while (i<=posa)
    {
        na[posa-i]=a[i];
        i++;
    }
    i=0;
    while (i<=posb)
    {
        nb[posb-i]=b[i];
        i++;
    }

    i=0;
    res[0]=c;
    while (i<=posa || i<=posb)
    {
        res[i]+=na[i]+nb[i];
        res[i+1]=res[i]/10;
        res[i]=res[i]%10;
        i++;
    }
    
}

int add_f(int *res,int *a,int *b)//实现a与b之间小数部分的加法运算,返回个位部分的进位
{
    int posa=0,posb=0;
    int i;
    for (i=N-1;i>=0;i--)
    {
        if (a[i]!=0)
        {
            posa=i;
            break;
        }
    }
    
    for (i=N-1;i>=0;i--)
    {
        if(b[i]!=0)
        {
            posb=i;
            break;
        }
    }

    int na[N]={0};
    int nb[N]={0};
    i=0;
    while (i<=posa)
    {
        na[posa-i]=a[i];
        i++;
    }
    i=0;
    while (i<=posb)
    {
        nb[posb-i]=b[i];
        i++;
    }

    i=0;

    while (i<=posa || i<=posb)
    {
        res[i]+=na[i]+nb[i];
        res[i+1]=res[i]/10;
        res[i]=res[i]%10;
        i++;
    }

    return res[i];
}

int rounded(int *f, int n)//四舍五入函数，保留n位，返回个位的进位
{
    int i;
    int l=0;
    
    for (i=N;i>=0;i--)
    {
        if (f[i]!=0)
        {
            l=i;
            break;
        }
    }
    
    for (i=0;i<n;i++)
    {
        int t=f[n-1-i];
        f[n-1-i]=f[i];
        f[i]=t;
    }

    int c=0;
    if(f[n-1]>=5)
    {
        f[n-1]=0;
        c=1;
    }
    for (i=n-1;i>=0;i--)
    {
        if (i==n-1) continue;
        if (f[i]+c>=10)
        {
            f[i]=0;
            c=1;
        }
        else
        {
            c=0;
        }
    }
    return c;
}
