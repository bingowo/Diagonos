#include <stdio.h>
#include <stdlib.h>

void f(int *s,int *ans,int l,int r,int h,int n)
{
    if(h==n)
    {
        if(l<r) ans[r-l]=1;
        return ;
    }
    h++;
    f(s,ans,(l+s[h-1]),r,h,n);
    f(s,ans,l,(r+s[h-1]),h,n);
    f(s,ans,l,r,h,n);
}
int main()
{
    int n;
    scanf("%d",&n);
    int *s=(int*)malloc(sizeof(int)*n);
    int ans[2000]={0};int num=0;
    for(int i=0;i<n;i++) {scanf("%d",&s[i]);num+=s[i];}
    int l=0,r=0,h=0;
    f(s,ans,l,r,h,n);
    for(int i=1;i<=num;i++) printf("%d",ans[i]);
    printf("\n");
    free(s);
    return 0;
}
