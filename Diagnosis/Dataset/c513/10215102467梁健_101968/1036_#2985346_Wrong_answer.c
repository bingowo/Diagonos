#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
typedef struct dot
{
    long long x;
    long long y;
}DOT;
int cmp(const void *a,const void *b)
{
    DOT a1=*(DOT*)a;
    DOT b1=*(DOT*)b;
    long long unsigned len1=llabs(a1.x)+llabs(a1.y);
    long long unsigned len2=llabs(b1.x)+llabs(b1.y);
    if(len1!=len2)return len1>len2?-1:1;
    else if(a1.x!=b1.x)return a1.x>b1.x?1:-1;
    else return a1.y>b1.y?1:-1;
}
int main()
{
    int n;scanf("%d",&n);
    DOT *a=NULL;
    a=(DOT*)malloc(sizeof(DOT)*n);
    for(int i=0;i<n;i++)scanf("%lld %lld",&a[i].x,&a[i].y);
    qsort(a,n,sizeof(DOT),cmp);
    long double dist=llabs(a[0].x-a[1].x)+llabs(a[0].y-a[1].y);
    printf("%.0llf\n",dist);
    long long unsigned ord[130],k=2;
    ord[1]=1;
    int Res=0;
    for(int i=2;i<129;i++){
        ord[i]=ord[i-1]+k;
        k*=2;
    }
    for(int m=0;m<n-1;m++){
        dist=llabs(a[m].x-a[m+1].x)+llabs(a[m].y-a[m+1].y);
        if((long long unsigned)dist%2==0)break;
        if (dist==1)Res++;
        else{
            for(int i=2;i<128;i++){
                if(dist==ord[i]){
                    Res+=i;break;
                }
                else if(dist>ord[i-1]&&dist<ord[i]){
                    Res+=i;break;
                }
            }
        }
    }
    printf("%d",Res);
    return 0;
}
