#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct string{char q[40];} std;

int cmp(const void * a,const void * b){
    std * p1 = (std*)a;
    std * p2 = (std*)b;
    return strcmp(p1->q,p2->q);
}

int main(){
    int loop;
    scanf("%d",&loop);getchar();
    for (int d = 0; d < loop; ++d) {
        printf("case #%d:\n",d);

        std str[260];
        char s[501] ;gets(s);
        int k = 0;int j = 0;int bool = 0;
        for (int i = 0;s[i] != '\0'; ++i)
        {
            if(s[i] == ' '||s[i] == '.'||
               s[i] == ','||s[i] == '!'||s[i] == '?')
            { str[k].q[j++] = '\0';  if(!bool){if(s[i+1] != '\0')k++;bool = 1;}  j = 0;continue;}
            str[k].q[j++] = s[i];bool = 0;
        }if(k == 0)str[k].q[j] = '\0';
        qsort(str,k+1,sizeof(std),cmp);

        int bol = 0;
        for (int i = 0; i < k+1; ++i) {
            if((bol&&(cmp(str[i-1].q,str[i].q) == 0))||str[i].q[0] == '\0')continue;
            printf("%s ",str[i].q);bol++;
        }printf("\n");

    }

}