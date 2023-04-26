#include <stdio.h>
#include <stdlib.h>
typedef struct Mychar
{
    int n;
    char c;
}mychar;
int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        char s[600];memset(s,0,600*sizeof(char));
        scanf("%s",s);
        mychar mc[500];memset(mc,0,500*sizeof(mychar));
        int j = 0,k = 0,cnt = 0;
        while((s[j]!=0))
        {
            mc[cnt].c = s[j];
            mc[cnt].n++;
            k = j+1;
            while(s[j]==s[k])
            {
                mc[cnt].n++;
                k++;
            }
            j = k;
            cnt++;
        }

        printf("case #%d:\n",i);
        for(int j1 = 0;j1<cnt;j1++)
        {
            while(mc[j1].n>255){printf("255%c",mc[j1].c);mc[j1].n-=255;}
            printf("%d%c",mc[j1].n,mc[j1].c);
            //printf("mc[%d]: c = %c, n = %d\n",j1,mc[j1].c,mc[j1].n);
        }
        printf("\n");
    }
    return 0;
}
