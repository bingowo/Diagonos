#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b){
    char *a1 = (char*)a;
    char *b1 = (char*)b;
    char a2 = *a1;
    char b2 = *b1;
    if((a2 >= 'A' && a2 <= 'Z')&&(b2 >= 'A' && b2 <= 'Z')){
        return a2 - b2;
    }else{
         return 0;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int i = 0;
    char s[201];
    getchar();
    while(i < T){
        gets(s);
        int len = strlen(s);
        for(int j = 0;j < len - 1;j++){
            if(s[j] >= 'A' && s[j] <= 'Z')
                for(int k = j + 1;k < len;k++){
                    if(s[k] >= 'A' && s[k] <= 'Z'){
                        if(s[k] < s[j]){
                            char temp = s[k];
                            s[k] = s[j];
                            s[j] = temp;
                        }
                    }
                }
        }
        printf("case #%d:\n",i++);
        printf("%s\n",s);
    }
    return 0;
}
