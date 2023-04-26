#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *p1, const void *p2){
    return *(char*)p1 - *(char*)p2;
}

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int i = 0; i < T; i++){
        char in[20];
        scanf("%s",in);

        qsort(in,strlen(in),sizeof(char),cmp);

        char dic[20];
        int cnt = 0;
        for(int v = 0; v < strlen(in); v++){
            if(in[v] != in[v+1]){
                dic[cnt] = in[v];
                cnt++;
                dic[cnt] = '\0';
            }
        }

        cnt = 0;
        char out[1000][20];
        for(int v = 0; v < strlen(dic); v++){
            out[cnt][0] = dic[v];
            out[cnt++][1] = '\0';
            for(int k = v; dic[k] != '\0'; k++){
                char temp[20] = {0};
                temp[0] = dic[v];
                temp[1] = '\0';
                for(int z = k+1; dic[z] != '\0'; z++){
                    temp[z-k] = dic[z];
                    temp[z-k+1] = '\0';
                    strcpy(out[cnt],temp);
                    cnt++;
                }
            }
        }

        printf("case #%d:\n",i);
        for(int v = 0; v < cnt; v++){
            printf("%s\n",out[v]);
        }
    }
    return 0;
}