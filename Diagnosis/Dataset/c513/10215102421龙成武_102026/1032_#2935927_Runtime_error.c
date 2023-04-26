#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int compar(const void *p1,const void *p2);
void myPrint(int *a);
int main()
{
    int T,N,i,j,**a,temp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        a=(int**)malloc(N*sizeof(int*));
        for(i=0;i<N;i++)
        {
            j=0;
            a[i]=(int*)malloc(50*sizeof(int));
            do
            {
                scanf("%d",&temp);
                a[i][j++]=temp;
            }
            while(temp!=-1);
        }
        qsort(a,N,sizeof(int*),compar);
        for(i=0;i<N;i++)
        {
            myPrint(a[i]);
        }
    }
    return 0;
}

int compar(const void *p1,const void *p2)
{
    int flag=0;
    int **A=(int**)p1,**B=(int**)p2,*a,*b;
    a=*A;b=*B;
    while(*a==*b)
    {
        a++;
        b++;
    }
    if(*a<*b)
        flag=1;
    else
        flag=-1;
    return flag;
}
void myPrint(int *a)
{
    //static int tim=0;
    int i=0;
    //printf("case #%d:\n",tim++);
    while(a[i]!=-1)
        printf("%d ",a[i++]);
    printf("\n");
}
