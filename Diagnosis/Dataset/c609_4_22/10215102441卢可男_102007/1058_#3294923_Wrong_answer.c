#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int cnt;
    int v[101];
}bigint;
void DIV(bigint*n)
{
    int carry=0;
    if(n->v[n->cnt-1]<2)carry=1,n->cnt--;
    for(int i=n->cnt-1;i>=0;i--)
    {
        int t=carry*10+n->v[i];
        carry=t%2;
        n->v[i]=t/2;
    }
}
void add1(bigint*n)
{
    int carry=0,i=1;
    n->v[0]+=1;
    carry=n->v[0]/10;
    n->v[0]%=10;
    while(carry!=0&&i<n->cnt)
    {
        n->v[i]+=carry;
        n->v[i]%=10;
        carry=n->v[i]/10;
        i++;
    }
    if(carry!=0)
    {
        n->v[i]=carry;
        n->cnt++;
    }
}
int main()
{
    char s[110]={0};
    scanf("%s",s);
    int len=strlen(s);
    bigint n={0,{0}};
    int sign=1;

    for(int i=len-1;i>=1;i--)
    {
        n.v[n.cnt++]=s[i]-'0';
    }
    if(s[0]=='-')
    {
        sign=-1;
    }
    else
    {
        n.v[n.cnt++]=s[0]-'0';
    }
    int ans[400]={0};
    int index=0;
    while(n.cnt>0)//计算
    {
        int temp=n.v[0]%2;
        ans[index++]=temp;
        DIV(&n);
        if(sign==-1&&temp)
        {
            if(n.cnt==0)
            {
                n.cnt++;
                n.v[0]=1;
            }
            else
            {
                add1(&n);
            }

        }
        sign=-sign;
    }
    for(int j=index-1;j>=0;j--)
    {
       printf("%d",ans[j]);
    }
    printf("\n");
    return 0;
}
