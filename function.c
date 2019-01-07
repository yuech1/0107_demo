#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define length 15

/*�U�W��q �N�O����*/
void Delay(unsigned int secs)
{
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);
}

/*���9*9�x�}*/
void printf_array(int a[ ])
{

    int i, j;
    for(j=0 ; j<9 ; j++)
    {
        for (i=0; i<9; i++)
        {
            printf("%4d",a[i+j*9]);
        }
        printf("%\n");

    }
}

/*�üƶ�J9*9�x�}*/
void Random_SQ(struct Square k[],int size)
{
    srand(time(NULL));
    int i,a;
    for (i=0; i<size; i++)
    {
        a=(rand()% 4)+1;
        k[i].number = a;
    }
}

/*��ܦۭqstruct 9*9�x�}*/
void Print_SQ(struct Square k[])
{
    int i, j;
    for(j=0 ; j<9 ; j++)
    {
        for (i=0; i<9; i++)
        {
            printf("%4d",k[i+9*j].number);
            printf("Test github");
        }
        printf("%\n");

    }
}


/*��Jstruct 9*9�x�}x�y��*/
void SQ_X(struct Square k[])
{

    int i, j;
    for(j=0 ; j<9 ; j++)
    {
        for (i=0; i<9; i++)
        {
            k[i+9*j].x=i;
        }
    }
}

/*��Jstruct 9*9�x�}y�y��*/
void SQ_Y(struct Square k[])
{

    int i, j;
    for(j=0 ; j<9 ; j++)
    {
        for (i=0; i<9; i++)
        {
            k[i+9*j].x=j;
        }
    }
}

/*��J�N�@�}�l�x�}�M�������b9*9�L3�s*/
void SQ_F_clear(struct Square k[],int a[],int size_x,int size_y)
{

    int i,j,p=0;
    int x=0 ;

    while(p!=81)
    {
        p=0;
        for(j=0; j<size_x; j++)
        {
            for(i=0; i<size_x-2; i++)
            {
                if( k[i+j*(size_x)].number == k[i+j*(size_x)+1].number && k[i+j*(size_x)].number == k[i+j*(size_x)+2].number )
                {
                    a[i+j*(size_x)]=1;
                    a[i+j*(size_x)+1]=1;
                    a[i+j*(size_x)+2]=1;
                }
            }
        }
        for(j=0; j<size_y; j++)
        {
            for(i=0; i<size_y*6+1; i=i+size_y)
            {
                if( k[i+j].number == k[i+j+size_y].number && k[i+j].number == k[i+j+2*size_y].number )
                {
                    a[i+j]=1;
                    a[i+j+size_y]=1;
                    a[i+j+2*size_y]=1;
                }
            }
        }

        for(j=0; j<size_x; j++)
        {
            for(i=0; i<size_x; i++)
            {
                if (a[i+j*(size_x)] ==1)
                {
                    k[i+j*(size_x)].number=(rand()% 4)+1;
                    a[i+j*(size_x)]=0;
                }
                else
                {
                    p=p+1;
                }
            }
        }
    }
}


/*��J�y�Шç�*/
void coordinate(double AX,double AY, double BX, double BY, struct Square k[])
{

    double distance =0;
    int a=0,b=0,c=0;


    printf("*******************�п�JA�IX�y��******************************\n");
    scanf("%lf",&AX);
    printf("*******************�п�JA�IY�y��******************************\n");
    scanf("%lf",&AY);
    printf("*******************�п�JB�IX�y��******************************\n");
    scanf("%lf",&BX);
    printf("*******************�п�JB�IY�y��******************************\n");
    scanf("%lf",&BY);

    distance = sqrt(pow(AX-BX,2)+pow(AY-BY,2));

    if(distance!=1)
    {
        printf("**********�z��J���y�ШS�۾F�ЦA��J�@��***********************\n");
        printf("*******************�п�JA�IX�y��******************************\n");
        scanf("%lf",&AX);
        printf("*******************�п�JA�IY�y��******************************\n");
        scanf("%lf",&AY);
        printf("*******************�п�JB�IX�y��******************************\n");
        scanf("%lf",&BX);
        printf("*******************�п�JB�IY�y��******************************\n");
        scanf("%lf",&BY);

    }
    else
    {
        /*p=k[AX+9*AY].number;
        k[AX+9*AY].number = k[BX+9*BY].number;
        k[BX+9*BY].number = p;
        */

        a=AX+9*AY;
        b=BX+9*BY;
        c=k[a].number;
        k[a].number = k[b].number;
        k[b].number = c;

    }



}

/*3�s����*/
int three_poinit(struct Square k[],int a[],int size_x,int size_y )
{
    int i,j,p=0, good=0;
    int x=0 ;

    while(p!=81)
    {
        p=0;
        for(j=0; j<size_x; j++)
        {
            for(i=0; i<size_x-2; i++)
            {
                if( k[i+j*(size_x)].number == k[i+j*(size_x)+1].number && k[i+j*(size_x)].number == k[i+j*(size_x)+2].number )
                {
                    a[i+j*(size_x)]=1;
                    a[i+j*(size_x)+1]=1;
                    a[i+j*(size_x)+2]=1;
                }
            }
        }
        for(j=0; j<size_y; j++)
        {
            for(i=0; i<size_y*6+1; i=i+size_y)
            {
                if( k[i+j].number == k[i+j+size_y].number && k[i+j].number == k[i+j+2*size_y].number )
                {
                    a[i+j]=1;
                    a[i+j+size_y]=1;
                    a[i+j+2*size_y]=1;
                }
            }
        }

        for(j=0; j<size_x; j++)
        {
            for(i=0; i<size_x; i++)
            {
                if (a[i+j*(size_x)] ==1)
                {
                    k[i+j*(size_x)].number=(rand()% 4)+1;
                    a[i+j*(size_x)]=0;
                    good =good+100;
                }
                else
                {
                    p=p+1;
                }
            }
        }
    }
    return good;
}



