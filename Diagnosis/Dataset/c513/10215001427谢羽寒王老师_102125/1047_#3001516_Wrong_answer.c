#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int T,n,i,j;
    scanf("%d",&T);
    for(n=0;n<T;n++){
    char s[501];
    char a[10000];
    scanf("%s",s);
    printf("case #%d:\n",n);
    if(strlen(s)==1){printf("1%c",s[0]); }
    else{
    int sum=1;
    for(i=1;i<=strlen(s);i++){
       if(s[i]==s[i-1]) {
            sum++;
            if(sum==256){printf("%d%c",sum-1,s[i-1]);
            sum=1;}
            
            
            }
       else{printf("%d%c",sum,s[i-1]);
            sum=1;}

    }
       printf("%d%c",sum,s[i]);
    }


    printf("\n");
    }
return 0;
}