#include<stdio.h>
#include<stdlib.h>
typedef struct {
  long long  int x,y,dis;
}node;

int cmp(const void*a,const void*b)
{
    node p1=*((node*)a);
    node p2=*((node*)b);
    if(p1.dis>p2.dis)return 1;
    else if(p1.dis<p2.dis)return -1;
    else{
        if(p1.x>p2.x)return 1;
    else if(p1.x<p2.x)return -1;
    else {
         if(p1.y>p2.y)return 1;
    else return -1;
        
    }    
        
    }
    
}
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    int n;
    scanf("%d",&n);
    node*p=(node*)malloc(sizeof(node)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&p[i].x,&p[i].y);
        long long int tmp1=p[i].x-x<0?x-p[i].x:p[i].x-x;
        long long int tmp2=p[i].y-y<0?y-p[i].y:p[i].y-y;
        p[i].dis=tmp1>tmp2?tmp1:tmp2;
    }
    qsort(p,n,sizeof(p[0]),cmp);
    printf("%lld\n%lld %lld\n",p[0].dis,p[0].x,p[0].y);
    
    
    return 0;
}