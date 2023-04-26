#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b)
{char *s1,*s2,*d1,*d2; int i=0;
s1=*((char**)a);
s2=*((char**)b);
while(*(s1+i)!='@') i++;
d1=s1+i+1;
i=0;
while(*(s2+i)!='@') i++;
d1=s2+i+1;

if(strcmp(d1,d2)==0) return strcmp(s2,s1);
else return strcmp(d1,d2);
}
int main()
{int n,i,len; char **email;
char s[1000001],*p;
scanf("%d\n",&n); 
email=(char**)malloc(sizeof(char*)*n);
for(i=0;i<n;i++)
{scanf("%s",s);
len=strlen(s);
p=(char*)malloc(len+1);
strcpy(p,s);
*(email+i)=p;
}
 qsort(email,n,sizeof(char *),cmp);   
 for(i=0;i<n;i++)
 { printf("%s\n",email[i]);
     }
     for(i=0;i<n;i++)
     { p=email[i];
        free(p); 
     }
     free(email);
     return 0;
}