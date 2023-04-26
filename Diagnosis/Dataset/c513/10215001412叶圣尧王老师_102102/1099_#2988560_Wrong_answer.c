#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void val(char a[])
{
    if(strcmp(a,".-")==0)printf("A");
    else if(strcmp(a,"-...")==0)printf("B");
    else if(strcmp(a,"-.-.")==0)printf("C");
    else if(strcmp(a,"-..")==0)printf("D");
    else if(strcmp(a,".")==0)printf("E");
    else if(strcmp(a,"..-.")==0)printf("F");
    else if(strcmp(a,"--.")==0)printf("G");
    else if(strcmp(a,"....")==0)printf("H");
    else if(strcmp(a,"..")==0)printf("I");
    else if(strcmp(a,".---")==0)printf("J");
    else if(strcmp(a,"-.-")==0)printf("K");
    else if(strcmp(a,".-..")==0)printf("L");
    else if(strcmp(a,"--")==0)printf("M");
    else if(strcmp(a,"-.")==0)printf("N");
    else if(strcmp(a,"---")==0)printf("O");
    else if(strcmp(a,".--.")==0)printf("P");
    else if(strcmp(a,"--.-")==0)printf("Q");
    else if(strcmp(a,".-.")==0)printf("R");
    else if(strcmp(a,"...")==0)printf("S");
    else if(strcmp(a,"-")==0)printf("T");
    else if(strcmp(a,"..-")==0)printf("U");
    else if(strcmp(a,"...-")==0)printf("V");
    else if(strcmp(a,".--")==0)printf("W");
    else if(strcmp(a,"-..-")==0)printf("X");
    else if(strcmp(a,"-.--")==0)printf("Y");
    else if(strcmp(a,"--..")==0)printf("Z");
    else if(strcmp(a,"-----")==0)printf("0");
    else if(strcmp(a,".----")==0)printf("1");
    else if(strcmp(a,"..---")==0)printf("2");
    else if(strcmp(a,"...--")==0)printf("3");
    else if(strcmp(a,"....-")==0)printf("4");
    else if(strcmp(a,".....")==0)printf("5");
    else if(strcmp(a,"-....")==0)printf("6");
    else if(strcmp(a,"--...")==0)printf("7");
    else if(strcmp(a,"---..")==0)printf("8");
    else if(strcmp(a,"----.")==0)printf("9");
    else if(strcmp(a,"/")==0);
    else if(strcmp(a,"///")==0)printf(" ");
    else if(strcmp(a,"/////")==0)printf(".");
}

int main()
{
    char s[1001];int T,i;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        scanf("%s",s);char ms[500][7];
        int k1=0,k2=0;
        for(i=0;i<strlen(s);i++)
        {
            if(i==strlen(s)-1)
            {
                ms[k1][k2++]=s[i];
                ms[k1][k2]='\0';
            }
            else if(s[i]!='/')
                ms[k1][k2++]=s[i];
            else
            {
                ms[k1][k2]='\0';
                k1++;k2=0;
                while(s[i]=='/')
                {
                    ms[k1][k2++]='/';
                    i++;
                }
                ms[k1][k2]='\0';
                k1++;k2=0;i--;
            }
        }
        for(i=0;i<=k1;i++)
            val(ms[i]);
        printf("\n");
    }
}
