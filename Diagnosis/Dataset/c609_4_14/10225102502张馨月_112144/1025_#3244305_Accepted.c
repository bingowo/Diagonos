typedef struct{
int w;
int l;
int p;
int score;
int num;
} info;

int cmp(const void*a,const void*b)
{
    info pa=*(info*)a;
    info pb=*(info*)b;
    if(pa.score!=pb.score)
        return pb.score-pa.score;
    else
    {
        if(pa.w!=pb.w)
            return pb.w-pa.w;
        else
        {
            if(pa.l!=pb.l)
                return pa.l-pb.l;
            else return pa.num-pb.num;
        }
    }

}

#include<stdio.h>
#include<stdlib.h>
int main()
{
    long long n,m;
    info*res;
    scanf("%lld%lld",&n,&m);
    while(m!=0||n!=0)//n是球队数量，m是比赛场数
   {
    //info*res;
    //info res[n];//={0};




    res=(info*)malloc(n*sizeof(info));
    int s;
    for(s=0;s<n;s++)
    {
        res[s].score=0;
        res[s].l=0;
        res[s].p=0;
        res[s].w=0;

    }
    for(int i=0;i<n;i++) res[i].num = i;
    int i,j,k;
    for(long long q=0;q<m;q++)
    {
        scanf("%d%d%d",&i,&j,&k);

        if(k==0)
            {res[i-1].p++;res[j-1].p++;}
        else if(k==1)
            {res[i-1].w++;res[j-1].l++;}
        else if(k==-1)
            {res[i-1].l++;res[j-1].w++;}
        //if(m==0&n==0)
           // break;
    }
    //int score[n+1]={0};还有一个score【0】=0,排在最后（第n位）
    for(int v=0;v<n;v++)
        res[v].score=3*res[v].w-res[v].l+res[v].p;
    qsort(res,n,sizeof(res[0]),cmp);
    int u;
    for( u=0;u<n-1;u++)
        printf("%d ",res[u].num+1);
    printf("%d\n",res[u].num+1);
    free(res);


    scanf("%lld%lld",&n,&m);

   }

    return 0;
}

