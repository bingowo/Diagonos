#include <stdio.h>
#include <stdlib.h>
#include<string.h>



int main()
{
    char s[14];
    scanf("%s",s);
    int n=0,find=0;
    int a[14];
    memset(a,0,sizeof(a));
    for (int i=0;i<strlen(s);i++) a[i]=s[strlen(s)-i-1]-'0';
    int len=strlen(s);

    while (find==0){
        n++;
        find=1;

        for (int i=0;i<=(len-1)/2;i++){
            if (a[i]+a[len-i-1]>=10) find=0;
            int m=a[i]+a[len-i-1];
            a[i]=m;
            a[len-i-1]=m;
        }

        for (int i=0;i<len||a[i]>=10;i++){
            a[i+1]=a[i]/10+a[i+1];
            a[i]=a[i]%10;
            if (i>=len-1&&a[i+1]>0) len++;
        }


    }
    printf("%d ",n);
    for (int i=len-1;i>=0;i--) printf("%d",a[i]);
    printf("\n");
    return 0;
}