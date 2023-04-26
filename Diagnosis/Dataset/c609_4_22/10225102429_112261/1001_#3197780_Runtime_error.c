#include <stdio.h>
void f(int n, int R, int *p)
{
    int i = 0;
    while(n)
    {
        p[i]=n%R;
        n/=R;
        i++;
    }
}
int main()
{
    int T; scanf("%d",&T);
    while(T--)
    {
        int a[10] = {-1};
        int *p = a;
        for(int i = 0; i<10; i++) {a[i] = -1;}
        int n,R; scanf("%d%d",&n,&R);
        if(n<0) {printf("-"); n = -n;}
        f(n,R,p);
        for(int i = 9; i>=0; i--)
        {
            if(a[i]==-1) continue;
            if(a[i]>9) printf("%c",'A'+a[i]-10);
            else printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}