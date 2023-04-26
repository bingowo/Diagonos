#include <stdio.h>
#include <stdlib.h>

int RecIsMeasurable(int target,int* set,int index,int n)
{
    if (target==0)
        return 1;
    if (index>=n)
        return 0;
    return (RecIsMeasurable(target+set[index],set,index+1,n)
            || RecIsMeasurable(target,set,index+1,n)
            || RecIsMeasurable(target-set[index],set,index+1,n));
}

int isMeasurable (int target,int* set,int n)
{
    return RecIsMeasurable(target,set,0,n);
}


int main()
{
    int n,sum=0;
    scanf("%d",&n);
    int* set=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
    {
        scanf("%d",&set[i]);
        sum+=set[i];
    }
    int* ST=(int*)calloc(sum,sizeof(int));

    for (int i=0;i<sum;i++)
        printf("%s",isMeasurable(i,set,n)?"1":"0");
    printf("\n");
    return 0;
}
