#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    int i=0;
    for(i=0;i<T;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        int w=x^y;
        int ans=0;
        while(w)
        {
            w=w&(w-1);
            ans++;
        }
        printf("%d\n",w);
    }

}
