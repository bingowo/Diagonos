#include<stdio.h>
#include<string.h>

#define False 0
#define True 1

int judge(char a[])
{
    if(strlen(a)==0) return True;
    for(int i=0;i<strlen(a)-1;i++)
    {
        if(a[i]==a[i+1]) return False;
    }
    return True;
}


int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        char in[110]={'\0'},tmp[110]={'\0'},del[110]={'\0'};
        scanf("%s",in);
        int max=0;
        for(int j=0;j<=strlen(in);j++)
        {
            strncpy(tmp,in,j);
            if(j!=strlen(in)) tmp[j]=in[j];
            else tmp[j]=in[j-1];
            for(int i=j;i<strlen(in);i++) tmp[i+1]=in[i];
            strcpy(del,tmp);

            int cnt=0;
            while (judge(del)==False)
            {
                memset(tmp,0,strlen(tmp));
                int index=0;
                for(int i=0;i<strlen(del);i++)
                {
                    if(i==0)
                    {
                        if(del[i]!=del[i+1]) tmp[index++]=del[i];
                    }
                    else if(i==strlen(del)-1)
                    {
                        if(del[i]!=del[i-1]) tmp[index++]=del[i];
                    }
                    else
                    {
                        if(del[i]!=del[i-1] && del[i]!=del[i+1]) tmp[index++]=del[i];
                    }
                }
                cnt+=(strlen(del)-strlen(tmp));
                strcpy(del,tmp);
            }
            if(cnt>max) max=cnt;
        }
        printf("case #%d:\n%d\n",t,max);
    }
    return 0;
}