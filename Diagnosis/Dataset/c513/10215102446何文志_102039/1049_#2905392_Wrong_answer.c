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
        char s[600];memset(s,0,600*sizeof(char));
        gets(s);
        char ss[500][30];memset(ss,0,500*30*sizeof(char));
        int j = 0,k = 0, cnt = 0, slen = strlen(s);
        //printf("slen = %d\n",slen);
        if(s[slen]==0){s[slen] = '.';slen++;}
        //printf("%s\n",s);
        //if(s)
        for(j = 0;j<slen;j++)
        {
            if(isalpha(s[j]))
            {
                //printf("hhh\n");
                ss[cnt][k] = s[j];
                //printf("%d: %s\n",cnt,ss[cnt]);
                k++;
            }
            else
            {
                if(!isalpha(s[j+1])){j++;}
                if(!isalpha(s[j+2])){j++;}
                k = 0;
                cnt++;
            }
        }
        //cnt++;
        //if(!(isdigit(s[slen]))){cnt--;}
        //printf("%d\n",cnt);
        char res[cnt][20];memset(res,0,cnt*20*sizeof(char));
        int rcnt = 0;
        for(int k = 0;k<cnt;k++)
        {
            int flag = 0;
            for(int k1 = k+1;k1<cnt;k1++)
            {
                if(strcmp(ss[k],ss[k1])==0)
                {
                    //printf("ss%d = %s,ss%d = %s,hhh\n",k,ss[k],k1,ss[k1]);
                    flag = 1;
                    break;
                }
            }
            if(flag==0)
            {
                strcpy(res[rcnt],ss[k]);rcnt++;
            }
        }
        //for(int j1 = 0;j1<cnt;j1++)
        //{
        //    printf("%s\n",ss[j1]);
        //}
        //if(s[slen]==0){rcnt++;}
        qsort(res,rcnt,sizeof(res[0]),cmp);
        printf("case #%d:\n",i);
        //printf("cnt = %d\n",cnt);
        //printf("rcnt = %d\n",rcnt);
        for(int j1 = 0;j1<rcnt;j1++)
        {
            printf("%s ",res[j1]);
        }
        printf("\n");
    }
    return 0;
}
