#include <stdio.h>
#include <string.h>

int main()
{
    char S[100];
    int A[100];
    scanf("%s",S);
    char *p=S;
    int R=0,I=0,O=0,len,jieduan=1,temp,i=0;
    int yushu=0;
    int sign1=1,sign2=1;
    len=strlen(S);
    while(*p)
    {
        if(*p=='+'||*p=='-'||*p=='i')
        {
            jieduan++;
            if(jieduan==2&&p==S)
            {
                sign1=-1;
            }
            if(jieduan==3&&*p=='-'||(jieduan==3&&*p=='i'&&*(p-1)=='-'))
            {
                sign2=-1;
            }
            if(*p=='i'&&(*(p-1)=='+'||*(p-1)=='-'||len==1))
            {
                if(R==0)
                {
                    O=1;
                }
                else
                {
                    I=1;
                }
            }
            p++;
        }
        if(jieduan==1&&*p!='i'&&p<=S+len-1)
        {
            R=R*10+*p-'0';
            p++;
        }
        if(jieduan==2&&*p!='i'&&p<=S+len-1)
        {
            I=I*10+*p-'0';
            p++;
        }
        if(jieduan==3&&*p!='i'&&p<S+len-1)
        {
            O=O*10+*p-'0';
            p++;
        }
    }
    if(R!=0)
    {
        R=R*sign1;
        I=I*sign2;
    }
    else
    {
        R=I*sign1;
        I=O*sign2;
    }
    /*printf("%d%d",R,I);*/
    while(R!=0||I!=0)
    {
        if(R%2==0&&I%2==0||(R%2*I%2)==1||(R%2*I%2)==-1)
            {
                yushu=0;
                A[i]=yushu;
                i++;
            }
        else
            {
                yushu=1;
                A[i]=yushu;
                i++;
            }
        temp=R;
        R=(I-R+yushu)/2;
        I=(temp+I-yushu)/-2;
    }
    i--;
    for(int j=i;j>=0;j--)
    {
        printf("%d",A[j]);
    }


}
