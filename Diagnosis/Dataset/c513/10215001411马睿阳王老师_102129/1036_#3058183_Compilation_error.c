#include<stdio.h>
#nclude<string.h>
#include<math.h>

int sum=0;
typedef struct
{
    long long int x,y,dis;
}com;

int cmp(const void*a,const void*b)
{
    com c=*(com*)a;
    com d=*(com*)b;
    if(c.dis>d.dis) return -1;
    else if(c.dis<d.dis) return 1;
    else if(c.x>d.x) return 1;
    else if(c.x<d.x) return -1;
    else if(c.y>d.y) return 1;
    else if(c.y<d.y) return -1;
}

int  re(com a,,com b)
{
    
        int j=0;
        while(1)
        {
            if(((a.x+pow(2,j)==b.x)&&a.y=b.y)||((a.x-pow(2,j)==b.x)&&a.y=b.y)||
               ((a.y+pow(2,j)==b.y)&&a.x=b.x)||((a.y-pow(2,j)==b.y)&&a.x=b.x)
               {
                   sum+=j+1;
                   j=0;
                   break;
               }
            else 
            {
                j++;
                return 
            }
        }
    
}
int main()
{
    int n,i,j;
    long long int ans;
    scanf("%d",&n);
    com *a;
    a=(com*)malloc(n*sizeof(com));
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&a[i].x,&a[i].y);
        d=abs(a[i].x)+abs(a[i].y);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    ans=abs(a[0].x-a[1].x)+abs(a[0].y-a[1].y);
    printf("%lld\n",ans);
    for(i=0;i<n;i++)
    {
        while()
    }
}
