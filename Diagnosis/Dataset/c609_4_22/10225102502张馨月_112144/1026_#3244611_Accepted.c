int count(char *a)//计算a中不同字母的个数
{
    int p,res=0;
    int b[26];
    for(p=0;p<26;p++)
        b[p]=1;
    for(p=0;p<strlen(a);p++)
      {

        if(b[a[p]-65]==1){
        b[a[p]-65]=-1;
        res++;
        }
      }
    return res;

}

int cmp(const void*a,const void*b)
{
    char*pa=(char*)a;
    char*pb=(char*)b;
    if(count(pa)!=count(pb))
        return count(pb)-count(pa);
    else return strcmp(pa,pb);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
         int n;
         scanf("%d",&n);
         char table[n][21];
         for(int k=0;k<n;k++)
         {
             scanf("%s",table[k]);//注意注意输入的是table[k],别写成table[n]了
         }

         qsort(table,n,sizeof(table[0]),cmp);
         printf("case #%d:\n",i);
         for(int k=0;k<n;k++)
            printf("%s\n",table[k]);

    }


    return 0;
}
