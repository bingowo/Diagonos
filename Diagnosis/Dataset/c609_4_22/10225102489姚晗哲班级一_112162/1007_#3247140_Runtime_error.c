#include <stdio.h>
#include <stdio.h>
#include <string.h>
void cmp(const void *a,const void *b)
{
  int* p1=(int*)a;
  int* p2=(int*)b;//设计一个可以得到数字补码中1的个数
  if(over(*p1)==over(*p2))
        return *(int*)a-*(int*)b;
  else
    return over(*p2)-over(*p1);
}
int over(unsigned int n)
{
    int count=0;
    while(n)
    {
        if(n%2==1)
            count++;
        n/=2;
    }
    return count;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N,n=0;
        scanf("%d",&N);
        int arr[N];
        do
        {
            scanf("%d",&arr[n]);
            n++;
        }while(getchar()!='\n');
        qsort(arr,N,sizeof(int),cmp);
        printf("case #%d\n",i);
        for(int t=0;t<N;t++)
        printf("%d ",arr[t]);
        printf('\n');
    }

    return 0;
}
