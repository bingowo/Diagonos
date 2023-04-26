#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void*a,const void *b)
{
    int *p1=(int *)a;
    int *p2=(int *)b;
    while(*p1==*p2)
    {
        p1++;p2++;
    }
    if(*p1<*p2)
    {
        return 1;
    }
    else if(*p1>*p2)
    {
        return -1;
    }
}

int main()
{
    int count,num;
    scanf("%d",&count);

    while(count--)
    {
        int A[1000][50];
        scanf("%d",&num);

        for(int i=0;i<num;i++)
        {
            int j=0;
            while(1)
            {
                scanf("%d",&A[i][j]);
                if(A[i][j]==-1)
                    break;
                else{j++;}
            }
        }
        qsort(A,num,sizeof(A[0]),cmp);
        for(int i=0;i<num;i++)
        {
            int j=0;
            while(1)
            {
                if(A[i][j+1]==-1)
                {
                    printf("%d\n",A[i][j]);
                    break;
                }
                else
                {
                    printf("%d ",A[i][j]);
                    j++;
                }

            }

        }
    }
}
