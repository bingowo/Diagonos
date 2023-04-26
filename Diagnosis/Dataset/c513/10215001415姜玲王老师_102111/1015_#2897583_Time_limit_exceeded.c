int main()
{int n,i,j;
int num[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
scanf("%d",&n);
for(i=0;i<n;i++)
{int k=0,m=0,v,o,t;
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
for(o=1;o<=k;o++)
{a[k-o]=a[26-o];
}
}
scanf("%s",s);
for(j=0;j<strlen(s);j++)
{if(s[j]!=',')
{for(;s[j]>='0'&&s[j]<='9'&&j<strlen(s);j++)
{b[m]=b[m]*10+s[j]-'0';}
m++;}
for(o=1;o<=m;o++)
{b[m-o]=b[26-o];
}}
for(v=25;v>0;v--)
    { c[v+1]=(b[v]+a[v]+c[v])/num[v];
        c[v]=(b[v]+a[v]+c[v])%num[v];}
printf("case #%d:\n",i);
for(t=0;c[t]==0;t++)
for(t;t<25;v++){printf("%d,",c[t]);}
  printf("%d\n",c[t]);
}
}

