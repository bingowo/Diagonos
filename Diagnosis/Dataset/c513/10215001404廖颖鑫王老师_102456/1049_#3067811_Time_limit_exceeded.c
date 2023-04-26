#define N 500

int replace (char m[],char sign,char *p[],int max)//把每一个单词存入s1中
{
    int i,co=0,sz=strlen(m);
    p[co++]=m;//存入第一个单词首字母的地址
    for(i=0;i<sz;i++)
    {
        if(m[i]==sign)//如果读到空格
        {
            m[i]=0;
            p[co++]=&m[i+1];//存入空格后面一个字符的地址
            if(co>=max)break;
        }
    }
    return co;//单词个数
}

int delete(char *p[],int co)
{
    int i,j,k;
    for(i=0;i<co;i++)
    {
        for(j=i+1;j<co-1;j++)
        {
            if(strcmp(p[i],p[j])==0)
            {
                for(k=j;k<co-1;k++)
                {
                    p[k]=p[k+1];
                }
                co--;
                j--;
            }
        }
    }
    return co;
}

int cmp(const void* p1,const void* p2)
{
    return (strcmp(*(char**)p1,*(char**)p2));
}

int main()
{
    int T,i,co,ans;
    scanf("%d",&T);
    getchar();
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[N+1],*p[N+1],m[N+1];
        gets(s);
        int sz=strlen(s),j=0,k=0;
        while(s[j])//把单词挖出来
        {
            if(s[j]>='a'&&s[i=j]<='z')
                m[k]=s[j];//s[j]为字母时，存入m[j]中
            if(m[k-1]==' ')
            {
                i++;  //s[j]不是字母，并且m[j-1]已经是空格的情况下，m[j]不存东西留到下一次
                continue;//不运行后面的东西，进入下一次循环
            }
            else m[k]=' ';
            i++;k++;
        }
           co=replace(m,' ',p,sz);
           ans=delete(p,co);
           qsort(p,ans,sizeof(p[0]),cmp);
    }
}
