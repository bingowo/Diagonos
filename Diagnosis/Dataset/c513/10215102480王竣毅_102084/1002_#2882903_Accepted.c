#include <stdio.h>
#include <string.h>
#include <ctype.h>



int ChangeIndex(char c)	
{
    int ret;
    if(isdigit(c)){
        ret = c - '0';
    }else if(isupper(c)){
        ret = c - 'A' + 10;
    }else{
        ret = c - 'a' + 36;
    }
    return ret;
}

int main(void)
{
    char s[61];
    int isFind[62], CroNum[62];
    int t;
    scanf("%d", &t);
    for(int i = 0 ; i < t; i ++){
        memset(isFind, -1, sizeof(isFind));
        memset(CroNum, -1, sizeof(CroNum));

        scanf("%s", s);
        int len = strlen(s);
        for(int j = 0 ; j < len; j ++){
            
			isFind[j] = ChangeIndex(s[j]);
        }
        int Number = 0;
        unsigned long long outNum = 0;
        for(int j = 0 ; j < len; j ++){
            if(CroNum[isFind[j]] == -1){
                if(j == 0){
                
                    CroNum[isFind[j]] = 1;
                }else if(Number == 0){
                	
                    CroNum[isFind[j]] = Number;
                    Number = 2;
                }else{
                
                    CroNum[isFind[j]] = Number;
                    Number ++;
                }
            }
        }
        if(Number == 0){
        
			Number = 2;
        }
        for(int j = 0 ; j < len ; j ++){
            outNum = outNum * Number + CroNum[isFind[j]];
        }
        printf("case #%d:\n", i);
        printf("%llu\n", outNum);
    }

    return 0;
}


