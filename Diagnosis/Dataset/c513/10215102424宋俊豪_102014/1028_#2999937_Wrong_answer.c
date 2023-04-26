#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>



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
    int a[100],flag[100],ans[100];
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
    }//循环输入，标记第一个出现的不同数字,数据个数为i
    n=i;
    int index,k;
    for(index = 0,k = 0;index < n;index++)
    {
        if(flag[index] == 1)
        {
            ans[k] = a[index];
            k++;
        }
    }
    int N;
    N = k ;
    if(ch == 'A')
    {
        qsort(ans,k,sizeof(int),cmpfuncA);
    }

    if(ch == 'D')
    {
        qsort(ans,k,sizeof(int),cmpfuncD);
    }

    if(N>1)
    {
        for(j=0;j<N-1;j++)
            printf("%d ",ans[j]);
        printf("%d",ans[N-1]);
    }
    else
        printf("%d",ans[0]);

    return 0;
}
