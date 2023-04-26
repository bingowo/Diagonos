#include <stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
int main() {
    int a[123],i,n,k,i0;
    unsigned long long ans;
    char s[61],*p=s;
    scanf("%d",&n);
    for(i0=0;i0<n;i0++)
    {
        memset(a,-1,123*sizeof(int));
        scanf("%s",s);
        k=0;p=s;
        while(*p){if(a[*p]==-1){a[*p]=k;k++;}p++;}
        a[s[0]]=1;
        for(i=0;i<123;i++)if(a[i]==1&&i!=s[0]){a[i]=0;break;}
        p=s;ans=0;
        if(k<2)k=2;
        while(*p)ans=ans*k+a[*p++];
        printf("case #%d:\n%llu\n",i0,ans);
    }
    return 0;
}
