#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void huiwen(char s[1000],int count)
{
    int i,j=strlen(s);
    char s1[1000]={0};
    for(i=0;i<j;i++){s1[i]=s[j-1-i];}
    s1[i]='\0';
    if(strcmp(s,s1)==0)printf("%d %s",count,s);
    else
    {
        long long k=0;
        k=atoi(s)+atoi(s1);count++;
        itoa(k,s,10);
        huiwen(s,count);
    }

}
int main()
{
    char s[100]={0};
    int count=0;
    scanf("%s",s);
    huiwen(s,count);
    return 0;
}
