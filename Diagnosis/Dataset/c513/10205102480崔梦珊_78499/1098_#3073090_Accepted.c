#include<stdio.h>
#include<string.h>

void f(char* s,int* flag,int* num,int r,int b,int y,int g)
{
    int len=strlen(s);
    for(int i=0;i<=len-4;i++)
    {
        if(num[i]==3)
        {
            if(s[i]=='!')
            {
                char temp='R'+'B'+'Y'+'G'-s[i+1]-s[i+2]-s[i+3];
                /*printf("***********%c\n",temp);*/
                s[i]=temp;
                if(temp=='R') r++;
                if(temp=='B') b++;
                if(temp=='Y') y++;
                if(temp=='G') g++;
                continue;
            }
            if(s[i+1]=='!')
            {
                char temp='R'+'B'+'Y'+'G'-s[i]-s[i+2]-s[i+3];
                /*printf("***********%c\n",temp);*/
                s[i+1]=temp;
                if(temp=='R') r++;
                if(temp=='B') b++;
                if(temp=='Y') y++;
                if(temp=='G') g++;
                continue;
            }
            if(s[i+2]=='!')
            {
                char temp='R'+'B'+'Y'+'G'-s[i]-s[i+1]-s[i+3];
                /*printf("***********%c\n",temp);*/
                s[i+2]=temp;
                if(temp=='R') r++;
                if(temp=='B') b++;
                if(temp=='Y') y++;
                if(temp=='G') g++;
                continue;
            }
            if(s[i+3]=='!')
            {
                char temp='R'+'B'+'Y'+'G'-s[i]-s[i+2]-s[i+1];
                /*printf("***********%c\n",temp);*/
                s[i+3]=temp;
                if(temp=='R') r++;
                if(temp=='B') b++;
                if(temp=='Y') y++;
                if(temp=='G') g++;
                continue;
            }
        }
    }
    /*printf("%d %d %d %d\n",r,b,y,g);*/

    for(int k=0;k<len;k++)
    {
        if(s[k]=='!') flag[k]=0;
        else flag[k]=1;
        if(k<=len-4) num[k]=flag[k];
    }
    for(int k=0;k<=len-4;k++)
    {
        num[k]=flag[k]+flag[k+1]+flag[k+2]+flag[k+3];
        /*printf("%d ",num[k]);*/
    }
    /*printf("\n");*/
    int ans=0;
    for(int k=0;k<len;k++)
    {
        ans+=flag[k];
    }
    if(ans!=len) f(s,flag,num,r,b,y,g);
    else
    {
        printf("%d %d %d %d\n",r,b,y,g);
    };
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int r=0,b=0,y=0,g=0;
        char s[101]={0};
        scanf("%s",s);
        int flag[101]={-1};
        int len=strlen(s);
        int num[101]={0};
        for(int k=0;k<len;k++)
        {
            if(s[k]=='!') flag[k]=0;
            else flag[k]=1;
            if(k<=len-4) num[k]=flag[k];
        }
        for(int k=0;k<=len-4;k++)
        {
            num[k]=flag[k]+flag[k+1]+flag[k+2]+flag[k+3];
            /*printf("%d ",num[k]);*/
        }
        printf("case #%d:\n",i);
        f(s,flag,num,r,b,y,g);
        /*printf("%s",s);*/
    }
}
