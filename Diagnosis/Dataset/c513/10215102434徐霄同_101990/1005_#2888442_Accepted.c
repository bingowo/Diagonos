#include <stdio.h>
#include <string.h>
int main()
{
    int t,i,j,k,x,y,ls,la;
    char s[51],a[151];
    scanf("%d\n",&t);
    for(i=0;i<t;i++){
        scanf("%s",s);
        ls=strlen(s);
        la=0;
        for(j=ls-1;j>=2;j--){
            x=s[j]-'0';
            k=0;
            while(x!=0 || k<la){
                if(k<la)
                    y=x*10+a[k]-'0';
                else
                    y=x*10;
                a[k++]=y/8+'0';
                x=y%8;
            }
            la=k;
        }
        a[la]=0;
        printf("case #%d:\n",i);
        printf("0.%s\n",a);
    }
    return 0;
}