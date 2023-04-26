#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char fa[5],ma[5],son[5];
        scanf("%s",fa);
        scanf("%s",ma);
        scanf("%s",son);
        if(strcmp(fa,"?")==0)
        {
            int l1=strlen(ma),l2=strlen(son);int bo=1;
            if(son[l2-1]=='+'&&ma[l1-1]=='-') bo=0;//+
            else bo=1;//+-
            if(ma[0]=='A'&&strlen(ma)==2&&son[0]=='A'&&strlen(son)==2&&bo==0) printf("{A+,AB+,B+,O+} %s %s",ma,son);
            else if(ma[0]=='A'&&strlen(ma)==2&&son[0]=='A'&&strlen(son)==2&&bo==1) printf("{A+,A-,AB+,AB-,B+,B-,O+,O-} %s %s",ma,son);
            else if(ma[0]=='B'&&son[0]=='B'&&bo==0) printf("{A+,AB+,B+,O+} %s %s",ma,son);
            else if(ma[0]=='B'&&son[0]=='B'&&bo==1) printf("{A+,A-,AB+,AB-,B+,B-,O+,O-} %s %s",ma,son);
            else if(ma[0]=='A'&&strlen(ma)==2&&son[0]=='B'&&bo==0) printf("{AB+,B+} %s %s",ma,son);
            else if(ma[0]=='A'&&strlen(ma)==2&&son[0]=='B'&&bo==1) printf("{AB+,AB-,B+,B-} %s %s",ma,son);
            else if(ma[0]=='A'&&strlen(ma)==2&&strlen(son)==3&&bo==0) printf("{AB+,B+} %s %s",ma,son);
            else if(ma[0]=='A'&&strlen(ma)==2&&strlen(son)==3&&bo==1) printf("{AB+,AB-,B+,B-} %s %s",ma,son);
            else if(ma[0]=='A'&&strlen(ma)==2&&son[0]=='O'&&bo==0) printf("{A+,B+,O+} %s %s",ma,son);
            else if(ma[0]=='A'&&strlen(ma)==2&&son[0]=='O'&&bo==1) printf("{A+,A-,B+,B-,O+,O-} %s %s",ma,son);
            else if(ma[0]=='B'&&strlen(son)==3&&bo==0) printf("{A+,AB+} %s %s",ma,son);
            else if(ma[0]=='B'&&strlen(son)==3&&bo==1) printf("{A+,A-,AB+,AB-} %s %s",ma,son);
            else if((ma[0]=='B'||ma[0]=='O')&&son[0]=='O'&&bo==0) printf("{A+,B+,O+} %s %s",ma,son);
            else if((ma[0]=='B'||ma[0]=='O')&&son[0]=='O'&&bo==1) printf("{A+,A-,B+,B-,O+,O-} %s %s",ma,son);
            else if(ma[0]=='A'&&ma[1]=='B'&&strlen(son)==3&&bo==0) printf("{A+,AB+,B+} %s %s",ma,son);
            else if(ma[0]=='A'&&ma[1]=='B'&&strlen(son)==3&&bo==1) printf("{A+,A-,AB+,AB-,B+,B-} %s %s",ma,son);
            else if(ma[0]=='B'&&son[0]=='A'&&strlen(son)==2&&bo==0) printf("{A+,AB+} %s %s",ma,son);
            else if(ma[0]=='B'&&son[0]=='A'&&strlen(son)==2&&bo==1) printf("{A+,A-,AB+,AB-} %s %s",ma,son);
            else if(ma[0]=='O'&&son[0]=='A'&&strlen(son)==2&&bo==0) printf("{A+,AB+} %s %s",ma,son);
            else if(ma[0]=='O'&&son[0]=='A'&&strlen(son)==2&&bo==1) printf("{A+,A-,AB+,AB-} %s %s",ma,son);
            else if(ma[0]=='O'&&son[0]=='B'&&bo==0)printf("{AB+,B+} %s %s",ma,son);
            else if(ma[0]=='O'&&son[0]=='B'&&bo==1)printf("{AB+,AB-,B+,B-} %s %s",ma,son);
            else if(strlen(ma)==3&&son[0]=='A'&&strlen(son)==2&&bo==0) printf("{A+,AB+,B+,O+} %s %s",ma,son);
            else if(strlen(ma)==3&&son[0]=='A'&&strlen(son)==2&&bo==1) printf("{A+,A-,AB+,AB-,B+,B-,O+,O-} %s %s",ma,son);
            else if(strlen(ma)==3&&son[0]=='B'&&bo==0) printf("{A+,AB+,B+,O+} %s %s",ma,son);
            else if(strlen(ma)==3&&son[0]=='B'&&bo==1) printf("{A+,A-,AB+,AB-,B+,B-,O+,O-} %s %s",ma,son);
            else printf("impossible %s %s",ma,son);
        }
        if(strcmp(ma,"?")==0)
        {
            int l1=strlen(fa),l2=strlen(son);int bo=1;
            if(son[l2-1]=='+'&&fa[l1-1]=='-') bo=0;//+
            else bo=1;//+-
            if(fa[0]=='A'&&strlen(fa)==2&&son[0]=='A'&&strlen(son)==2&&bo==0) printf("%s {A+,AB+,B+,O+} %s",fa,son);
            else if(fa[0]=='A'&&strlen(fa)==2&&son[0]=='A'&&strlen(son)==2&&bo==1) printf("%s {A+,A-,AB+,AB-,B+,B-,O+,O-} %s",fa,son);
            else if(fa[0]=='B'&&son[0]=='B'&&bo==0) printf("%s {A+,AB+,B+,O+} %s",fa,son);
            else if(fa[0]=='B'&&son[0]=='B'&&bo==1) printf("%s {A+,A-,AB+,AB-,B+,B-,O+,O-} %s",fa,son);
            else if(fa[0]=='A'&&strlen(fa)==2&&son[0]=='B'&&bo==0) printf("%s {AB+,B+} %s",fa,son);
            else if(fa[0]=='A'&&strlen(fa)==2&&son[0]=='B'&&bo==1) printf("%s {AB+,AB-,B+,B-} %s",fa,son);
            else if(fa[0]=='A'&&strlen(fa)==2&&strlen(son)==3&&bo==0) printf("%s {AB+,B+} %s",fa,son);
            else if(fa[0]=='A'&&strlen(fa)==2&&strlen(son)==3&&bo==1) printf("%s {AB+,AB-,B+,B-} %s",fa,son);
            else if(fa[0]=='A'&&strlen(fa)==2&&son[0]=='O'&&bo==0) printf("%s {A+,B+,O+} %s",fa,son);
            else if(fa[0]=='A'&&strlen(fa)==2&&son[0]=='O'&&bo==1) printf("%s {A+,A-,B+,B-,O+,O-} %s",fa,son);
            else if(fa[0]=='B'&&strlen(son)==3&&bo==0) printf("%s {A+,AB+} %s",fa,son);
            else if(fa[0]=='B'&&strlen(son)==3&&bo==1) printf("%s {A+,A-,AB+,AB-} %s",fa,son);
            else if((fa[0]=='B'||fa[0]=='O')&&son[0]=='O'&&bo==0) printf("%s {A+,B+,O+} %s",fa,son);
            else if((fa[0]=='B'||fa[0]=='O')&&son[0]=='O'&&bo==1) printf("%s {A+,A-,B+,B-,O+,O-} %s",fa,son);
            else if(strlen(fa)==3&&strlen(son)==3&&bo==0) printf("%s {A+,AB+,B+} %s",fa,son);
            else if(strlen(fa)==3&&strlen(son)==3&&bo==1) printf("%s {A+,A-,AB+,AB-,B+,B-} %s",fa,son);
            else if(fa[0]=='B'&&son[0]=='A'&&strlen(son)==2&&bo==0) printf("%s {A+,AB+} %s",fa,son);
            else if(fa[0]=='B'&&son[0]=='A'&&strlen(son)==2&&bo==1) printf("%s {A+,A-,AB+,AB-} %s",fa,son);
            else if(fa[0]=='O'&&son[0]=='A'&&strlen(son)==2&&bo==0) printf("%s {A+,AB+} %s",fa,son);
            else if(fa[0]=='O'&&son[0]=='A'&&strlen(son)==2&&bo==1) printf("%s {A+,A-,AB+,AB-} %s",fa,son);
            else if(fa[0]=='O'&&son[0]=='B'&&bo==0)printf("%s {AB+,B+} %s",fa,son);
            else if(fa[0]=='O'&&son[0]=='B'&&bo==1)printf("%s {AB+,AB-,B+,B-} %s",fa,son);
            else if(strlen(fa)==3&&((son[0]=='A'&&strlen(son)==2)||son[0]=='B')&&bo==0) printf("%s {A+,AB+,B+,O+} %s",fa,son);
            else if(strlen(fa)==3&&((son[0]=='A'&&strlen(son)==2)||son[0]=='B')&&bo==1) printf("%s {A+,A-,AB+,AB-,B+,B-,O+,O-} %s",fa,son);
            else printf("%s impossible %s",fa,son);
        }
        if(strcmp(son,"?")==0)
        {
            int l1=strlen(fa),l2=strlen(ma);int bo=1;
            if(fa[l1-1]=='-'&&ma[l2-1]=='-') bo=1;//-
            else bo=0;//+-
            if(((fa[0]=='A'&&strlen(fa)==2)||strlen(fa)==3||fa[0]=='B')&&strlen(ma)==3&&bo==1) printf("%s %s {A-,AB-,B-}",fa,ma);
            else if(((fa[0]=='A'&&strlen(fa)==2)||strlen(fa)==3||fa[0]=='B')&&strlen(ma)==3&&bo==0) printf("%s %s {A+,A-,AB+,AB-,B+,B-}",fa,ma);
            else if(((ma[0]=='A'&&strlen(ma)==2)||strlen(ma)==3||ma[0]=='B')&&strlen(fa)==3&&bo==1) printf("%s %s {A-,AB-,B-}",fa,ma);
            else if(((ma[0]=='A'&&strlen(ma)==2)||strlen(ma)==3||ma[0]=='B')&&strlen(fa)==3&&bo==0) printf("%s %s {A+,A-,AB+,AB-,B+,B-}",fa,ma);
            else if(((fa[0]=='A'&&strlen(fa)==2)||fa[0]=='O')&&(ma[0]=='A'&&strlen(ma)==2)&&bo==1) printf("%s %s {A-,O-}",fa,ma);
            else if(((fa[0]=='A'&&strlen(fa)==2)||fa[0]=='O')&&(ma[0]=='A'&&strlen(ma)==2)&&bo==0) printf("%s %s {A+,A-,O+,O-}",fa,ma);
            else if(((ma[0]=='A'&&strlen(ma)==2)||ma[0]=='O')&&(fa[0]=='A'&&strlen(fa)==2)&&bo==1) printf("%s %s {A-,O-}",fa,ma);
            else if(((ma[0]=='A'&&strlen(ma)==2)||ma[0]=='O')&&(fa[0]=='A'&&strlen(fa)==2)&&bo==0) printf("%s %s {A+,A-,O+,O-}",fa,ma);
            else if((((fa[0]=='A'&&strlen(fa)==2)&&ma[0]=='B')||(ma[0]=='A'&&fa[0]=='B'))&&bo==1) printf("%s %s {A-,AB-,B-,O-}",fa,ma);
            else if((((fa[0]=='A'&&strlen(fa)==2)&&ma[0]=='B')||(ma[0]=='A'&&fa[0]=='B'))&&bo==0) printf("%s %s {A+,A-,AB+,AB-,B+,B-,O+,O-}",fa,ma);
            else if(fa[0]=='O'&&ma[0]=='O'&&bo==1) printf("%s %s O-",fa,ma);
            else if(fa[0]=='O'&&ma[0]=='O'&&bo==0) printf( "%s %s {O+,O-}",fa,ma);
            else if(fa[0]=='B'&&(ma[0]=='B'||ma[0]=='O')&&bo==1) printf("%s %s {B-,O-}",fa,ma);
            else if(fa[0]=='B'&&(ma[0]=='B'||ma[0]=='O')&&bo==0) printf("%s %s {B+,B-,O+,O-}",fa,ma);
            else if(ma[0]=='B'&&(fa[0]=='B'||fa[0]=='O')&&bo==1) printf("%s %s {B-,O-}",fa,ma);
            else if(ma[0]=='B'&&(fa[0]=='B'||fa[0]=='O')&&bo==0) printf("%s %s {B+,B-,O+,O-}",fa,ma);
            else if(((fa[0]=='O'&&strlen(ma)==3)||(ma[0]=='O'&&strlen(fa)==3))&&bo==1) printf("%s %s {A-,B-}",fa,ma);
            else if(((fa[0]=='O'&&strlen(ma)==3)||(ma[0]=='O'&&strlen(fa)==3))&&bo==0) printf("%s %s {A+,A-,B+,B-}",fa,ma);
            else printf("%s %s impossible",fa,ma);
        }
        printf("\n");
    }

    return 0;
}
