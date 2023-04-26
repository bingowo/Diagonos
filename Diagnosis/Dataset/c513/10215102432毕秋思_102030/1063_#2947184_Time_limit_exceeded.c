#include<stdio.h>

int effort_min(int x,int y)
{
    int ans=0;
    if(x==y) return 4*x;
    else
    {
        int L=x>y?x:y;
        int S=x<y?x:y;
        return 4*S+effort_min(L-S,S);
    }
}

int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d",effort_min(x,y));
    return 0;
}
