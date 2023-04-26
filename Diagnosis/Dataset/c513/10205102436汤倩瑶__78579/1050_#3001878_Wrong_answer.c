#include<stdio.h>
#include<string.h>
int main()
{int T;
char s1[85],s2[85],s[85];

scanf("%d",&T);
for(int i=0;i<T;i++)
{int pos1=-1,pos2=-1,pos3=-1,pos4=-1;
    scanf("%s%s%s",s1,s2,s);
    int l1=strlen(s1);
    int l2=strlen(s2);
    int l=strlen(s);

    for(int i=0;i+l1<=l;i++)
    {
        int flag=1;
        for(int j=0;j<l1;j++)
        {
            if(s1[j]!=s[i+j]){flag=0;break;}
        }
        if(flag){pos1=i;break;}
    }
    printf("%d\n",pos1);
    for(int i=0;i+l2<=l;i++)
    {
        int flag=1;
        for(int j=0;j<l2;j++)
        {
            if(s2[j]!=s[i+j]){flag=0;break;}
        }
        if(flag){pos2=i;break;}
    }
    printf("%d\n",pos2);
     for(int i=0;i+l1<=l;i++)
    {
        int flag=1;
        for(int j=0;j<l1;j++)
        {
            if(s1[j]!=s[i+j]){flag=0;break;}
        }
        if(flag){pos3=i;}
    }
    printf("%d\n",pos3);
    for(int i=0;i+l2<=l;i++)
    {
        int flag=1;
        for(int j=0;j<l2;j++)
        {
            if(s2[j]!=s[i+j]){flag=0;break;}
        }
        if(flag){pos4=i;}
    }
    printf("%d\n",pos4);
    printf("%d\n",pos4-pos1-l1);
    printf("%d\n",pos3-pos2-l2);

  int max=pos4-pos1-l1>pos3-pos2-l2?pos4-pos1-l1:pos3-pos2-l2;
  if(max<0)max=0;
  if(pos1==-1||pos2==-1||pos3==-1||pos4==-1)max=0;
  printf("case #%d:\n%d\n",i,max);
}
return 0;
}



