#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        char s[101];
        scanf("%s",s);
        int light4 = strlen(s) / 4;
        int cnt[4] = {0,0,0,0};
        int ans[4] = {0,0,0,0};
        char seq[4];
        int j = 0;
        while(j + 3 <= strlen(s)){
            if(s[j] != '!'){
                seq [0]= s[j];
            }
            if(s[j + 1] != '!'){
                seq [1]= s[j + 1];
            }
            if(s[j + 2] != '!'){
                seq [2]= s[j + 2];
            }
            if(s[j + 3] != '!'){
                seq [3]= s[j + 3];
            }
            j = j + 4;
        }
        for(int i = 0; i < light4 * 4; i++){
            switch(s[i]){
                case 'R':cnt[0]++;break;
                case 'B':cnt[1]++;break;
                case 'Y':cnt[2]++;break;
                case 'G':cnt[3]++;break;
            }
        }
        ans[0] = light4 - cnt[0];
        ans[1] = light4 - cnt[1];
        ans[2] = light4 - cnt[2];
        ans[3] = light4 - cnt[3];
        for(int i = light4 * 4; i < strlen(s); i++){
            if(s[i] == '!'){
                switch(seq[i%4]){
                    case 'R':ans[0]++;break;
                    case 'B':ans[1]++;break;
                    case 'Y':ans[2]++;break;
                    case 'G':ans[3]++;break;
                }
            }
        }
        printf("case #%d:\n%d %d %d %d\n",t,ans[0],ans[1],ans[2],ans[3]);

    }
    return 0;
}
