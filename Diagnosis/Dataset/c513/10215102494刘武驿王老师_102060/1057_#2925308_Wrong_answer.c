#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char c;
    char res[1000];
    char tmp[1000];
    c=getchar();
    res[0]=c;
    int count=1,i;
    while((c=getchar())!=EOF)
    {
        if(c>res[0])
        {
            for(i=0;i<count;i++) tmp[i]=res[i];
            for(i=0;i<count;i++) res[i+1]=tmp[i];
            res[0]=c;
        }
        else res[count]=c;
        count++;
    }
    res[count]='\0';
    for(int j=0;j<count;j++) res[j]=toupper(res[j]);
    printf("%s",res);
}
