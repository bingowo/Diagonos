#include <stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
int main() {
    int a[1000],i,n,k,j,i0;
    unsigned long long ans;
    char s[100],*p=s;
    scanf("%d",&n);
    for(i0=0;i0<n;i0++)
    {
        memset(a,-1,1000*sizeof(int));
        scanf("%s",s);
        k=0;p=s;
        a[*p++]=1;
        while(*p)
        {if(a[*p]==-1){a[*p]=k;k++;if(k==1)k++;}
         p++;}
        p=s;ans=0;
        if(k<2)k=2;
        while(*p)ans=ans*k+a[*p++];
        printf("case #%d:\n%llu\n",i0,ans);
    }
    return 0;
}
