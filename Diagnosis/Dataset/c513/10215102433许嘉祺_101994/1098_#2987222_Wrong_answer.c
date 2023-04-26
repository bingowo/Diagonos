#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    char s[101];
    int count[4];
    char sign[4];
    for (int i=0;i<n;i++){
        memset(count,0,sizeof(count));

        scanf("%s",s);
        for (int j=0;j<strlen(s);j++){
            if (s[j]=='!') count[j%4]++;
            else sign[j%4]=s[j];
        }
        for (int j=0;j<4;j++)
            if (sign[j]=='R') printf("%d ",count[j]);
        for (int j=0;j<4;j++)
            if (sign[j]=='B') printf("%d ",count[j]);
        for (int j=0;j<4;j++)
            if (sign[j]=='Y') printf("%d ",count[j]);
        for (int j=0;j<4;j++)
            if (sign[j]=='G') printf("%d\n",count[j]);

    }
    return 0;
}
