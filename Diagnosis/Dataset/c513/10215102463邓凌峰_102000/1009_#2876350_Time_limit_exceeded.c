#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{
    int T;
    scanf("%d",&T);
    char a=getchar();
    for(int i=0;i<T;i++){
        char s[300]={'\0'};
        scanf("%s",&s);
        int num=strlen(s)*8,ones;
        for(int j=0;j<strlen(s);j++){
            int tmp=s[j];
            while(tmp>0){
            if((tmp&1)==1){ones++;}
            }
        }

        printf("%d/%d",ones,num);
    }
    return 0;
}




