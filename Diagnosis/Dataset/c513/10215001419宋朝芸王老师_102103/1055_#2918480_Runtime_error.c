#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int index[255];
    for(int i = 0; i < 255; i++) index[i] = -1;

    int temp_ans = 0, ans = 0, temp_str = 0, str = 0;
    //char res[1000000] = {'\0'};
    char res[10] = {'\0'};

    scanf("%s",res);

    char *p = res;
    while(*p){
        if(index[*p] == -1){
            index[*p] = p - res;
            temp_ans++;
        }
        else if(index[*p] != -1){
            if(temp_ans > ans){
                ans = temp_ans;
                str = temp_str;
            }
            temp_str = index[*p] + 1;
            temp_ans = p - res - index[*p];

            memset(index+str,-1,temp_str-str);
            index[*p] = p - res;
        }
        p++;
    }

    if(temp_ans > ans){
        ans = temp_ans;
        str = temp_str;
    }

    for(int i = 0; i < ans; i++){
        printf("%c",res[i+str]);
    }

    return 0;
}
