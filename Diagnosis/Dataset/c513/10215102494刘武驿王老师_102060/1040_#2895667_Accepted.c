#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(void *a,void *b)
{
    return strcmp((char *)a,(char *)b);
}
int main()
{
    char blo[3][3];
    scanf("%s %s %s",blo[0],blo[1],blo[2]);
    int gen[3][2],flag;
    for(int i=0;i<3;i++)
    {
        if(blo[i][0]!='?')
        {
            if(strcmp(blo[i],"A")==0)
            {
                gen[i][0]=2;
                gen[i][1]=1;
                continue;
            }
            if(strcmp(blo[i],"AB")==0)
            {
                gen[i][0]=2;
                gen[i][1]=3;
                continue;
            }
            if(strcmp(blo[i],"B")==0)
            {
                gen[i][0]=3;
                gen[i][1]=1;
                continue;
            }
            if(strcmp(blo[i],"O")==0)
            {
                gen[i][0]=1;
                gen[i][1]=1;
                continue;
            }
        }
        flag=i;
    }
    if(flag==2)
    {
        char res[20][3];
        int count=0,posi;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                posi=gen[0][i]*gen[1][j];
                if(posi==1)
                {
                    res[count][0]='O';
                    res[count][1]='\0';
                    count++;
                }
                else if(posi==2)
                {
                    res[count][0]='A';
                    res[count][1]='\0';
                    count++;
                }
                else if(posi==3)
                {
                    res[count][0]='B';
                    res[count][1]='\0';
                    count++;
                }
                else if(posi==4)
                {
                    res[count][0]='A';
                    res[count][1]='\0';
                    count++;
                }
                else if(posi==6)
                {
                    res[count][0]='A';
                    res[count][1]='B';
                    res[count][2]='\0';
                    count++;
                }
                else if(posi==9)
                {
                    res[count][0]='B';
                    res[count][1]='\0';
                    count++;
                }
            }
        }
        qsort(res,count,sizeof(res[0]),cmp);
        printf("%s %s ",blo[0],blo[1]);
        printf("{");
        for(int i=0;i<count-1;i++)
        {
            if(strcmp(res[i],res[i+1])!=0) printf("%s,",res[i]);
        }
        printf("%s}",res[count-1]);
        return 0;
    }
    else
    {
        int p=(flag+1)%2,count=0,peizi[4],poss=0,posi;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++) if(gen[2][j]==gen[p][i]) peizi[count++]=gen[2][(j+1)%2];
        }
        if(count==0)
        {
            for(int i=0;i<2;i++)
            {
                if(i==flag) printf("impossible ");
                else printf("%s ",blo[i]);
            }
            printf("%s",blo[2]);
            return 0;
        }
        char res[20][3];
        for(int i=0;i<count;i++)
        {
            posi=peizi[i];
            if(posi==1)
            {
                res[poss][0]='A';
                res[poss][1]='\0';
                res[poss+1][0]='O';
                res[poss+1][1]='\0';
                res[poss+2][0]='B';
                res[poss+2][1]='\0';
                poss+=3;
            }
            if(posi==2)
            {
                res[poss][0]='A';
                res[poss][1]='\0';
                res[poss+1][0]='A';
                res[poss+1][1]='B';
                res[poss+1][2]='\0';
                poss+=2;
            }
            if(posi==3)
            {
                res[poss][0]='B';
                res[poss][1]='\0';
                res[poss+1][0]='A';
                res[poss+1][1]='B';
                res[poss+1][2]='\0';
                poss+=2;
            }
        }
        if(blo[p][0]!='O'&&blo[2][0]!='O')
        {
            res[poss][0]='A';
            res[poss][1]='B';
            res[poss][2]='\0';
            poss++;
        }
        qsort(res,poss,sizeof(res[0]),cmp);
        for(int i=0;i<2;i++)
        {
            if(i==flag)
            {
                printf("{");
                for(int j=0;j<poss-1;j++)
                {
                    if(strcmp(res[j],res[j+1])!=0) printf("%s,",res[j]);
                }
                printf("%s} ",res[poss-1]);
            }
            else printf("%s ",blo[i]);
        }
        printf("%s",blo[2]);
    }
}
