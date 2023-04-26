int cmp(const void*a,const void*b)
{char*p1=*(char**)a;
char*p2=*(char**)b;
char*q1,*q2;
int i;
for(i=0;*(p1+i)!='@';i++)
q1=p1+i+1;
for(i=0;*(p2+i)!='@';i++)
q2=p2+i+1;
if(strcmp(q1,q2)) return strcmp(q1,q2);
return -strcmp(p1,p2);

}
int main()
{int n,len;
char**email;
scanf("%d",&n);
email=(char**)malloc(n*sizeof(char*));
char s[1000001],*p;
for(int i=0;i<n;i++)
{scanf("%s",s);
len=strlen(s);
p=(char*)malloc(len+1);
strcpy(p,s);
*(email+i)=p;
}
qsort(email,n,sizeof(char*),cmp);
for(int i=0;i<n;i++)
    {printf("%s\n",email[i]);}
for(int i=0;i<n;i++)
{p=email[i];
free(p);
}
free(email);}