/*�p��*/
void ranking(char name[100], int score[100],int a)

{
    int len;
    time_t now; // �ܼƫŧi
    time(&now); // ���o�{�b������ɶ�

    FILE *fptr;
    fptr=fopen("ranking.txt","a+");
    if (fptr == NULL)
    {
        printf("can't open the file!!");
        return 0;
    }

    printf("please enter player name:");
    scanf("%s",name);
    fprintf(fptr,"name:%s\t",name);

    score=a;
    printf("score:%d\n",score);
    fprintf(fptr,"score:%d\t",score);



    printf("Date/time: %s\n",ctime(&now)); // �C�L�ɶ�
    fprintf(fptr,"Date/time:%s\n",ctime(&now));


    fclose(fptr);


    fptr=fopen("ranking.txt","r");
    if (fptr == NULL)
    {
        printf("can't open the file!!");
        return 0;
    }
    char c = (char)fgetc(fptr);
    while(c!=EOF)
    {
        printf("%c",c);
        c = (char)fgetc(fptr);
    }
    fclose(fptr);

}


/*�C���}�l�e�ʵe*/
void printf_fftto()
{
    system("CLS");
    printf("***********************************************************\n");
    printf("***********************************************************\n");
    printf("***************                         *******************\n");
    printf("***************    ****************************************\n");
    printf("***************    ****************************************\n");
    printf("***************    ****************************************\n");
    printf("***************    ****************************************\n");
    printf("***************    ****************************************\n");
    printf("***************                         *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("***************                         *******************\n");
    printf("***********************************************************\n");
    printf("***********************************************************\n");
    Delay(1);
    system("CLS");
    printf("***********************************************************\n");
    printf("***********************************************************\n");
    printf("***************    *****************    *******************\n");
    printf("***************    *****************    *******************\n");
    printf("***************    *****************    *******************\n");
    printf("***************    *****************    *******************\n");
    printf("***************    *****************    *******************\n");
    printf("***************    *****************    *******************\n");
    printf("***************                         *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("***********************************************************\n");
    printf("***********************************************************\n");
    Delay(1);
    system("CLS");
    printf("***********************************************************\n");
    printf("***********************************************************\n");
    printf("***************                         *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("***************                         *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("***************                         *******************\n");
    printf("***********************************************************\n");
    printf("***********************************************************\n");
    Delay(1);
    system("CLS");
    printf("***********************************************************\n");
    printf("***********************************************************\n");
    printf("***************                         *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("***************                         *******************\n");
    printf("***************    ****************************************\n");
    printf("***************    ****************************************\n");
    printf("***************    ****************************************\n");
    printf("***************    ****************************************\n");
    printf("***************                         *******************\n");
    printf("***********************************************************\n");
    printf("***********************************************************\n");
    Delay(1);
    system("CLS");
    printf("***********************************************************\n");
    printf("***********************************************************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");;
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("************************************    *******************\n");
    printf("***********************************************************\n");
    printf("***********************************************************\n");
    Delay(1);
    system("CLS");























}













/*
    for(i=0;i<size_x-3;i++)
    {
        if( k[i].number == k[i+1].number && k[i].number == k[i+2].number&& k[i].number == k[i+3].number )
        {
           printf("444");
        }
    }
    for(i=0;i<size_x-4;i++)
    {
        if( k[i].number == k[i+1].number && k[i].number == k[i+2].number&& k[i].number == k[i+3].number&& k[i].number == k[i+4].number )
        {
           printf("555");
        }
    }
    for(i=0;i<size_x-5;i++)
    {
        if( k[i].number == k[i+1].number && k[i].number == k[i+2].number&& k[i].number == k[i+3].number&& k[i].number == k[i+4].number && k[i].number == k[i+4].number)
        {
           printf("666");
        }
    }
    for(i=0;i<size_x-6;i++)
    {
        if( k[i].number == k[i+1].number && k[i].number == k[i+2].number&& k[i].number == k[i+3].number&& k[i].number == k[i+4].number && k[i].number == k[i+4].number&& k[i].number == k[i+5].number)
        {
           printf("7777");
        }
    }
    for(i=0;i<size_x-7;i++)
    {
        if( k[i].number == k[i+1].number && k[i].number == k[i+2].number&& k[i].number == k[i+3].number&& k[i].number == k[i+4].number && k[i].number == k[i+4].number&& k[i].number == k[i+5].number&& k[i].number == k[i+6].number)
        {
           printf("88888");
        }
    }
     for(i=0;i<size_x-8;i++)
    {
        if( k[i].number == k[i+1].number && k[i].number == k[i+2].number&& k[i].number == k[i+3].number&& k[i].number == k[i+4].number && k[i].number == k[i+4].number&& k[i].number == k[i+5].number&& k[i].number == k[i+6].number&& k[i].number == k[i+7].number)
        {
           printf("99999");
        }
    }

*/



