#include <stdio.h>
#include <stdlib.h>
/*
int main()
{
    long long int T;
    scanf("%lld",&T);
    char C[37] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G',
    'H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};//方法一：对照表
    while(T--)
    {
        int n,r;
        scanf("%d %d",&n,&r);
        char num[40],rnum[40];
        int j = 0;
        if (n<0)  num[0] = '-',j++,n=0-n;
        int i = 0;
        while(n>0)
        {
            int a = n%r;
            rnum[i++] = C[a];// 方法二：余数可以判断是否大于10，进而对'A'进行加减
            n = n/r;
        }
        for (int e = i-1;e>=0;--e)
        {
            num[j++] = rnum[e];
        }
        num[j] = 0;
        printf("%s\n",num);
    }
    return 0;
}
/*
小数：从小数点开始向小数点两侧分别取n位转化
*/
// 方法三：递归实现（利用递归自身的逆序输出）
// 递归到最后一位回溯时，依次输出

char C[37] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G',
    'H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
void printd(int n,int r)
{
    if(n<0){
        putchar('-');
        n = -n;
    }
    else {
        if (n>r)
        {
            printd(n/r,r);
            putchar(C[n%r]);
        }
        else putchar(C[n]);
    }
}
int main()
{
    long long int T;
    scanf("%lld",&T);
    while(T--)
    {
        int n,r;
        scanf("%d %d",&n,&r);
        printd(n,r);
        printf("\n");
    }
    return 0;
}