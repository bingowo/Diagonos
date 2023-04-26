#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct consts
{
    char *cs;
};

struct words
{
    char w[200];
};
int main()
{
    int N,i;
    scanf("%d",&N);
    getchar();
    struct consts C[7];
    C[0].cs = "the";
    C[1].cs = "a";
    C[2].cs = "an";
    C[3].cs = "of";
    C[4].cs = "for";
    C[5].cs = "and";
    for(i=0;i<N;i++)
    {
        struct words W[200]={0};;
        int j=0,k=0;
        char ch;
        while( (ch = getchar()) !='\n')
        {
            if(ch == ' ') j++,k=0;
            else W[j].w[k++] = ch;
        }
        int r;
        int count =0;
        for(k=0;k<=j;k++)
        {
            int flag=0;
            for(r=0;r<6;r++)
            {
                if(strcmp(W[k].w , C[r].cs) == 0) flag = 1;
            }
            if(flag == 0) count++;

        }
        printf("case #%d:\n",i);
        printf("%d\n",count);
    }
    return 0;
}
