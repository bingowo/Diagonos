#include <stdio.h>
#include <string.h>
#include <ctype.h>
int cmp(const void *a,const void *b)
{
	char *str1,*str2;
	str1=*(char (*)[500])a; str2=*(char (*)[500])b;
	return strcmp(str1,str2);
}
int main(){
    int t,i,j,k,num;
    char c;
    scanf("%d",&t);
    c = getchar();
    for(i=0;i<t;i++){
        char s[500];
        gets(s);
        char word[500][500];
        k=0;
        num=0;
        for(j=0;j<strlen(s);j++){
            if(s[i]==' '||s[i]==','||s[i]=='.'||s[i]=='?'||s[i]=='!'){
                word[k][num]='\0';
                printf("%c\n",word[k][num]);
                k++;
                num=0;
            }else{
                word[k][num]=s[i];
                printf("%c",word[k][num]);
                num++;
            }
        }
        
    }
}