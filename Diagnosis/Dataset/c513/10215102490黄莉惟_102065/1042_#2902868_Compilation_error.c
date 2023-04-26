#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char char_comb[17]="";
void comb(char *s,int depth,int k){
    if(depth) printf("%s\n",char_comb);
    for(int i=k;s[i];i++){
        char_comb[depth]=s[i];
        char_comb[depth+1]=0;
        comb(s,depth+1,i+1);
    }
}
int cmp(const void *a, const void *b)
{
	s *pa = (s *)a;
	s *pb = (s *)b;
	return strcmp(a,b);
}
int main(){
    int t;
    scanf("%d",&t);
    int i;
    char s[17];
    for(i=0;i<t;i++){
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(s[0]),cmp)
        printf("%s",s);
    }
}