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
        int a[1000];
        while(scanf("%d",&a[n])==1)n++;
        int len=n;
        if(c=='A')qsort(a, n, sizeof(int), cmp1);
        else qsort(a, n, sizeof(int), cmp2);
        for(int i=0;i<n;i++)
	    {
		    int k = a[i];
		    for(int j=i+1;j<n;j++)
		    {
			    if(k==a[j])//判断数组中是否有重的元素
			    {
				    for(int k=j;k<n-1;k++)
				    {
					    a[k] = a[k+1];
				    } 
				    n--;
				    j--;//这一步非常重要，没有的话部分结果就会不正确
			    }
		    }
	    }
        for(int j=0;j<n;j++){
            printf("%d%c",a[j],j!=n-1?' ':'\n');
        }
        return 0;
}
