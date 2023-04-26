//整数不知道有多少个scanf返回值==EOF  在clodeblocks中ctrl z加回车表示输入数据的结束.去重排序，输出去重
#include<stdio.h>
#include<stdlib.h>
int cmp1(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;

}
int cmp2(const void* a, const void* b)
{
    
    return *(int*)b-*(int*)a;

}
int main()
{
        char c;
        scanf("%c",&c);
        int n=0;
        int a[1000],b[1000];
        while(scanf("%d",&a[n])==1)n++;
        if(c=='A')qsort(a, n, sizeof(int), cmp1);
        else qsort(a, n, sizeof(int), cmp2);
        int i=0;
        while(a[i]!=0){
                if(a[i]==a[i+1])b[i]=a[i];
                else i++;
        }
        for(int j=0;j<n;j++){
            printf("%d%c",b[j],j!=n-1?' ':'\n');
        }
        return 0;
}
