#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{   int m,n;
    char s[30];
    char ans[30];
    char s1[38]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d",&m);
    scanf("%s",s);
    scanf("%d",&n);
    int t=0,l,y;
    l=strlen(s);
    for(int i=0;i<l;i++){
        if(s[i]>='A' && s[i]<='Z')
            t=t*m+s[i]-55;
        else if(s[i]>='a' && s[i]<='a')
            t=t*m+s[i]-87;
        else  t=t*m+s[i]-'0';
    }
    if(t==0) printf("0");
    else { int j=0;
        while(t>0){
        y=m%n;
       ans[j++]=s1[y];
       m/=n;
       }
       ans[j]='\0';
       for(t=j-1;t>=0;t--){
        printf("%c",ans[t]);
       }

    }
    return 0;
}
