#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include <string.h>

int cmp(const void *p1,const void *p2);

int main(void)
{
    int T;
    scanf("%d\n",&T);
    for(int i = 0; i < T; i++){
        char in[502];
        char *out[251];
        fgets(in,501,stdin);

        int num = 0;
        char *begin = in;
        char *end = in;
        for(; num <= 250; num++){
            char temp[502];
            while(isalpha(*end)){
                temp[end-begin] = *end;
                end++;
            }
            temp[end-begin] = '\0';
            out[num] = (char*)malloc(strlen(temp) * sizeof(char) +1);
            strcpy(out[num],temp);
            //printf("**%s\n",out[num]);

            begin = end;
            while(!isalpha(*begin)){
                if(*begin == '\n') break;
                begin++;
            }
            end = begin;
            if(*end == '\n'|| (*(end+1) == '\n' && !isalpha(*end))) break;
        }

        qsort(out,num+1,sizeof(out[0]),cmp);

        printf("case #%d:\n",i);
        printf("%s",out[0]);
        for(int v = 1; v <= num; v++){
            if(strcmp(out[v],out[v-1]) != 0) printf(" %s" , out[v]);
        }
        putchar('\n');
    }
    return 0;
}

int cmp(const void *p1,const void *p2)
{
    return strcmp(*(char**)p1, *(char**)p2);
}