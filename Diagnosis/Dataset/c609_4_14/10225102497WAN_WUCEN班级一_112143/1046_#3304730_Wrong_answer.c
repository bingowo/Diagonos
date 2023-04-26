#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char String[102],SST[101]={0};//SST refers to SimplifiedStringTable which copy String and erase repetitive characters.
    short (*TCT)[101],differ=0,k=0,kk=0;//TCT refers to TimesCountTable.
    int TT=0;//TT refers to the shortest TransformationTimes
    int n=0;
    scanf("%d",&n);
    getchar();
    TCT=(short(*)[101])malloc(n*sizeof(short[101]));
    for(int i=0;i<n;i++)
        memset(*(TCT+i),0,sizeof(*(TCT+i)));
    fgets(String,101,stdin);
    String[strlen(String)-1]='\0';
    k=-1;
    for(short j=0;String[j];j++)
    {
        if(String[j]!=SST[k])
        {
            SST[++k]=String[j];
            (*TCT)[k]++;
        }
        else
            (*TCT)[k]++;
    }
    kk=k;
    for(int i=1;i<n;i++)
    {
        fgets(String,101,stdin);
        String[strlen(String)-1]='\0';
        k=-1;
        char tempc=0;
        for(short j=0;String[j];j++)
        {
            if(String[j]==tempc)
            {
                (*(TCT+i))[k]++;
                continue;
            }
            k++;
            if(String[j]==SST[k])
            {
                (*(TCT+i))[k]++;
                tempc=SST[k];
            }
            else
            {
                differ=1;
                break;
            }
        }
        if(k!=kk)
            differ=1;
        if(differ)
        {
            printf("-1\n");
            break;
        }
    }
    if(!differ)
    {
        for(short i=0;i<=kk;i++)
        {
            int sumc=0,Timessum=0,temp=0,test=0;
            short result2=0,result1=0;
            int *TOTC;//TOTC refers to TimesOfTimesCount
            TOTC=(int*)malloc(101*sizeof(int));
            memset(TOTC,0,101*sizeof(int));
            for(int j=0;j<n;j++)
            {
                (*(TOTC+(*(TCT+j))[i]))++;
            }
            for(int j=0;j<100;j++)
            {
                Timessum+=*(TOTC+j);
                if(Timessum)
                {
                    if(n/Timessum>=2)
                        result2=j;
                    else
                    {
                        result1=j;
                        break;
                    }
                }
            }
            for(int j=0;j<=n;j++)
            {
                short abs;
                abs=(result1-j>0)?1:-1;
                temp+=abs*(result1-j)*(*(TOTC+j));
            }
            for(int j=0;j<=n;j++)
            {
                short abs;
                abs=(result2-j>0)?1:-1;
                sumc+=abs*(result2-j)*(*(TOTC+j));
            }
            if(temp<sumc)sumc=temp;
            TT+=sumc;
        }
        printf("%d",TT);
    }
    return 0;
}

