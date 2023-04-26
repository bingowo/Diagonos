#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int cmp(const void *a,const void *b)
{
    char *A = (char*)a,*B = (char*)b;
    return strcmp(A,B);
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    getchar();
    for(int i = 0;i<T;i++)
    {
        char s[501];memset(s,0,501*sizeof(char));
        gets(s);
        int slen = strlen(s);
        char ans[500][20];memset(ans,0,500*20*sizeof(char));
        int cnt = 0,k = 0,j = 0;
        //printf("%s\n",s);
        while(s[j]!=0)
        {

            while(isalpha(s[j]))
            {
                //printf("%c\n",s[j]);
                //printf("%d\n",j);
                ans[cnt][k] = s[j];
                j++;k++;
            }

            while((!isalpha(s[j]))&&(s[j]!=0))
            {
                //printf("hhh\n");
                j++;
            }
            k = 0;
            cnt++;
        }


        char ans1[cnt][20];memset(ans1,0,cnt*20*sizeof(char));
        int ans1Cnt = 0;
        for(int j1 = 0;j1<cnt;j1++)
        {
            int flag = 0;
            for(int k1 = j1+1;k1<cnt;k1++)
            {
                if(strcmp(ans[k1],ans[j1])==0)//repeated string
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                strcpy(ans1[ans1Cnt],ans[j1]);
                ans1Cnt++;
            }
        }
        qsort(ans1,ans1Cnt,sizeof(ans1[0]),cmp);
        printf("case #%d:\n",i);
        for(int j2 = 0;j2<ans1Cnt;j2++)
        {
            printf("%s ",ans1[j2]);
        }
        printf("\n");
        //printf("cnt = %d\n",cnt);
        //for(int j = 0;j<cnt;j++)
        //{
        //    printf("%d: %s\n",j,ans[j]);
        //}
    }
    return 0;
}
