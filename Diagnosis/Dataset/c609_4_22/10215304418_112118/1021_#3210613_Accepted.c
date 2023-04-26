#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int change[123];
char st[123][123];
char dict[123];

int check(int i,int j){
    char stx[123];
    strcpy(stx,st[i]);
    char sty[123];
    strcpy(sty,st[j]);
    int len=strlen(stx);
    if (len>strlen(sty)) len=strlen(sty);
    i=0;
    for (i=0;i<len;i++){
        char cx=stx[i];
        char cy=sty[i];
        if (cx>='A' && cx<='Z') cx=cx-'A'+'a';
        if (cy>='A' && cy<='Z') cy=cy-'A'+'a';
        if (change[cx-'a']>change[cy-'a']) return 1;
        if (change[cx-'a']<change[cy-'a']) return 0;
    }
    if (strlen(stx)>strlen(sty)) return 1;
    else return 0;
}

int main(){
    while (scanf("%s",dict)!=EOF){
        for (int ii=0;ii<strlen(dict);ii++)
            change[dict[ii]-'A']=ii;
        char s[21345];
        gets(s);
        gets(s);
        int i=0;
        int j=0;
        for (int l=0;l<=strlen(s);l++){
            if (s[l]==' ' || s[l]=='\0'){
                st[i][j]='\0';
                j=0;
                i++;
            }
            else {
                st[i][j]=s[l];
                j++;
            }
        }
        for (int ii=0;ii<i;ii++){
            for (int jj=ii+1;jj<i;jj++){
                if (check(ii,jj)){
                    char temp[123];
                    strcpy(temp,st[ii]);
                    strcpy(st[ii],st[jj]);
                    strcpy(st[jj],temp);
                }
            }
        }
        for (int ii=0;ii<i;ii++)
            printf("%s ",st[ii]);
        printf("\n");
    }
    return 0;
}
