#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a,const void*b)//一行一行的比较
{
    int *s1=*(int**)a;
    int *s2=*(int**)b;
    int i=0;
    while(s1[i]!=-1&&s2[i]!=-1)
    {
        int l=s1[i];
        int r=s2[i];
        if(l>r) return -1;
        else if(l<r) return 1;
        else
        {
            i++;
        }
    }
    if(s1[i]==-1) return 1;
    else return -1;
}

int main()
{
    int T,N,i,j;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        int k=0;
        int **t=(int**)malloc(N*sizeof(int*));//malloc的使用
        for(j=0;j<N;j++)
        {
            int x[51];
            int y=0;
            while(1)
            {
                scanf("%d",&x[y]);//先输入再判断
                if(x[y]==-1) break;
                else
                y++;
            }
            t[j]=(int*)malloc((y+1)*sizeof(int));
            for(k=0;k<=y;k++)
                t[j][k]=x[k];
        }
        qsort(t,N,sizeof(t[0]),cmp);
        for(j=0;j<N;j++)//输出注意空格和换行
        {
            for(k=0;t[j][k]!=-1;k++)
            {
                if(k==0) printf("%d",t[j][k]);
                else printf(" %d",t[j][k]);
            }
            printf("\n");
        }
    }
    return 0;
}
