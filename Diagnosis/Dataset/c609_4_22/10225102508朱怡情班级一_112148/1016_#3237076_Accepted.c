#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[109];
    char a[109]={'0'},b[109]={'0'};
    long long x,y,qr=1,qi=1,r;
    int i,k=0;
    scanf("%s",s);
    if(s[0]=='-')a[k++]=s[0];
    for(i=k;s[i]!=0;i++){
        if(s[i]<'0'||s[i]>'9'){
            if(s[i]=='i'&&(i==0||s[i-1]=='-'))a[k++]='1';
            break;
        }
        a[k++]=s[i];
    }
    a[k]=0;
    if(s[i]=='i'){
        for(int j=0;j<=k;j++)
            b[j]=a[j];
        a[0]='0';
        a[1]=0;
    }
    else{
        k=0;
        if(s[i]=='-')b[k++]=s[i];
        for(int j=i+1;s[j]!=0;j++){
            if(s[j]<'0'||s[j]>'9'){
               if(s[j]=='i'&&(s[j-1]=='-'||s[j-1]=='+'))b[k++]='1';
               break;
            }
            b[k++]=s[j];
        }
        b[k]=0;
    }
    x=atoll(a);
    y=atoll(b);
    int ans[109];
    k=0;
    while(qr!=0||qi!=0){
        if(abs(x)%2==abs(y)%2)r=0;
        else r=1;
        ans[k++]=r;
        qr=(r+y-x)/2;
        qi=(r-x-y)/2;
        x=qr;
        y=qi;
    }
    ans[k]=0;
    for(int j=k-1;j>=0;j--)printf("%d",ans[j]);
    return 0;
}
