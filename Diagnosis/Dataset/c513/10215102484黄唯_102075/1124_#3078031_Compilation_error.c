#include <stdio.h>
#include <stdlib.h>
#define LL long long LL 
gcd(LL a,LL b) 
{ return (b?gcd(b,a%b):a); }
int cmp(const void *a,const void *b) 
{
    return *(int*)a-*(int*)b;
    }
    int main()
    { int T;
    scanf("%d", &T); 
    for (int t = 0; t < T; ++t)
    { int N;
    scanf("%d",&N);
    int flag[1001]={0},a[1001]={0},cnt=0;
    for(int j=0;j<N;j++)
{ int d; 
scanf("%d",&d);
if(!flag[d])
{ a[cnt++]=d;flag[d]=1;}
}
qsort(a,cnt,sizeof(a[0]),cmp);
int sum=0; 
for(int i=0;i<cnt;i++)
{ for(int j=i+1;j<cnt;j++) 
if(gcd(a[i],a[j])==1) sum++; }
printf("case #%d:\n",t);
printf("%d\n",sum); 
        
    }
    return 0;
    }