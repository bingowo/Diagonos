#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int cmp(const void* a1,const void* a2)
{   int ua1=*(int*)a1;
    int ua2=*(int*)a2;
        return ua1-ua2;
}                                  /*返回值大于0 交换 */







int main()
{
    int n,N,i,j,k,e=0,x,result=0;
    scanf("%d",&n);
    int s[n];
    N=n/2;
    int c ;

    int a[N];
    for(i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    qsort(s,n,sizeof(int),cmp);
    for(j=1;j<n;j++){
            a[e]=s[j]-s[j-1];
            e++;
            j++;
        }
    }
    qsort(a,N,sizeof(int),cmp);

    for(x=0;x<N;x++){
        result+=a[x];
    }

    printf("%d",result);



    return 0;
}