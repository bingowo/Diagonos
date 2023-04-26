#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int *A,*B,hash[1001];
int compar(const void *p1,const void *p2);
void gethash(int m);
void myPrint(char*a);
int main()
{
    int n,m,i,j;
    scanf("%d",&m);
    A=(int*)malloc(m*sizeof(int));
    for(i=0;i<m;i++)
    {
        scanf("%d",&A[i]);
    }
    gethash(m);
    scanf("%d",&n);
    B=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&B[i]);
    }
    qsort(B,n,sizeof(int),compar);
    for(i=0;i<n;i++)
    {
        printf("%d ",B[i]);
    }

    free(A);free(B);
    return 0;
}
int compar(const void *p1,const void *p2)
{
    int flag=0,numa,numb,fa,fb;
    int *a=(int*)p1,*b=(int*)p2;
    fa=hash[*a];
    fb=hash[*b];
    if(fa!=0&&fb!=0)
    {
        if(fa<fb)
            flag=-1;
        else
            flag=1;
    }
    else if(fa==0&&fb==0)
    {
        if(*a<*b)
            flag=-1;
        else
            flag=1;
    }
    else if(fa==0&&fb!=0)
    {
        flag=1;
    }
    else
        flag=-1;
    return flag;
}
void gethash(int m)
{
    int i,j=1;
    memset(hash,0,sizeof(hash));
    for(i=0;i<m;i++)
    {
        hash[A[i]]=j++;
    }
}
void myPrint(char*a)
{
    static int tim=0;
    int i=0;
    printf("case #%d:\n",tim++);
    printf("%s\n",a);
}
