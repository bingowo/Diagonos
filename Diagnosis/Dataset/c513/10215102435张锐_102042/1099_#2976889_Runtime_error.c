#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    char sa[]=".-",sb[]="-...",sc[]="-.-.",sd[]="-..",se[]=".",sf[]="..-.";
    char sg[]="--.",sh[]="....",si[]="..",sj[]=".---",sk[]="-.-.",sl[]=".--.",sm[]="--",sn[]="-.",so[]="---",sp[]=".--.",sq[]="--.-",sr[]=".-.",ss[]="...",st[]="-",su[]="..-";
    char sv[]="...-",sw[]=".--",sx[]="-..-";
    char sy[]="-.--",sz[]="--..",s0[]="-----",s1[]=".----",s2[]="..---",s3[]="...--",s4[]="....-",s5[]=".....",s6[]="-....",s7[]="--...",s8[]="---..",s9[]="----.";
    for(int f=0;f<t;f++)
    {
        char s[1006];
        scanf("%s",s);
        int len=strlen(s);
        char temp[6];int j=0;
        printf("case #%d:\n",f);
        for(int i=0;i<len;i++)
        {
            j=0;
            while(s[i+j]!='/')
            {
                temp[j++]=s[i+j];
            }
            i=i+j;
            temp[j]='\0';
            if(strcmp(temp,sa)==0) printf("A");
            if(strcmp(temp,sb)==0) printf("B");
            if(strcmp(temp,sc)==0) printf("C");
            if(strcmp(temp,sd)==0) printf("D");
            if(strcmp(temp,se)==0) printf("E");
            if(strcmp(temp,sf)==0) printf("F");
            if(strcmp(temp,sg)==0) printf("G");
            if(strcmp(temp,sh)==0) printf("H");
            if(strcmp(temp,si)==0) printf("I");
            if(strcmp(temp,sj)==0) printf("J");
            if(strcmp(temp,sk)==0) printf("K");
            if(strcmp(temp,sl)==0) printf("L");
            if(strcmp(temp,sm)==0) printf("M");
            if(strcmp(temp,sn)==0) printf("N");
            if(strcmp(temp,so)==0) printf("O");
            if(strcmp(temp,sp)==0) printf("P");
            if(strcmp(temp,sq)==0) printf("Q");
            if(strcmp(temp,sr)==0) printf("R");
            if(strcmp(temp,ss)==0) printf("S");
            if(strcmp(temp,st)==0) printf("T");
            if(strcmp(temp,su)==0) printf("U");
            if(strcmp(temp,sv)==0) printf("V");
            if(strcmp(temp,sw)==0) printf("W");
            if(strcmp(temp,sx)==0) printf("X");
            if(strcmp(temp,sy)==0) printf("Y");
            if(strcmp(temp,sz)==0) printf("Z");
            if(strcmp(temp,s0)==0) printf("0");
            if(strcmp(temp,s1)==0) printf("1");
            if(strcmp(temp,s2)==0) printf("2");
            if(strcmp(temp,s3)==0) printf("3");
            if(strcmp(temp,s4)==0) printf("4");
            if(strcmp(temp,s5)==0) printf("5");
            if(strcmp(temp,s6)==0) printf("6");
            if(strcmp(temp,s7)==0) printf("7");
            if(strcmp(temp,s8)==0) printf("8");
            if(strcmp(temp,s9)==0) printf("9");
            i++;
            if(s[i]=='/') printf(" ");
        }
    }
    return 0;
}
