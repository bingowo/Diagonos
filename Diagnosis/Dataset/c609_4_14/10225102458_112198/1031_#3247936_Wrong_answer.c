#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cnt(int m)
{

    return m*(m+1)/2;
}
int cmp(const void* a,const void* b)
{
    int aa=*(int *)a;
    int bb=*(int *)b;
    if(aa>bb)return 1;
    else return -1;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int p,q,l,u;
        scanf("%d%d",&p,&q);
        int a[p];
        for(int i=0;i<p;i++)scanf("%d",a+i);
        int len=cnt(p),count=0,number;
            int aa[len];
            for(int i=0;i<p;i++){
                    number=0;
                for(int j=i;j<p;j++){
                    number+=a[j];
                    aa[count++]=number;

                }
            }
            qsort(aa,count,sizeof(aa[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<q;j++){
            scanf("%d%d",&l,&u);
            int max=0;
            for(int i=l-1;i<u;i++)max+=aa[i];
            printf("%d\n",max);


        }
    }
    return 0;
}
