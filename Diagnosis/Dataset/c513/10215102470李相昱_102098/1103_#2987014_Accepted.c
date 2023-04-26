#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    char str[5];
}string;
int main(){
    string opera[12]={"IN","OUT","MOV","XCHG","ADD","SUB",
                      "MUL","DIV","MOD","AND","OR","XOR"};
    char ope[5];
    int num[26]={0};
    while(scanf("%s",ope)!=EOF){
        int i=0;
        for(;i<12;i++){
            if(strcmp(ope,opera[i].str)==0){
                break;
            }
        }
        getchar();
        char s2[50]={0},s3[50]={0};
        int number;
        scanf("%s",s2);
        switch (i) {
            case 0:
                strncpy(s3,s2+3, strlen(s2)-3);
                num[s2[0]-'A'] = atoi(s3);
                break;
            case 1:
                printf("%d\n",num[s2[0]-'A']);
                break;
            case 2:
                num[s2[0]-'A']=num[s2[3]-'A'];
                break;
            case 3:
                number = num[s2[0]-'A'];
                num[s2[0]-'A']=num[s2[3]-'A'];
                num[s2[3]-'A']=number;
                break;
            case 4:
                num[s2[0]-'A']=num[s2[0]-'A']+num[s2[3]-'A'];
                break;
            case 5:
                num[s2[0]-'A']=num[s2[0]-'A']-num[s2[3]-'A'];
                break;
            case 6:
                num[s2[0]-'A']=num[s2[0]-'A']*num[s2[3]-'A'];
                break;
            case 7:
                num[s2[0]-'A']=num[s2[0]-'A']/num[s2[3]-'A'];
                break;
            case 8:
                num[s2[0]-'A']=num[s2[0]-'A']%num[s2[3]-'A'];
                break;
            case 9:
                num[s2[0]-'A']=num[s2[0]-'A']&num[s2[3]-'A'];
                break;
            case 10:
                num[s2[0]-'A']=num[s2[0]-'A']|num[s2[3]-'A'];
                break;
            case 11:
                num[s2[0]-'A']=num[s2[0]-'A']^num[s2[3]-'A'];
                break;
        }
    }
    return 0;
}
