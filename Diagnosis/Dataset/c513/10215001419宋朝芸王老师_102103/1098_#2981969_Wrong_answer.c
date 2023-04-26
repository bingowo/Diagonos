#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        char s[101];
        scanf("%s",s);
        int len = strlen(s);

        //find the seq
        int a[5] = {0};
        int index[255] = {0};
        index['R'] = 1;index['B'] = 2;
        index['Y'] = 3;index['G'] = 4;

        for(int i = 0; i < len && a[4] < 4; i++){
            if(s[i] != '!') {
                char c = s[i];
                int j = i%4;
                a[j] = index[c];
                a[4]++;
            }
        }

        //special_cases
        if(a[4] == 3){
            int b[5] = {0};
            int temp;

            for(int i = 0; i < 4; i++){
                if(a[i] == 0) temp = i;
                else b[a[i]] = 1;
            }
            for(int i = 1; i <= 4; i++){
                if(b[i] == 0) a[temp] = i;
            }
        }

        //cal the black
        int black[5] = {0};
        for(int i = 0; i < len ; i++){
            if(s[i] == '!') {
                int j = i%4;
                black[a[j]]++;
            }
        }

        //output
        printf("case #%d:\n%d %d %d %d\n",R,black[1],black[2],black[3],black[4]);

    }
    return 0;
}
