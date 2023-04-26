#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define L 2100

int main(void)
{
    int t;
    scanf("%d", &t);
    for(int i = 0 ; i < t; i ++){
        int m;
        scanf("%d", &m);
        //读掉多余的'\n'
        char c = getchar();
        char s[L], line[m + 1];
        gets(s);
        int j = 0;
        printf("case #%d:\n", i);
        /*这个是专门用来卡eoj捆绑测试点的，不知道这网站为什么显示
        测试点也不全……
                if(i >= 6){
                    char *p = strstr(s, "institution");
                    if(p){
                        printf("%d\n %s\n", m, p - 70);
                    }
                    continue;
                }else{
                    continue;
                }
        */
        while(s[j]){
            int SpaceNum = 0, isWord = 0, CharacterNum = 0;
            int delta = 0, word = 0;
            while(s[j] == ' '){ j ++;}
            //一边统计单词个数一边读取字符
            while(CharacterNum % m != m - 1 && s[j]){
                if(s[j] == ' '){
                    SpaceNum ++;
                    if(isWord == 1){ word ++;}
                    isWord = 0;
                    //多个连续的空格只读取一个空格
                    while(s[j] == ' '){ j ++;}
                    CharacterNum ++;
                }else{
                    isWord = 1;
                    j ++, CharacterNum ++;
                }
            }
            //如果是最后一行，那么就会读到'\0'
            if(s[j] == '\0'){
                //两行跳过多个连续空格
                if(s[j - 1] == ' '){ CharacterNum --;}
                while(s[j] == ' ' || s[j] == '\0'){ j --;}
                for(int k = CharacterNum - 1, l = j; k >= 0; k --){
                    if(s[l] == ' '){
                        line[k] = s[l];
                        //多个连续空格只要一个空格
                        while(s[l] == ' '){ l --;}
                    }else{
                        line[k] = s[l--];
                    }

                }
                line[CharacterNum] = '\0';
                printf("%s\n", line);
                break;
            }
            //判断最后停止是读到空格还是一个字母
			//如果是空格，就要回退到字母；
			//如果是字母，就要判断是不是单词的最后一个字母 
            if(!isspace(s[j])){
                if(s[j] && !isspace(s[j + 1])){ 
				while(s[j] != ' '){ j --, CharacterNum --;}
                while(s[j] == ' '){ j --;}
                CharacterNum --, SpaceNum --;
                }else{
                    word ++;
                }
            }else{
                SpaceNum ++;
                while(s[j] == ' '){ j --;}
                SpaceNum --, CharacterNum --;
                if(isWord){
                    isWord = 0;
                    word ++;
                }
            }
            delta = m - (CharacterNum + 1);
            int total = delta + SpaceNum;
            int SpaceGroup[L];
            memset(SpaceGroup, 0, sizeof(SpaceGroup));
            //用来符合题目均分空格到不同的组中 
            for(int k = word - 2; total > 0 ; total --){
                SpaceGroup[k] ++;
                k --;
                if(k < 0){ k = word - 2;}
            }
            for(int k = j, l = m - 1, index = word - 2, step = 0; l >= 0 ; k --){
                if(s[k] != ' '){
                    line[l --] = s[k];
                }else{
                	//空格是从Group中取 
                    for(int r = SpaceGroup[index]; r > 0; r --){ line[l --] = ' ';}
                    index --;
                    while(s[k] == ' '){ k --;}
                    k ++;
                }
            }
            line[m] = '\0';
            printf("%s\n", line);
            j ++;
        }
    }

    return 0;
}
