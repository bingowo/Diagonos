#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    getchar();getchar();
    char s[20],consulta[21],consultb[21];int str[100];
    scanf("%s",s);
    void two(char *s,int *str);
    two(s,str);
    
}

void two(char *s,int *str)
{
    int i,j,k;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9')k=s[i]-'0';
        else k=s[i]-55;
        for(j=i*4;j<i*4+4;j++)
        {
            str[i*4+3-j+i*4]=k%2;
            k/=2;
        }
    }for(k=0;k<strlen(str);k++) printf("%s",str);
}
