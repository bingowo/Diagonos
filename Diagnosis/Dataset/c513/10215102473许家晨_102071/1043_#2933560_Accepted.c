#include <stdio.h>
#include <string.h>
void insert(char *s,char c,int index)
{
    int len=strlen(s);
    memmove(s+index+1,s+index,len-index+1);
    *(s+index)=c;
}
int del(char *s)
{
    int ret=0;
    int isSame=0,iscom=1,lens;
    char *pa=s;
    char *pb=pa+1;
    char *pend=NULL,*pstart=NULL;
    while(1)
    {
        lens=strlen(s);
        pend =s+lens;
        pstart=s;
        if(*pa==*pb)isSame=1;
        else isSame=0;
        if(isSame)pb++;
        else
        {
            if(pb-pa>1)
            {
                ret+=(pb-pa);
                memmove(pa,pb,pend-pb+1);
                iscom=0;
                if(*pstart=='\0')break; 
                else if(*pa=='\0')
                {
                    pa-=1;
                    pb=pa+1;
                    continue;
                }
                else
                {
                    pb=pa+1;
                    continue;
                }
            }
        	if(*pb=='\0'){
        		if(!iscom){
        			pa=s;
        			pb=pa+1;
        			iscom=1;
				}
				else break;
				
			}
			else{
				pb+=1,pa+=1;//往后推 
			}
		}
        
    }
    return ret;
}int main()
{
	int T,cnt=0;
	scanf("%d", &T);
	while(T)
	{
		char s[102], temp[102];
		scanf("%s", s);
		strcpy(temp, s);
		int max = 0, len = strlen(s), num;
		for(int i = 0 ; i <= len; i ++)
		{
			for(int k = 0 ; k < 3; k ++)
			{
				strcpy(temp, s);
				insert(temp, 'A' + k, i);
				num = del(temp);
				if(num > max)
				{
					max = num;
				}
			}
		}
		printf("case #%d:\n%d\n", cnt++, max);
		T--;
	}

	return 0;
}