//整数不知道有多少个scanf返回值==EOF  在clodeblocks中ctrl z加回车表示输入数据的结束.去重排序，输出去重
#include<stdio.h>
#include<stdlib.h>
int cmp1(const void* A, const void* B)
{
    int* a = (int*) A;
    int* b = (int*) B;

    return *b-*a;

}
int cmp2(const void* A, const void* B)
{
    int* a = (int*) A;
    int* b = (int*) B;

    return *a-*b;

}
int main()
{
        char b;
        scanf("%c",&b);
        int n;
        int a[n];
        for(int j;j<n;j++)scanf("%d",a+j);
        if(b=='A')qsort(a, n, sizeof(int), cmp1);
        else qsort(a, n, sizeof(int), cmp2);
        int i=0;
        while(a[i]!=EOF){
                if(a[i]==a[i+1])a[i+1]=a[i+2];
                else i=i+1;
        }
        for(int j;j<n;j++)printf("%d%c",a[j],j!=n-1?' ':'\n');
        return 0;
}
