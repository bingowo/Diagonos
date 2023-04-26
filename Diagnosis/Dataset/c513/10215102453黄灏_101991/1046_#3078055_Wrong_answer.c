#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int T;
    scanf("%d\n",&T);
    getchar();
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        char ch[500000];
        scanf("%s",ch);
        int len=strlen(ch);
        for(int j=0;j<len;j++){
            if(ch[j]<='Z' && ch[j]>='A') ch[j]=ch[j]+32;
        }
        int all_words=1,bad_words=0;
        for(int j=0;j<len;j++){
            if(ch[j]==' ') all_words++;
            if(j==len-3){
                if(ch[j]=='t'&&ch[j+1]=='h'&&ch[j+2]=='e') {bad_words++;break;}
                else if(ch[j]=='f'&&ch[j+1]=='o'&&ch[j+2]=='r') {bad_words++;break;}
            }
            if(j==len-2){
                if(ch[j]=='a'&&ch[j+1]=='n') {bad_words++;break;}
                else if(ch[j]=='o'&&ch[j+1]=='f') {bad_words++;break;}
            }
            if(j==len-1){
                if(ch[j]=='a') {bad_words++;break;}
            }
            if(j==0){
                if(len>=3&&ch[j]=='t'&&ch[j+1]=='h'&&ch[j+2]=='e'&&ch[j+3]==' ')
                {
                        bad_words++;j+=2;
                }
                else if(len>=3&&ch[j]=='f'&&ch[j+1]=='o'&&ch[j+2]=='r'&&ch[j+3]==' '){
                    bad_words++;j+=2;
                }
                else if(len>=2&&ch[j]=='a'&&ch[j+1]=='n'&&ch[j+2]==' '){
                    bad_words++;j+=1;
                }
                else if(len>=2&&ch[j]=='o'&&ch[j+1]=='f'&&ch[j+2]==' '){
                    bad_words++;j+=1;
                }
                else if(len>=1&&ch[j]=='a'&&ch[j+1]==' '){
                    bad_words++;
                }

            }
            //printf("%d\n",all_words-bad_words);
        }
        printf("%d\n",all_words-bad_words);
    }
    return 0;
}
