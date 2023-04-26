#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct
{
    char s[3];
}gine;
void kid(char f[],char m[])
{
    char rh[3];
    int index=0,lenf=strlen(f),lenm=strlen(m);
    if(f[lenf-1]=='-'&&m[lenm-1]=='-')
    {
        rh[index++]='-';
    }
    else
    {
        rh[index++]='+';
        rh[index++]='-';
    }
    if(f[0]=='O'&&m[0]=='O')
    {
        char ans[2]="O";
        if(index==1)
        {
            printf("O-");
        }
        else
        {
            printf("{O+,O-}");
        }
    }
    else if((f[0]=='O'&&m[0]=='A'&&lenm==2)||(m[0]=='O'&&f[0]=='A'&&lenf==2))
    {
        char ans[3]="AO";
        printf("{");
        for(int i=0;i<strlen(ans);i++)
        {
            for(int j=0;j<index;j++)
            {
                printf("%c%c%c",ans[i],rh[j],(i==1&&j==index-1)?'}':',');

            }
        }
    }
    else if((f[0]=='O'&&m[0]=='B'&&lenm==2)||(m[0]=='O'&&f[0]=='B'&&lenf==2))
    {
        char ans[3]="BO";
        printf("{");
        for(int i=0;i<strlen(ans);i++)
        {
            for(int j=0;j<index;j++)
            {
                printf("%c%c%c",ans[i],rh[j],(i==1&&j==index-1)?'}':',');

            }
        }
    }
    else if((f[0]=='O'&&lenm==3)||(m[0]=='O'&&lenf==3))
    {
        char ans[3]="AB";
        printf("{");
        for(int i=0;i<strlen(ans);i++)
        {
            for(int j=0;j<index;j++)
            {
                printf("%c%c%c",ans[i],rh[j],(i==1&&j==index-1)?'}':',');

            }
        }
    }
    else if((f[0]=='B'&&lenf==2&&lenm==3)||(m[0]=='B'&&lenm==2&&lenf==3))
    {
        gine ans[3]={"A","AB","B"};
        printf("{");
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<index;j++)
            {
                printf("%s%c%c",ans[i].s,rh[j],(i==2&&j==index-1)?'}':',');

            }
        }
    }
    else if((f[0]=='A'&&lenf==2&&lenm==3)||(m[0]=='A'&&lenm==2&&lenf==3))
    {
        gine ans[3]={"A","AB","B"};
        printf("{");
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<index;j++)
            {
                printf("%s%c%c",ans[i].s,rh[j],(i==2&&j==index-1)?'}':',');

            }
        }
    }
    else if((m[0]=='A'&&lenm==2&&f[0]=='B'&&lenf==2)||(m[0]=='A'&&lenm==2&&f[0]=='B'&&lenf==2))
    {
        gine ans[4]={"A","AB","B","O"};
        printf("{");
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<index;j++)
            {
                printf("%s%c%c",ans[i].s,rh[j],(i==3&&j==index-1)?'}':',');

            }
        }
    }
    else if(m[0]=='A'&&lenm==2&&f[0]=='A'&&lenf==2)
    {
        gine ans[2]={"A","O"};
        printf("{");
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<index;j++)
            {
                printf("%s%c%c",ans[i].s,rh[j],(i==1&&j==index-1)?'}':',');

            }
        }
    }
    else if(m[0]=='B'&&lenm==2&&f[0]=='B'&&lenf==2)
    {
        gine ans[2]={"B","O"};
        printf("{");
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<index;j++)
            {
                printf("%s%c%c",ans[i].s,rh[j],(i==1&&j==index-1)?'}':',');

            }
        }
    }
    else if(lenf==3&&lenf==3)
    {
         gine ans[3]={"A","AB”,"B"};
        printf("{");
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<index;j++)
            {
                printf("%s%c%c",ans[i].s,rh[j],(i==2&&j==index-1)?'}':',');

            }
        }
    }

}
void parent(char f[],char k[])
{
    char rh[3];
    int index=0,lenf=strlen(f),lenk=strlen(k);
    if(k[lenk-1]=='-')
    {
        rh[index++]='+';
        rh[index++]='-';
    }
    else if(f[lenf-1]=='-')
    {
        rh[index++]='+';
    }
    else
    {
        rh[index++]='+';
        rh[index++]='-';
    }
    if((f[0]=='O'&&k[0]=='O')||(k[0]=='O'&&f[0]=='A'&&lenf==2)||(k[0]=='O'&&f[0]=='B'&&lenf==2))
    {
        char ans[4]="ABO";
        printf("{");
        for(int i=0;i<strlen(ans);i++)
        {
            for(int j=0;j<index;j++)
            {
                printf("%c%c%c",ans[i],rh[j],(i==2&&j==index-1)?'}':',');

            }
        }

    }
    else if(f[0]=='O'&&k[0]=='A'&&lenk==2)
    {
        gine ans[2]={"A","AB"};
        printf("{");
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<index;j++)
            {
                printf("%s%c%c",ans[i].s,rh[j],(i==1&&j==index-1)?'}':',');

            }
        }
    }
    else if(f[0]=='O'&&k[0]=='B'&&lenk==2)
    {
        gine ans[2]={"AB","B"};
        printf("{");
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<index;j++)
            {
                printf("%s%c%c",ans[i].s,rh[j],(i==1&&j==index-1)?'}':',');

            }
        }
    }
    else if((f[0]=='O'&&lenk==3)||(k[0]=='O'&&lenf==3))
    {
        printf("impossible");
    }
    else if((f[0]=='B'&&lenf==2&&lenk==3)||(f[0]=='B'&&lenf==2&&k[0]=='A'&&lenk==2))
    {
        gine ans[2]={"A","AB"};
        printf("{");
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<index;j++)
            {
                printf("%s%c%c",ans[i].s,rh[j],(i==1&&j==index-1)?'}':',');

            }
        }
    }
    else if(f[0]=='A'&&lenf==2&&lenk==3)
    {
        gine ans[2]={"AB","B"};
        printf("{");
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<index;j++)
            {
                printf("%s%c%c",ans[i].s,rh[j],(i==1&&j==index-1)?'}':',');

            }
        }
    }
    else if(f[0]=='A'&&lenf==2&&k[0]=='B'&&lenk==2)
    {
        gine ans[2]={"AB","B"};
        printf("{");
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<index;j++)
            {
                printf("%s%c%c",ans[i].s,rh[j],(i==1&&j==index-1)?'}':',');

            }
        }
    }
    else if((k[0]=='B'&&lenk==2&&lenf==3)||(k[0]=='A'&&lenk==2&&lenf==3)||(k[0]=='A'&&lenk==2&&lenf==2&&f[0]=='A')||(k[0]=='B'&&lenk==2&&lenf==2&&f[0]=='B'))
    {
        gine ans[4]={"A","AB","B","O"};
        printf("{");
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<index;j++)
            {
                printf("%s%c%c",ans[i].s,rh[j],(i==3&&j==index-1)?'}':',');

            }
        }
    }
    else if(lenf==3&&lenk==3)
    {
        gine ans[3]={"A","AB","B"};
        printf("{");
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<index;j++)
            {
                printf("%s%c%c",ans[i].s,rh[j],(i==2&&j==index-1)?'}':',');

            }
        }
    }

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char f[4],m[4],k[4];
        scanf("%s %s %s",f,m,k);
        if(strcmp(k,"?")==0)
        {
            printf("%s %s ",f,m);
            kid(f,m);
            printf("\n");
        }
        else if(strcmp(f,"?")==0)
        {
            parent(m,k);
            printf(" %s %s\n",m,k);
        }
        else
        {
            printf("%s ",f);
            parent(f,k);
            printf(" %s\n",k);
        }
    }
    return 0;
}
