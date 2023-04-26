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
    int t,i,j,k,num,r;
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
            if(s[j]==' '||s[j]==','||s[j]=='.'||s[j]=='?'||s[j]=='!'){
                word[k][num]='\0';
                //printf("%c\n",word[k][num]);
                k++;
                num=0;
            }else{
                word[k][num]=s[j];
                //printf("%c",word[k][num]);
                num++;
            }
        }
      qsort(word,k,sizeof(word[0]),cmp);
      char b[500];
      b[0]=word[0];
      j=0;
      for(r=1;r<k;r++){
        if(word[r]!=word[r-1]){
            b[j]=word[r];
            j++;
        }
      }
      for(r=0;r<k;r++){
        printf("%s%c",b[r],r==k-1?'\n':' ');
        }
    }
}