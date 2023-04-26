#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[1001];
    scanf("%s",s);
    if (strlen(s)==1) printf("1");
    else {
        int count=0;
        if (s[0]==s[1]) count=1;
        else count=2;
        if (s[strlen(s)-2]!=s[strlen(s)-1]) count=count*2;
        for (int i=1;i<strlen(s)-1;i++){
            int sum=0;
            if (s[i]!=s[i+1]) sum++;
            if (s[i]!=s[i-1]) sum++;
            if (s[i+1]!=s[i-1]) sum++;
            if (sum==0) sum++;
            count=count*sum;
            count=count%1000000007;
        }
        printf("%d",count);
    }
    return 0;
}