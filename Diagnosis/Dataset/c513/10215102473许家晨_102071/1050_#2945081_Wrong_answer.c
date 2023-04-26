#include<string.h>
#include<stdio.h>
char *strrstr(const char *s1, const char *s2)
{
 int n;
 int len1 = strlen(s1);
 int len2 = strlen(s2);
 s1 = s1+len1-len2;//(len1-1)-(len2-1)
 if (*s2){
  while(*s1){
   for (n=0; *(s1 + n) == *(s2 + n); n++){
    if (!*(s2 + n + 1))
     return (char *)s1;
   }
   s1--;
  }
  return NULL;
 }
 else return (char *)s1;
}

int findmax(char* s1,char* s2,char* s) {
    char* start=strstr(s,s1);
	char* pend=strrstr(s,s2);

	
    int len=strlen(s1);
    int max=pend-start-len;
    
    return max-1;
}


int main() {
    int T,cnt=0;
    scanf("%d",&T);
    while(T--) {
        printf("case #%d:\n",cnt++);
        char s1[81]= {'\0'};
        char s2[81]= {'\0'};
        char s[81]= {'\0'};
        scanf("%s%s%s",s1,s2,s);
        printf("%d\n",findmax(s1,s2,s));
    }
}