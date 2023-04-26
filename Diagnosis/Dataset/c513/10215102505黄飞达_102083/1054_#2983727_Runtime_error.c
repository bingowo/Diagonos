#include<stdio.h>
#include<string.h>

int main(){
    int T;
    scanf("%d ",&T);
    for (int t=0; t<T; t++){
        printf("case #%d:\n", t);
        int M;
        scanf("%d ", &M);
        char words[1000][35]={};//一个单词一行
        int n=0, index=0;
        char s[75]={};
        gets(s);
        char*p = strtok(s, " ");
        while(p){
            strcat(words[n++], p);
            p = strtok(NULL, " ");
        }
        char res[205][75]={};//排版后
        for (int i=0; i<n; i++){//先普通的分配到行上
            int templen=(res[index][0]=='\0'?0:strlen(res[index]));
            // if (strlen(words[i])>M-templen) index++;//写成这样就不行？什么几把。
            if (templen>M-strlen(words[i])) {
                res[index][strlen(res[index])-1]='\0';
                index++;
            }
            strcat(res[index], words[i]);
            res[index][strlen(res[index])]=' ';
        }
        for (int i=0; i<index-1; i++){//在调整一下空格的分布
            int templen = strlen(res[i]), delta_len=M-templen, count=0, sum=0;
            for (int j=0; j<templen; j++) if (res[i][j]==' ') sum++;
            for (int j=0; j<templen; j++) {
                if (res[i][j]==' '){
                    count++;
                    int kmax=0;
                    if (count<sum-(delta_len%sum)) kmax=delta_len/sum-1; 
                    else kmax=delta_len/sum; 
                    for (int k=0; k<=kmax; k++) printf(" ");
                }
                printf("%c", res[i][j]);
            }
            printf("\n");
        }
        printf("%s\n", res[index-1]);
    }
    return 0;
}