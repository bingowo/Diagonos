#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>


typedef struct abc
{
    char user_n[1000];
    char domain_n[1000];
}user;

int cmp(const void *_a, const void *_b);

int main()
{
    int n,num=0;
    int flag;
    int i;
    char t[2001];
    char *p=NULL;
    scanf("%d",&n);
    getchar();
    user *a = (user *)malloc(sizeof(user)*n);
    
    //读取用户信息
    while (scanf("%s",t) == 1)
    {
        p=t;
        flag=0;
        i=0;
        while (*p)
        {
            if (*p == '@')
            {
                a[num].user_n[i]='\0';
                flag=1;
                i=0;
            }
            
            else if (!flag)//读取邮件地址用户名
            {
                a[num].user_n[i++]=*p;
            }

            else if (flag)//读取邮件地址域名
            {
                a[num].domain_n[i++]=*p;
            }
            p++;
        }
        a[num].domain_n[i]='\0';
        num++;
    }

    //排序
    qsort(a,n,sizeof(user),cmp);

    //输出
    for (i=0;i<n;i++)
    {
        printf("%s@%s\n",a[i].user_n,a[i].domain_n);
    }
    return 0;
}

int cmp(const void *_a, const void *_b)
{
    user *a = (user *)_a;
    user *b = (user *)_b;
    if (strcmp((*a).domain_n,(*b).domain_n))
    {
        return 1;
    }
    else if (strcmp((*a).domain_n,(*b).domain_n) == 0  && strcmp((*b).user_n,(*a).user_n))
    {
        return 1;
    }
    else
    {
        return -1;
    }

}