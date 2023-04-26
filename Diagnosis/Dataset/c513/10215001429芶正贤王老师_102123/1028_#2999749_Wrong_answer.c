#include<stdio.h>
#include<stdlib.h>

int cmpfuncA(const void * a,const void * b)//升序排
{
    return(*(int*)a - *(int*)b);
}
int cmpfuncD(const void * a,const void * b)//降序排
{
    return(*(int*)b - *(int*)a);
}

int main()
{
    char ch;
    ch = getchar();
    long long int a[100],flag[100],ans[100];
    int i,j,n;
    for(i = 0;scanf("%lld",&a[i]) != EOF;i++)
    {
        flag[i] = 1;
        for(j=0;j<i;j++)
        {
            if(a[i] == a[j])
            {
                flag[i] = 0;
                break;     //重复出现
            }
        }
    }//循环输入，标记第一个出现的不同数字,数据个数为i-1
    n = i-1;
    long long int index,k;
    for(index = 0,k = 0;index < n;index++)
    {
        if(flag[index] == 1)
        {
            ans[k] = a[index];
            k++;
        }
    }
    int N;
    N = k;
    
    if(ch == 'A')
    {
        qsort(ans,i,sizeof(long long int),cmpfuncA);
    }
    
    if(ch == 'D')
    {
        qsort(ans,i,sizeof(long long int),cmpfuncD);
    }
    
    if(N>1)
    {
        for(j=0;j<N-1;j++)
            printf("%lld ",ans[j]);
        printf("%lld",ans[N-1]);
    }
    else
        printf("%lld",ans[N-1]);

    return 0;
}
