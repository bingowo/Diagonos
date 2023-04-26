#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct data{
    char s[501];
    char s1[501];
};

int cmp(const void *a, const void *b) {
    struct data *w1 = (struct data *) a, *w2 = (struct data *) b;
    return strcmp(w1->s1, w2->s1);
}

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    for (int i = 0; i < T; i++) {
        char *s;
        s= (char*)malloc(1000);
        gets(s);
        char *p=s;
        struct data t[501];
        int j=0;
        while (*p)
        {
            if(isspace(*p) || ispunct(*p))
                p++;
            else
            {
                char *q=p+1;
                while(*q && *q!=' ' && *q!=',' && *q != '.' && *q!= '!' && *q!='?')
                {
                    q++;
                }
                int len = q-p;
                strncpy(t[j].s,p,len);
                strncpy(t[j].s1,p,len);
                t[j].s[len]=t[j].s1[len]=0;
                j++;
                p=q;
            }
        }
        int num=0;
        for(int x=0;x<j;x++)
        {
            int flag=0;
            for(int y=0;y<num;y++)
            {
                if(strcmp(t[x].s,t[y].s1)==0)
                    flag =1;
            }
            if(flag ==0)
            {
                strcpy(t[num].s1,t[x].s);
                num++;
            }
        }
        qsort(t,num, sizeof(t[0]), cmp);
        printf("case #%d:\n",i);
        for(int x=0;x<num;x++)
        {
            printf("%s ",t[x].s1);
        }
        printf("\n");
        free(s);
    }
    return 0;
}
