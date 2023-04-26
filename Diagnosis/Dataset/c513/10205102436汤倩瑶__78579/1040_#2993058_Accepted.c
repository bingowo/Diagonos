#include<stdio.h>

#include<string.h>
int main()
{//A AB B O
    char  no[][3]={"A","AB","B","O"};
    const int p[4][4][4]={{{1,0,0,1},{1,1,1,0},{1,1,1,1},{1,0,0,1}},
                    {{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,0,1,0}},
                    {{1,1,1,1},{1,1,1,0},{0,0,1,1},{0,0,1,1}},
                    {{1,0,0,1},{1,0,1,0},{0,0,1,1},{0,0,0,1}}};
    int ans[4]={0};
    char f[3],m[3],s[3];
    int i,j,k,cnt,t;
    scanf("%s%s%s",f,m,s);
    if(strcmp(f,"?")==0){
        if(strcmp(m,"A")==0)j=0;
        if(strcmp(m,"AB")==0)j=1;
        if(strcmp(m,"B")==0)j=2;
        if(strcmp(m,"O")==0)j=3;
        if(strcmp(s,"A")==0)k=0;
        if(strcmp(s,"AB")==0)k=1;
        if(strcmp(s,"B")==0)k=2;
        if(strcmp(s,"O")==0)k=3;
        cnt=0;
        for(i=0;i<4;i++)
        {
            ans[i]=p[i][j][k];

            if(ans[i])cnt++;
        }

        if(cnt==0)
        printf("impossible ");
        else {printf("{");
        for(t=0;t<4&&cnt>1;t++)
        {
            if(ans[t]){printf("%s,",no[t]);
            cnt--;
        }}
        for(;t<4;t++)
            if(ans[t])
        printf("%s} ",no[t]);
        }
        printf("%s %s",m,s);


    }
    else if(strcmp(m,"?")==0){
        if(strcmp(f,"A")==0)i=0;
        if(strcmp(f,"AB")==0)i=1;
        if(strcmp(f,"B")==0)i=2;
        if(strcmp(f,"O")==0)i=3;
        if(strcmp(s,"A")==0)k=0;
        if(strcmp(s,"AB")==0)k=1;
        if(strcmp(s,"B")==0)k=2;
        if(strcmp(s,"O")==0)k=3;
        printf("%s ",f);
        cnt=0;
        for(j=0;j<4;j++)
        {
            ans[j]=p[i][j][k];
            if(ans[j])cnt++;
        }
        if(cnt==0)
        printf("impossible ");
        else {printf("{");
        for(t=0;t<4&&cnt>1;t++)
        {
            if(ans[t]){printf("%s,",no[t]);
            cnt--;}
        }
        for(;t<4;t++)
            if(ans[t])
        printf("%s} ",no[t]);
        }
        printf("%s",s);
    }
    else{
        if(strcmp(f,"A")==0)i=0;
        if(strcmp(f,"AB")==0)i=1;
        if(strcmp(f,"B")==0)i=2;
        if(strcmp(f,"O")==0)i=3;
        if(strcmp(m,"A")==0)j=0;
        if(strcmp(m,"AB")==0)j=1;
        if(strcmp(m,"B")==0)j=2;
        if(strcmp(m,"O")==0)j=3;
        printf("%s %s ",f,m);
        cnt=0;
        for(k=0;k<4;k++)
        {
            ans[k]=p[i][j][k];
            if(ans[k])cnt++;
        }

        if(cnt==0)
        printf("impossible ");
        else {printf("{");
        for(t=0;t<4&&cnt>1;t++)
        {
            if(ans[t]){printf("%s,",no[t]);
            cnt--;
        }}
        for(;t<4;t++)
            if(ans[t])
        printf("%s}",no[t]);
        }
    }
}
