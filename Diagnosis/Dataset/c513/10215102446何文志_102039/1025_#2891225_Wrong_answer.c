#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    char *A = (char*)a,*B = (char*)b;
    int Anum = getNum(A),Bnum = getNum(B);
    //printf("%s:num = %d, %s:num = %d\n",A,Anum,B,Bnum);
    if(Anum!=Bnum){return Bnum-Anum;}
    else{return strcmp(A,B);}
}

int getNum(char *s)
{
    int i = 0,j = 0;
    int len = strlen(s);
    int ans = 0;
    for(i = 0;i<len;i++)
    {
        int flag = 0;
        for(j = i+1;j<len;j++)
        {
            if(s[i]==s[j]){flag = 1;break;}
        }
        if(flag==0){ans++;}
    }
    return ans;
}

int main()
{
    //char* s1 = "abcdcbaba";
    //printf("s1 num = %d\n",getNum(s1));

    int T = 0;
    scanf("%d",&T);
    int i = 0;
    for(i = 0;i<T;i++)
    {
        int n = 0;
        scanf("%d",&n);
        char s[100][20];
        for(int i1 = 0;i1<100;i1++){memset(s[i1],0,20*sizeof(char));}
        for(int j = 0;j<n;j++)
        {
            scanf("%s",s[j]);
        }

        qsort(s,n,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int k = 0;k<n;k++)
        {
            printf("%s\n",s[k]);
        }
    }
    return 0;
}
