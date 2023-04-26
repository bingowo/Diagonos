#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shouritsu(char *s)
{
    if(strcmp(s,".-")==0) printf("A");
    else if(strcmp(s,"-...")==0) printf("B");
    else if(strcmp(s,"-...")==0) printf("B");
    else if(strcmp(s,"-.-.")==0) printf("C");
    else if(strcmp(s,"-..")==0) printf("D");
    else if(strcmp(s,".")==0) printf("E");
    else if(strcmp(s,"..-.")==0) printf("F");
    else if(strcmp(s,"--.")==0) printf("G");
    else if(strcmp(s,"....")==0) printf("H");
    else if(strcmp(s,"..")==0) printf("I");
    else if(strcmp(s,".---")==0) printf("J");
    else if(strcmp(s,"-.-")==0) printf("K");
    else if(strcmp(s,".-..")==0) printf("L");
    else if(strcmp(s,"--")==0) printf("M");
    else if(strcmp(s,"-.")==0) printf("N");
    else if(strcmp(s,"---")==0) printf("O");
    else if(strcmp(s,".--.")==0) printf("P");
    else if(strcmp(s,"--.-")==0) printf("Q");
    else if(strcmp(s,".-.")==0) printf("R");
    else if(strcmp(s,"...")==0) printf("S");
    else if(strcmp(s,"-")==0) printf("T");
    else if(strcmp(s,"..-")==0) printf("U");
    else if(strcmp(s,"...-")==0) printf("V");
    else if(strcmp(s,".--")==0) printf("W");
    else if(strcmp(s,"-..-")==0) printf("X");
    else if(strcmp(s,"-.--")==0) printf("Y");
    else if(strcmp(s,"--..")==0) printf("Z");
    else if(strcmp(s,"-----")==0) printf("0");
    else if(strcmp(s,".----")==0) printf("1");
    else if(strcmp(s,"..---")==0) printf("2");
    else if(strcmp(s,"...--")==0) printf("3");
    else if(strcmp(s,"....-")==0) printf("4");
    else if(strcmp(s,".....")==0) printf("5");
    else if(strcmp(s,"-....")==0) printf("6");
    else if(strcmp(s,"--...")==0) printf("7");
    else if(strcmp(s,"---..")==0) printf("8");
    else if(strcmp(s,"----.")==0) printf("9");
    for(int i=0;i<5;i++)
    {
        s[i]=0;
    }

}
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char c;
        char s[6]={'\0'};
        int j=0;
        while((c=getchar())!=10)
        {
            if(c!='/')
            {
                s[j]=c;
                j++;
            }
            else
            {
                int k=1;
                shouritsu(s);
                j=0;
                while((c=getchar())=='/') k++;
                ungetc(c,stdin);
                if(k==3) printf("%c",32);
                else if(k==5) printf(".");
            }
        }
        shouritsu(s);
        printf("%c",10);
    }
    return 0;
}
