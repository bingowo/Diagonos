int main()
{
    char s[1000];
    while (scanf("%s",s)!=EOF)
    {
        int i;
        for(i=0;s[i];i++)
        {
            if(s[i]=='.')
                fudianshu(s);
        }
        zhengshu(s);
        return 0;
    }
}
