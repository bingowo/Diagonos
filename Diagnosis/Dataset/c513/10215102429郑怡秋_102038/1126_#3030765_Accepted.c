#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
typedef struct{
    char a[10100];
}hh;
void tran(hh* p,int x,ll k)
{
    int i=0;
    while(k>0)
    {
        p[x].a[i]=k%10+'0';
        k/=10;
        i++;
    }
    p[x].a[i]='\0';//printf("a:%s\n",p[x].a);
}
int cmp(const void*a,const void*b)
{
    hh*p1=(hh*)a;
    hh*p2=(hh*)b;
    int x1=strlen(p1->a)-1;
    int x2=strlen(p2->a)-1;
    if(x1>x2) return 1;
    else if(x1<x2) return -1;
    else{
        while(p1->a[x1]==p2->a[x2]&&x1>0&&x2>0) x1--,x2--;
        if(p1->a[x1]>p2->a[x2]) return 1;
        else return -1;
    }
}
void plus(char* a,hh* m,int b)
{
    int carry=0;
    int l1=strlen(a),l2=strlen(m[b].a);
    int max=l1>l2?l1:l2;
    for(int i=0;i<max;i++)
    {
        int p=0,q=0;
        if(i<l1) p=a[i]-'0';
        if(i<l2) q=m[b].a[i]-'0';
        int x=p+q+carry;
        a[i]=x%10+'0';
        carry=x/10;
    }
    if(carry>0) a[max]=carry+'0';
    a[max+1]='\0';
}
int main()
{
    int n;
    scanf("%d",&n);
    hh* p=(hh*)malloc(n*sizeof(hh));
    ll tmp=0;
    for(int i=0;i<n;i++)
    {
        ll k=0;
        scanf("%lld",&k);
        tmp^=k;
        tran(p,i,k);//printf("%s\n",p[i]);
    }
    if(tmp==0)
    {
        qsort(p,n,sizeof(p[0]),cmp);//printf("%s\n",p[0].a);
        char ans[100000]={0};
        for(int i=1;i<n;i++) plus(ans,p,i);
        int i=strlen(ans)-1;
        for(;i>=0;i--) printf("%c",ans[i]);
    }
    else printf("-1\n");
    return 0;
}
