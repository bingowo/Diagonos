#include <stdio.h>
#include <stdlib.h>

int issame(int yu[],int mid,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(yu[i]==mid) return i;
    }
    return -1;
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int zi,mu,j=0,k=0,mid,st=-1,en=-1;
        scanf("%d%d",&zi,&mu);
        int zheng=zi/mu;
        int shang[100],yu[100];
        memset(shang,0,sizeof(int)*100);
        memset(yu,0,sizeof(int)*100);
        mid=zi%mu;
        yu[k++]=mid;
        while(mid>0)
        {
            mid*=10;
            shang[j++]=mid/mu;
            mid=mid%mu;
            if(issame(yu,mid,k)>=0) {st=issame(yu,mid,k);en=k-1;break;}
            yu[k++]=mid;
        }
        int len=j;
        printf("case #%d:\n",i);
        if((st!=-1)&&(en!=-1))
        {
            printf("%d.",zheng);
            for(j=0;j<len;j++) printf("%d",shang[j]);
            printf("\n");
            printf("%d-%d\n",st+1,en+1);
        }
        else if(len==0)
        {
            printf("%d",zheng);
        }
        else
        {
            printf("%d.",zheng);
            for(j=0;j<len;j++) printf("%d",shang[j]);
            printf("\n");
        }

    }
    return 0;
}
