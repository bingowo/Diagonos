#include <stdio.h>

int x[]={1,-1,0};

int solve(int *w, int n, int target)
{
    int end;
    if(target==0) return 1;
    if(n==0) return 0;
    for(int i=0;i<3;i++)
    {
        end = solve(w+1, n-1, target+x[i]*w[0]);
        if(end==1) return 1;
    }
    return 0;
}

int main()
{
    int n, flag, target=1;
    scanf("%d",&n);
    int w[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",w+i);
    }
    while(1)
    {
        flag = solve(w,n,target);
        printf("%d",flag);
        if(flag==0 && solve(w,n,target+1)==0) break;
        target++;
    }
    return 0;
}
