#include <stdio.h>
#include <stdlib.h>
char table[60];
int getNum(char c)
{
    int i = 0;
    for(i = 0;i<52;i++)
    {
        if(c == table[i]){return i+1;}
    }
    return -1;
}
int cmp(const void *a,const void *b)
{
    char *A = (char*)a, *B = (char*)b;
    int i = 0;
    while((A[i]!=0)&&(B[i]!=0))
    {
        int an = getNum(A[i]),bn = getNum(B[i]);
        if(an!=bn){return an-bn;}
        i++;
    }

    //printf("%s. %s.\n",A,B);
}



int main()
{
    char s0[30];memset(s0,0,30*sizeof(char));
    while(scanf("%s",s0)!=EOF)
    {
        extern char table[60];memset(table,0,60*sizeof(char));
        for(int i = 0,j = 0;i<51,j<26;i+=2,j++)
        {
            table[i] = s0[j];
            table[i+1] = s0[j]+32;
        }

        char s[3000];memset(s,0,3000*sizeof(char));
        getchar();
        gets(s);
        char words[100][21];memset(words,0,100*21*sizeof(char));
        int k = 0,k1 = 0,cnt = 0;
        while(s[k]!=0)
        {
            if(s[k]!=' '){words[cnt][k1] = s[k];k1++;}
            else if(s[k]==' '){cnt++;k1 = 0;}
            k++;
        }
        cnt++;
        qsort(words,cnt,sizeof(words[0]),cmp);

        //printf("%s\n",s);
        //printf("%s\n",table);
        //printf("cnt = %d",cnt);
        for(int i = 0;i<cnt;i++)
        {
            printf("%s ",words[i]);
        }
    }



    return 0;
}
