#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int index[255];
    for(int i = 0; i < 255; i++) index[i] = -1;

    int temp_ans = 0, ans = 0, temp_str = 0, str = 0;
    char res[1000000] = {'\0'};

    scanf("%s",res);

    index[res[0]] = 0;
    temp_ans = 1;

    for(int k = 1; res[k]; k++){
        if(index[res[k]] < temp_str){
            index[res[k]] = k;
            temp_ans++;
        }
        else{
            if(temp_ans > ans){
                ans = temp_ans;
                str = temp_str;
            }
            temp_str = index[res[k]] + 1;
            temp_ans = k - temp_str + 1;
        }
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
