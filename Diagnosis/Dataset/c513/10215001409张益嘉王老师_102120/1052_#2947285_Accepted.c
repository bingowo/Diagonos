#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int zhi;
    int sum;
}zu;

void del(char sign,char *n)
{
    int len=strlen(n),i;
    for(i=0;i<len;i++)
    {
        if(n[i]==sign) {n[i]='#';break;}
    }

}

zu find_0(char s[])
{
    int i;
    zu re;
    re.sum=0;
    re.zhi=-1;
    int len=strlen(s);
    //char ne[25];
    //strcpy(ne,s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='Z')
        {
            re.zhi=0;
            re.sum++;
        }

    }
    if(re.zhi!=-1)
    {
        for(i=0;i<re.sum;i++)
        {
            del('Z',s);
            del('E',s);
            del('R',s);
            del('O',s);

        }
    }
    return re;

}

zu find_6(char s[])
{
    int i;
    zu re;
    re.sum=0;
    re.zhi=-1;
    int len=strlen(s);
    //char ne[25];
    //strcpy(ne,s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='X')
        {
            re.zhi=6;
            re.sum++;
        }

    }
    if(re.zhi!=-1)
    {
        for(i=0;i<re.sum;i++)
        {
            del('S',s);
            del('I',s);
            del('X',s);

        }
    }
    return re;
}

zu find_2(char s[])
{
    int i;
    zu re;
    re.sum=0;
    re.zhi=-1;
    int len=strlen(s);
    //char ne[25];
    //strcpy(ne,s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='W')
        {
            re.zhi=2;
            re.sum++;
        }

    }
    if(re.zhi!=-1)
    {
        for(i=0;i<re.sum;i++)
        {
            del('T',s);
            del('O',s);
            del('W',s);

        }
    }
    return re;
}

zu find_4(char s[])
{
    int i;
    zu re;
    re.sum=0;
    re.zhi=-1;
    int len=strlen(s);
    //char ne[25];
    //strcpy(ne,s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='U')
        {
            re.zhi=4;
            re.sum++;
        }

    }
    if(re.zhi!=-1)
    {
        for(i=0;i<re.sum;i++)
        {
            del('F',s);
            del('O',s);
            del('U',s);
            del('R',s);

        }
    }
    return re;
}

zu find_5(char s[])
{
    int i;
    zu re;
    re.sum=0;
    re.zhi=-1;
    int len=strlen(s);
    //char ne[25];
    //strcpy(ne,s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='F')
        {
            re.zhi=5;
            re.sum++;
        }

    }
    if(re.zhi!=-1)
    {
        for(i=0;i<re.sum;i++)
        {
            del('F',s);
            del('I',s);
            del('V',s);
            del('E',s);

        }
    }
    return re;
}

zu find_1(char s[])
{
    int i;
    zu re;
    re.sum=0;
    re.zhi=-1;
    int len=strlen(s);
    //char ne[25];
    //strcpy(ne,s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='O')
        {
            re.zhi=1;
            re.sum++;
        }

    }
    if(re.zhi!=-1)
    {
        for(i=0;i<re.sum;i++)
        {

            del('O',s);
            del('N',s);
            del('E',s);

        }
    }
    return re;
}

zu find_8(char s[])
{
    int i;
    zu re;
    re.sum=0;
    re.zhi=-1;
    int len=strlen(s);
    //char ne[25];
    //strcpy(ne,s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='G')
        {
            re.zhi=8;
            re.sum++;
        }

    }
    if(re.zhi!=-1)
    {
        for(i=0;i<re.sum;i++)
        {
            del('E',s);
            del('I',s);
            del('G',s);
            del('H',s);
            del('T',s);

        }
    }
    return re;
}

zu find_9(char s[])
{
    int i;
    zu re;
    re.sum=0;
    re.zhi=-1;
    int len=strlen(s);
    //char ne[25];
    //strcpy(ne,s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='I')
        {
            re.zhi=9;
            re.sum++;
        }

    }
    if(re.zhi!=-1)
    {
        for(i=0;i<re.sum;i++)
        {
            del('N',s);
            del('I',s);
            del('N',s);
            del('E',s);

        }
    }
    return re;
}

zu find_7(char s[])
{
    int i;
    zu re;
    re.sum=0;
    re.zhi=-1;
    int len=strlen(s);
    //char ne[25];
    //strcpy(ne,s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='S')
        {
            re.zhi=7;
            re.sum++;
        }

    }
    if(re.zhi!=-1)
    {
        for(i=0;i<re.sum;i++)
        {
            del('S',s);
            del('E',s);
            del('V',s);
            del('E',s);
            del('N',s);

        }
    }
    return re;
}

zu find_3(char s[])
{
    int i;
    zu re;
    re.sum=0;
    re.zhi=-1;
    int len=strlen(s);
    //char ne[25];
    //strcpy(ne,s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='H')
        {
            re.zhi=3;
            re.sum++;
        }

    }
    if(re.zhi!=-1)
    {
        for(i=0;i<re.sum;i++)
        {
            del('T',s);
            del('H',s);
            del('R',s);
            del('E',s);
            del('E',s);

        }
    }
    return re;
}

int cmp(const void*a,const void*b)
{
    int aa=*((int*)a);
    int bb=*((int*)b);

    return aa-bb;

}

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        char s[25];
        scanf("%s",s);
        int len=strlen(s),j,k,m=0;
        zu ans[15];
        int re[15];
        memset(re,0,sizeof(int)*15);
        memset(ans,0,sizeof(zu)*15);
        ans[0]=find_0(s);

        ans[6]=find_6(s);

        ans[2]=find_2(s);

        ans[4]=find_4(s);

        ans[5]=find_5(s);

        ans[1]=find_1(s);

        ans[8]=find_8(s);

        ans[9]=find_9(s);

        ans[7]=find_7(s);

        ans[3]=find_3(s);


        for(j=0;j<10;j++)
        {

            if(ans[j].zhi!=-1)
            {
                for(k=0;k<ans[j].sum;k++)
                {
                    re[m++]=ans[j].zhi;

                }
            }
        }

        qsort(re,m,sizeof(int),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<m;j++)
        {
            printf("%d",re[j]);
        }
        printf("\n");


    }
    return 0;
}
