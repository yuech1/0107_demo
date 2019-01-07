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

   struct Square ALL_SQ[81] ;  //定義大小
   struct ranking name = {100,0};//計分名稱定義
   struct ranking score = {0,100};//計分分數定義
   int check[81] ={} ;        //9*9檢查矩陣用
   int x ,ch_good=0, get_good=0;//紀錄分數用變數
   double AX=0,AY=0,BX=0,BY=0;  //矩症交換用變數

   game_run=atoi(argv[1]);
   game_over=atoi(argv[2]);

   Random_SQ(ALL_SQ,array);     //如副程式講解
 //  printf_array(check);
   SQ_F_clear(ALL_SQ ,check, size_x,size_y); //如副程式講解

   printf("*************************請遊戲說明***************************\n");
   printf("**********您輸入的回合為%d*************************************\n",game_run);
   printf("**********您輸入的過關分數為%d***********************************\n",game_over);
   printf("**************************************************************\n");
   printf("********規則一---> 每移動一步即為算一回合*********************\n");
   printf("********規則二---> 每刪除3格相鄰一可得去300分*****************\n");
   printf("********規則三---> 遊戲於6回合後結束**************************\n");
   printf("********規則四---> 左到右(x0~x8)*******************************\n");
   printf("********規則五---> 上到下(y0~y8)*******************************\n");
   printf("**************************************************************\n");
    printf("Git_0107_Demo_HW");


   system("pause");  //暫停
   system("CLS");     //清除版面
   printf_fftto();   //動畫
   system("CLS");    //清除版面



   for(int i=0;i<game_run;i++)        //遊戲開始回合
   {

   printf("******************第%d回合開始***********************\n",i+1);
   Print_SQ(ALL_SQ);
   printf("*****************************************************\n");
   printf("******************目前分數為 %4d********************\n",get_good);
   printf("*****************************************************\n");
   coordinate(AX,AY,BX,BY,ALL_SQ);
   printf("******************將於3秒更換位置***********************\n");
   Delay(3);
   system("CLS");
  // Print_SQ(ALL_SQ);
   //printf("******************確認是否消除***********************\n");

   ch_good =three_poinit(ALL_SQ ,check, size_x,size_y);
   if(ch_good==0)
   {
     printf("******************沒消除***********************\n");
   }
   else
   {
    get_good=get_good+ch_good;
   }
   }
     /*---------------------------------*/


   if(get_good>game_over)
   {

       printf("********************過關***************************\n");
       ranking(name.name,score.score,get_good); //計分
   }
   else
   {
          printf("***********************沒過關*********************************\n");
       ranking(name.name,score.score,get_good); //計分

   }





   }
/************************************/
   else
   {

        printf("******請輸入正確參數 argv[1]為遊戲最多能玩 N 步，argv[2] 為過關分數。**********\n");
       system("pause");  //暫停
   }



} /* end main */

