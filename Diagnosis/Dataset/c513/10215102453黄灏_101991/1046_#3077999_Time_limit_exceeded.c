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
        char ch[101];
        scanf("%s",ch);
        int len=strlen(ch);
        int all_words=1,bad_words=0;
        for(int j=0;j<len;){
            if(ch[j]==' ') {all_words++;j++;}
            if(ch[j-1]==' ' && ch[j]=='t' && ch[j+1]=='h' && ch[j+2]=='e' && ch[j+3]==' '){
                j+=3;bad_words++;continue;
            }
            else if(ch[j-1]==' ' && ch[j]=='a',ch[j+1]==' '){
                j+=1;bad_words++;continue;
            }
            else if(ch[j-1]==' ' && ch[j]=='a' && ch[j+1]=='n' && ch[j+2]==' '){
                j+=2;bad_words++;continue;
            }
            else if(ch[j-1]==' ' && ch[j]=='o' && ch[j+1]=='f' && ch[j+2]==' '){
                j+=2;bad_words++;continue;
            }
            else if(ch[j-1]==' ' && ch[j]=='f' && ch[j+1]=='o' && ch[j+2]=='r' && ch[j+3]==' '){
                j+=3;bad_words++;continue;
            }
        }
        printf("%d\n",all_words-bad_words);
    }
    return 0;
}
