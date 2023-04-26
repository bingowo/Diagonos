#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void*a,const void*b);
int main()
{int n;
 char**email;
 scanf("%d\n",&n);
 email=(char**)malloc(n*sizeof(char*));
 int i,len,*p;
 char s[1000001];
 for(i=0;i<n;i++)
 {scanf("%c",&s[i]);
  len=strlen(s);
  p=(char*)malloc(len+1);
  strcpy(p,s);
  *(email+i)=p;
 }
 qsort(email,n,sizeof(char*),cmp);
 for(i=0;i<n;i++)
 printf("%s\n",email[i]);
 for(i=0;i<n;i++)
 {p=email[i];
  free(p);
 }
 free(email);
 return 0;
}

int cmp(const void*a,const void*b)
{char*p1,*p2,*d1,*d2;
 int i=0;
 p1=*((char**)a);
 p2=*((char**)b);
 while(*(p1+i)!='@') i++;
 d1=p1+i+1;
 i=0;
 while(*(p2+i)!='@') i++;
 d2=p2+i+1;
 if(strcmp(d1,d2)==0) return strcmp(p2,p1);
 else return  strcmp(d1,d2);
}
