#include<stdio.h>
#include<stdlib.h>
int cmp(void *a,void *b)
{
    int *a1,*b1;
    a1=(int *)a;
    b1=(int *)b;
    while(*a1==*b1)
    {
        a1++;
        b1++;
    }
    return *a1-*b1;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int nums[2000][100];
        for(int p=0;p<2000;p++)
        {
            for(int q=0;q<100;q++) nums[p][q]=-1;
        }
        int pros;
        scanf("%d",&pros);
        int m=0,n=0;
        for(int x=0;x<pros;x++)
        {
        int tmp;
        scanf("%d",&tmp);
        while(tmp!=-1)
        {
            nums[m][n++]=tmp;
            scanf("%d",&tmp);
        }
        m++;
        n=0;
        }
        qsort(nums,pros,sizeof(nums[0]),cmp);
        for(int x=0;x<pros;x++)
        {
           for(m=0;m<2000;m++) if(nums[x][m]==-1) break;
           n=0;
           for(n=0;n<m-1;n++) printf("%d ",nums[x][n]);
           printf("%d\n",nums[x][n]);
        }
    }
}