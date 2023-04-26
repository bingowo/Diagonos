#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    char s[200][200];
    for(int i = 0;i < T;i++){
        printf("case #%d:\n",i);
        char str[200];
        int table[130]={0};
        int j = 0;
        while(scanf("%s",str) != '\n' && scanf("%s",str) != EOF){
            strcpy(s[j++],str);
        }
        for(int k = 0;k < j;k++){
            for(int t = 0;t < strlen(s[k]);t++){
                if(s[k][t]>='A' && s[k][t]<='Z'){
                    table[s[k][t]]++;
                    s[k][t] = '_';
                }
            }
        }
        char start = 'A';
        for(int k = 0;k < j;k++){
            for(int t = 0;t < strlen(s[k]);t++){
                while(table[start]==0)start++;
                if(table[start]>0 && s[k][t] == '_'){
                    table[start]--;
                    s[k][t]=start;
                }
            }
        }
        for(int q = 0;q < j;q++){
            printf("%s ",s[q]);

        }
        printf("\n");

    }
    return 0;
}
