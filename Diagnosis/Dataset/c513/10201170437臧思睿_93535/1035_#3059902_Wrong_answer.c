#include <stdio.h>
#include <string.h>
typedef long long int ll;
typedef struct{int i;int j;ll k;}P;

int cmp(const void*a,const void*b)
{
    P *pa=(P *)a;
    P *pb=(P *)b;
    if((pb->k)!=(pa->k))
    {
       return (((pa->k)>(pb->k))?-1:1);
    }
    return (((pa->i)>=(pb->i))?-1:1);
}

int main()
{
    int n,m,a=0,b;
    scanf("%d %d",&n,&m);
    P s[n];
    while(a++<n)
    {
        scanf("%d %d",&s[a-1].i,&s[a-1].j);
        s[a-1].k=(ll)s[a-1].i*(ll)s[a-1].j*2;
    }
    qsort(s,n,sizeof(P),cmp);
    ll r=0;
    for(a=0;a<n;a++)
    {
        ll x=(ll)s[a].i*(ll)s[a].i+(ll)s[a].k;
        for(b=0;b<m-1;b++)
        {
            if(a==b || s[a].i<s[b].i){continue;}
            x+=(ll)s[b].k;
        }
        r=(r>x)?r:x;
    }
    printf("%d",r);
    return 0;
}
