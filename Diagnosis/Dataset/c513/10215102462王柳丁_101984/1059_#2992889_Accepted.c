#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b);
int gcd(int a,int b);
int main()
{
   int n,s,i,area=0;
   int res_int=0,res_fz=0,res_fm=0;
   int a[1111];
   scanf("%d %d",&n,&s);
   for(i=0;i<n;i++){scanf("%d",&a[i]);}
   qsort(a,n,sizeof(a[0]),cmp);
   //for(i=0;i<n;i++){printf("%d",a[i]);}
   a[n]=1000009;
   for(i=1;i<=n;i++)
   {
       area=(a[i]-a[i-1])*i;
       if(area>s)
       {
           res_int=a[i-1]+s/i;
           res_fz=s%i;
           res_fm=i;
           break;
       }
       else s-=area;
   }
   int mid=gcd(res_fz,res_fm);
   res_fz=res_fz/mid;
   res_fm=res_fm/mid;
   if(res_int==0&&res_fz!=0)
   {
       printf("%d/%d\n",res_fz,res_fm);
   }
   else if(res_int!=0&&res_fz!=0)
   {
       printf("%d+%d/%d\n",res_int,res_fz,res_fm);
   }
   else if(res_int!=0&&res_fz==0)
   {
       printf("%d\n",res_int);
   }
    return 0;
}
int cmp(const void *a,const void *b)
{
    return ((*(int *)a)>(*(int *)b))?1:-1;
}
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
