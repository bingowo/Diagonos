#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char s[3];
}blood;
void  bu(char s[])
{
    int ret;
    if(strcmp(s,"A")==0)
      {
          s[1]='O';
          s[2]='\0';
      }
    else if(strcmp(s,"B")==0)
       {
          s[1]='O';
          s[2]='\0';
      }
    else if(strcmp(s,"O")==0)
    {
          s[1]='O';
          s[2]='\0';
      }
}
void qu(char s[])
{
    if(strcmp(s,"AA")==0||strcmp(s,"AO")==0||strcmp(s,"OA")==0)
    {
        s[0]='A';
        s[1]='\0';
    }
    else if(strcmp(s,"BB")==0||strcmp(s,"BO")==0||strcmp(s,"OB")==0)
    {
        s[0]='B';
        s[1]='\0';
    }
    else if(strcmp(s,"AB")==0||strcmp(s,"BA")==0)
    {
        s[0]='A';
        s[1]='B';
        s[2]='\0';
    }
    else
    {
        s[0]='O';
        s[1]='\0';
    }
}
void kid(char s1[],char s2[],blood ret[])
{
    int index=0;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            ret[index].s[0]=s1[i];
            ret[index].s[1]=s2[j];
            index++;
        }
    }
    for(int i=0;i<index;i++)
    {
        qu(ret[i].s);
    }

}
int parent(blood ret[],char s1[],char s2[])
{
    int temp=0,index=0,cnt=0;
    for(int i=0;i<2;i++)
    {
        if(s1[i]==s2[0])
        {
            temp=1;

        }
        if(s1[i]==s2[1])
        {
            cnt=1;
        }
    }
    if(temp)
    {
        if(s2[1]=='A')
        {
            ret[index].s[0]='A';
            ret[index].s[1]='\0';
            index++;
            ret[index].s[0]='A';
            ret[index].s[1]='B';
            ret[index].s[2]='\0';
        }
        else if(s2[1]=='B')
        {
            ret[index].s[0]='B';
            ret[index].s[1]='\0';
            index++;
            ret[index].s[0]='A';
            ret[index].s[1]='B';
            ret[index].s[2]='\0';
        }
        else
        {
            ret[index].s[0]='O';
            ret[index].s[1]='\0';
        }
        index++;
    }
    if(cnt)
    {
        if(s2[0]=='A')
        {
            ret[index].s[0]='A';
            ret[index].s[1]='\0';
            index++;
            ret[index].s[0]='A';
            ret[index].s[1]='B';
            ret[index].s[2]='\0';
        }
        else if(s2[0]=='B')
        {
            ret[index].s[0]='B';
            ret[index].s[1]='\0';
            index++;
            ret[index].s[0]='A';
            ret[index].s[1]='B';
            ret[index].s[2]='\0';
        }
        else
        {
            ret[index].s[0]='O';
            ret[index].s[1]='\0';
        }
        index++;
    }
    return index;

}
int cmp(const void*a,const void*b)
{
    char*x=(char*)a;
    char*y=(char*)b;

    return strcmp(x,y)<=0?-1:1;
}
int main()
{
    blood ans[3];
    for(int i=0;i<3;i++)
    {
        scanf("%s",ans[i].s);
        bu(ans[i].s);
    }

    if(strcmp(ans[2].s,"?")==0)
    {
        blood a[4];
        kid(ans[0].s,ans[1].s,a);
        qsort(a,4,sizeof(blood),cmp);
        for(int i=0;i<3;i++)
        {
            qu(ans[i].s);
        }
        printf("%s %s {%s",ans[0].s,ans[1].s,a[0].s);
        for(int i=1;i<4;i++)
        {
           if(strcmp(a[i-1].s,a[i].s)==0)
                continue;
           printf(",%s",a[i].s);
        }
        printf("}");

    }
    else if(strcmp(ans[0].s,"?")==0)
    {
        blood a[10];
        int x=parent(a,ans[1].s,ans[2].s);
        for(int i=0;i<3;i++)
        {
            qu(ans[i].s);
        }
        if(x==0)
        {
            printf("impossible %s %s",ans[1].s,ans[2].s);
        }
        else
        {
            qsort(a,x,sizeof(blood),cmp);
            printf("{%s",a[0].s);
            for(int i=1;i<x;i++)
            {
                if(strcmp(a[i-1].s,a[i].s)==0)
                    continue;
                printf(",%s",a[i].s);
            }
            printf("} %s %s",ans[1].s,ans[2].s);
        }
    }
    else
    {
        blood a[10];
        int x=parent(a,ans[0].s,ans[2].s);
        for(int i=0;i<3;i++)
        {
            qu(ans[i].s);
        }
        if(x==0)
        {
            printf("%s impossible %s",ans[0].s,ans[2].s);
        }
        else
        {
            qsort(a,x,sizeof(blood),cmp);
            printf("%s {%s",ans[0].s,a[0].s);
            for(int i=1;i<x;i++)
            {
                if(strcmp(a[i-1].s,a[i].s)==0)
                    continue;
                printf(",%s",a[i].s);
            }
            printf("} %s",ans[2].s);
        }
    }
    return 0;
}
