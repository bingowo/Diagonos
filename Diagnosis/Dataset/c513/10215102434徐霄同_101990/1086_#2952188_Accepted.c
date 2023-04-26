#include <stdio.h>
#include <string.h>
int ans[1001];
void m(int a[],int b[],int n)
{
    int i;
    for(i=1000;i>=0;i--){
        if(a[i]<b[i]){
            a[i]=a[i]+10;
            a[i-1]--;
        }
        ans[i]=a[i]-b[i];
    }
    if(ans[501+n]>=5){
        i=500+n;
        ans[i]++;
        while(ans[i]>9){
            ans[i]=ans[i]-10;
            ans[i-1]++;
            i--;
        }
    }
}
int main()
{
    int a[1001],b[1001];
    char s1[501],s2[501];
    int i,j,p,l1,l2,n,f;
    scanf("%s%s",s1,s2);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    l1=strlen(s1);
    l2=strlen(s2);
    p=0;
    while(p<l1&&s1[p]!='.')
        p++;
    i=500;
    for(j=p-1;j>=0;j--){
        a[i]=s1[j]-'0';
        i--;
    }
    i=501;
    for(j=p+1;j<l1;j++){
        a[i]=s1[j]-'0';
        i++;
    }
    p=0;
    while(p<l2&&s2[p]!='.')
        p++;
    i=500;
    for(j=p-1;j>=0;j--){
        b[i]=s2[j]-'0';
        i--;
    }
    i=501;
    for(j=p+1;j<l2;j++){
        b[i]=s2[j]-'0';
        i++;
    }
    f=0;
    for(i=0;i<1001;i++)
        if(a[i]>b[i]){
            f=1;
            break;
        }
        else if(a[i]<b[i]){
            f=-1;
            break;
        }
    scanf("%d",&n);
    if(f==0){
        printf("0.");
        for(i=0;i<n;i++)
            printf("0");
        printf("\n");
    }
    else{
        if(f==1)
            m(a,b,n);
        else{
            m(b,a,n);
            printf("-");
        }
        i=0;
        while(i<=500&&ans[i]==0)
            i++;
        if(i==501)
            printf("0");
        else
            while(i<=500){
                printf("%d",ans[i]);
                i++;
            }
        printf(".");
        while(i<=500+n){
            printf("%d",ans[i]);
            i++;
        }
        printf("\n");
    }
    return 0;
}
