#include <stdio.h>
#include <stdlib.h>

struct post{
    int r;
    int h;
    int all;
    int skin;
};

int cmp1(const void* a,const void* b)
{
    struct post x=*((struct post*)a);
    struct post y=*((struct post*)b);
    if(x.all>y.all)return -1;
    else
        return 1;
}

int cmp2(const void* a,const void* b)
{
    struct post x=*((struct post*)a);
    struct post y=*((struct post*)b);
    if(x.skin>y.skin)return -1;
    else
        return 1;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    struct post s[1001];
    //printf("1");
    for(int i=0;i<1001;i++){
        s[i].r=0;
        s[i].h=0;
    }
    for(int i=0;i<n;i++){
        scanf("%d%d",&s[i].r,&s[i].h);
        s[i].skin=2*s[i].r*s[i].h;
        //printf("%d\n",s[i].skin);
        s[i].all=s[i].r*s[i].r+s[i].skin;
        //printf("all=%d\n",s[i].all);
    }
    qsort(s,n,sizeof(struct post),cmp1);
    int ans=s[0].all;
    //double *x=&s[1];
    qsort(s+1,n-1,sizeof(struct post),cmp2);
    for(int i=1;i<m;i++){
        ans+=s[i].skin;
    }
    printf("%d",ans);
    return 0;
}
