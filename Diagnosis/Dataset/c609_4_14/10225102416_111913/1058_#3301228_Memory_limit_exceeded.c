#include <stdio.h>

#define N 102//最小-10^10，共计102位
#define R -2//负二进制

typedef struct { int sign,d[N],i1,i2; }T;

int isZero(T n) { return n.i1==n.i2 && n.d[n.i1]==0;}

T Dec(T n,int b)
{
    if (b) //余数时无需减1
        if (!n.sign) n.d[n.i2]--;//n为正时个位数减1即可
        else //n为负时的处理，减1实际执行相反数的加1操作
            {
                int i;n.d[i=n.i2]++; //个位数加1
                while (n.d[i]>9) n.d[i]=0;n.d[--i]++; //从个位开始调整进位
                if (i<n.i1) n.i1--;//若调整到最高位的话，总计加了1位，如999+1
            }
    return n;
}

T DivR(T n)
{
    int i,t,carry=0;n.sign=!n.sign;//符号正负切换
    for (i=n.i1;i<=n.i2;i++) t=n.d[i]&1;n.d[i]=(carry*10+n.d[i])/-R;carry=t;
    if (!isZero(n)&&!n.d[n.i1]) n.i1++;//最高位为0时总计少了1位24
    return n;
}

void dec2R(T n)
{
    int b; if (!isZero(n)) dec2R(DivR(Dec(n,b=n.d[n.i2]&1))), printf("%1d",b); }
int main()
{
    T n={0}; char s[N+1],*p=s; scanf("%s",s);
    if (*p=='+'|*p=='-') { if (*p=='-') n.sign=1; p++; }
    n.i1=n.i2=1;
    while (*p) n.d[n.i2++]=*p++-'0';n.i2--;
    if (isZero(n)) printf("0"); else dec2R(n); printf("\n");
    return 0;
}
