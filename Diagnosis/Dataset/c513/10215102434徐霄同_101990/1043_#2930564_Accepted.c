#include <stdio.h>
#include <string.h>
char s[102],s0[102];
int l,ll;
void add(int x,char y)
{
    int i;
    for(i=l+1;i>x;i--)
        s0[i]=s0[i-1];
    s0[x]=y;
}
int dec()
{
    int a[102];
    int i,n,l0;
    for(i=0;i<ll;i++)
        a[i]=0;
    if(s0[0]!=s0[1])
        a[0]=1;
    if(s0[ll-1]!=s0[ll-2])
        a[ll-1]=1;
    for(i=1;i<ll-1;i++)
        if(s0[i]!=s0[i-1]&&s0[i]!=s0[i+1])
            a[i]=1;
    n=0;
    l0=0;
    for(i=0;i<ll;i++)
        if(a[i]==1){
            s0[l0]=s0[i];
            l0++;
        }
        else
            n++;
    for(i=l0;i<ll;i++)
        s0[i]=0;
    ll=l0;
    return n;
}
int main()
{
    int t,i,j,m,n,d;
    char c;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s",s);
        l=strlen(s);
        m=0;
        for(j=0;j<=l;j++)
            for(c='A';c<='C';c++){
            strcpy(s0,s);
            ll=l+1;
            add(j,c);
            d=dec();
            n=d;
            while(ll>0&&d!=0){
                d=dec();
                n=n+d;
            }
            if(n>m)
                m=n;
            }
        printf("case #%d:\n",i);
        printf("%d\n",m);
    }
    return 0;
}