#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int space;
    int coword;
}hang;


int stringsplit(char *zong,char sign,char *fen[],int nmax)
{
    int len=strlen(zong),i,co=0;
    fen[co]=zong;
    for(i=0;i<len;i++)
    {
        if(zong[i]==sign)
        {
            zong[i]=0;
            if(strlen(fen[co])>0) co++;
            fen[co]=&zong[i+1];
        }
        if(co>=nmax) break;
    }
    return co+1;
}



int main()
{
    char tt[5];
    int t,i;
    gets(tt);
    t=atoi(tt);
    for(i=0;i<t;i++)
    {
        int m,j,k=0,c,p;
        char mm[5];
        gets(mm);
        m=atoi(mm);
        char s[2010];
        gets(s);
        char *word[2000];
        int sum=stringsplit(s,' ',word,2000);
        printf("case #%d:\n",i);
        /*for(j=0;j<sum;j++)
        {
            printf("word[%d]=%s",j,word[j]);
        }*/
        hang line[400];
        memset(line,0,sizeof(hang)*400);
        int mid=0,l=0;
        for(j=0;j<sum;j++)
        {
            mid+=strlen(word[j]);
            if(mid<m)
            {
                line[l].coword++;
                line[l].space++;
                mid++;
                if(j==sum-1) {line[l].space--;l++;}
            }
            else if(mid==m)
            {
                line[l].coword++;
                mid=0;
                l++;
            }
            else
            {
                mid-=strlen(word[j]);
                line[l].space+=(m-mid);
                j--;
                mid=0;
                l++;
            }
        }
        /*for(j=0;j<l;j++)
        {
            printf("line[%d].coword=%d,line[%d].space=%d\n",j,line[j].coword,j,line[j].space);
        }*/

        int kongge[400][100];
        for(j=0;j<400;j++)
        {
            for(p=0;p<100;p++)
            {
                kongge[j][p]=0;
            }
        }
        for(j=0;j<l;j++)
        {
            if(line[j].coword==1) break;
            int jun=line[j].space/(line[j].coword-1);
            for(p=0;p<line[j].coword-1;p++)
            {
                kongge[j][p]=jun;
            }
            int yu=line[j].space%(line[j].coword-1);
            for(p=line[j].coword-2;yu!=0;p--)
            {
                kongge[j][p]++;
                yu--;
            }

        }
        for(j=0;j<l;j++)
        {
            for(c=0;c<line[j].coword;c++)
            {
                printf("%s",word[k++]);
                for(p=0;p<kongge[j][c];p++)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }


    }

    return 0;
}
