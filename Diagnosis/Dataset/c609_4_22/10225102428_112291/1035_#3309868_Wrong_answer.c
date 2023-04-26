#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int j=0;j<t;j++){
        char s[101];
        scanf("%s",s);
        printf("case #%d:\n",j);
        printf("%d\n",strlen(s));
    }
    return 0;
}

