#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int compar(const void *p1,const void *p2);
void myPrint(int N);
int comparb(const void *p1,const void *p2);
int main()
{
    int T,n,i,*a,*b,res;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        a=(int*)malloc(n*sizeof(int));
        b=(int*)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            scanf("%d",&b[i]);
        qsort(a,n,sizeof(int),compar);
        qsort(b,n,sizeof(int),comparb);

        res=0;
        for(i=0;i<n;i++)
        {
            res+=a[i]*b[i];
        }
        myPrint(res);
        free(a);
        free(b);
    }
    return 0;
}

int compar(const void *p1,const void *p2)
{
    int flag=0;
    int *a=(int*)p1,*b=(int*)p2;
    if(*a<*b)
        flag=-1;
    else
        flag=1;
    return flag;
}
void myPrint(int N)
{
    static int tim=0;
    //int i;
    printf("case #%d:\n",tim++);
    printf("%d\n",N);
}
int comparb(const void *p1,const void *p2)
{
    return -compar(p1,p2);
}
