#include <stdio.h>

int fuc(int, int, int, int);

int main()
{
    int cas;
    scanf("%d", &cas);

    for(int k=0; k<cas; k++)
    {
        int n, p, m, t;
        scanf("%d%d%d%d", &n, &p, &m, &t);
        if(p>t || (p-t>0 ? (p-t>m?1:0) : (t-p>m?1:0)))
        {
            printf("%d\n", 0);
            continue;
        }
        int answer = fuc(n, p, m, t);
        printf("%d\n", answer);
    }

    return 0;
}

int fuc(int n, int p, int m, int t)
{
    if(m==0 && p==t) return 1;
    if(m==0 && p!=t) return 0;
    if(m>0 && t==n) return fuc(n, p, m-1, t-1);
    if(m>0 && t==1) return fuc(n, p, m-1, t+1);
    if(m>=0 && p!=0 && p!=n)
        return fuc(n, p, m-1, t+1) + fuc(n, p, m-1, t-1);
}