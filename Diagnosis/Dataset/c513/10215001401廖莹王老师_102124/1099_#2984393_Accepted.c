#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char c;
    char s[10];
}point;
void jisuan(int h)
{
    point p[26]={'A',".-",'B',"-...",'C',"-.-.",'D',"-..",'E',".",'F',"..-.",'G',"--.",'H',"....",'I',"..",'J',
    ".---",'K',"-.-",'L',".-..",'M',"--",'N',"-.",'O',"---",'P',".--.",'Q',"--.-",'R',".-.",'S',"...",'T',"-",
    'U',"..-",'V',"...-",'W',".--",'X',"-..-",'Y',"-.--",'Z',"--.."};
    point q[10]={'0',"-----",'1',".----",'2',"..---",'3',"...--",'4',"....-",'5',".....",'6',"-....",'7',"--...",
    '8',"---..",'9',"----."};
    char s[1010]={0};
    scanf("%s",s);
    int i=0,j=0,k=0,l=0;
    printf("case #%d:\n",h);
    for(i=0;s[i];)
    {   char t[6]={0};
        for(j=0;s[i+j];j++){if(s[i+j]=='/')break;else t[j]=s[i+j];}t[j]='\0';
        for(k=0;s[i+j+k];k++){if(s[i+j+k]!='/')break;}
        if(j<5){for(l=0;l<26;l++){if(strcmp(t,p[l].s)==0){printf("%c",p[l].c);break;}}}
        else {for(l=0;l<10;l++){if(strcmp(t,q[l].s)==0){printf("%c",q[l].c);break;}}}
        if(k==3)printf(" ");else if(k==5)printf(".");
        i=i+j+k;
    }
    printf("\n");
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
}
