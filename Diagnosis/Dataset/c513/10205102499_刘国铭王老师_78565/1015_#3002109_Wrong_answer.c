#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int prime[26]={101,97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,19,17,13,11,7,5,3,2};
int a[26]={0},b[26]={0},c[26]={0};
char s[100];
void add(int *a,int *b,int *c)
{
    int temp2=0;
    for(int i=25;i>=0;i--)
    {
        int d=a[i]+b[i]+temp2;
       c[i]=d%prime[i];
        temp2=d/prime[i];
        //printf("%d %d %d \n",d,c[i],temp);
    }
}

void output()
{
    int flag=25;
    for(int i=0;i<26;i++)
        if(c[i]!=0)
        {
            flag=i;
            break;
        }
    for(int j=flag;j<25;j++)
    {
        printf("%d,",c[j]);
    }
    printf("%d",c[25]);
    printf("\n");
}

void Readnumber(char *s,int *a)
{
    int num=strlen(s);
    int i,j;
    int k=-1;
    int temp=0;
    s[num]=',';
    num++;
    for(i=0;i<num;i++)
    {
        if(s[i]==',')
        {
            k++;
            a[k]=temp;
            temp=0;
            continue;
        }
        temp=temp*10+s[i]-'0';
    }
    int num1=num-1-(num/2);
    for(i=0;i<num1+1;i++)
    {
        int temp1=a[i];
        a[i]=0;
        a[25-num1+i]=temp1;
    }
   /* for(int m=0;m<26;m++)
    {
        printf("%d ",a[m]);
    }
    printf("\n");*/
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        memset(s,0,sizeof(s));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%s",s);
        Readnumber(s,a);
        scanf("%s",s);
        Readnumber(s,b);

        /*char e;
        int j=0,q=0;
        while((e=getchar())!=' ')
        {
            if(e==',')
                continue;
            int temp=0;
            while(e!=',' && e!=' ')
            {
                temp*=10;
                temp+=(e-'0');
            }
            a[j]=temp;
            j++;
        }
        while((e=getchar())!='\n')
        {
            if(e==',')
                continue;
            int temp=0;
            while(e!=',' && e!='\n')
            {
                temp*=10;
                temp+=(e-'0');
            }
            b[q]=temp;
            q++;
        }*/
        add(a,b,c);
        printf("case #%d:\n",i);
        output();
    }
    return 0;
}
