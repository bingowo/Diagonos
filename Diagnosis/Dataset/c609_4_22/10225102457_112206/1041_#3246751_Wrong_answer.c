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
        char out[400][20];
        for(int v = 0; v < strlen(dic); v++){
            char temp[20] = {0};
            for(int z = v; dic[z] != '\0'; z++){
                temp[z-v] = dic[z];
                temp[z-v+1] = '\0';
                strcpy(out[cnt],temp);
                cnt++;
            }
        }

        printf("case #%d:\n",i);
        for(int v = 0; v < cnt; v++){
            printf("%s\n",out[v]);
        }
    }
    return 0;
}