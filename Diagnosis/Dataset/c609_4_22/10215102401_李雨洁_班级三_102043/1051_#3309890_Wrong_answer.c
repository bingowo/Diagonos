#include <stdio.h>
#include <string.h>
#define L 500
int Input(int a[])
{
    char s[L+1];
    scanf("%s",s);
    int i = 0,j,k;
    while(s[i] && s[i]!='.')
        i++; //定位小数点
    int len=i;
    for(j = i - 1,k = L;j >= 0; j--,k--)
        a[k] = s[j]-'0'; //整数部分
    for(j = i + 1, k = L + 1;j < strlen(s); j++,k++)
        a[k] = s[j]-'0'; //小数部分
    return len;
}
void sub(int a[],int b[],int N)//A-=B
{
    //int flag=0;//结果符号位
    int i;
    for(i = 2 * L; i > L + N; i--)
    {
        if(a[i] >= b[i]) a[i] -= b[i];
        else
        {
            a[i-1] -= 1;
            a[i] += 10;
            a[i] -= b[i];
        }
    }
    if(a[i+1] >= 5)//四舍五入
        a[i]++;
    for(i = L + N; i > 0; i--)
    {
        if(a[i] >= b[i]) a[i] -= b[i];
        else
        {
            a[i-1] -= 1;
            a[i] += 10;
            a[i] -= b[i];
        }
    }

}

int main()
{
    int A[2 * L + 1] = { 0 };
    int B[2 * L + 1] = { 0 };
    int N;
    int len1=Input(A);
    int len2=Input(B);
    scanf("%d",&N);
    int flag=0;
    if(len1>len2)
        flag=0;
    else if(len1==len2)
    {
        for(int i=len1-1;i>=0;i--)
        {
            if(A[i]>B[i])
            {
                flag=0;
                break;
            }
            if(A[i]<B[i])
            {
                flag=1;
                break;
            }
        }

    }
    else flag=1;
    sub(A,B,N);
    if(flag==1)
            printf("-");
    int i = 0;
    while(i <= L && A[i] == 0)
        i++; //跳过前置0
   //整数部分
    if(i > L)
        printf("0");
    else
    {
        while(i <= L)
            printf("%d",A[i++]);
    }
    printf(".");
    //小数部分
    while(i <= L + N)
        printf("%d",A[i++]);
    printf("\n");
    return 0;
}
