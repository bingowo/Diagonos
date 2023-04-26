int cmp(const void*a,const void*b)
{string p1=*(string*)a;
string p2=*(string*)b;
if(p1.b>p2.b) return 1;
if(p1.b<p2.b) return -1;
return strcmp(p1.a,p2.a);
}
long long caculate(char*d)
{char o['z'+1]={0};
long long answer=0;
int sum=0;
for(int i=0;i<strlen(d);i++)
{if(o[d[i]]==0) sum++;
if(i==0){o[d[i]]='1';}
if(i!=0&&o[d[i]]==0&&sum==2) o[d[i]]='0';
if(i!=0&&o[d[i]]==0) o[d[i]]=sum-1+'0';
}
for(int i=0;i<strlen(d);i++)
{answer=answer*sum+o[d[i]]-'0';
}
return answer;}
int main()
{int n;
scanf("%d",&n);
string c[10000];
for(int i=0;i<n;i++)
{scanf("%s",c[i].a);
c[i].b=caculate(c[i].a);
}
qsort(c,n,sizeof(c[0]),cmp);
for(int i=0;i<n;i++)
    {printf("%s\n",c[i].a);
    }
}
