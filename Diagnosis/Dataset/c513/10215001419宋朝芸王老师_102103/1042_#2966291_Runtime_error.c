//去重排序；二进制枚举；字典序排序；
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int cmp(const void *a, const void *b){
    return *(char*)a - *(char*)b;
}

int cmp1(const void *a, const void *b){
    return strcmp(*(char**)a,*(char**)b);
}

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){

        /***input***/
        char in[17];
        scanf("%s",in);

        /***sort***/
        qsort(in,strlen(in),sizeof(char),cmp);

        /***remove_rep***/
        int len = 1;
        for(int slow = 0, quick = 1; quick < strlen(in); quick++){

            if(in[slow] != in[quick]){
                in[++slow] = in[quick];
                len++;
            }
        }
        in[len] = '\0';


        /***binary_enum***/
        //char** a = (char**)malloc(16*(1<<(len-1))*sizeof(char));
        char ** a = (char**)malloc(((1<<len)-1)*sizeof(char*));
        for(int k = 0; k < 1<<len; k++)
            a[k] = (char*)malloc(17*sizeof(char));


        for(int i = 1; i < (1<<len); i++){
            int l = 0;
            for(int j = 0; j < len; j++){
                if(i &(1 << j)) a[i-1][l++] = in[j];
            }
            a[i-1][l] = '\0';
        }

        qsort(a,(1<<len)-1,sizeof(char*),cmp1);

        /***output***/
        printf("case #%d:\n",R);
        for(int k = 0; k < (1<<len) -1; k++){
            printf("%s\n",a[k]);
        }


        free(a);
    }
    return 0;
}
