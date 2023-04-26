#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int i = 0;i < T;i++){
        char s[100000];
        printf("case #%d:\n",i);
        char c;
        int table[130]={0};
        int j = 0;
        while((c = getchar())!='\n'){
            s[j]=c;
            if(s[j]>='A' && s[j]<='Z'){
                table[c]++;
                s[j]='-';
            }
            j++;
        }
        s[j]='\0';
        char start = 'A';
        for(int q = 0;q < strlen(s);q++){
            while(table[start]==0)start++;
            if(s[q]=='-'){
                s[q]=table[start];
                table[start]--;
            }
            printf("%c",s[q]);
        }
        printf("\n");

    }
    return 0;
}
