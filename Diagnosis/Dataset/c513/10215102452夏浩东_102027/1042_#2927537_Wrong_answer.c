#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp1(const void *a, const void *b)
{
    char *A=(char*)a;
    char *B=(char*)b;
    return *A-*B;
}
int main()
{
    int num=0;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        printf("case #%d:\n",i);
        char s[20];
        char ns[20];
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(char),cmp1);
        int num=1;
        ns[0]=s[0];
        for(int k=1;k<strlen(s);k++) if(s[k]!=s[k-1]){ns[num]=s[k];num++;}
        for(int k=0;k<num;k++)
        {
            int cnt=1;
            char out[20];
            out[0]=ns[k];
            printf("%c\n",out[0]);
            for(int j=k+1;j<num;j++)
            {
                for(int r=j;r<num;r++)
                {
                    out[cnt++]=ns[r];
                    for(int m=0;m<cnt;m++) printf("%c",out[m]);
                    printf("\n");
                    if(r==num-1) {r=num+1-cnt;cnt=1;}   
                }
            }
        }
    }
    return 0;
}