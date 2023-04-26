#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int read(char s[])
{
    int ret=-1;
    if(strcmp(s,".-")==0)
        ret='A';
    else if(strcmp(s,"-...")==0)
    {
        ret='B';
    }
    else if(strcmp(s,"-.-.")==0)
    {
        ret='C';
    }
    else if(strcmp(s,"-..")==0)
    {
        ret='D';
    }
    else if(strcmp(s,".")==0)
    {
        ret='E';
    }
    else if(strcmp(s,"..-.")==0)
    {
        ret='F';
    }
    else if(strcmp(s,"--.")==0)
    {
        ret='G';
    }
    else if(strcmp(s,"....")==0)
    {
        ret='H';
    }
    else if(strcmp(s,"..")==0)
    {
        ret='I';
    }
    else if(strcmp(s,".---")==0)
    {
        ret='J';
    }
    else if(strcmp(s,"-.-")==0)
    {
        ret='K';
    }
    else if(strcmp(s,".-..")==0)
    {
        ret='L';
    }
    else if(strcmp(s,"--")==0)
    {
        ret='M';
    }
    else if(strcmp(s,"-.")==0)
    {
        ret='N';
    }
    else if(strcmp(s,"---")==0)
    {
        ret='O';
    }
    else if(strcmp(s,".--.")==0)
    {
        ret='P';
    }
    else if(strcmp(s,"--.-")==0)
    {
        ret='Q';
    }
    else if(strcmp(s,".-.")==0)
    {
        ret='R';
    }
    else if(strcmp(s,"...")==0)
    {
        ret='S';
    }
    else if(strcmp(s,"-")==0)
    {
        ret='T';
    }
    else if(strcmp(s,"..-")==0)
    {
        ret='U';
    }
    else if(strcmp(s,"...-")==0)
    {
        ret='V';
    }
    else if(strcmp(s,".--")==0)
    {
        ret='W';
    }
    else if(strcmp(s,"-..-")==0)
    {
        ret='X';
    }
    else if(strcmp(s,"-.--")==0)
    {
        ret='Y';
    }
    else if(strcmp(s,"--..")==0)
    {
        ret='Z';
    }
    else if(strcmp(s,"-----")==0)
    {
        ret=48;
    }
    else if(strcmp(s,".----")==0)
    {
        ret=49;
    }
    else if(strcmp(s,"..---")==0)
    {
        ret=50;
    }
    else if(strcmp(s,"...--")==0)
    {
        ret=51;
    }
    else if(strcmp(s,"....-")==0)
    {
        ret=52;
    }
    else if(strcmp(s,".....")==0)
    {
        ret=53;
    }
    else if(strcmp(s,"-....")==0)
    {
        ret=54;
    }
    else if(strcmp(s,"--...")==0)
    {
        ret=55;
    }
    else if(strcmp(s,"---..")==0)
    {
        ret=56;
    }
    else if(strcmp(s,"----.")==0)
    {
        ret=57;
    }
    return ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[1001];
        scanf("%s",s);
        char*l=s,*r=s;
        printf("case #%d:\n",i);
        while(*r)
        {
            char temp[6]={0};
            while(*r!='/'&&*r!='\0')
                r++;
            if(*r=='/')
            {
                memmove(temp,l,r-l);
                int flag=0,ret=read(temp);
                printf("%c",ret);
                while(*r=='/')
                {
                    flag++;
                    r++;
                }
                if(flag==3)
                    printf(" ");
                else if(flag==5)
                    printf(".");
                l=r;
            }
            else if(*r=='\0')
            {
                 memmove(temp,l,r-l);
                 int ret=read(temp);
                 printf("%c",ret);
                 break;
            }


        }
        printf("\n");
    }
    return 0;
}