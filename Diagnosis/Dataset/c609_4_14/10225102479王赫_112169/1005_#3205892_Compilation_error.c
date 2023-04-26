#include<stdio.h>
#include<stddef.h>
#include<math.h>
int main()
{
    int T;
    scanf("%d",&T);
    int i=0;
    for(i=0;i<T;i++){
        char a[50];
        scanf("%s",a);
        int len=sizeof(a)/sizeof(a[0]),t=0;
        for(len=len-1,t=0;len>=0,t<len;len--,t++){
            int r;
            if(a[len]=='-') r+=(-1)*pow(3,t);
            else if(a[len]=='1') r+=pow(3,t);
            else(a[len]=='0') r=r;
            }
        printf("case #%d:\n%d\n",t,r);
    }
    return 0;
}