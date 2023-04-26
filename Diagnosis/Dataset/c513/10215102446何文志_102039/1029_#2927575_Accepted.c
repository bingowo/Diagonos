#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct MyChar
{
    int index;
    char c;
}mychar;
void insert(char s[], int index, char c)
{
    int slen = strlen(s);
    for(int i = slen;i>index;i--)
    {
        s[i] = s[i-1];
    }
    s[index] = c;

}
int cmp(const void *a, const void *b)
{
    char A = *(char*)a, B = *(char*)b;
    return A-B;
}
int main()
{
    int T = 0;
    scanf("%d",&T);
    getchar();
    for(int i = 0;i<T;i++)
    {
        char s[201];memset(s,0,201*sizeof(char));
        gets(s);
        int slen = strlen(s);
        //int index[201];memset(index,0,201*sizeof(int));
        //int icnt = 0;
        //for(int j = 0;j<slen;j++)
        //{
        //    if(s[j]==' '){index[icnt] = j;icnt++;}
        //}
        char t[201];memset(t,0,201*sizeof(char));
        mychar mc[201];memset(mc,0,201*sizeof(mychar));
        int tcnt = 0,icnt = 0;
        for(int j = 0;j<slen;j++)
        {
            if((s[j]>='A')&&(s[j]<='Z')){t[tcnt] = s[j];tcnt++;}
            else{mc[icnt].index = j;mc[icnt].c = s[j];icnt++;}
        }
        int tlen = strlen(t);
        qsort(t,tlen,sizeof(char),cmp);
        for(int k = 0;k<icnt;k++)
        {
            insert(t,mc[k].index,mc[k].c);
        }
        //printf("s = %s\n",s);
        //printf("t = %s\n",t);
        printf("case #%d:\n",i);
        printf("%s\n",t);
        //for(int k = 0;k<icnt;k++)
        //{
        //    printf("index = %d, c = %c\n",mc[k].index,mc[k].c);
        //}
    }
    return 0;
}
