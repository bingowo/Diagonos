#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[200];

void del(char s[],int bg,int end)
{
    char temp[200]={0};
    int i=0,r=0;
    while(s[i])
    {
        if(i>= bg && i<= end)
        {
            i++;
            continue;
        }

        else temp[r++]=s[i];
        i++;
    }
    strcpy(s,temp);
}

void search(char s[])
{
    int bg=0,end=0;
    while(bg<strlen(s))
    {
        while(s[bg] && s[end] && s[bg] == s[end])
            end++;
        if(bg+1 != end)
        {
            del(s,bg,end-1);
            bg=0;
            end=0;
            continue;
        }
        bg++;
    }
}

void insert(char s[],int i,char a)
{
    char temp[20]={0};
    int t=0,k=0;
    while(s[k])
    {
        if(t!=i)
            temp[t] = s[k++];
        else temp[t] = a;
        t++;
    }
    strcpy(s,temp);

}
int main()
{
    int N,i,j;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%s",s);
        int len = strlen(s);
        search(s);
        int max = 0;
        int flag=0;
        max = len - strlen(s);
        if(s[0] == 0)
            max++;
        else
        {
            //遍历，有AxA结构的插入才有意义，否则只是+2
            for(j=0;j<strlen(s);j++)
            {
                if(s[j] == s[j+2])
                {
                    flag=1;
                    insert(s,j+1,s[j+1]);
                    search(s);
                    j=0;//继续从头开始找
                }
            }

            if(flag == 0)
                max += 2;
            else max = len - strlen(s)+1;
        }
            //max += 2;
        printf("case #%d:\n",i);
        printf("%d\n",max);

    }
    return 0;
}