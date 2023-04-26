#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int cmp(const void *p1,const void *p2);

double dic[27];

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int i = 0; i < T; i++){
        for(int v = 0; v < 26; v++){
            scanf("%lf",&dic[v]);
        }
        char input[110];
        scanf("%s",input);

        qsort(input,strlen(input),sizeof(char),cmp);

        printf("case #%d:\n",i);
        printf("%s\n",input);
    }

    return 0;
}


int cmp(const void *p1,const void *p2)
{
    char a = *(char*)p1;
    char b = *(char*)p2;
    char biga = toupper(a);
    char bigb = toupper(b);
    double a1 = dic[biga-'A'];
    double b1 = dic[bigb-'A'];

    if(fabs(a1 - b1) > 0.009) return b1 > a1?1:b1 < a1?-1:0;
    else if(biga != bigb) return bigb < biga?1:bigb > biga?-1:0;
    else return b > a?1:b < a?-1:0;
}