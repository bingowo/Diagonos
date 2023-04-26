#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
    do
    {
        int a[1000],b[1000],n=0,m=0,i,j,*p,ans[1000];
        char s[501],*ps;
        memset(a,0,1000*sizeof(a[0]));
        memset(b,0,1000*sizeof(b[0]));
        memset(ans,0,1000*sizeof(ans[0]));
        if(scanf("%s",s)!=EOF);
        else break;
        for(ps=s+strlen(s)-1;ps>=s;ps--){a[n++]=*ps-'0';}
        scanf("%s",s);
        for(ps=s+strlen(s)-1;ps>=s;ps--){b[m++]=*ps-'0';}
        int l=n>m?n:m;
        for(i=0;i<l;i++){ans[i]=a[i]-b[i];if(ans[i]<0){ans[i]+=10;a[i+1]--;}}
        if(a[i]<0){printf("-");for(i=0;i<l;i++){ans[i]=b[i]-a[i];if(ans[i]<0){ans[i]+=10;b[i+1]--;}}}
        p=ans+l;
        while(*p==0)p--;
        while(p>=ans)printf("%d",*p--);
        printf("\n");
    }while(1);

}

