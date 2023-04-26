#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void add(char x[],int n,char a)
{
    x[strlen(x)]='\0';
    for(int i=strlen(x)-1;i>=n;i--)
    {
        x[i+1]=x[i];
    }
    x[n]=a;

}
int main()
{
    char s1[300]={0},s[300]={0};
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        strcpy(s1,s);
        add(s,i,s[i]);
        if(strcmp(s1,s)<0)
        {
            strcpy(s,s1);
        }
        else
        {
            i++;
        }
    }
    printf("%s",s);
    return 0;
}
