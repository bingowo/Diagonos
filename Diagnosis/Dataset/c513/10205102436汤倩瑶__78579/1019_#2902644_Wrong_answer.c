#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int num,win,fail,sum;
}bs;
int cmp(const void *a,const void *b)
{
    bs p1=*((bs*)a);
    bs p2=*((bs*)b);
    if(p1.sum!=p2.sum)return p2.sum-p1.sum;
    else if(p1.win!=p2.win)return p2.win-p1.win;
else if(p1.fail!=p2.fail)return p1.fail-p2.fail;
else return p1.num-p2.num;


}
int main()
{
    int m,n;
    while(scanf("%d%d",&n,&m)!=EOF&&m!=0&&n!=0)
    {
        bs *p=(bs *)malloc(sizeof(bs)*n);
        for(int i=0;i<n;i++)
       { p[i].sum=0;p[i].win=0;p[i].fail=0;p[i].num=i+1;}

        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(c==1){
                p[a-1].sum+=3;
                p[b-1].sum-=1;
                p[a-1].win+=1;
                p[b-1].fail+=1;
            }
            else if(c==0){
                p[a-1].sum+=1;
                p[b-1].sum+=1;
                
            }
            else {
                p[a-1].sum-=1;
                p[b-1].sum+=3;
                p[b-1].win+=1;
                p[a-1].fail+=1;
            }
        }
qsort(p,n,sizeof(p[0]),cmp);
int k;
for(k=0;k<n-1;k++)
printf("%d ",p[k].num);
printf("%d\n",p[n-1].num);

    }

}
