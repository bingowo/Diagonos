#include <stdio.h>
#include <string.h>
char ans[102],s0[102];
int bj(char a[],char b[])
{
    int la,lb,i,f;
    la=strlen(a);
    lb=strlen(b);
    if(la>lb)
        return 1;
    else if(la<lb)
        return -1;
    else{
        f=0;
        for(i=la-1;i>=0;i--)
            if(a[i]>b[i]){
                f=1;
                break;
            }
            else if(a[i]<b[i]){
                f=-1;
                break;
            }
        return f;
    }
}
int cf(char s[])
{
    int i,l;
    l=strlen(s);
    for(i=0;i<l-1;i++)
        if(s[i]==s[i+1])
            return i;
    return -1;
}
void p(int x)
{
    int i,l;
    i=x;
    l=strlen(ans);
    ans[i]++;
    while(i<l-1&&ans[i]>'9'){
        ans[i+1]++;
        ans[i]=ans[i]-10;
        i++;
    }
    if(ans[l-1]>'9'){
        ans[l-1]=ans[l-1]-10;
        ans[l]='1';
        ans[l+1]=0;
    }
}
void m(int x)
{
    int i,l;
    i=x;
    l=strlen(ans);
    ans[i]--;
    while(i<l-1&&ans[i]<'0'){
        ans[i+1]--;
        ans[i]=ans[i]+10;
        i++;
    }
    i=l-1;
    while(ans[i]=='0'){
        ans[i]=0;
        i--;
    }
}
int main()
{
    char s[102];
    int i,j,l,t,x;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s",s);
        l=strlen(s);
        memset(ans,0,sizeof(ans));
        for(j=0;j<l;j++)
            ans[j]=s[l-1-j];
        ans[l]=0;
        strcpy(s0,ans);
        p(0);
        x=cf(ans);
        while(x!=-1){
            if(ans[x]!='0')
                while(ans[x]!='0'&&bj(ans,s0)>0)
                    m(x);
            else
                p(x);
            if(bj(ans,s0)<=0){
                p(x);
                p(x);
            }
            x=cf(ans);
        }
        printf("case #%d:\n",i);
        for(j=strlen(ans)-1;j>=0;j--)
            printf("%c",ans[j]);
        printf("\n");
    }
    return 0;
}
