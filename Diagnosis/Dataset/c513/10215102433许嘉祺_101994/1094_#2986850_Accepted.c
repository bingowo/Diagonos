#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(int*a,int*b){
    if (a[0]==1&&b[0]==-1) return 1;
    if (a[0]==-1&&b[0]==1) return -1;
    if (a[0]==1&&b[0]==1){
        for (int i=121;i>=1;i--)
            if (a[i]>b[i]) return 1;
            else if (a[i]<b[i]) return -1;
        return 0;
    }
    else {
        for (int i=121;i>=1;i--)
            if (a[i]>b[i]) return -1;
            else if (a[i]<b[i]) return 1;
        return 0;
    }
}
void cpy(int*a,int*b){
    for (int i=0;i<122;i++) a[i]=b[i];
}
void minus(int*ans,int*a,int*b){
    if (a[0]==1&&b[0]==1){
        ans[0]=1;
        for (int i=1;i<122;i++)
            ans[i]=a[i]-b[i];
        for (int i=1;i<122;i++)
        if (ans[i]<0) {ans[i]+=10;ans[i+1]--;}
    }
    if (a[0]==1&&b[0]==-1){
        ans[0]=1;
        for (int i=1;i<122;i++)
            ans[i]=a[i]+b[i];
        int carry=0;
        for (int i=1;i<122;i++){
            ans[i]=ans[i]+carry;
            carry=ans[i]/10;
            ans[i]=ans[i]%10;
        }
    }
    if (a[0]==-1){
        ans[0]=1;
        for (int i=1;i<122;i++)
            ans[i]=b[i]-a[i];
        for (int i=1;i<122;i++)
        if (ans[i]<0) {ans[i]+=10;ans[i+1]--;}
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    char s[121];
    scanf("%s",s);
    int max[122];
    int min[122];
    memset(max,0,sizeof(max));
    memset(min,0,sizeof(min));
    if (s[0]=='-')
    {
        min[0]=-1;
        max[0]=-1;
        for (int i=1; i<strlen(s); i++)
        {
            min[i]=s[strlen(s)-i]-'0';
            max[i]=s[strlen(s)-i]-'0';
        }
    }
    else
    {
        min[0]=1;
        max[0]=1;
        for (int i=1; i<=strlen(s); i++)
        {
            min[i]=s[strlen(s)-i]-'0';
            max[i]=s[strlen(s)-i]-'0';
        }
    }
    int a[122];
    for (int i=1; i<n; i++)
    {
        memset(a,0,sizeof(a));
        scanf("%s",s);
        if (s[0]=='-')
        {
            a[0]=-1;
            for (int i=1; i<strlen(s); i++)
                a[i]=s[strlen(s)-i]-'0';
        }
        else
        {
            a[0]=1;
            for (int i=1; i<=strlen(s); i++)
                a[i]=s[strlen(s)-i]-'0';
        }
        if (cmp(a,max)==1){
            memset(max,0,sizeof(max));
            cpy(max,a);
        }
        if (cmp(min,a)==1){
            memset(min,0,sizeof(min));
            cpy(min,a);
        }
    }
    int ans[122];
    memset(ans,0,sizeof(ans));
    minus(ans,max,min);
    int i=121;
    while(ans[i]==0&&i>=1) i--;
    if (i==0) printf("0");
    else
        for (;i>=1;i--) printf("%d",ans[i]);
    return 0;
}