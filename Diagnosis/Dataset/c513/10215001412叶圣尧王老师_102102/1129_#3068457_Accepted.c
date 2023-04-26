#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
    char*s=malloc(sizeof(char)*10000);
    char*temp=malloc(sizeof(char)*10000);
    int i,j,k;scanf("%s",s);
    for(i=0;i<strlen(s);)
    {
        k=0;
        if(isdigit(s[i]))
        {
            while(isdigit(s[i])&&i<strlen(s)){k=k*10+s[i]-'0';i++;}
            for(j=0;j<k;j++)
                printf("%s",temp);
        }
        else
        {
            while(!isdigit(s[i])&&i<strlen(s)){temp[k++]=s[i];i++;}
            temp[k]='\0';
            if(i>=strlen(s))printf("%s",temp);
        }

    }
}