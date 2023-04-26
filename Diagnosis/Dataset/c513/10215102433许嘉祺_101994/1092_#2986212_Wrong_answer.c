#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[1001];
    scanf("%s",s);
    if (strlen(s)==1){
        printf("1");
    }
    else {
        int sum=1;
        if (s[0]==s[1]) sum=1;
        else sum=2;
        if (s[strlen(s)-1]!=s[strlen(s)-2]) sum=sum*2;
        for (int i=1;i<=strlen(s)-2;i++){
            int count=1;
            if (s[i-1]!=s[i]) count++;
            if (s[i+1]!=s[i]) count++;
            sum=sum*count;
        }
        printf("%d",sum);
    }
    return 0;
}
