#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "function.h"
#include "code_top.h"
#define array 81
#define size_x 9
#define size_y 9
int main( int argc, char *argv[1])
{

   if (argc==3)
   {

   /* create clientData with default information */

   int game_run ;
   int game_over ;

   struct Square ALL_SQ[81] ;  //�w�q�j�p
   struct ranking name = {100,0};//�p���W�٩w�q
   struct ranking score = {0,100};//�p�����Ʃw�q
   int check[81] ={} ;        //9*9�ˬd�x�}��
   int x ,ch_good=0, get_good=0;//�������ƥ��ܼ�
   double AX=0,AY=0,BX=0,BY=0;  //�x�g�洫���ܼ�

   game_run=atoi(argv[1]);
   game_over=atoi(argv[2]);

   Random_SQ(ALL_SQ,array);     //�p�Ƶ{������
 //  printf_array(check);
   SQ_F_clear(ALL_SQ ,check, size_x,size_y); //�p�Ƶ{������

   printf("*************************�йC������***************************\n");
   printf("**********�z��J���^�X��%d*************************************\n",game_run);
   printf("**********�z��J���L�����Ƭ�%d***********************************\n",game_over);
   printf("**************************************************************\n");
   printf("********�W�h�@---> �C���ʤ@�B�Y����@�^�X*********************\n");
   printf("********�W�h�G---> �C�R��3��۾F�@�i�o�h300��*****************\n");
   printf("********�W�h�T---> �C����6�^�X�ᵲ��**************************\n");
   printf("********�W�h�|---> ����k(x0~x8)*******************************\n");
   printf("********�W�h��---> �W��U(y0~y8)*******************************\n");
   printf("**************************************************************\n");
    printf("Git_0107_Demo_HW");


   system("pause");  //�Ȱ�
   system("CLS");     //�M������
   printf_fftto();   //�ʵe
   system("CLS");    //�M������



   for(int i=0;i<game_run;i++)        //�C���}�l�^�X
   {

   printf("******************��%d�^�X�}�l***********************\n",i+1);
   Print_SQ(ALL_SQ);
   printf("*****************************************************\n");
   printf("******************�ثe���Ƭ� %4d********************\n",get_good);
   printf("*****************************************************\n");
   coordinate(AX,AY,BX,BY,ALL_SQ);
   printf("******************�N��3��󴫦�m***********************\n");
   Delay(3);
   system("CLS");
  // Print_SQ(ALL_SQ);
   //printf("******************�T�{�O�_����***********************\n");

   ch_good =three_poinit(ALL_SQ ,check, size_x,size_y);
   if(ch_good==0)
   {
     printf("******************�S����***********************\n");
   }
   else
   {
    get_good=get_good+ch_good;
   }
   }
     /*---------------------------------*/


   if(get_good>game_over)
   {

       printf("********************�L��***************************\n");
       ranking(name.name,score.score,get_good); //�p��
   }
   else
   {
          printf("***********************�S�L��*********************************\n");
       ranking(name.name,score.score,get_good); //�p��

   }





   }
/************************************/
   else
   {

        printf("******�п�J���T�Ѽ� argv[1]���C���̦h�઱ N �B�Aargv[2] ���L�����ơC**********\n");
       system("pause");  //�Ȱ�
   }



} /* end main */

