#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    double b=0.0;
    char s[51];
    for(int i=0;i<t;i++){
        scanf("%s",s);
        int n=0;
        while (s[n]!='.') n++;
        n=n+1;
        for (int j=strlen(s)-1;j>=n;j--){
            b=b+s[j]-'0';
            b=b/8.00;
        }
        printf("case #%d:\n",i);
        printf("0.");
        for (int j=0;j<3*(strlen(s)-n);j++)
            {
                printf("%d",(int)(b*10.0));
                b=b*10.0-(int)(b*10.0);
            }
        printf("\n");
    }
    return 0;
}