#include<stdio.h>
#include<stdlib.h>

int win[15],lose[15],score[15];

int cmp(const void* a,const void *b)
{
    int ia=*(int*)a,ib=*(int*)b;
    if(score[ia]==score[ib])
    {
        if(win[ia]==win[ib])
        {
            if(lose[ia]==lose[ib]) return ia-ib;
            else return lose[ia]-lose[ib];
        }
        else return win[ib]-win[ia];
    }
    else return score[ib]-score[ia];
}

int main()
{
    int m,n;
    while (scanf("%d %d",&n,&m))
    {
        if(m==0 && n==0) break;
        int a,b,c,i,index[15]={0,1,2,3,4,5,6,7,8,9,10,11};
        for(i=0;i<15;i++) {score[i]=0;win[i]=0;lose[i]=0;}
        while (m--)
        {
            scanf("%d %d %d",&a,&b,&c);
            a--;b--;
            if(c==1) {score[a]+=3;win[a]++;score[b]--;lose[b]++;}
            else if(c==-1) {score[a]--;lose[a]++;score[b]+=3;win[b]++;}
            else if(c==0) {score[a]++;score[b]++;}
        }
        qsort(index,n,sizeof(index[0]),cmp);
        for(i=0;i<n;i++) i!=n-1 ? printf("%d ",index[i]+1):printf("%d\n",index[i]+1);
    }
    return 0;
}