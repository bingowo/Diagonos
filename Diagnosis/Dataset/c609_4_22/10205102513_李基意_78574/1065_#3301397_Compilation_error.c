#include<stdio.h>
#include<stdlib.h>
#include<string.h>

getline(cahr s[],int lim){
    int c,i;
    i=0;
    while(c!='\n' && --lim>0 && (c=getchar()!=EOF))
        s[i++]=c;
    if(c=='\n')
        s[i]='\0';
}

int main()
{   
    int T;
    scanf("%d",&T);
    for(int k=0;k<T;k++){
        char s[101];
        getline(s,101);
        double a[101];
        int count=0;
        for (int i=strlen(s)-1;i>=0;i--)
        {
            if (s[i]>='0'&&s[i]<='9'&&s[i-1]==' ')
                a[count++]=s[i]-'0';
            else if (s[i]>='0'&&s[i]<='9'&&s[i-1]!=' ') 
            {
                char b[10];
                int count2=0,flag=0;
                b[count2++]=s[i--];
                while(s[i]!=' ')
                {
                    if(s[i]=='.')flag=1;
                    b[count2++]=s[i--];
                }
                if(flag)
                {
                    double x=0;
                    int y=0,j,k;
                    for (j=0;b[j]!='.';j++)
                    x=0.1*x+(b[j]-'0')*0.1;
                    for(k=count2-1;k>j;k--)
                        y=y*10+b[k]-'0';
                        a[count++]=y+x;
                }
                else
                {
                    int y=0;
                    for (int k=count2-1;k>=0;k--)
                    {
                    y=y*10+b[k]-'0';
                    }
                    a[count++]=y;
                }
            }
            else if (s[i]==' ')
            {
                a[count-2]=a[count-1];
                count--;
            }
            else if (s[i]=='/')
            {
                a[count-2]=a[count-1]/a[count-2];
                count--;
            }
            else if (s[i]=='+')
            {
                a[count-2]=a[count-1]+a[count-2];
                count--;
            }
            else if (s[i]=='-')
            {
                a[count-2]=a[count-1]-a[count-2];
                count--;
            }
        }
        printf("case #%d:\n%.6f\n",k,a[0]);
        
    }
    return 0;
}