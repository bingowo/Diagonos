#include<stdio.h>
#include<stdlib.h>

int cmpfuncA(const void * a,const void * b)
{
    return(*(int*)a - *(int*)b);
}
int cmpfuncD(const void * a,const void * b)
{
    return(*(int*)b - *(int*)a);
}

int main()
{
    char ch;
    ch = getchar();
    long long int a[100],flag[100],ans[100];
    int i,j;
    for(i = 0;scanf("%lld",&a[i]) != EOF;i++)
    {
        flag[i] = 0;
        for(j=0;j<i;j++)
        {
            if(a[i] == a[j])
                break;
            else 
                flag[i] = 1;
        }
    }//循环输入，标记第一个出现的不同数字
    
    long long int index,k;
    for(index = 0,k = 0;flag[index] == 1;index++)
    {
        ans[k] = a[index];
        k++;
    }
    
    if(ch == 'A')
    {
        qsort(ans,i,sizeof(long long int),cmpfuncA);
    }
    
    if(ch == 'D')
    {
        qsort(ans,i,sizeof(long long int),cmpfuncD);
    }
    
    if(i>1)
    {
        for(j=0;j<i;j++)
            printf("%lld ",ans[j]);
        printf("%lld",ans[i]);
    }
    else
        printf("%lld",ans[i]);

    return 0;
}



