#include <stdio.h>
#include <string.h>
#define L 500
void Input(int a[])
{
    char s[L+1]; scanf("%s",s);
    int i = 0,j,k;
    while(s[i] && s[i]!='.') i++; //定位小数点
    for(j = i - 1,k = L;j >= 0; j--,k--)  a[k] = s[j]-'0'; //整数部分
    for(j = i + 1, k = L + 1;j < strlen(s); j++,k++)  a[k] = s[j]-'0'; //小数部分
}
void add(int a[],int b[],int N)
{
    int i;
    for(i = 2 * L; i > L + N; i--)
    {
        a[i] += b[i];
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }
    if(a[i+1] >= 5)//四舍五入
        a[i]++;
    for(i = L + N; i > 0; i--)
    {
        a[i] += b[i];
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }
}
int main()
{
    int A[2 * L + 1] = { 0 }; int B[2 * L + 1] = { 0 };
    int N;
    Input(A);Input(B);
    scanf("%d",&N);
    add(A,B,N);
    int i = 0;
    while(i <= L && A[i] == 0) i++; //跳过前置0
    if(i > L)  printf("0"); //整数部分为0
    else
         while(i <= L)  printf("%d",A[i++]); //整数部分
    printf(".");
    while(i <= L + N) printf("%d",A[i++]); //小数部分
    printf("\n");
    return 0;
}
