#include <stdio.h>
#include <string.h>
int main()
{
    int t,i,j,l,n,n0,x;
    int a[123];
    char s[60];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        for(j=0;j<123;j++)
            a[j]=-1;
        scanf("%s",s);
        l=strlen(s);
        n=0;
        for(j=0;j<l;j++)
            if(a[s[j]]==-1){
                if(n==0)
                    a[s[j]]=1;
                else if(n==1)
                    a[s[j]]=0;
                else
                    a[s[j]]=n;
                n++;
            }
        x=0;
        n0=1;
        if(n==1)
            n=2;
        for(j=l-1;j>=0;j--){
            x=x+a[s[j]]*n0;
            n0=n0*n;
        }
        printf("case #%d:\n",i);
        printf("%d\n",x);
    }
    return 0;
}
