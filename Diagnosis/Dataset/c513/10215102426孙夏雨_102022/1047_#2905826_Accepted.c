#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s[501],c;
        scanf("%s",s);
        int num=0,len=strlen(s),j=0;
        printf("case #%d:\n",t);
        for(int i=0;i<len;){
            num=0;
            do{
                c=s[i];
                num++;
                j++;
            }while(num<255&&s[j]==c);
            i=j;
            printf("%d%c",num,c);
        }
        printf("\n");
    }
    return 0;
}
