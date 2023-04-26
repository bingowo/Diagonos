#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    int i=0,j=0;
    char a,b;
    int c; 
    char line[20];
    struct troop
    {
        int score;
        char win;
        char fail;
    };
    while(scanf("%d %d\n",&n,&m))
    {
    	struct troop T[128]={0};
        for(i=0;i<m;i++)
        {
            scanf("%c %c %d",&a,&b,&c);
            switch(c)
            {
            case 1:
                T[a].score+=3;
                T[a].win+=1;
                T[b].score-=1;
                T[b].fail+=1;
                break;
            case -1:
                T[a].score-=1;
                T[a].fail+=1;
                T[b].score+=3;
                T[b].win+=1;
                break;
            case 0:
                T[a].score+=1;
                T[b].score+=1;
            }
        }
        for(i='1';i<'1'+n-1;i++)
        {
            if(T[i].score>T[i+1].score)
            {
                line[j++]=i;
                line[j]=i+1;
            }
            else if(T[i].score<T[i+1].score)
            {
                line[j++]=i+1;
                line[j]=i;
            }
            else
            {
                if(T[i].win>T[i+1].win)
                {
                    line[j++]=i;
                    line[++j]=i+1;
                }
                else if(T[i].win<T[i+1].win)
                {
                    line[j++]=i+1;
                    line[++j]=i;
                }
                else
                {
                    if(T[i].fail<T[i].fail)
                    {
                        line[j++]=i;
                        line[++j]=i+1;
                    }
                    else if(T[i].fail>T[i].fail)
                    {
                        line[j++]=i+1;
                        line[++j]=i;
                    }
                    else
                    {
                        line[j++]=i;
                        line[++j]=i+1;
                    }
                }
            }
        }

        for(i=0;i<n;i++)
        {
        	printf("%c ",line[i]);
		}
		printf("\n");
    }
    return 0;
}