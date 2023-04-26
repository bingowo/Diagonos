#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()

{
    int t,a;
    char s[20];
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%s",s);
        int l=strlen(s);
        a=0;
        for (int j=0;j<l;j++){
            a=a*3;
            switch (s[j])                {
                    case '1':a=a+1;break;
                    case '0':break;
                    case '-':a=a-1;break;
                }
        }
        printf("case #%d:\n",i);
        printf("%d\n",a);
    }
    return 0;
}
