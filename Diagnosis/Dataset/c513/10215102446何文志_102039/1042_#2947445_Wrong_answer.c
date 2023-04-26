#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
    char A = *(char*)a,B = *(char*)b;
    return A-B;
}

void dfs(char* t, int* mark, char* res1, int start){
    int tlen = strlen(t),rlen = strlen(res1);
    for(int i = start;i<tlen;i++){
        if(mark[i]==0){
            mark[i] = 1;
            res1[rlen] = t[i];
            printf("%s\n",res1);
            dfs(t, mark, res1, start+1);
            mark[i] = 0;
            res1[rlen] = 0;
        }
    }
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        char s[20];memset(s,0,20*sizeof(char));
        scanf("%s",s);
        char temp[20];memset(temp,0,20*sizeof(char));

        int len = strlen(s),cnt = 0;
        for(int j = 0;j<len;j++)
        {
            int flag = 0;
            for(int k = j+1;k<len;k++)
            {
                if(s[j]==s[k]){flag = 1;break;}
            }
            if(flag==0){temp[cnt++]=s[j];}
        }
        int tlen = cnt;
        qsort(temp,tlen,sizeof(temp[0]),cmp);

        int rlen = 1<<tlen;
        char res[rlen-1][tlen+1];memset(res,0,(rlen-1)*(tlen+1)*sizeof(char));
        int mark[tlen];memset(mark,0,tlen*sizeof(int));
        char res1[tlen+1];memset(res1,0,(tlen+1)*sizeof(char));
        int start = 0;



        printf("case #%d:\n",i);
        dfs(temp,mark,res1,start);



        //for(int i1 = 0;i1<tlen;i1++)
        //{
        //    char res[20];memset(res,0,20*sizeof(char));
        //    int rcnt = 0;
        //    res[rcnt++] = temp[i1];
        //    printf("%s\n",res);
        //    for(int j1 = i1+1;j1<tlen;j1++)
        //    {
        //        res[rcnt++] = temp[j1];
        //        printf("%s\n",res);
        //    }
        //}



    }
    return 0;
}
