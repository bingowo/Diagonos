#include <stdio.h>
#include <string.h>
int main()
{
    int T, I;
    scanf("%d",&T);
    getchar();
    for(I=0; I<T; I++)
    {
        char code[1050], word[510][7], ans[500];
        int i, j=0, cnt=0, m;
        gets(code);
        int l=strlen(code);
        for(i=0; i<l; i++)
        {
            if(code[i]=='/')
            {
                m++;
                if(code[i+1]!='/')
                {
                    if(m==3) {word[cnt++][j]='\0';for(j=0; j<6; j++)word[cnt][j]='.';}
                    else if(m==5) {word[cnt++][j]='\0';for(j=0; j<6; j++)word[cnt][j]='-';}
                    word[cnt++][j]='\0';
                    j=0;
                }
            }
            else
            {
                m=0;
                word[cnt][j++]=code[i];
            }
        }
        if(code[l-1]!='/') {word[cnt++][j]='\0';}
        printf("case #%d:\n",I);
        for(i=0, j=0; i<cnt; i++)
        {
            if(!strcmp(word[i],".-")){printf("A");}
            else if(!strcmp(word[i],"-...")){printf("B");}
            else if(!strcmp(word[i],"-.-.")){printf("C");}
            else if(!strcmp(word[i],"-..")){printf("D");}
            else if(!strcmp(word[i],".")){printf("E");}
            else if(!strcmp(word[i],"..-.")){printf("F");}
            else if(!strcmp(word[i],"--.")){printf("G");}
            else if(!strcmp(word[i],"....")){printf("H");}
            else if(!strcmp(word[i],"..")){printf("I");}
            else if(!strcmp(word[i],".---")){printf("J");}
            else if(!strcmp(word[i],"-.-")){printf("K");}
            else if(!strcmp(word[i],".-..")){printf("L");}
            else if(!strcmp(word[i],"--")){printf("M");}
            else if(!strcmp(word[i],"-.")){printf("N");}
            else if(!strcmp(word[i],"---")){printf("O");}
            else if(!strcmp(word[i],".--.")){printf("P");}
            else if(!strcmp(word[i],"--.-")){printf("Q");}
            else if(!strcmp(word[i],".-.")){printf("R");}
            else if(!strcmp(word[i],"...")){printf("S");}
            else if(!strcmp(word[i],"-")){printf("T");}
            else if(!strcmp(word[i],"..-")){printf("U");}
            else if(!strcmp(word[i],"...-")){printf("V");}
            else if(!strcmp(word[i],".--")){printf("W");}
            else if(!strcmp(word[i],"-..-")){printf("X");}
            else if(!strcmp(word[i],"-.--")){printf("Y");}
            else if(!strcmp(word[i],"--..")){printf("Z");}
            else if(!strcmp(word[i],"-----")){printf("0");}
            else if(!strcmp(word[i],".----")){printf("1");}
            else if(!strcmp(word[i],"..---")){printf("2");}
            else if(!strcmp(word[i],"...--")){printf("3");}
            else if(!strcmp(word[i],"....-")){printf("4");}
            else if(!strcmp(word[i],".....")){printf("5");}
            else if(!strcmp(word[i],"-....")){printf("6");}
            else if(!strcmp(word[i],"--...")){printf("7");}
            else if(!strcmp(word[i],"---..")){printf("8");}
            else if(!strcmp(word[i],"----.")){printf("9");}
            else if(!strcmp(word[i],"......")){printf(" ");}
            else if(!strcmp(word[i],"------")){printf(".");}
        }
        printf("\n");
    }
    return 0;
}