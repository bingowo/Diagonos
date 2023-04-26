#include <stdio.h>
#include <stdlib.h>

void zhuanxing(char *s)
{
    int len=strlen(s),i;
    for(i=0;i<len;i++)
    {
        if(s[i]=='/') s[i]='*';
    }
    for(i=0;i<len;i++)
    {
        if((s[i]=='*')&&((s[i-1]=='*')||(s[i-1]=='/'))&&((s[i+1]=='*')||(s[i+1]=='/'))) s[i]='/';
    }
}

int splitstring(char *s,char sign,char* fen[],int nmax)
{
    int len=strlen(s),i,co=0;
    fen[co++]=s;
    for(i=0;i<len;i++)
    {
        if(s[i]=='*')
        {
            s[i]=0;
            fen[co++]=&s[i+1];
        }
        if(co>=nmax) break;
    }
    return co;
}

char jiema(char *w)
{
    if(strcmp(w,".-")==0) return 'A';
    else if(strcmp(w,"-...")==0) return 'B';
    else if(strcmp(w,"-.-.")==0) return 'C';
    else if(strcmp(w,"-..")==0) return 'D';
    else if(strcmp(w,".")==0) return 'E';
    else if(strcmp(w,"..-.")==0) return 'F';
    else if(strcmp(w,"--.")==0) return 'G';
    else if(strcmp(w,"....")==0) return 'H';
    else if(strcmp(w,"..")==0) return 'I';
    else if(strcmp(w,".---")==0) return 'J';
    else if(strcmp(w,"-.-")==0) return 'K';
    else if(strcmp(w,".-..")==0) return 'L';
    else if(strcmp(w,"--")==0) return 'M';
    else if(strcmp(w,"-.")==0) return 'N';
    else if(strcmp(w,"---")==0) return 'O';
    else if(strcmp(w,".--.")==0) return 'P';
    else if(strcmp(w,"--.-")==0) return 'Q';
    else if(strcmp(w,".-.")==0) return 'R';
    else if(strcmp(w,"...")==0) return 'S';
    else if(strcmp(w,"-")==0) return 'T';
    else if(strcmp(w,"..-")==0) return 'U';
    else if(strcmp(w,"...-")==0) return 'V';
    else if(strcmp(w,".--")==0) return 'W';
    else if(strcmp(w,"-..-")==0) return 'X';
    else if(strcmp(w,"-.--")==0) return 'Y';
    else if(strcmp(w,"--..")==0) return 'Z';
    else if(strcmp(w,"/")==0) return ' ';
    else if(strcmp(w,"///")==0) return '.';
    else if(strcmp(w,"-----")==0) return '0';
    else if(strcmp(w,".----")==0) return '1';
    else if(strcmp(w,"..---")==0) return '2';
    else if(strcmp(w,"...--")==0) return '3';
    else if(strcmp(w,"....-")==0) return '4';
    else if(strcmp(w,".....")==0) return '5';
    else if(strcmp(w,"-....")==0) return '6';
    else if(strcmp(w,"--...")==0) return '7';
    else if(strcmp(w,"---..")==0) return '8';
    else if(strcmp(w,"----.")==0) return '9';
    else return '+';

}

int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        char s[1010];
        memset(s,0,sizeof(char)*1010);
        int co,j;
        char* ma[1000];
        scanf("%s",s);
        zhuanxing(s);
        //printf("s=%s\n",s);
        co=splitstring(s,'*',ma,1000);
        //for(j=0;j<co;j++) printf("%s\n",ma[j]);
        char re[1000];
        memset(re,0,sizeof(char)*1000);
        for(j=0;j<co;j++)
        {
            re[j]=jiema(ma[j]);
        }
        printf("case #%d:\n",i);
        printf("%s\n",re);

    }
    return 0;
}
