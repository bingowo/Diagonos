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
        printf("%lld",flag[1]);
    }//循环输入，标记第一个出现的不同数字
    
   
    

    return 0;
}



