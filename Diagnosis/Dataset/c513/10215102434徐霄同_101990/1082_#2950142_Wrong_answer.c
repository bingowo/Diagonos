#include <stdio.h>
#include <string.h>

int main()
{
    int a[1001],b[1001];
    char s[501];
    int i,j,p,l,n;
    scanf("%s",s);
    p=0;
    l=strlen(s);
    while(p<l&&s[p]!='.')
        p++;
    i=500;
    for(j=p-1;j>=0;j--){
        a[i]=s[j]-'0';
        i--;
    }
    i=501;
    for(j=p+1;j<l;j++){
        a[i]=s[j]-'0';
        i++;
    }
    scanf("%s",s);
    p=0;
    l=strlen(s);
    while(p<l&&s[p]!='.')
        p++;
    i=500;
    for(j=p-1;j>=0;j--){
        b[i]=s[j]-'0';
        i--;
    }
    i=501;
    for(j=p+1;j<l;j++){
        b[i]=s[j]-'0';
        i++;
    }
    scanf("%d",&n);
    for(i=1000;i>500+n;i--){
        a[i]=a[i]+b[i];
        a[i-1]=a[i-1]+a[i]/10;
        a[i]=a[i]%10;
    }
    if(a[i+1]>=5)
        a[i]++;
    for(i=500+n;i>0;i--){
        a[i]=a[i]+b[i];
        a[i-1]=a[i-1]+a[i]/10;
        a[i]=a[i]%10;
    }
    i=0;
    while(i<=500&&a[i]==0)
        i++;
    if(i>500)
        printf("0");
    else
        while(i<=500){
            printf("%d",a[i]);
            i++;
        }
    printf(".");
    while(i<=500+n){
        printf("%d",a[i]);
        i++;
    }
    printf("\n");
    return 0;
}
