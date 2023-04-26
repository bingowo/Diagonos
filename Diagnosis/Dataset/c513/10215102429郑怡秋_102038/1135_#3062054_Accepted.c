#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char a[10100];
}hh;
void plus(hh* m,int c,int b)
{
    int carry=0;
    int l1=strlen(m[c].a),l2=strlen(m[b].a);
    int max=l1>l2?l1:l2;
    for(int i=0;i<max;i++)
    {
        int p=0,q=0;
        if(i<l1) p=m[c].a[i]-'0';
        if(i<l2) q=m[b].a[i]-'0';
        int x=p+q+carry;
        m[c].a[i]=x%10+'0';
        carry=x/10;
    }
    if(carry>0) m[c].a[max]=carry+'0';
    m[c].a[max+1]='\0';
}
int main()
{
    int n;
    scanf("%d",&n);
    hh* ans=(hh*)malloc((n+1)*sizeof(hh));
    ans[1].a[0]='1';ans[1].a[1]='\0';
    ans[2].a[0]='2';ans[2].a[1]='\0';
    ans[3].a[0]='3';ans[3].a[1]='\0';
    ans[4].a[0]='6';ans[4].a[1]='\0';
    ans[5].a[0]='0';ans[5].a[1]='1';ans[5].a[2]='\0';
    for(int i=6;i<=n;i++)
    {
        plus(ans,i,i-1);
        plus(ans,i,i-2);
        plus(ans,i,i-4);
    }
    int l=strlen(ans[n].a);
    for(int i=l-1;i>=0;i--) printf("%c",ans[n].a[i]);
    return 0;
}