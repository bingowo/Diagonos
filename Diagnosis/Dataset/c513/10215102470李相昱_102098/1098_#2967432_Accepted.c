#include <stdio.h>
#include <string.h>
int main() {
    int T;
    scanf("%d",&T);
    char s[101];
    for(int i=0;i<T;i++){
        int cnt[4]={0},sign[4]={-1,-1,-1,-1};
        scanf("%s",s);
        int len= strlen(s);
        for(int j=0;j<len;j++){
            switch (s[j]) {
                case 'R':
                    cnt[0]++;
                    if (sign[j%4]==-1){
                        sign[j%4] = 0;
                    }
                    break;
                case 'B':
                    cnt[1]++;
                    if (sign[j%4]==-1){
                        sign[j%4] = 1;
                    }
                    break;
                case 'Y':
                    cnt[2]++;
                    if (sign[j%4]==-1){
                        sign[j%4] = 2;
                    }
                    break;
                case 'G':
                    cnt[3]++;
                    if (sign[j%4]==-1){
                        sign[j%4] = 3;
                    }
                    break;
                default:
                    break;
            }
        }
        int tot[4]={0};
        printf("case #%d:\n",i);
        for(int p=0;p<len%4;p++){
            tot[sign[p]]++;
        }
        for(int m=0;m<4;m++){
            printf("%d%c",len/4+tot[m]-cnt[m],m==3?'\n':' ');
        }

    }
    return 0;
}
