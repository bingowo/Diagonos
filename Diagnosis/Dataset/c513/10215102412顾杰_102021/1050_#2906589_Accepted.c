#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
int main() {
    int n,i;
    char s[100],a[100],b[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s%s%s",a,b,s);
        char*min,*max,*p0=s,*p1=s+strlen(s)-1,t,tem[100];
        int ans1,ans2;

        min=strstr(s,a);
        while(p1>p0){t=*p0;*p0=*p1;*p1=t;*p0++;*p1--;}
        p0=b;p1=b+strlen(b)-1;
        while(p1>p0){t=*p0;*p0=*p1;*p1=t;*p0++;*p1--;}
        max=strstr(s,b);
        ans1=strlen(s)-(max-s)-(min-s)-strlen(a)-strlen(b);

        p0=b;p1=b+strlen(b)-1;
        while(p1>p0){t=*p0;*p0=*p1;*p1=t;*p0++;*p1--;}
        p0=s;p1=s+strlen(s)-1;
        while(p1>p0){t=*p0;*p0=*p1;*p1=t;*p0++;*p1--;}

        strcpy(tem,a);strcpy(a,b);strcpy(b,tem);
        min=strstr(s,a);
        p0=s;p1=s+strlen(s)-1;
        while(p1>p0){t=*p0;*p0=*p1;*p1=t;*p0++;*p1--;}
        p0=b;p1=b+strlen(b)-1;
        while(p1>p0){t=*p0;*p0=*p1;*p1=t;*p0++;*p1--;}
        max=strstr(s,b);
        ans2=strlen(s)-(max-s)-(min-s)-strlen(a)-strlen(b);
        if(max==NULL||min==NULL)printf("case #%d:\n0\n",i);
        else{int d=ans1>ans2?ans1:ans2;printf("case #%d:\n%d\n",i,d>0?d:0);}
    }
    return 0;
}
