#include <stdio.h>
#include <string.h>
int main() {
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        char s[50];
        scanf("%s",s);
        int len= strlen(s);
        int sum=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='-')
                s[i]=-1;
            else
                s[i]=s[i]-'0';
            sum=sum*3+s[i];
        }
        printf("case #%d:\n%d\n",t,sum);
    }
    return 0;
}
