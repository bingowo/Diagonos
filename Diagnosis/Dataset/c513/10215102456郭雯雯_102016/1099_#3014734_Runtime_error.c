#include<stdio.h>
#include<string.h>

char trans(char *s){
    char c;
    if(strcmp(s,".-")==0)c='A';
    if(strcmp(s,"-...")==0)c='B';
    if(strcmp(s,"-.-.")==0)c='C';
    if(strcmp(s,"-..")==0)c='D';
    if(strcmp(s,".")==0)c='E';
    if(strcmp(s,"..-.")==0)c='F';
    if(strcmp(s,"--.")==0)c='G';
    if(strcmp(s,"....")==0)c='H';
    if(strcmp(s,"..")==0)c='I';
    if(strcmp(s,".---")==0)c='J';
    if(strcmp(s,"-.-")==0)c='K';
    if(strcmp(s,".-..")==0)c='L';
    if(strcmp(s,"--")==0)c='M';
    if(strcmp(s,"-.")==0)c='N';
    if(strcmp(s,"---")==0)c='O';
    if(strcmp(s,".--.")==0)c='P';
    if(strcmp(s,"--.-")==0)c='Q';
    if(strcmp(s,".-.")==0)c='R';
    if(strcmp(s,"...")==0)c='S';
    if(strcmp(s,"-")==0)c='T';
    if(strcmp(s,"..-")==0)c='U';
    if(strcmp(s,"...-")==0)c='V';
    if(strcmp(s,".--")==0)c='W';
    if(strcmp(s,"-..-")==0)c='X';
    if(strcmp(s,"-.--")==0)c='Y';
    if(strcmp(s,"--..")==0)c='Z';
    if(strcmp(s,"-----")==0)c='0';
    if(strcmp(s,".----")==0)c='1';
    if(strcmp(s,"..---")==0)c='2';
    if(strcmp(s,"...--")==0)c='3';
    if(strcmp(s,"....-")==0)c='4';
    if(strcmp(s,".....")==0)c='5';
    if(strcmp(s,"-....")==0)c='6';
    if(strcmp(s,"--...")==0)c='7';
    if(strcmp(s,"---..")==0)c='8';
    if(strcmp(s,"----.")==0)c='9';
    return c;
}

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        printf("case #%d:\n",a);
        char s[1001];
        scanf("%s",s);
        int l=strlen(s);
        for(int i=0;i<l;){
            if(s[i]!='/'){
                int m=0,j;
                for(j=i;s[j]!='/';j++)m++;
                char si[6];memset(si,0,sizeof(si));
                strncpy(si,s+i,m);
                si[m]='\0';
                char c=trans(si);
                printf("%c",c);
                i=j;
            }
            if(s[i]=='/'){
                int m=0,j;
                for(j=i;s[j]=='/';j++)m++;
                if(m==1);
                else if(m==3)printf(" ");
                else if(m==5)printf(".");
                i=j;
            }
        }
        printf("\n");
        a++;
    }
}