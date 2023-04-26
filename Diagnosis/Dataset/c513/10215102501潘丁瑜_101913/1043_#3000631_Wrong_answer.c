#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[200]={0};
char temps[200]={0};

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
                //bg=0;
                //end=0;
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
        int j;
        int len = strlen(s);
        int max = 0;
        int temp = 0;
        int flag=0;
        for(j=0;j<strlen(temps);j++)
        {
            if(s[j] == s[j+2] && j+2<strlen(s))
            {
                insert(s,j+1,s[j+1]);
                flag = 1;
                search(s);
                temp = len - strlen(s)+flag;
                if(temp > max) max = temp;
                strcpy(s,temps);
                    //j=-1;//继续从头开始找（因为后续要j++，为了让j=0，就让j=-1）
            }
        }
        if(flag == 0) temp = len - strlen(s) + 2;
        if(temp > max) max = temp;

        printf("case #%d:\n",i);
        printf("%d\n",max);
    }

    return 0;
}
