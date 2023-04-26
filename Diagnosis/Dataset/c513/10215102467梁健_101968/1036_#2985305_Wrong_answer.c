#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
typedef struct dot
{
    long x;
    long y;
}DOT;
int cmp(const void *a,const void *b)
{
    DOT a1=*(DOT*)a;
    DOT b1=*(DOT*)b;
    long long len1=abs(a1.x)+abs(a1.y);
    long long len2=abs(b1.x)+abs(b1.y);
    if(len1!=len2)return len1>len2?-1:1;
    else if(a1.x!=b1.x)return a1.x>b1.x?1:-1;
    else return a1.y>b1.y?1:-1;
}
int main()
{
    int n;scanf("%d",&n);
    DOT *a=NULL;
    a=(DOT*)malloc(sizeof(DOT)*n);
    for(int i=0;i<n;i++)scanf("%ld %ld",&a[i].x,&a[i].y);
    qsort(a,n,sizeof(DOT),cmp);
    long double dist=llabs(a[0].x-a[1].x)+llabs(a[0].y-a[1].y);
    printf("%.0llf\n",dist);
    long long res[65],k=2;
    res[1]=1;
    for(int i=2;i<65;i++){
        res[i]=k+res[i-1];
        k*=2;
    }
    int Res=0;
    for(int i=0;i<n-1;i++){
        dist=llabs(a[i].x-a[i+1].x)+llabs(a[i].y-a[i+1].y);
        if((long long unsigned)dist%2==0)break;
        if(dist==1)Res++;
        else{
            for(int i=2;i<64;i++){
                if(dist==res[i]){
                    Res+=i;
                }
                else if(dist>res[i-1]&&dist<res[i]){
                    Res+=i;
                }
            }
        }
    }
    printf("%d",Res);

    return 0;
}
