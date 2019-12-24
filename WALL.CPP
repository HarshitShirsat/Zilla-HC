
#include <iostream.h>
#include <ctype.h>
#include <fstream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <alloc.h>
#include <process.h>
#include <string.h>
#include <iomanip.h>
const char directory[15]="d:\\proj\\";
int button,x,y;
#include "d:\proj\allmose.cpp"
#include "d:\proj\dis_img.cpp"
#include "d:\proj\cursor.cpp"
#include "d:\proj\dis_img2.cpp"



//#include "d:\proj\user_fun.cpp"
/*#include "d:\proj\drop_dow.cpp"
#include "d:\proj\start.cpp"
#include "d:\proj\dia_box.cpp"
#include "d:\proj\l_sig_gr.cpp"
#include "d:\proj\loadin.cpp"
#include "d:\proj\img_con.cpp"
#include "d:\proj\gender.cpp"
#include "d:\proj\open_lic.cpp"
#include "d:\proj\lg_si_o.cpp"
#include "d:\proj\acc_fr.cpp"
#include "d:\proj\pro_grap.cpp"
#include "d:\proj\fr_rq_m.cpp"
//#include"f:\proj\fri_req.cpp"
#include "d:\proj\abt_pg.cpp"
#include "d:\proj\game.cpp"
#include "d:\proj\signup.cpp"
#include "d:\proj\login.cpp"
#include "d:\proj\pro_pic.cpp"
#include "d:\proj\ext_det.cpp"
#include "d:\proj\bk.cpp"
//#include "d:\proj\mn_chat.cpp"
//#include "h:\proj\friend.cpp"
#include "d:\proj\extraa.cpp"*/
void main()
{
int GD=DETECT,GM;
initgraph(&GD,&GM,"c:\\tc\\bgi");

setcolor(WHITE);
circle(160,240,54);
circle(480,240,54);
setcolor(RED);
settextstyle(0,0,1);
outtextxy(130,250,"POST PIC");
outtextxy(460,250,"POST TEXT");

restrictmouse(0,0,640,480);
movemouseptr(0,0);
showmouse();
changecursor(cursorhc);
start:
int option=1;
/*while(1)
{
   getmousepos(&button, &x, &y );

   if(x>=106 && x<=214 && y>=186 && y<=294 || x>=426 && x<=534 && y>=186 && y<=294)
      changecursor(cursorhand);
   else
     changecursor(cursorhc);
     if(x>=106 && x<=214 && y>=186 && y<=294)// ((x-160)*(x-160))+((y-120)*(y-120))-2916 <= 0)
       {
	setcolor(GREEN);
	circle(160,240,55);
	circle(160,240,56);
	}
    else
       {setcolor(BLACK);
	circle(160,240,55);
	circle(160,240,56);
	}
	if(x>=426 && x<=534 && y>=186 && y<=294)// ((x-160)*(x-160))+((y-120)*(y-120))-2916 <= 0)
       {
	setcolor(GREEN);
	circle(480,240,55);
	circle(480,240,56);
	}
   else
       {setcolor(BLACK);
	circle(480,240,55);
	circle(480,240,56);
	}

	showmouse();
	if( button & 1 == 1 )
	 {
	 //see received
	if(x>=106 && x<=214 && y>=186 && y<=294)
	  {cleardevice();
	  option=1;
	  hidemouse();
	  break;
	  }
	  //send
	  if(x>=426 && x<=534 && y>=186 && y<=294)
	   {option=2;
	   hidemouse();
	   break;}
	}
 }//while
*/
if(option==1)
 {cleardevice();
 setlinestyle(0,0,2);
 setcolor(YELLOW);
 rectangle(50,40,590,440);
 rectangle(55,45,585,435);
 setcolor(RED);
 settextstyle(10,0,2);
 outtextxy(220,50,"POST A PIC");

 setcolor(WHITE);
 settextstyle(3,0,2);
 outtextxy(150,150,"ENTER THE PATH OF THE PIC :");
 settextstyle(3,0,1);
 outtextxy(100,280,"INSTRUCTIONS :");
 settextstyle(2,0,5);
 outtextxy(60,320,"STEP 1:Install java(jdk 6) to your device");
 outtextxy(60,335,"STEP 2:Transfer the image you want to post into the \"c:\" directory ");
 outtextxy(120,350,"(The image should be of PNG,JPG or BPI format)");
 outtextxy(60,365,"STEP 3:Open the ImgtoTxt converter and select the image.");
 outtextxy(60,380,"STEP 4:Save the image by typing a name and then press Enter key");
 outtextxy(60,395,"STEP 5:Right click the image to switch to the 16-bit color format");
 outtextxy(60,410,"STEP 6:Press \'s\'.The converted image gets saved in the current folder.");
 //outtextxy(100,200,"ENTER THE TEXT :");
 setcolor(YELLOW);
 rectangle(100,200,540,260);
 //bar(400,200,640,250);
 gotoxy(15,15);
 char path[100];
 gets(path);
 if(path[0]==27)
  goto start;
 cleardevice();
 fstream file;
 file.open(path,ios::in | ios::binary);
 if(!file)
  {settextstyle(0,0,3);
  outtextxy(200,200,"Image not found.");
  getch();
  goto start;
  }
 file.close();
 setlinestyle(0,0,2);
 setcolor(YELLOW);
 rectangle(50,40,590,440);
 rectangle(55,45,585,435);
 cleardevice();
 int op=dis_img2(path,20,20);
 if(op==1)
   { 	exit(0);
    cleardevice();
    settextstyle(0,0,2);
    setcolor(WHITE);
    outtextxy(100,200,"YOUR IMAGE HAS BEEN POSTED");
    getch();
    strcpy(filename,per_filepath);
    strcat(filename,"temp2.txt");
    fstream file2;
    file2.open(filename.ios::out | ios::binary);
    file2<<current_user.name;
    file2.put(':');
    char temp[100];
    strcpy(temp,current_user.name);
    strcpy(temp," has posted a pic.click to see the pic..");

    fstream file;
    strcpy(filename,per_filepath);
    strcat(filename,"wall.txt");
    file.open(filename,ios::app | ios::binary);
    while(!file.eof())
     {

     }
    file.close();
   }
 else
   {
   goto start;
   }
 }//if option==1


closegraph();
}