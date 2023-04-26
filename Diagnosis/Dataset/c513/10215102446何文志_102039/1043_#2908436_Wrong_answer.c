#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(char s[],int index,char c)
{
    int len = strlen(s);
    for(int i = len;i>=index;i--)
    {
        s[i+1] = s[i];
    }
    s[index] = c;
}

int  eliminate(char s[])
{
    int slen = strlen(s);
    char t[slen];memset(t,0,slen*sizeof(char));
    int i = 0,j = 0;
    while((s[i]!=0)&&(s[j]!=0))
    {
        j = i+1;
        int flag = 0;
        while((s[i]!=s[j])&&(s[i]!=0)&&(s[j]!=0)){i++;j++;}
        while(s[i]==s[j]){j++;}
        //printf("s = %s, i = %d, j = %d\n",s,i,j);
        if(i<slen-1)
        {
            for(int k = i;k<j;k++)
            {
                s[k] = '0';
            }
        }
        i = j;
        //printf("s = %s, i = %d, j = %d\n",s,i,j);
    }
    int cnt = 0;
    for(int i1 = 0;i1<slen;i1++)
    {
        if(s[i1]!='0')
        {
            t[cnt++] = s[i1];
        }
    }
    memset(s,0,slen);
    for(int i2 = 0;i2<cnt;i2++){s[i2] = t[i2];}
    //printf("n = %d\n",slen - cnt);
    return slen-cnt;
}

int main()
{
    int T = 0;
    scanf("%d",&T);

    for(int i = 0;i<T;i++)
    {
        char s[110];memset(s,0,110*sizeof(char));
        char t[110];memset(t,0,110*sizeof(char));
        int n = 0,res = 0;
        scanf("%s",s);
        strcpy(t,s);
        int j = 0;
        while(1)
        {
            n = eliminate(t);
            res+=n;
            if(n == 0){break;}
        }

        int res1 = 0;
        int tlen =strlen(t);
        int M = 1;
        for(M = 1;M<tlen;M++)
        {
            int cnt = 1;
            int L = M-1,R = M+1;
            while((L>=0)&&(t[R]!=0))
            {
                if(t[L]==t[R])
                {
                    cnt++;
                }
                L--;R++;
            }
            //printf("cnt = %d\n",cnt);
            if(cnt>=res1)
            {
                res1 = cnt;
            }
        }
        if(tlen==0){res+=1;}
        else{res+=res1*2;}
        printf("case #%d:\n",i);
        //printf("s = %s, t = %s, res = %d\n",s,t,res);
        //printf("tlen = %d\n",tlen);
        printf("%d\n",res);
    }

    //char s1[100] = "abcdefg";
    //insert(s1,3,'h');
    //printf("%s\n",s1);
    return 0;
}
