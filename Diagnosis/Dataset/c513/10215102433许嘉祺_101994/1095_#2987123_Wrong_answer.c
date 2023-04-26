#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(int*a,int*b)
{

    for (int i=1000; i>=1; i--)
        if (a[i]>b[i]) return 1;
        else if (a[i]<b[i]) return -1;
    return 0;

}
void cpy(int*a,int*b)
{
    for (int i=0; i<1001; i++) a[i]=b[i];
}
void plus(int*ans,int*a,int*b)
{
    if (a[0]==b[0])
    {
        ans[0]=a[0];
        for (int i=1; i<1001; i++)
            ans[i]=a[i]+b[i];
        int carry=0;
        for (int i=1; i<1001; i++)
        {
            ans[i]=ans[i]+carry;
            carry=ans[i]/10;
            ans[i]=ans[i]%10;
        }
    }
    else if (cmp(a,b)==1)
    {
        ans[0]=a[0];

        for (int i=1; i<1001; i++)
            ans[i]=a[i]-b[i];
        for (int i=1; i<1001; i++)
            if (ans[i]<0)
            {
                ans[i]+=10;
                ans[i+1]--;
            }

    }
    else if (cmp(a,b)==-1)
    {
        ans[0]=b[0];
        for(int i=1; i<1001; i++)
            ans[i]=b[i]-a[i];
        for (int i=1; i<1001; i++)
            if (ans[i]<0)
            {
                ans[i]+=10;
                ans[i+1]--;
            }
    }
    else
    {
        ans[0]=1;
    }

}
void plus1(int*a)
{
    int len=1000;
            while(a[len]==0&&len>=1) len--;
    if (a[0]==1)
    {
        a[1]++;
        if (a[1]==10)
            for (int i=1; i<1001; i++)
            {
                a[i+1]=a[i]/10;
                a[i]=a[i]%10;
            }
    }
    else if (len==1&&a[len]==1)
    {

        a[len]=0;
        a[0]=1;
    }
    else
    {

        a[1]=a[1]-1;
        if (a[1]<0)
            for (int i=1; i<1001; i++)
                if (a[i]<0)
                {
                    a[i]+=10;
                    a[i+1]--;
                }
                else break;
    }
}
int main()
{
    char s[1001];
    scanf("%s",s);
    int a[4004];
    int len=0;
    for (int i=2; i<strlen(s); i++)
    {
        int d;
        if (s[i]>='A'&&s[i]<='F') d=10+s[i]-'A';
        else d=s[i]-'0';
        for (int j=0; j<4; j++)
            a[len+3-j]=(d>>j)&1;
        len=len+4;
    }
    int x[1001],y[1001];
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    x[0]=1;
    y[0]=1;
    y[1]=0;
    x[1]=1;
    int first=0;
    while (a[first]==0) first++;
    for (int i=first+1; i<len; i++)
    {
        int x1[1001],y1[1001];
        x[0]=-x[0];
        y[0]=-y[0];
        memset(x1,0,sizeof(x1));
        memset(y1,0,sizeof(y1));
        plus(x1,x,y);
        x[0]=-x[0];
        plus(y1,x,y);
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        cpy(x,x1);
        cpy(y,y1);

        if (a[i]==1)
            plus1(x);

    }

    int lenx=1000;
    int leny=1000;
    while (lenx>=1&&x[lenx]==0) lenx--;
    while (leny>=1&&y[leny]==0) leny--;
    int findx=1;
    int findy=1;
    if (leny==0) findy=0;
    if (lenx==0) findx=0;
    if (s[3]=='0') printf("0");
    else if (findy==0){
        if (x[0]==-1) printf("-");
        for(int i=lenx;i>=1;i--) printf("%d",x[i]);

    }
    else if (findx==0){
        if (y[0]==-1) printf("-");
        if (leny!=1&&y[leny]!=1)
        for(int i=leny;i>=1;i--) printf("%d",y[i]);
        printf("i");
    }
    else{
        if (x[0]==-1) printf("-");
        for (int i=lenx;i>=1;i--) printf("%d",x[i]);
        if (y[0]==-1) printf("-");
        else printf("+");
        if (leny!=1||y[leny]!=1)
        for (int i=leny;i>=1;i--) printf("%d",y[i]);
        printf("i");
    }
    return 0;
}