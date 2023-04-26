#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isSame(char s1[], char s2[])
{
    char *s11 = s1, *s22 = s2;
    int len1 = strlen(s11),len2 = strlen(s22);
    for(int i = 0;i<len1;i++)
    {
        if((s11[i]>='A')&&(s11[i]<='Z'))
        {
            s11[i]+=32;
        }
    }
    for(int i = 0;i<len2;i++)
    {
        if((s22[i]>='A')&&(s22[i]<='Z'))
        {
            s22[i]+=32;
        }
    }
    //printf("s1 = %s, s2 = %s\n",s11,s22);
    int res = strcmp(s11,s22);
    //printf("==? %d\n",res);
    return strcmp(s11,s22);
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    getchar();
    for(int i = 0;i<T;i++)
    {
        char s[110];memset(s,0,110*sizeof(char));
        char ss[100][20];memset(ss,0,100*20*sizeof(char));
        gets(s);
        int j = 0,cnt = 0,slen = strlen(s),k = 0;
        for(j = 0;j<slen;j++)
        {
            if(isalpha(s[j]))
            {
                ss[cnt][k] = s[j];
                k++;
            }
            else
            {
                k = 0;
                cnt++;
            }
        }
        int n = cnt+1;
        for(int j = 0;j<cnt;j++)
        {
            if((strcmp(ss[j],"the")==0)||(strcmp(ss[j],"a")==0)
               ||(strcmp(ss[j],"an")==0)||(strcmp(ss[j],"of")==0)
               ||strcmp(ss[j],"for")==0||strcmp(ss[j],"and")==0)
            {
                n--;
            }
        }

        printf("case #%d:\n",i);
        //printf("cnt = %d\n",cnt);
        printf("%d\n",n);
        //for(int j = 0;j<=cnt;j++)
        //{
        //    printf("%s\n",ss[j]);
        //}

        //char res[100][20];memset(res,0,100*20*sizeof(char));
        //int rcnt = 0;
        //for(int j = 0;j<=cnt;j++)
        //{
        //    int flag = 0;
        //    for(int k = j+1;k<=cnt;k++)
        //    {
        //        if(isSame(ss[j],ss[k])==0)
        //        {
        //            flag = 1;
        //            break;
        //        }
        //    }
        //    if(flag == 0)
        //    {
        //        strcpy(res[rcnt],ss[j]);
        //        rcnt++;
        //    }
        //}
        //int n = rcnt;
        //printf("rcnt = %d\n",rcnt);
        //printf("case #%d:\n",i);

        //for(int j = 0;j<rcnt;j++)
        //{
        //    if((strcmp(res[j],"the")==0)||(strcmp(res[j],"a")==0)
        //       ||(strcmp(res[j],"an")==0)||(strcmp(res[j],"of")==0)
        //       ||strcmp(res[j],"for")==0||strcmp(res[j],"and")==0)
        //    {
        //        n--;
        //    }
        //    printf("%s\n",res[j]);
        //}
        //printf("%d\n",n);
        //printf("\n");
    }
    return 0;
}
