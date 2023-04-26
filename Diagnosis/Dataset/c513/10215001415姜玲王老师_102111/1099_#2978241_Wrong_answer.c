#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void print(char*a)
{
    if(!strcmp(a,".-")) printf("A");
    if(!strcmp(a,"-..")) printf("B");
    if(!strcmp(a,"-.-.")) printf("C");
    if(!strcmp(a,"-..")) printf("D");
    if(!strcmp(a,".")) printf("E");
    if(!strcmp(a,"..-.")) printf("F");
    if(!strcmp(a,"--.")) printf("E");
    if(!strcmp(a,"--.")) printf("G");
    if(!strcmp(a,"....")) printf("H");
    if(!strcmp(a,"..")) printf("I");
    if(!strcmp(a,".---")) printf("J");
    if(!strcmp(a,"-.-")) printf("K");
    if(!strcmp(a,".-..")) printf("L");
    if(!strcmp(a,"--")) printf("M");
    if(!strcmp(a,"-.")) printf("N");
    if(!strcmp(a,"---")) printf("O");
    if(!strcmp(a,".--.")) printf("P");
    if(!strcmp(a,"--.-")) printf("Q");
    if(!strcmp(a,".-.")) printf("R");
    if(!strcmp(a,"...")) printf("S");
    if(!strcmp(a,"-")) printf("T");
    if(!strcmp(a,"..-")) printf("U");
    if(!strcmp(a,"...-")) printf("V");
    if(!strcmp(a,".--")) printf("W");
    if(!strcmp(a,"-..-")) printf("X");
    if(!strcmp(a,"-.--")) printf("Y");
    if(!strcmp(a,"--..")) printf("Z");
    if(!strcmp(a,"-----")) printf("0");
    if(!strcmp(a,".----")) printf("1");
    if(!strcmp(a,"..---")) printf("2");
    if(!strcmp(a,"...--")) printf("3");
    if(!strcmp(a,"....-")) printf("4");
    if(!strcmp(a,".....")) printf("5");
    if(!strcmp(a,"-....")) printf("6");
    if(!strcmp(a,"--...")) printf("7");
    if(!strcmp(a,"---..")) printf("8");
    if(!strcmp(a,"----.")) printf("9");
}
int main()
{int n,i;
char a[1001];
scanf("%d",&n);
for(i=0;i<n;i++)
{
    printf("case #%d:\n",i);
    scanf("%s",a);
    int t=strlen(a),j=0,k,l;
    char b[6];
    while(j<t)
    {if(a[j]!='/')
    {
        memset(b,0,sizeof(char)*6);
        for(k=0;j<t&&a[j]!='/';k++,j++)
        {
            b[k]=a[j];
        }
        b[k]=0;
        print(b);
    }
    if(a[j]=='/')
    {for(l=0;j<t&&a[j]=='/';l++,j++);
    if(l==3) printf(" ");
    if(l==5) printf(".");

    }
    }
    printf("\n");
}
}

