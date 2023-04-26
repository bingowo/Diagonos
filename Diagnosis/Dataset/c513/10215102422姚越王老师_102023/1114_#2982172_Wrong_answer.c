#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
typedef struct{int first,second;} f;
int main()
{
    char s[1010]={'\0'},tmp[1010]={'\0'};
    f fa[100],fc[100];
    int cnta=0,cntc=0,i,j,q,a=0,b=0,c=0;
    scanf("%s",s);
    for(i=0;s[i];++i)
    {
        if(s[i]=='^')
        {
            int start=0,end=i-2;
            if(end==-1)a=1;
            else
            {
                for(j=start,q=0;j<=end;++j,++q)tmp[q]=s[j];
                tmp[q]='\0';
                if(!strcmp(tmp,"-"))a=-1;
                else a=atoi(tmp);
            }
            i++;
        }
        if((s[i]=='+'||s[i]=='-')&&i)
        {
            if(strchr(s+i+1,'x'))
            {
                int start=i,end=i;while(s[end]!='x')end++;
                for(j=start,q=0;j<end;++j,++q)tmp[q]=s[j];
                tmp[q]='\0';
                if(!strcmp(tmp,"+"))b=1;
                else if(!strcmp(tmp,"-"))b=-1;
                else b=atoi(tmp);
                start=end+1;if(!s[start])break;
                end=start;while(s[end])end++;
                for(j=start,q=0;j<end;++j,++q)tmp[q]=s[j];
                tmp[q]='\0';
                c=atoi(tmp);
                break;
            }
            else
            {
                int start=i,end=i;while(s[end])end++;
                for(j=start,q=0;j<end;++j,++q)tmp[q]=s[j];
                tmp[q]='\0';
                c=atoi(tmp);
                break;
            }
        }
    }
    for(i=1;i<=(int)sqrt(a)+1;++i)
    {
		if(!(a%i))
		{
			fa[cnta].first=i;
			fa[cnta++].second=a/i;
			fa[cnta].first=a/i;
			fa[cnta++].second=i;
		}        
	}
	if(c>0)
    {
        i=(int)(-sqrt(c)-1);
        for(i;i<=sqrt(c)+1;++i)
        {
			if(!i)continue;
			if(!(c%i))
			{
				fc[cntc].first=i;
				fc[cntc++].second=c/i;
				fc[cntc].first=c/i;
				fc[cntc++].second=i;
			}  
		}
    }
    else if(c<0)
    {
        i=(int)(-sqrt(-c)-1);
        for(i;i<=sqrt(-c)+1;++i)
        {
			if(!i)continue;
			if(!(c%i))
			{
				fc[cntc].first=i;
				fc[cntc++].second=c/i;
				fc[cntc].first=c/i;
				fc[cntc++].second=i;
			}
		}	
    }
    if(!c)
    {
        printf("1 0 %d %d",a,b);
        return 0;
    }
    else
    {
        for(i=0;i<cnta;++i)
        {
            for(j=0;j<cntc;++j)
            {
                if(fa[i].first*fc[j].second+fa[i].second*fc[j].first==b)
                {
                    if(fa[i].first<fa[i].second)
                    {
                        printf("%d %d %d %d",fa[i].first,fc[j].first,fa[i].second,fc[j].second);
                        return 0;
                    }
                    else if(fa[i].first>fa[i].second)
                    {
                        printf("%d %d %d %d",fa[i].second,fc[j].second,fa[i].first,fc[j].first);
                        return 0;
                    }
                    else
                    {
                        if(fc[j].first<=fc[j].second)
                        {
                            printf("%d %d %d %d",fa[i].first,fc[j].first,fa[i].second,fc[j].second);
                            return 0;
                        }
                        else
                        {
                            printf("%d %d %d %d",fa[i].second,fc[j].second,fa[i].first,fc[j].first);
                            return 0;
                        }
                    }
                }
            }
        }
        printf("No Answer!");
        return 0;
    }
}