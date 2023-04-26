#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int b=0;b<t;b++){
        char s[33];
        scanf("%s",s);
        int a[33];
        for(int i=0;i<strlen(s);i++){
            if(s[i]=='-')a[i]=-1;
            else a[i]=s[i]-'0';
        }
        int n=0;
        int i=0;
        while(i<strlen(s)){
            n=n*3+a[i];
            i++;
        }
        printf("case #%d:",b);
        printf("\n");
        printf("%d\n",n);
    };
    return 0;
}