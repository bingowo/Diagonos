#include <stdio.h>
#include <string.h>
char ans(char *a)
{
    if(strcmp(a,".-")==0) return 'A';
    else if(strcmp(a,"-...")==0) return 'B';
    else if(strcmp(a,"-.-.")==0) return 'C';
    else if(strcmp(a,"-..")==0) return 'D';
    else if(strcmp(a,".")==0) return 'E';
    else if(strcmp(a,"..-.")==0) return 'F';
    else if(strcmp(a,"--.")==0) return 'G';
    else if(strcmp(a,"....")==0) return 'H';
    else if(strcmp(a,"..")==0) return 'I';
    else if(strcmp(a,".---")==0) return 'J';
    else if(strcmp(a,"-.-")==0) return 'K';
    else if(strcmp(a,".-..")==0) return 'L';
    else if(strcmp(a,"--")==0) return 'M';
    else if(strcmp(a,"-.")==0) return 'N';
    else if(strcmp(a,"---")==0) return 'O';
    else if(strcmp(a,".--.")==0) return 'P';
    else if(strcmp(a,"--.-")==0) return 'Q';
    else if(strcmp(a,".-.")==0) return 'R';
    else if(strcmp(a,"...")==0) return 'S';
    else if(strcmp(a,"-")==0) return 'T';
    else if(strcmp(a,"..-")==0) return 'U';
    else if(strcmp(a,"...-")==0) return 'V';
    else if(strcmp(a,".--")==0) return 'W';
    else if(strcmp(a,"-..-")==0) return 'X';
    else if(strcmp(a,"-.--")==0) return 'Y';
    else if(strcmp(a,"--..")==0) return 'Z';
    else if(strcmp(a,"-----")==0) return '0';
    else if(strcmp(a,".----")==0) return '1';
    else if(strcmp(a,"..---")==0) return '2';
    else if(strcmp(a,"...--")==0) return '3';
    else if(strcmp(a,"....-")==0) return '4';
    else if(strcmp(a,".....")==0) return '5';
    else if(strcmp(a,"-....")==0) return '6';
    else if(strcmp(a,"--...")==0) return '7';
    else if(strcmp(a,"---..")==0) return '8';
    else if(strcmp(a,"----.")==0) return '9';

}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        char s[1001],a[1001],b[1001];
        scanf("%s",s);
        int k = 0,num = 0,n = 0;
        for(j = 0;j<strlen(s);j++)
        {
            if(s[j]=='/')
            {if(k==0) {b[n] = '\0';a[num++] = ans(b);n = 0;}
            k++;}
            else
            {
                if(k==3) a[num++] = ' ';
                else if(k==5) a[num++] = '.';
                k = 0;
                b[n++] = s[j];
            }

        }
        b[n] = '\0';
        a[num++] = ans(b);
        a[num++] = '\0';
        printf("case #%d:\n%s\n",i,a);
        if(i==1) break;
    }
    return 0;
}
