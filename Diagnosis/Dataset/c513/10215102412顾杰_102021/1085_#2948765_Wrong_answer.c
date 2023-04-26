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
        int a[1000],b[1000],n=0,m=0,i,j,*p;
        char s[501],*ps;
        memset(a,0,1000*sizeof(a[0]));
        memset(b,0,1000*sizeof(b[0]));
        if(scanf("%s",s)!=EOF);
        else break;
        for(ps=s+strlen(s)-1;ps>=s;ps--){a[n++]=*ps-'0';}
        scanf("%s",s);
        for(ps=s+strlen(s)-1;ps>=s;ps--){b[m++]=*ps-'0';}
        int l=n>m?n:m;
        for(i=0;i<l;i++){a[i]-=b[i];if(a[i]<0){a[i]+=10;a[i+1]--;}}
        p=a+l-1;
        while(*p==0)p--;
        while(p>=a)printf("%d",*p--);
        printf("\n");
    }while(1);

}

