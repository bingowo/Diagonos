#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define M 1000
void mos(char* s,int n)
{
    char a[]=".-";
    char b[]="-...";
    char c[]="-.-.";
    char d[]="-..";
    char f[]="..-.";
    char g[]="--.";
    char h[]="....";
    char i[]="..";
    char j[]=".---";
    char k[]="-.-";
    char l[]=".-..";
    char m[]="--";
    char n[]="-.";
    char o[]="---";
    char p[]=".--.";
    char q[]="--.-";
    char r[]=".-.";
    char S[]="...";
    char u[]="..-";
    char v[]="...-";
    char w[]=".--";
    char x[]="-..-";
    char y[]="-.--";
    char z[]="--..";
    char zero[]="-----"
    char one[]=".----";
    char two[]="..---";
    char three[]="...--";
    char four[]="....-";
    char five[]=".....";
    char six[]="-....";
    char seven[]="--...";
    char eight[]="---..";
    char nine[]="----.";
    if(n==1)
    {
        if(s[0]=='.')
            printf("E");
        else if(s[0]=='-')
            printf("T");
    }
    else if(n==2)
    {
        if(strcmp(s,a)==0)
            printf("A");
        else if(strcmp(s,i)==0)
            printf("I");
        else if(strcmp(s,m)==0)
            printf("M");
        else if(strcmp(s,n)==0)
            printf("N");
    }
    else if(n==3)
    {
        if(strcmp(s,S)==0)
            printf("S");
        else if(strcmp(s,d)==0)
            printf("D");
        else if(strcmp(s,o)==0)
            printf("O");
        else if(strcmp(s,w)==0)
            printf("W");
        else if(strcmp(s,r)==0)
            printf("R");
        else if(strcmp(s,k)==0)
            printf("K");
        else if(strcmp(s,u)==0)
            printf("U");
        else if(strcmp(s,g)==0)
            printf("G");
    }
    else if(n==4)
    {
        if(strcmp(s,b)==0)
            printf("B");
        else if(strcmp(s,c)==0)
            printf("C");
        else if(strcmp(s,f)==0)
            printf("F");
        else if(strcmp(s,h)==0)
            printf("H");
        else if(strcmp(s,j)==0)
            printf("J");
        else if(strcmp(s,l)==0)
            printf("L");
        else if(strcmp(s,p)==0)
            printf("P");
        else if(strcmp(s,q)==0)
            printf("Q");
        else if(strcmp(s,v)==0)
            printf("V");
        else if(strcmp(s,x)==0)
            printf("X");
        else if(strcmp(s,y)==0)
            printf("Y");
        else if(strcmp(s,z)==0)
            printf("Z");
    }
    else if(n==5)
    {
        if(strcmp(s,zero)==0)
            printf("0");
        else if(strcmp(s,one)==0)
            printf("1");
        else if(strcmp(s,two)==0)
            printf("2");
        else if(strcmp(s,three)==0)
            printf("3");
        else if(strcmp(s,four)==0)
            printf("4");
        else if(strcmp(s,five)==0)
            printf("5");
        else if(strcmp(s,six)==0)
            printf("6");
        else if(strcmp(s,seven)==0)
            printf("7");
        else if(strcmp(s,eight)==0)
            printf("8");
        else if(strcmp(s,nine)==0)
            printf("9");
    }
}
int main()
{
    int T;
    int i,j;
    int L=0;
    int temp,t;
    char str[M]={0};
    char c[6]={0};
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",str);
        L=strlen(str);
        temp=0;
        t=0;
        j=0;
        printf("case #%d:\n",i);
        while(j<L)
        {
            if(str[j]=='/')
            {
                strncpy(c,str[temp],j-temp);
                mos(c,j-temp);
                t=0;
                while(str[j+t]=='/')
                {
                    t++;
                }
                j=j+t;
                temp=j;
                if(t==3)
                {
                    printf(" ");
                }
                else if(t==5)
                {
                    printf(".");
                }
            }
            else
            {
                j++;
            }
        }
        printf("\n");
    }
    return 0;
}