#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,m,sum=0,b;
    char s[100]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        sum = 0;
        scanf("%s",s);
        m=strlen(s);
        for(int j=0;j<m;j++){
            if(s[j]=='-') sum=sum*3-1;
            else if(s[j]=='1') sum = sum*3+1;
            else if(s[j]=='0') sum = sum*3;
        }
        printf("case #%d:\n%d\n",i,sum);
    }

    return 0;
}