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
        char b;
        scanf("%c",&b);
        int n=0;
        int a[1000];
        while(scanf("%d",&a[1000])==1)n++;
        if(b=='A')qsort(a, n, sizeof(int), cmp1);
        else qsort(a, n, sizeof(int), cmp2);
        //for(int i=0;i<n-1;){
                //if(a[i]==a[i+1])a[i+1]=0;
                //else i=i+1;
        //}
        for(int j=0;j<n;j++){
            printf("%d%c",a[j],j!=n-1?' ':'\n');
        }
        return 0;
}
