#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int l=1;l<=t;l++){
        char a[100010];
        scanf("%s",a);
        int ans=0;
        for (int i=0;i<strlen(a);i++){
            ans*=3;
            if (a[i]=='1') ans+=1;
            else if (a[i]=='-') ans-=1;
        }
        printf("case #%d:\n%d\n",l-1,ans);
    }
    return 0;
}
