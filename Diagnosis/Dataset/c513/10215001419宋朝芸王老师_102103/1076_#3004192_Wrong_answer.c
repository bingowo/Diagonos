#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 101

typedef struct{
    char v[M];
    int cnt;
}STA;

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        char s[2*M];
        scanf("%s",s);
        int len = strlen(s);

        int flag = 1;
        STA sta = {{0},0};

        for(int i = 0; i < len; i++){
            if(flag == -1) break;
            if(sta.cnt == 0){
                sta.v[sta.cnt++] = s[i];
                continue;
            }

            switch(s[i]){
            case'(':
                if(sta.v[sta.cnt-1] == '[')
                    sta.v[sta.cnt++] = s[i];
                else{
                    flag = -1;
                    break;
                }
                break;

            case')':
                if(sta.v[sta.cnt-1] == '(')
                    sta.cnt--;
                else{
                    flag = -1;
                    break;
                }
                break;

            case'[':
                if(sta.v[sta.cnt-1] == '{')
                    sta.v[sta.cnt++] = s[i];
                else{
                    flag = -1;
                    break;
                }
                break;

            case']':
                if(sta.v[sta.cnt-1] == '[')
                    sta.cnt--;
                else{
                    flag = -1;
                    break;
                }
                break;

            case'{':
                if(sta.v[sta.cnt-1] == '(')
                    sta.v[sta.cnt++] = s[i];
                else{
                    flag = -1;
                    break;
                }
                break;

            case'}':
                if(sta.v[sta.cnt-1] == '{')
                    sta.cnt--;
                else{
                    flag = -1;
                    break;
                }
                break;

            }
            if(flag == -1) break;
        }

        if(flag == -1) printf("No\n");
        else printf("Yes\n");

    }
    return 0;
}
