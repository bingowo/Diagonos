#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SclipT(char t[],char s[],int index,int tlen)
{

    int j = index;
    for(int i = 0;i<tlen;i++)
    {
        t[i] = s[j];
        j++;
    }
    //printf("t = %s\n",t);
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        char s1[90];memset(s1,0,90*sizeof(char));
        char s2[90];memset(s2,0,90*sizeof(char));
        char s[90];memset(s,0,90*sizeof(char));
        scanf("%s%s%s",s1,s2,s);
        int indexL1 = -1,indexR1 = -1;
        int indexL2 = -1,indexR2 = -1;
        int slen = strlen(s),len1 = strlen(s1),len2 = strlen(s2);
        //printf("slen = %d, len1 = %d, len2 = %d\n",slen,len1,len2);
        for(int jL1 = 0;jL1<slen-len1+1;jL1++)//t1 the left
        {
            char t1[len1+1];memset(t1,0,(len1+1)*sizeof(char));
            SclipT(t1,s,jL1,len1);
            //printf("t1 = %s\n",t1);
            if(strcmp(t1,s1)==0)
            {
                indexL1 = jL1+len1-1;
                break;
            }
        }
        for(int jL2 = 0;jL2<slen-len2+1;jL2++)//t2 the left
        {
            //printf("len2 = %d\n",len2);
            char t2[len2+1];memset(t2,0,(len2+1)*sizeof(char));
            SclipT(t2,s,jL2,len2);
            //printf("t2 = %s\n",t2);
            if(strcmp(t2,s2)==0)
            {
                indexL2 = jL2+len2-1;
                break;
            }
        }


        for(int jR1 = slen-len1;jR1>=0;jR1--)
        {
            char t1[len1+1];memset(t1,0,(len1+1)*sizeof(char));
            SclipT(t1,s,jR1,len1);
            if(strcmp(t1,s1)==0)
            {
                indexR1 = jR1;
                break;
            }
        }

        for(int jR2 = slen-len1;jR2>=0;jR2--)
        {
            char t2[len2+1];memset(t2,0,(len1+1)*sizeof(char));
            SclipT(t2,s,jR2,len2);
            if(strcmp(t2,s2)==0)
            {
                indexR2 = jR2;
                break;
            }
        }
        int n1 = indexR2-indexL1-1, n2 = indexR1-indexL2-1;
        int ans = 0;
        if((indexL1<0)||(indexL2<0))
        {
            ans = 0;
        }
        else
        {
            if(n1>n2){ans = n1;}
            else{ans = n2;}
        }
        //printf("indexL1 = %d, indexL2 = %d\n",indexL1,indexL2);
        //printf("indexR1 = %d, indexR2 = %d\n",indexR1,indexR2);
        printf("case #%d:\n",i);
        printf("%d\n",ans);
        //printf("%s\n%s\n%s\n",s1,s2,s);
    }
    return 0;
}

