#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int arr[51];
} MULT;

void zero(char*s)
{
    int i;
    for (i=0;i<20;i++)
        s[i]='\0';
}

MULT* convert(char* s)
{
    MULT* MM=(MULT*)calloc(1,sizeof(MULT));
    int i,j=0,k; char xx[20]={0}, yy[20]={0};
    if (strlen(s)==1)
    {
        if (isdigit(s[0]))
        {
            xx[j]=s[0];
            MM->arr[0]=atoi(xx);
            zero(xx);
        }
        else
        {
            MM->arr[1]=1;
        }

    }
    else
    {
         for (i=0;i<strlen(s);i++)
        {
            if (s[i]=='x')
            {
                if (i>=2)
                {
                    if (s[i-2]=='-')
                    {
                        xx[j++]=s[i-2];
                        xx[j]=s[i-1];
                        j=0;
                        if (s[i+1]=='^')
                        {
                            for (k=2;isdigit(s[i+k]);k++)
                                yy[j++]=s[i+k];
                            j=0;
                            MM->arr[atoi(yy)]=atoi(xx);
                            zero(yy);
                        }
                        else MM->arr[1]=atoi(xx);
                        zero(xx);
                    }
                    else if (s[i-1]=='-' || s[i-1]=='+')
                    {
                        xx[j++]=s[i-1];
                        xx[j]='1';
                        j=0;
                        if (s[i+1]=='^')
                        {
                            yy[j]=s[i+2];
                            j=0;
                            MM->arr[atoi(yy)]=atoi(xx);
                            zero(yy);
                        }
                        else MM->arr[1]=atoi(xx);
                        zero(xx);
                    }
                    else
                    {
                        for (k=1;isdigit(s[i-k]);k++) ;
                        for (j=0;j<k;j++)
                            xx[j]=s[i-k+j];
                        j=0;
                        if (s[i+1]=='^')
                        {
                            for (k=2;isdigit(s[i+k]);k++)
                                yy[j++]=s[i+k];
                            j=0;
                            MM->arr[atoi(yy)]=atoi(xx);
                            zero(yy);
                        }
                        else MM->arr[1]=atoi(xx);
                        zero(xx);
                    }
                }
                else if (i==1)
                {
                    if (s[i-1]=='-')
                    {
                        if (s[i+1]=='^')
                        {
                            xx[j]=s[i+2];
                            j=0;
                            MM->arr[atoi(xx)]=-1;
                            zero(xx);
                        }

                        else MM->arr[1]=1;
                    }
                    else
                    {
                        xx[j]=s[i-1];
                        j=0;
                        if (s[i+1]=='^')
                        {
                            for (k=2;isdigit(s[i+k]);k++)
                                yy[j++]=s[i+k];
                            j=0;
                            MM->arr[atoi(yy)]=atoi(xx);
                            zero(yy);
                        }
                        else MM->arr[1]=atoi(xx);
                        zero(xx);
                    }
                }
                else if (i==0)
                {
                    if (s[i+1]=='^')
                    {
                        yy[j]=s[i+2];
                        j=0;
                        MM->arr[atoi(yy)]=1;
                        zero(yy);
                    }
                    else MM->arr[1]=1;

                }
            }
            if (i==strlen(s)-1)
            {
                if (isdigit(s[i]))
                {
                    if (s[i-1]=='^')
                        break;
                    else if (s[i-1]=='-')
                    {
                        xx[j++]=s[i-1];
                        xx[j]=s[i];
                        j=0;
                        MM->arr[0]=atoi(xx);
                        zero(xx);
                    }
                    else if (s[i-1]=='+')
                    {
                        j=0;
                        xx[j]=s[i];
                        j=0;
                        MM->arr[0]=atoi(xx);
                        zero(xx);

                    }
                }
            }
        }
    }

        return MM;

}



int main()
{

    char s1[120]={0}, s2[120]={0};
    int i,j=0,m,n;
    while (scanf("%s %s",s1,s2)!=EOF)
    {
        MULT* MM=NULL; MULT* NN=NULL;
        MM=convert(s1);
        NN=convert(s2);
        int arr1[121]={0};
//        for (i=0;i<50;i++)
//        {
//            if (MM->arr[i])
//                printf("%d %d\n",i,MM->arr[i]);
//        }
//        for (i=0;i<50;i++)
//        {
//            if (NN->arr[i])
//                printf("%d %d\n",i,NN->arr[i]);
//        }
        for (i=0;i<50;i++)
        {
            if (NN->arr[i])
            {
                for (j=0;j<50;j++)
                {
                    if (MM->arr[j])
                        arr1[i+j]+=NN->arr[i]*MM->arr[j];
                }
            }

        }
        int n=0,m=0;
        for (i=120;i>=0;i--)
        {
            if (arr1[i])
                n++;

        }
        for (i=120;i>=0;i--)
        {
            if (arr1[i])
            {
                m++;
                printf("%d",arr1[i]);
                printf("%c",(m==n)?'\n':' ');
            }

        }


        free(MM);
        free(NN);
    }
    return 0;
}
