//R B Y G
#include <stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++) {
        char s[101];
        scanf("%s", s);
        char *p = s;
        int idx = 0;
        int light[4] = {0}, a[4] = {0}, b[4] = {0};
        int a1 = -1, a2 = -1;
        //a 的 0123的01代表R B Y G的有无
        while (*p) {
            if (*p != '!' && light[idx % 4] == 0) {
                switch (*p) {
                    case 'R':
                        light[idx % 4] = 'R';
                        a[0] = 1;
                        break;
                    case 'B':
                        light[idx % 4] = 'B';
                        a[1] = 1;
                        break;
                    case 'Y':
                        light[idx % 4] = 'Y';
                        a[2] = 1;
                        break;
                    case 'G':
                        light[idx % 4] = 'G';
                        a[3] = 1;
                        break;
                }
            }
            p++, idx++;
        }
        for (int i = 0; i < 4; i++) {
            if (light[i] == 0) {
                a1 = i;
                break;
            }
        }
        for (int j = 0; j < 4; j++) {
            if (a[j] == 0) {
                a2 = j;
                break;
            }
        }
        if(!(a1==-1 && a2==-1)){
            char c;
            switch(a2){
                case 0: c = 'R';break;
                case 1: c = 'B';break;
                case 2: c = 'Y';break;
                case 3: c = 'G';break;
            }
            light[a1]=c;
        }
        char *q = s;
        int idx1 = 0;
        while(*q){
            if(*q=='!'){
                switch(light[idx1%4]){
                    case 'R': b[0]++;break;
                    case 'B': b[1]++;break;
                    case 'Y': b[2]++;break;
                    case 'G': b[3]++;break;
                }
            }
            q++,idx1++;
        }
        printf("case #%d:\n",t);
        printf("%d %d %d %d\n",b[0],b[1],b[2],b[3]);

    }
    return 0;
}