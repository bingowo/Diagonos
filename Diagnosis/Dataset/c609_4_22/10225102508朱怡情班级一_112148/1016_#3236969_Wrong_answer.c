#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[109];
    char a[10]={'0'},b[10]={'0'};
    int k=1;
    scanf("%s",s);
    a[0]=s[0];
    int i;
    for(i=1;s[i]!=0;i++){
        if(s[i]>='0'&&s[i]<='9')a[k++]=s[i];
        else break;
    }
    a[k]=0;
    k=0;
    if(s[i]=='-'){
        b[k++]=s[i];
    }
    for(i=i+1;s[i]!=0;i++){
        if(s[i]>='0'&&s[i]<='9')b[k++]=s[i];
        else if(s[i-1]=='-'||s[i-1]=='+')b[k++]='1';
    }
    b[k]=0;
    int x,y,qr=1,qi=1,r;
    x=atoi(a);
    y=atoi(b);
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
