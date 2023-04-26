#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int ito16(char *s, int pl, int end);

int main()
{
    char s[1001];
    gets(s);
    int len = strlen(s);
    int plArr[1001];
    int cnt = 0;
    for(int i = 0; i < len - 1; i++){
        if(s[i] == '0' && s[i+1] == 'x'){
            plArr[cnt] = i;
            cnt++;
        }
    }//找到所有0x出现的位置
    for(int i = 0; i < cnt - 1; i++){
        int pl = plArr[i] + 2;
        int end;
        for(; pl < plArr[i + 1]; pl++){
            if(s[pl] >= '0' && s[pl] <= '9'){}
            else if (s[pl] >= 'a' && s[pl] <= 'f'){}
            else{
                end = pl;
            }
            printf("%u ",ito16(s,pl,end));
        }

    }
    int end;
    for(int i = plArr[cnt - 1] + 2; i < len; i++){
        if(s[i] >= 'a' && s[i] <= 'f'){
            end = i;
        }
        else if(s[i] >= '0' && s[i] <= '9'){
            end = i;
        }
        else{
            break;
        }
    }
    printf("%u ",ito16(s,plArr[cnt - 1] + 2,end));
    return 0;
}

unsigned int ito16(char *s, int pl, int end){
    unsigned int ans;
    if(*(s + pl) >= 'a' && *(s + pl) <= 'f'){
        ans = *(s + pl) - 'a' + 10;
    }else{
        ans = *(s + pl);
    }
    for(int i = pl + 1; i < end; i++){
        int temp;
        if(*(s + pl) >= 'a' && *(s + pl) <= 'f'){
            temp = *(s + pl) - 'a' + 10;
        }else{
            temp = *(s + pl);
        }
        ans = ans * 16 + temp;
    }
    return ans;
}
