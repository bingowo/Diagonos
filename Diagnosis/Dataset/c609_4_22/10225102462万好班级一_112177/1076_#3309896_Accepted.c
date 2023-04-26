#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    //初始化
    char alp[26][5];
    char num[10][6];
    strcpy(alp[0],".-");
    strcpy(alp[1],"-...");
    strcpy(alp[2],"-.-.");
    strcpy(alp[3],"-..");
    strcpy(alp[4],".");
    strcpy(alp[5],"..-.");
    strcpy(alp[6],"--.");
    strcpy(alp[7],"....");
    strcpy(alp[8],"..");
    strcpy(alp[9],".---");
    strcpy(alp[10],"-.-");
    strcpy(alp[11],".-..");
    strcpy(alp[12],"--");
    strcpy(alp[13],"-.");
    strcpy(alp[14],"---");
    strcpy(alp[15],".--.");
    strcpy(alp[16],"--.-");
    strcpy(alp[17],".-.");
    strcpy(alp[18],"...");
    strcpy(alp[19],"-");
    strcpy(alp[20],"..-");
    strcpy(alp[21],"...-");
    strcpy(alp[22],".--");
    strcpy(alp[23],"-..-");
    strcpy(alp[24],"-.--");
    strcpy(alp[25],"--..");
    strcpy(num[0],"-----");
    strcpy(num[1],".----");
    strcpy(num[2],"..---");
    strcpy(num[3],"...--");
    strcpy(num[4],"....-");
    strcpy(num[5],".....");
    strcpy(num[6],"-....");
    strcpy(num[7],"--...");
    strcpy(num[8],"---..");
    strcpy(num[9],"----.");

    int loop;
    scanf("%d",&loop);getchar();
    char bit[6];char line[1000];
    for (int i = 0; i < loop; ++i) {

        scanf("%s",line);
        printf("case #%d:\n",i);
        int b_fl = 0;
        for (int j = 0;j <= strlen(line); ++j) {
            bit[b_fl++] = line[j];
            if(line[j] == '/'||line[j] == '\0'){
                bit[b_fl - 1] = '\0';
                if(strlen(bit) == 5){
                    for (int k = 0; k < 10; ++k) {
                        if(!strcmp(num[k],bit)){
                            printf("%c",k + '0');
                        }
                    }
                }else if(strlen(bit) < 5){
                    for (int k = 0; k < 26; ++k) {
                        if(strlen(bit) == strlen(alp[k])){
                            if(!strcmp(alp[k],bit)){
                                printf("%c",k + 'A');
                            }
                        }
                    }
                }
                b_fl = 0;
                int band = 1;
                while(line[j + 1] == '/'){j++;band++;}
                if(band == 3)printf(" ");
                else if(band == 5)printf(".");
            }
        }
        printf("\n");getchar();
    }
}
