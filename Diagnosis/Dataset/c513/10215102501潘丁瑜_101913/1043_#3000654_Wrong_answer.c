#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[200]={0};
char temps[200]={0};
//删掉重复的
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
//search找重复的
void search(char s[])
{
    int i =0;
    for(i=0;i<strlen(s);i++)
    {
        int bg=0,end=0;
        while(bg<strlen(s))
        {
            while(s[bg] && s[end] && s[bg] == s[end])
                end++;
            if(bg+1 != end)
            {
                del(s,bg,end-1);
                end=bg;
                continue;
            }
            bg++;
        }
    }
}

void insert(char s[],int i,char a)
{
    char temp[200]={0};
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
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {

        scanf("%s",s);
        strcpy(temps,s);
        int j,k;
        int len = strlen(s);
        int max = 0;
        int temp = 0;
        int flag=0;
        for(j=0;j<=strlen(temps)+1;j++)
        {
            //每个位置依次插入ABC
            char ch='A';
            for(k=0;k<3;k++)
            {
                insert(s,j,ch);
                ch = ch + 1;
                flag = 1;//插入
                search(s);
                temp = len - strlen(s) + flag;
                if(temp > max) max = temp;
                strcpy(s,temps);
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",max);
    }
    return 0;
}
