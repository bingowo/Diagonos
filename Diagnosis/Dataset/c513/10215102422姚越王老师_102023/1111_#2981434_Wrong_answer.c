#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define C 1000
typedef struct{int x,y;}point;
int main()
{
    char s[C],tmp[C];int i,j,q;
    while(~scanf("%s",s))
    {
        int a[4]={0},pos[4]={0},cnt=0,start,end;
        for(i=6;s[i];++i)if(s[i]=='+'||s[i]=='-')pos[cnt++]=i;
        pos[cnt++]=strlen(s);
        for(i=0;i<cnt;++i)
        {
            if(isdigit(s[pos[i]-1]))
            {
                start=i?pos[i-1]:5;
                end=pos[i]-4;
                q=0;for(j=start;j<=end;++j,++q)tmp[q]=s[j];
                tmp[q]='\0';
                a[s[pos[i]-1]-'0']=atoi(tmp);
            }
            else if(s[pos[i]-1]=='x')
            {
                start=i?pos[i-1]:5;
                end=pos[i]-2;
                q=0;for(j=start;j<=end;++j,++q)tmp[q]=s[j];
                tmp[q]='\0';
                a[1]=atoi(tmp);
            }
            else
            {
                start=i?pos[i-1]:5;
                end=pos[i]-1;
                q=0;for(j=start;j<=end;++j,++q)tmp[q]=s[j];
                tmp[q]='\0';
                a[0]=atoi(tmp);
            }
        }
        char ans[41][41];
        for(i=0;i<41;++i)
        {
            for(j=0;j<41;++j)
            {
                if(i==20)
                {
                    if(j!=20&&j!=40)ans[i][j]='-';
                    else if(j==20)ans[i][j]='+';
                    else if(j==40)ans[i][j]='>';
                }
                else if(i==0)
                {
                    if(j!=20)ans[i][j]='.';
                    else ans[i][j]='^';
                }
                else
                {
                    if(j!=20)ans[i][j]='.';
                    else ans[i][j]='|';
                }
            }
        }
        point b[41];int x,y,cnt2=0,row,col;
        for(i=0;i<41;++i)
        {
            x=i-20;
            y=a[0]+a[1]*x+a[2]*x*x+a[3]*x*x*x;
            if(y>=-20&&y<=20){b[cnt2].x=x;b[cnt2++].y=y;}
        }
        for(i=0;i<cnt2;++i)
        {
            row=-b[i].y+20;
            col=b[i].x+20;
            ans[row][col]='*';
        }
        for(i=0;i<41;++i)
        {
            for(j=0;j<41;++j)printf("%c",ans[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}