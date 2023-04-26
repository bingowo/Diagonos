#include<stdio.h>
#include<string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int j = 0 ; j < T ; j++)
    {
        char s[101];
        scanf("%s",s);
        int len = strlen(s),count = 1;
        for(int i=0;i<len;i++)
        {
            if(s[i]==' ') count++;
            if(s[i]=='t'&&s[i+1]=='h'&&s[i+2]=='e'&& s[i+3]==' ') count--;
            if(s[i]=='a'&&s[i+1]==' ') count--;
            if(s[i]=='a'&&s[i+1]=='n'&& s[i+2]==' ') count--;
            if(s[i]=='o'&&s[i+1]=='f'&& s[i+2]==' ') count--;
            if(s[i]=='f'&&s[i+1]=='o'&& s[i+2]=='r'&& s[i+3]==' ') count--;
            if(s[i]=='a'&&s[i+1]=='n'&& s[i+2]=='d'&& s[i+3]==' ') count--;
        }
        printf("case #%d:\n",j);
        printf("%d\n",count);
    }
        return 0;
}

