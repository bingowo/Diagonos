int main()
{int n,i,j;
int num[25]={2,3,5,7,9,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};
scanf("%d",&n);
for(i=0;i<n;i++)
{int k=0,m=0,v;
char s[100];
int a[26]={0};
int b[26]={0};
int c[26]={0};
scanf("%s",s);
for(j=0;j<strlen(s);j++)
{if(s[j]!=',')
{for(;s[j]>='0'&&s[j]<='9'&&j<strlen(s);j++)
{a[k]=a[k]*10+(s[j]-'0');}
k++;}
}
scanf("%s",s);
for(j=0;j<strlen(s);j++)
{if(s[j]!=',')
{for(;s[j]>='0'&&s[j]<='9'&&j<strlen(s);j++)
{b[m]=b[m]*10+s[j]-'0';}
m++;}
}
for(v=0;v<m||v<n;v++)
    { c[v+1]=(b[v]+a[v]+c[v])/num[v];
        c[v]=(b[v]+a[v]+c[v])%num[v];}
printf("case #%d:\n",i);
if(c[v]!=0){printf("%d,",c[v]);}
for(v--;v>0;v--){printf("%d,",c[v]);}
  printf("%d\n",c[v]);
}
}

