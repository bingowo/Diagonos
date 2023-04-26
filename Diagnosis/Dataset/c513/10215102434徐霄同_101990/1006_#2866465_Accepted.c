#include <stdio.h>
#include <string.h>
int main()
{
    int t,i,j,x,n,l;
    char a[100];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s",a);
        l=strlen(a);
        x=0;
        n=1;
        for(j=l-1;j>=0;j--){
            if(a[j]=='-')
                x=x-n;
            else if(a[j]=='1')
                x=x+n;
            n=n*3;
        }
        printf("case #%d:\n",i);
        printf("%d\n",x);
    }
    return 0;
}
