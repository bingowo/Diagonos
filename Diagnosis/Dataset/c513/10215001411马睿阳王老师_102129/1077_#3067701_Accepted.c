#include<stdio.h>
#include<string.h>

typedef struct
{
    int pos;int num;
}bin;

int cmp1(const void*a,const void*b)
{
    bin x=*(bin*)a;
    bin y=*(bin*)b;
    if(x.pos<y.pos) return -1;
    else return 1;
}

int cmp2(const void*a,const void*b)
{
     int x=*(int*)a;
     int y=*(int*)b;
     if(x<y) return -1;
     else return 1;
}

int main()
{
    int sa[1007],sb1[1007],sb3[1007];
    bin sb2[1007];
    int i,j,k=0,t=0,m,n,flag=0;
    scanf("%d",&m);
    for(i=0;i<m;i++)
        scanf("%d",&sa[i]);
    scanf("%d",&n);
    for(j=0;j<n;j++)
        scanf("%d",&sb1[j]);
    for(j=0;j<n;j++)
    {
        for(i=0;i<m;i++)
        {
            if(sb1[j]==sa[i])
            {
                sb2[k].pos=i;
                sb2[k].num=sb1[j];
                k++;
                flag=1;
                break;
            }
        }
        if(flag==0)
            sb3[t++]=sb1[j];
        flag=0;
    }
    qsort(sb2,k,sizeof(sb2[0]),cmp1);
    qsort(sb3,t,sizeof(sb3[0]),cmp2);
    for(i=k,j=0;i<k+t;i++,j++)
        sb2[i].num=sb3[j];
    for(i=0;i<k+t;i++)
    {
        if(i!=k+t-1)
            printf("%d ",sb2[i].num);
        else
        {
            printf("%d",sb2[i].num);
        }
    }
    return 0;
}
