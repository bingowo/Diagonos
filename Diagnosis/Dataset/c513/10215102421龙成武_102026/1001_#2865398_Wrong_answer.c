#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
char* changeit(int N,int R)
{
    if(N<0) N=-N;
    char* result,*result2;
    char res;
    int a=N,tim=0,i=0,j;          //记录原来的N
    while(a!=0)
    {
        a=a/R;
        tim++;
    }
    result=(char*)malloc((tim+1)*sizeof(char));
    result2=(char*)malloc((tim+1)*sizeof(char));
    while(N>R)
    {
        if(N%R<10)
        {
            res=48+N%R;
        }
        else if(N%R>=10)
        {
            res=55+N%R;
        }
        result[i++]=res;
        N=N/R;
    }
    if(N<10)
    {
        res=48+N;
    }
    else if(N>=10)
    {
        res=55+N;
    }
    result[i++]=res;
    result[i]=0;
    for(j=0;result[j]!=0;j++)
    {
        result2[j]=result[i-1-j];
    }
    result2[j]=0;
    free(result);
    return result2;
}

int main()
{
    int T;
    scanf("%d",&T);
    int *a;
    a=(int*)malloc(2*T*sizeof(int));
    for(int i=0;i<2*T;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<T;i++)
    {
        int j=2*i;
        if(a[j]<0)
        printf("-%s\n",changeit(a[j],a[j+1]));
        else
        printf("%s\n",changeit(a[j],a[j+1]));
    }
    free(a);
    return 0;
}