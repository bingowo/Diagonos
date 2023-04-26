#include <stdio.h>
#include<string.h>
#include<math.h>
int main() {
    int n,x,i,po;
    char a[32],*p;
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        scanf("%s",a);
        p=a+strlen(a)-1;
        po=1;n=0;
        while(p>=a)
        {
            if(*p=='-')n-=po;
            else n+=po*(*p-'0');
            po*=3;p--;
        }
        printf("case #%d:\n%d\n",i,n);

    }
    return 0;
}
