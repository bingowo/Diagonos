#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define maxn 501

int main()
{
    char*a=(char*)malloc(sizeof(char)*maxn),*b=(char*)malloc(sizeof(char)*maxn);
    int N;
    scanf("%s%s%d",a,b,&N);
    // 先处理字符串，统一格式
    // 先找到a，b的小数点
    int p1=-1,p2=-1,p,l1=strlen(a),l2=strlen(b);
    for(int i=0;i<l1;i++)
    {
        if(a[i]=='.') 
        {
            p1 = i;
            break;
        }
    }
    for(int i=0;i<l2;i++)
    {
        if(b[i]=='.') 
        {
            p2 = i;
            break;
        }
    }
    // 记得考虑没有小数点的情况,即整数
    if(p1 == -1)
    {
        p1 = l1;
        a[l1++]='.';a[l1++]='0';
    }
    if(p2 == -1)
    {
        p2 = l2;
        b[l2++]='.';b[l2++]='0';
    }
    // 还要考虑纯小数的情况
    if(p1 == 0)
    {
        for(int i=l1-1;i>=0;i--) a[i+1]=a[i];
        a[0]='0';p1++;l1++;
    }
    if(p2 == 0)
    {
        for(int i=l2-1;i>=0;i--) b[i+1]=b[i];
        b[0]='0';p2++;l2++;
    }
    // 对齐小数点
    if(p1>=p2)
    {
        int d = p1 - p2;p = p1;l2+=d;
        for(int i=l2-1;i>=0;i--)
            b[i+d]=b[i];
        for(int i=0;i<d;i++)
            b[i] = '0';
    }
    else if(p1<p2)
    {
        int d = p2 - p1;p = p2;l1+=d;
        for(int i=l1-1;i>=0;i--)
            a[i+d]=a[i];
        for(int i=0;i<d;i++)
            a[i] = '0';
    }
    // 补齐末尾0
    if(l1>=l2)
        for(int i=l2;i<l1;i++) b[i] = '0';
    else
        for(int i=l1;i<l2;i++) a[i] = '0';
    // 完成格式统一，开始计算
    // 先判断大小    
    int l=strlen(a),flag=0;
    for(int i=0;i<l;i++)
    {
        if(a[i]<b[i])
        {
            flag = 1;
            break;
        }
    }
    // 若a小b大,则交换位置
    if(flag)
    {
        printf("-");
        char*c;
        c=a;a=b;b=c;
    }
    // 之后进行计算即可
    int borrow=0,tmp;
    char res[maxn];
    // 从末端开始,算到小数点停止
    for(int i=l-1;i>p;i--)
    {
        tmp = a[i] - b[i] - borrow;
        if(tmp>=0 && tmp<=9)
        {
            res[i] = tmp + '0';
            borrow = 0;
        }
        else
        {
            res[i] = tmp + 10 +'0';
            borrow = 1;
        }
    }
    res[p]='.';res[l]='\0';
    // 之后考虑整数部分
    for(int i=p-1;i>=0;i--)
    {
        tmp = a[i] - b[i] - borrow;
        if(tmp>=0 && tmp<=9)
        {
            res[i] = tmp + '0';
            borrow = 0;
        }
        else
        {
            res[i] = tmp + 10 +'0';
            borrow = 1;
        }
    }
    if(l-p>=N)
    {
        for(int i=0;i<p+N;i++) printf("%c",res[i]);
        if(res[p+N+1]>='5') printf("%c",res[p+N]+1);
        else printf("%c",res[p+N]);
    }
    else
    {
        printf("%s",res);
        for(int i=0;i<N-l+p;i++) printf("0");
    }

    return 0;
}