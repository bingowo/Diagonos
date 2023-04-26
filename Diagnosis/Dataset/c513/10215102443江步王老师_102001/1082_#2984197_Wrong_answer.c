#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#define N 501

void f(char *n, int *i, int *f, int pos);//f函数的作用是把n数组中的整数部分和小数部分分别保存至i数组和f叔祖中
void add(int *res, int n);
void add_i(int *res,int *a,int *b, int c);//实现a与b之间整数部分的加法运算,结果保存至res数组中
int add_f(int *res,int *a,int *b);//实现a与b之间小数部分的加法运算,返回个位部分的进位
int rounded(int *f, int n);//四舍五入函数，保留n位，返回个位的进位
void swap(int *a,int *b);


int main()
{
    char a[N];
    char b[N];
    int n;
    int i;
    int l=1;
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
    //debug
    /*l=1;
    for (i=N-1;i>=0;i--)
    {
        if (ia[i] != 0)
        {
            l=i+1;break;
        }
    }
    printf("ia:\n");
    for (i=0;i<=l-1;i++)
    {
        printf("%d",ia[i]);
    }
    putchar('\n');

    l=1;
    for (i=N-1;i>=0;i--)
    {
        if (fa[i] != 0)
        {
            l=i+1;break;
        }
    }
    printf("fa:\n");
    for (i=0;i<=l-1;i++)
    {
        printf("%d",fa[i]);
    }
    putchar('\n');
    */
    f(b,ib,fb,pb);
    
    //debug
    /*l=1;
    for (i=N-1;i>=0;i--)
    {
        if (ib[i] != 0)
        {
            l=i+1;break;
        }
    }
    printf("ib:\n");
    for (i=0;i<=l-1;i++)
    {
        printf("%d",ib[i]);
    }
    putchar('\n');

    l=1;
    for (i=N-1;i>=0;i--)
    {
        if (fb[i] != 0)
        {
            l=i+1;break;
        }
    }
    printf("fb:\n");
    for (i=0;i<=l-1;i++)
    {
        printf("%d",fb[i]);
    }
    putchar('\n');
    */
    //分别实现整数部分与小数部分的加法运算
    int res_i[N+1]={0};
    int res_f[N+1]={0};
    
    
    
    int c=add_f(res_f,fa,fb);
   /* 
    //debug
    
    for (i=N;i>=0;i--)
    {
        if (res_f[i] != 0)
        {
            l=i+1;break;
        }
    }
    printf("float:\n");
    for (i=0;i<=l-1;i++)
    {
        printf("%d",res_f[i]);
    }
    putchar('\n');
*/
    add_i(res_i,ia,ib,c);
/*
    //debug
    
    for (i=N;i>=0;i--)
    {
        if (res_i[i] != 0)
        {
            l=i+1;break;
        }
    }
    printf("int:\n");
    for (i=0;i<=l-1;i++)
    {
        printf("%d",res_i[i]);
    }
    putchar('\n');
    */
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
    
        /*for (i=0;i<len1;i++)
        {
            int t=res_i[len1-1-i];
            res_i[len1-1-i]=res_i[i];
            res_i[i]=t;
        }*/
    
    
    
    for (i=len1-1;i>=0;i--)
    {
        printf("%d",*(res_i+i));
    }
    putchar('.');
    
    for (i=N;i>=0;i--)
    {
        if (res_f[i] != 0)
        {
            len2=i+1;break;
        }
    }
    if(len2>=n)
    {
        for (i=0;i<n;i++)
        {
            printf("%d",*(res_f+i));
        }
    }
    else if(len2<n)
    {
        for (i=len2-1;i>=0;i--)
        {
            printf("%d",*(res_f+i));
        }
        for (i=len2;i<n;i++)
        {
            printf("0");
        }
    }
    return 0;
}


void f(char *n, int *i, int *f, int pos)//f函数的作用是把n数组中的整数部分和小数部分分别保存至i数组和f数组中
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
    
    else if (pos == 0)//整数部分为0的小数
    {
        char *p=n+1;
        while (*p)
        {
            if (isdigit(*p))
            {
                f[len-2-j]=*p-'0';
            }
            j++;
            p++;
        }
    }
    
    else if (pos>0)//浮点数
    {
        int li=pos,lf=len-pos-1;
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
                i[li-j-1]=*p-'0';
                j++;
            }
            
            else if (flag && isdigit(*p))
            {
                f[lf-j-1]=*p-'0';
                j++;
            }

            p++;
        }
    }
    return;
}
//一眼丁真，鉴定为没有问题
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

    return;
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
    int* na =(int *)malloc(sizeof(int)*N);
    for (i=0;i<N;i++)
    {
        na[i]=0;
    }
    int* nb =(int *)malloc(sizeof(int)*N);
    for (i=0;i<N;i++)
    {
        nb[i]=0;
    }
    //int na[N]={0};
    //int nb[N]={0};
    i=0;
    while (i<=posa)
    {
        na[i]=a[i];
        i++;
    }
    i=0;
    while (i<=posb)
    {
        nb[i]=b[i];
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
    free(na);free(nb);
    return ;
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
    int* na =(int *)malloc(sizeof(int)*N);
    for (i=0;i<N;i++)
    {
        na[i]=0;
    }
    int* nb =(int *)malloc(sizeof(int)*N);
    for (i=0;i<N;i++)
    {
        nb[i]=0;
    }
    //int na[N]={0};
    //int nb[N]={0};
    i=0;
    while (i<=posa)
    {
        na[i]=a[i];
        i++;
    }
    i=0;
    while (i<=posb)
    {
        nb[i]=b[i];
        i++;
    }
    
    //不足位补0
    if (posa<posb)
    {
        for (i=posa;i>=0;i--)
        {
            na[posb-posa+i]=na[i];
        }
        for (i=0;i<=posb-posa-1;i++)
        {
            na[i]=0;
        }
    }
    else if (posa>posb)
    {
        for (i=posb;i>=0;i--)
        {
            nb[posa-posb+i]=nb[i];
        }
        for (i=0;i<=posa-posb-1;i++)
        {
            nb[i]=0;
        }
    }
    i=0;

    while (i<=posa || i<=posb)
    {
        res[i]+=na[i]+nb[i];
        res[i+1]=res[i]/10;
        res[i]=res[i]%10;
        i++;
    }
    free(na);free(nb);
    return res[i];
}

int rounded(int *f, int n)//四舍五入函数，保留n位，返回个位的进位
{
    int i;
    int l=1;
    
    for (i=N;i>=0;i--)
    {
        if (f[i] != 0)
        {
            l=i+1;break;
        }
    }
    /*
    //转换前
    printf("before transforming:\n");
    for (i=0;i<n;i++)
    {
        printf("%d",f[i]);
    }
    putchar('\n');
*/
    if(l>=n)
    {
        for (i=0;i<n;i++)
        {
            f[i]=f[l-1-i];
            
        }
    }
    else
    {
        for (i=0;i<l;i++)
        {
            swap(f+i,f+l-1-i);
        }
    }
    
/*
    //转换后
    printf("after transforming:\n");
    for (i=0;i<n;i++)
    {
        printf("%d",f[i]);
    }
    putchar('\n');
   */ 
    int c=0;
    if(f[n-1]>=5)
    {
        f[n-1]=0;
        c=1;
    }
    for (i=n-1;i>=0;i--)
    {
        if (i==n-1) continue;
        f[i]+=c;
        if (f[i]>=10)
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

void swap(int *ma,int *mb)
{
    int tmp=0;
    tmp = *ma;
    *ma = *mb;
    *mb = tmp;
    return;
}