#include <stdio.h>
#include <stdlib.h>

int s[10];

void judge(int a[],int i,int n,int left,int num)
{
    if (i>=n) return ;
    if (left+a[i]==num||left-a[i]==num||left==num)
    {
        s[num] = 1;
        return ;
    }
    else
    {
        judge(a,i+1,n,left+a[i],num);
        judge(a,i+1,n,left-a[i],num);
        judge(a,i+1,n,left,num);
    }
}

int main()
{
    int a[10];
    int n; scanf("%d",&n);
    int sum = 0;
    for (int i=0;i<n;i++) {scanf("%d",&a[i]); sum += a[i];}
    for (int i=1;i<=sum;i++)
    {
        judge(a,0,n,0,i);
        if (s[i]) printf("1");
        else printf("0");
    }
    printf("\n");
    system("pause");
    return 0;
}