#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char proto[7];
    char domain[300];
    char adress[300];
}WEB;

int cmp1(const void* a,const void* b)
{
    WEB* pa=(WEB*)a;  WEB* pb=(WEB*)b;
    return strcmp(pa->proto,pb->proto);
}

int cmp2(const void* a,const void* b)
{
    WEB* pa=(WEB*)a;  WEB* pb=(WEB*)b;
    if (strcmp(pa->domain,pb->domain)==0)
    {
        return strcmp(pa->adress,pb->adress);
    }
    else return strcmp(pa->domain,pb->domain);
}

int main()
{
    int n,M=0;
    scanf("%d\n",&n);
    WEB* arr=(WEB*)malloc(n*sizeof(WEB));
    for (int i=0;i<n;i++)
    {
        char c;
        int m=0;
        while ((c=getchar())!=EOF && c!='\n' && c!=':')
        {
            arr[i].proto[m++]=c;
        }
        arr[i].proto[m]=0;
        while ((c=getchar())!=EOF && c!='\n' && c=='/');
        //.................................
        m=1;
        arr[i].domain[0]=c;
        while ((c=getchar())!=EOF && c!='\n' && c!='/')
        {
            arr[i].domain[m++]=c;
        }
        arr[i].domain[m]=0;
        //........................................
        m=0;
        while ((c=getchar())!=EOF && c!='\n')
        {
            arr[i].adress[m++]=c;
        }
        arr[i].adress[m]=0;

        if (strcmp(arr[i].proto,"http")==0)
            M++;
    }

    qsort(arr,n,sizeof(WEB),cmp1);
    qsort(arr,M,sizeof(WEB),cmp2);
    for (int i=0;i<M;i++)
        printf("%s://%s/%s\n",arr[i].proto,arr[i].domain,arr[i].adress);
    return 0;
}
