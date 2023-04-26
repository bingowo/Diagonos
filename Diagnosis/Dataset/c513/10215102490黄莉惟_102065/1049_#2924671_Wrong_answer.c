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
    int t,i,j,k,num,r,res;
    res=0;
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
      printf("case #%d:\n",i);
      if(word[0]!=' '){
          printf("%s",word[0]);
          printf(" ");
      }
      for(r=1;r<k;r++){
          res=0;
            if(strlen(word[r])!=strlen(word[r-1])){
                res=1;
            }
            if(strlen(word[r])==strlen(word[r-1])){
                for(j=0;j<strlen(word[r]);j++){
                    if(word[r][j]!=word[r-1][j]){
                        res=1;
                    }
                   // printf("%c %c\n",word[r][j],word[r-1][j]);
                    
                }
            }
            if(res==1){
                printf("%s",word[r]);
                printf(" ");
            }
            
        }
        printf("\n");
    }
}