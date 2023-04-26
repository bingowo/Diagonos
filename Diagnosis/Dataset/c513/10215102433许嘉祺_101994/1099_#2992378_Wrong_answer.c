#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    char s[1001];
    char ans[1001];
    char b[300];
    b[5]='A';
    b[67]='B';
    b[70]='C';
    b[22]='D';
    b[1]='E';
    b[43]='F';
    b[25]='G';
    b[40]='H';
    b[4]='I';
    b[53]='J';
    b[23]='K';
    b[49]='L';
    b[8]='M';
    b[7]='N';
    b[26]='O';
    b[52]='P';
    b[77]='Q';
    b[16]='R';
    b[13]='S';
    b[2]='T';
    b[14]='U';
    b[41]='V';
    b[17]='W';
    b[68]='X';
    b[71]='Y';
    b[76]='Z';
    b[242]='0';
    b[161]='1';
    b[134]='2';
    b[125]='3';
    b[122]='4';
    b[121]='5';
    b[202]='6';
    b[229]='7';
    b[238]='8';
    b[241]='9';
    int len;
    for (int i=0;i<t;i++){
        scanf("%s",s);
        len=0;
        printf("case #%d:\n",i);
        char *point=strchr(s,'/');
        if (point==NULL){
            int sum=0;
            for (int j=0;j<strlen(s);j++)
            if (s[j]=='.') sum=sum*3+1;
            else sum=sum*3+2;
            printf("%c\n",b[sum]);
        }
        else {
            char *start=s;
            while (point!=NULL){
                int sum=0;
                for (;start<point;start++)
                    if (s[start-s]=='.') sum=sum*3+1;
                    else sum=sum*3+2;
                printf("%c",b[sum]);
                if (s[point+1-s]=='/'&&s[point+3-s]=='/') {printf(".");point=point+5;start=point;}
                else if (s[point+1-s]=='/') {printf(" ");point=point+3;start=point;}
                else {point=point+1;start=point;}
                point=strchr(point,'/');
            }
            int sum=0;
            for (;start<s+strlen(s);start++)
                if (s[start-s]=='.' )sum=sum*3+1;
                else sum=sum*3+2;
            printf("%c\n",b[sum]);
        }
    }
    return 0;
}
