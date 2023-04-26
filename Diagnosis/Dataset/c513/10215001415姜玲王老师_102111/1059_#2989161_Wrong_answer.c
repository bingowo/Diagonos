#include <stdio.h>
#include <stdlib.h>
int cmp(int *a,int*b)
{
    return(*a-*b);
}
int gcd(int a,int b)
{
    if(a%b) return gcd(b,a%b);
    else{return b;}
}
typedef struct {int a;int b;} height;
int main()
{
    int n,t,c[1001],i,j=0,sum=0,width=0,ans,k;
    scanf("%d%d",&n,&t);
    for(i=0;i<n;i++)
    {
        scanf("%d",&c[i]);
    }
    qsort(c,n,sizeof(c[0]),cmp);
    height h[1001];
    for(i=0;i<n-1;i++)
    {
        h[j].a=c[i];
        h[j].b=1;
        for(;c[i]==c[i+1]&&i<n-1;i++){h[j].b++;}
        j++;
    }
    if(n==1){h[0].a=c[0];j=1;h[0].b=1;}
    for(i=0;i<j-1;i++)
    {

        width+=h[i].b;
        sum+=(h[i+1].a-h[i].a)*width;
        if(sum>=t) break;
    }
    if(sum<t)
    {
        width+=h[i].b;
        ans=h[j-1].a+(t-sum)/width;
        printf("%d",ans);
        k=gcd((t-sum)%width,width);
        if((t-sum)%width) printf("+%d/%d",((t-sum)%width)/k,width/k);
    }
    if(sum==t)
    {
        printf("%d",h[i+1].a);
    }
    if(sum>t)
    {
        if((sum-t)%width)
        {
        ans=h[i+1].a-(sum-t)/width-1;
        printf("%d",ans);
        printf("+");
        k=gcd((sum-t)%width,width);
        printf("%d/%d",(width-(sum-t)%width)/k,width/k);

        }
        else printf("%d",(h[i+1].a-(sum-t)/width));
    }

}
