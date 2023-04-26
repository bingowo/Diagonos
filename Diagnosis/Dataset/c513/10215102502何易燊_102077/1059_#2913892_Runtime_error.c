#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}

int GCD(int x,int y)
{
    if (y>x) {x^=y; y^=x; x^=y;}
    if (x%y==0) return y;
    else return GCD(y,x%y);
}

main()
{
    int n,s;
    scanf("%d %d",&n,&s);
    int a[1001];
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    qsort(a+1,n,sizeof(a[1]),cmp);
    int i = 1;
    int p = 0, q = 0;
    while (i<n)
    {
        if (a[i]==a[i+1]) {i++; continue;}
        int need = 0;
        if (s>=(a[i+1]-a[i])*i)
        {
            s -= (a[i+1]-a[i])*i;
            for (int j=1;j<=i;j++) a[j] = a[i+1];
            i++;
        }
        else
        {
            a[i] += s/i;
            s %= i;
            p = s/GCD(s,i); q = i/GCD(s,i);
            s = 0;
            break;
        }
    }
    if (s>0) 
    {
        a[i] += s/i;
        s %= i;
        if (s) {p = s/GCD(s,i); q = i/GCD(s,i);}
    }
    if (p==0) printf("%d\n",a[i]);
    else if (a[i]==0) printf("%d/%d\n",p,q);
    else printf("%d+%d/%d\n",a[i],p,q);
    return 0;
}