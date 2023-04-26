#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX_LENGTH		200
#define MAX_LINE_COUNTS		500

typedef struct {
	char szStr[LINE_MAX_LENGTH];
}LineContent;

int numof(char *s,int pl)
{
    int len=strlen(s),i,co=0;
    for(i=pl-1;i>=0;i--)
    {
        if(s[i]=='\\') {co++;continue;}
        else break;
    }
    return co;
}

int FindStartNote(char *szSource, int *pos)
{
	int nLen = strlen(szSource)-1;
	int i;
	int nQuotation = 0;
	
	for(i=0;i<nLen;i++)
	{
		if( szSource[i]=='\"' )
		{
		    if(i>0)
		    {
		        if(numof(szSource,i)%2==0) nQuotation = 1-nQuotation;
		    }
		    
			else nQuotation = 1-nQuotation;
		}
		else if( !nQuotation )
		{
			if( szSource[i]=='/' )
			{
				if( szSource[i+1]=='/' )
				{
					*pos = i;
					return 1;
				}
				else if( szSource[i+1]=='*' )
				{
					*pos = i;
					return 2;
				}
			}
		}
	}
	
	return 0;
}

int FindEndNote(char *szSource, int *pos, int nFindBegin)
{
	int nLen = strlen(szSource)-1;
	int i;
	
	for(i=nFindBegin;i<nLen;i++)
	{
		if( szSource[i]=='*' && szSource[i+1]=='/' ) 
		{
			*pos = i;
			return 1;
		}
	}
	
	return 0;
}

int main()
{
	LineContent	*pLines;
	int nLineCount;
	
	pLines = (LineContent *)malloc(sizeof(LineContent)*MAX_LINE_COUNTS);
	memset(pLines, 0, sizeof(LineContent)*MAX_LINE_COUNTS);
	nLineCount = 0;
	
	while( 1 )
	{
		if( gets(pLines[nLineCount].szStr)==NULL ) break;
		
		nLineCount++;
		if( nLineCount>=MAX_LINE_COUNTS ) break;
	}
	
	int i, k;
	int nStatus = 0;
	int nNoteLine, nNotePos;
	/*
	for(i=0;i<nLineCount;i++)
	{
		int nPos, nFind;
		 
		switch( nStatus )
		{
			case 0:	//什么也没找到的时候 
				nFind = FindStartNote(pLines[i].szStr, &nPos);
				if( nFind==1 ) 
				{
					
                    pLines[i].szStr[nPos] = 0;
					
				}
				else if( nFind==2 )
				{
					nStatus = 1;	//进入发现了 /* 的状态，并记录发现的 /* 位置 
					nNoteLine = i;
					nNotePos = nPos;
					
					if( FindEndNote(pLines[i].szStr, &nPos, nNotePos+2) )
					{
						// 从nNotePos起，到nPos+2止（不含），删除
						int nLeftChars = strlen(pLines[i].szStr)-(nPos+2);	//计算删除后应该留下的字符个数，也就是要前移的字符个数 
						int nSkipChars = nPos+2-nNotePos;
						
						nLeftChars += nNotePos +1;	//加1是为了把最后的结束符0也前移，这样就不用了主动加结束符了 
						for(k=nNotePos;k<nLeftChars;k++)
							pLines[i].szStr[k] = pLines[i].szStr[k+nSkipChars];
							
						nStatus = 0;	 
						i--;			 
					}
				}
				else
					break;
				
			case 1:
				if( FindEndNote(pLines[i].szStr, &nPos, 0) )
				{
				
					int nLeftChars = strlen(pLines[i].szStr) - (nPos+2);
					
					nLeftChars++;
					for(k=0;k<nLeftChars;k++)
					{
						pLines[i].szStr[k] = pLines[i].szStr[k+nPos+2];
					}
					
					
					nLeftChars = nLineCount-i;	
					nLeftChars += nNoteLine;
					int nSkipLines = i-nNoteLine;	
					for(k=nNoteLine;k<nLeftChars;k++) 
					{
						pLines[k] = pLines[k+nSkipLines];
					}
					nLineCount -= nSkipLines;
					i = nNoteLine-1;	
					nStatus = 0; 
				}
				break;
		}
	}*/

	for(i=130;i<170;i++) 
	{
		printf("%s\n", pLines[i].szStr);
	}
	
}