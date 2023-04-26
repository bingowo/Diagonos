#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ans[150];
void f(char a[],char b[])
{
    int la,lb,i;
    la=strlen(a);
    lb=strlen(b);
    if(la>lb){
        for(i=la-1;i>=la-lb;i--)
            b[i]=b[i-la+lb];
        for(i=la-lb-1;i>=0;i--)
            b[i]='0';
        b[la]=0;
    }
    else if(la<lb){
        for(i=lb-1;i>=lb-la;i--)
            a[i]=a[i-lb+la];
        for(i=lb-la-1;i>=0;i--)
            a[i]='0';
        a[lb]=0;
    }
}
int cmp(const void* a,const void* b)
{
    char* aa=(char*)a;
    char* bb=(char*)b;
    char a0[150],b0[150];
    int i;
    for(i=0;i<strlen(aa);i++)
        a0[i]=aa[i];
    a0[i]=0;
    for(i=0;i<strlen(bb);i++)
        b0[i]=bb[i];
    b0[i]=0;
    if(a0[0]=='-'&&b0[0]!='-')
        return -1;
    else if(b0[0]=='-'&&a0[0]!='-')
        return 1;
    else if(a0[0]=='-'&&b0[0]=='-'){
        for(i=0;i<strlen(a0)-1;i++)
            a0[i]=a0[i+1];
        a0[i]=0;
        for(i=0;i<strlen(b0)-1;i++)
            b0[i]=b0[i+1];
        b0[i]=0;
        f(a0,b0);
        return strcmp(b0,a0);
    }
    else{
        f(a0,b0);
        return strcmp(a0,b0);
    }
}
void p(char a[],char b[])
{
    int i,c,l;
    l=strlen(a);
    c=0;
    for(i=l-1;i>=0;i--){
        ans[i]=((a[i]-'0')+(b[i]-'0')+c)%10+'0';
        c=((a[i]-'0')+(b[i]-'0')+c)/10;
    }
    ans[l]=0;
    if(c>0){
        for(i=l+1;i>0;i--)
            ans[i]=ans[i-1];
        ans[0]=c+'0';
    }
}
void m(char a[],char b[])
{
    int i,l;
    l=strlen(a);
    for(i=l-1;i>=0;i--){
        if(a[i]<b[i]){
            a[i]=a[i]+10;
            a[i-1]--;
        }
        ans[i]=a[i]-b[i]+'0';
    }
    ans[l]=0;
    i=0;
    while(ans[i]=='0'){
        ans[i]=0;
        i++;
    }
}
int main()
{
    char d[50][150];
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%s",d[i]);
    qsort(d,n,sizeof(d[0]),cmp);
    memset(ans,0,sizeof(ans));
    if(d[0][0]=='-'&&d[n-1][0]!='-'){
        for(i=0;i<strlen(d[0])-1;i++)
            d[0][i]=d[0][i+1];
        d[0][i]=0;
        f(d[0],d[n-1]);
        p(d[0],d[n-1]);
    }
    else if(d[0][0]=='-'&&d[n-1][0]=='-'){
        for(i=0;i<strlen(d[0])-1;i++)
            d[0][i]=d[0][i+1];
        d[0][i]=0;
        for(i=0;i<strlen(d[n-1])-1;i++)
            d[n-1][i]=d[n-1][i+1];
        d[n-1][i]=0;
        f(d[0],d[n-1]);
        m(d[0],d[n-1]);
    }
    else{
        f(d[0],d[n-1]);
        m(d[n-1],d[0]);
    }
    printf("%s\n",ans);
    return 0;
}
