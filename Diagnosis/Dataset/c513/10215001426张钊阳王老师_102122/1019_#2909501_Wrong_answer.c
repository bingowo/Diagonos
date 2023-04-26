#include <stdio.h>
#include <stdlib.h>
int win[10]={0};
int count[10]={0};
int lose[10]={0};

int main()
{
    int cmp(const void *a,const void *b);
    int n,m;
    int x1,x2;
    int jud;
    while(1)
    {
        scanf("%d %d",&n,&m);
        if(n==0&&m==0) break;
        int *team=(int *)malloc(sizeof(int)*n);
        for(int s=0;s<n;s++)
        {
            *(team+s)=s+1;
        }
        for(int s=0;s<m;s++)
        {
            scanf("%d %d %d",&x1,&x2,&jud);
            if(jud==1) {count[x1]+=3;count[x2]--;win[x1]++;lose[x2]++;}
            else if(jud==-1) {count[x2]+=3;count[x1]--;win[x2]++;lose[x1]++;}
            else if (jud==0) {count[x2]++;count[x1]++;}
        }
        qsort(team,n,sizeof(int),cmp);
        for(int k=n-1;k>=0;k--) if(k==0) printf("%d\n",team[k]);else printf("%d ",team[k]);
    }

    return 0;
}

int cmp(const void *a,const void *b)
{
    int a1=*(int *)a;
    int b1=*(int *)b;
    if(count[a1]!=count[b1]) return count[a1]-count[b1];
    else if(count[a1]==count[b1]){
        if(win[a1]!=win[b1]) return win[a1]-win[b1];
        else if(win[a1]==win[b1]) {
            if(lose[a1]!=lose[b1]) return lose[b1]-lose[a1];
            else return  b1-a1;
        }
    }
}