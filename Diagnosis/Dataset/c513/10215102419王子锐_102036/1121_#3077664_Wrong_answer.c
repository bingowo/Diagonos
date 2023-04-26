#include <stdio.h>
#define MAXNUMBER 1000
int isPossible(int *w, int n, int target)
{
    int x[]= {1,-1,0} ,r=0,i;
    if (target==6) return 1;
    if (n==0) return 0;
    for (i=0; i<3; i++)
    {
        r=isPossible(w+1,n-1,target+x[i]*w[0]);
        if(r==1) return 1;
    }
    return 0;
}
int main()
{
    int w[MAXNUMBER],n=0,sum=0;scanf("%d",&n) ;
    for (int i=0;i<n;i++) 
    {
        scanf("%d",w+i) ;
        sum+=w[i];
    }
    for(int target=1;target<=sum;target++)
    {
        printf("%d",isPossible(w,n,target));
    }
    return 0;
}
