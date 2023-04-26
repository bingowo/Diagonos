#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int num;
    int jf;
    int yj;
    int sj;
}SR;
void Sort(SR *ps,int n)
{
    int cmp(const void *p1,const void *p2)
    {
        SR *ps1=p1;
        SR *ps2=p2;
        if((*ps1).jf>(*ps2).jf) return -1;
         else if((*ps1).jf<(*ps2).jf) return 1;
         else
         {
             if((*ps1).yj>(*ps2).yj) return -1;
             else if((*ps1).yj<(*ps2).yj) return 1;
             else
             {
                 if((*ps1).sj>(*ps2).sj) return 1;
                 else if((*ps1).sj<(*ps2).sj) return -1;
                 else
                 {
                     return (*ps1).num-(*ps2).num;
                 }
             }
         }
    }
    qsort(ps,n,sizeof(SR),cmp);
}
int main()
{
    int m,n;
    SR s[11];
    while(1)
    {
        scanf("%d",&n);scanf("%d",&m);
        if(m==0&&n==0) break;
        for(int q=0;q<11;q++)
            {
                s[q].num=q;
                s[q].jf=0;
                s[q].sj=0;
                s[q].yj=0;
            }
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(c==1)
            {
                s[a-1].jf=s[a-1].jf+3;
                s[b-1].jf=s[b-1].jf-1;
                s[a-1].yj=s[a-1].yj+1;
                s[b-1].sj=s[b-1].sj+1;
            }
            else if(c==-1)
            {
                s[a-1].jf=s[a-1].jf-1;
                s[b-1].jf=s[b-1].jf+3;
                s[b-1].yj=s[b-1].yj+1;
                s[a-1].sj=s[a-1].sj+1;
            }
            else
            {
                s[a-1].jf=s[a-1].jf+1;
                s[b-1].jf=s[b-1].jf+1;
            }
        }
        Sort(s,n);
        for(int w=0;w<n;w++) printf("%d ",s[w].num+1);
        printf("\n");
    }
}
