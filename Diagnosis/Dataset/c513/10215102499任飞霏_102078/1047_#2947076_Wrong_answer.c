#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        char s[500]={'\0'};
        scanf("%s",s);
        int l=strlen(s);
        //printf("%d",l);
        char c=s[0];
        int count=1;
        for(int j=1;j<l;j++){

            if(s[j]==c)count++;
            else{
                printf("%d%c",count,c);
                count=1;
                c=s[j];
            }
            if(count>=255){
                printf("%d%c",count,c);
                count=0;
            }
        }
        if(count!=0)printf("%d%c\n",count,c);
    }
    return 0;
}
