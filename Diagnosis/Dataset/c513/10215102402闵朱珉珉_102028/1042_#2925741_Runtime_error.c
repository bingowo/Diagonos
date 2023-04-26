#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    void change(char *S1,char *S,int len)
    {
        int num=0,flag=1,k=0;
        for (int i=0;i<len;i=k)
        {
            for (int j=i+1;j<len;j++)
            {
                flag=1;
                if (S1[j]!=S1[i]) {flag=0;k=j;break;}
            }
            S[num++]=S1[i];
            if (flag) break;
        }
    }
    void comb(char* S,char* char_comb)
{
    if (S[0])
    {
        char left[17]={0};
        sprintf(left,"%s%c",char_comb,S[0]);
        printf("%s\n",left);
        comb(S+1,left);
        comb(S+1,char_comb);
    }
}
    int cmp(const void*a,const void *b)
    {
        char *a1=(char*)a,*b1=(char*)b;
        return *a1-*b1;
    }
    int T;
    scanf ("%d",&T);
    for (int i=0;i<T;i++)
    {
        char S1[17],S[17],char_comb[17]="";
        scanf("%s",S1);
        int len=strlen(S1);
        qsort (S1,len,sizeof(S1[0]),cmp);
        change(S1,S,len);
        printf("case #%d:\n",i);
        comb(S,char_comb);
    }
    return 0;
}
