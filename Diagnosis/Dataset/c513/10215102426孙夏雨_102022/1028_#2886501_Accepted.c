#include <stdio.h>
#include <stdlib.h>

int cmp1(const void* p3,const void* p4)
{
    int* p1=(int* )p3;
    int* p2=(int* )p4;
    if((*(p1))>(*(p2))) return 1;
    else return -1;
}

int cmp2(const void* p3,const void* p4)
{
    int* p1=(int* )p3;
    int* p2=(int* )p4;
    if((*(p1))>(*(p2))) return -1;
    else return 1;
}

int main()
{
    char c;
    scanf("%c",&c);
    int* p=(int* )malloc(100*sizeof(int));
    char a;
    int n=0;
    do{
        int t=0,i=0;
        scanf("%d",&t);
        for(;i<n;i++) if (t==*(p+i)) break;
        if(i==n) {
            *(p+n)=t;
            n++;
        }
    }while((a=getchar())!='\n');
    if(c=='A') qsort(p,n,sizeof(int),cmp1);
    else qsort(p,n,sizeof(int),cmp2);
    for(int j=0;j<n;j++) printf("%d ",*(p+j));
    free(p);
    return 0;
}
