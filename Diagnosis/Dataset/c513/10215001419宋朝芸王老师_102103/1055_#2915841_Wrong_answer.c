#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int index[255] = {0};
    char c;
    int cnt = 0,ans = 0;
    char temp[1000000],res[1000000];

    while((c = getchar()) != '\n' && c != EOF){
        if(index[c] != 0){
            temp[cnt] = '\0';
            if(ans < cnt){
                strcpy(res,temp);
                ans = cnt;
            }
            cnt = 0;
            memset(index,0,255*sizeof(int));
        }

        if(index[c] == 0){
            index[c]++;
            temp[cnt] = c;
            cnt++;
        }
    }

    if(ans < cnt){
        strcpy(res,temp);
        ans = cnt;
    }

    for(int i = 0; i < ans; i++){
        printf("%c",res[i]);
    }

    return 0;
}
