#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void findcore(char* s, char* core);
int main()
{
    int T,i,j,k,x,num;
    char s[501],core[501];
    unsigned char res[1050];
    scanf("%d",&T);getchar();
    for(i=0;i<T;i++)
    {
        gets(s);
        memset(core,0,sizeof(core));
        findcore(s,core);
        k=0;
        x=0;
        for(j=0;j<strlen(core);j++)
        {
            num=0;
            while(s[k]==core[j]&&num<255)
            {
                num++;
                k++;
            }
            res[2*x]=num;
            res[2*x+1]=core[j];
            x++;
            if(num==255&&s[k]==core[j])
                j--;
        }
        res[2*x]=0;
        printf("case #%d:\n",i);
        for(k=0;k<2*x;k++)
        {
            if(k%2==0)
                printf("%d",res[k]);
            else
                printf("%c",res[k]);
        }
        printf("\n");
    }
    return 0;
}
void findcore(char* s, char* core)
{
    int i, j;j = 0;
    for (i = 0;i < strlen(s);i++)
    {
        if(core[j-1]!=s[i])
            core[j++] = s[i];
    }
}
