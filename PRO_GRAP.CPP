
//draws the graphics for the user profile
int profile_graphics()
{
int option=0;
cleardevice();
settextstyle(0,0,3);
setcolor(GREEN);
setlinestyle(SOLID_FILL,0,4);
rectangle(1,1,639,479);
setcolor(YELLOW);
outtextxy(230,20,"PROFILE");
setcolor(WHITE);
settextstyle(0,0,1);
rectangle(590,10,630,40);
outtextxy(590,20,"HIST");
settextstyle(0,0,2);
circle(160,120,54);
circle(160,240,54);
circle(160,360,54);

circle(320,120,54);
circle(320,240,54);
circle(320,360,54);

circle(480,120,54);
circle(480,240,54);
circle(480,360,54);
settextstyle(3,0,1);
outtextxy(140,120,"EDIT");
outtextxy(130,250,"DELETE");
outtextxy(130,350,"FRIEND");
outtextxy(120,370,"REQUESTS");

outtextxy(280,120,"GAME ON!");
outtextxy(300,250,"CHAT");
outtextxy(290,360,"FRIENDS");

outtextxy(450,120,"SEARCH");
outtextxy(450,250,"LOGOUT");
outtextxy(460,360,"ME");
restrictmouse(0,0,640,480);
movemouseptr(0,0);
showmouse();
changecursor(cursorhc);
while(1)
{
   getmousepos(&button, &x, &y );

   if((x>=106 && x<=214 && y>=66 && y<=174) || (x>=106 && x<=214 && y>=186 && y<=294) || (x>=106 && x<=214 && y>=306 && y<=414) || (x>=266 && x<=374 && y>=66 && y<=174) || (x>=266 && x<=374 && y>=186 && y<=294) || (x>=266 && x<=374 && y>=306 && y<=414) || (x>=426 && x<=534 && y>=66 && y<=174) || (x>=426 && x<=534 && y>=186 && y<=294) || (x>=426 && x<=534 && y>=306 && y<=414) ||(x>=426 && x<=534 && y>=306 && y<=414))
      changecursor(cursorhand);
   else
     changecursor(cursorhc);
   //edit
   if(x>=106 && x<=214 && y>=66 && y<=174)// ((x-160)*(x-160))+((y-120)*(y-120))-2916 <= 0)
       {
	setcolor(GREEN);
	circle(160,120,55);
	circle(160,120,56);
	}
   else
       {setcolor(BLACK);
	circle(160,120,55);
	circle(160,120,56);
	}
    //delete
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

    //friend request
    if(x>=106 && x<=214 && y>=306 && y<=414)// ((x-160)*(x-160))+((y-120)*(y-120))-2916 <= 0)
       {
	setcolor(GREEN);
	circle(160,360,55);
	circle(160,360,56);
	}

   else
       {setcolor(BLACK);
	circle(160,360,55);
	circle(160,360,56);
	}

    //game on
    if(x>=266 && x<=374 && y>=66 && y<=174)// ((x-160)*(x-160))+((y-120)*(y-120))-2916 <= 0)
       {
	setcolor(GREEN);
	circle(320,120,55);
	circle(320,120,56);
	}
   else
       {setcolor(BLACK);
	circle(320,120,55);
	circle(320,120,56);
	}

    //chat
    if(x>=266 && x<=374 && y>=186 && y<=294)// ((x-160)*(x-160))+((y-120)*(y-120))-2916 <= 0)
       {
	setcolor(GREEN);
	circle(320,240,55);
	circle(320,240,56);
	}
   else
       {setcolor(BLACK);
	circle(320,240,55);
	circle(320,240,56);
	}

    //friend
    if(x>=266 && x<=374 && y>=306 && y<=414)// ((x-160)*(x-160))+((y-120)*(y-120))-2916 <= 0)
       {
	setcolor(GREEN);
	circle(320,360,55);
	circle(320,360,56);
       }
   else
       {setcolor(BLACK);
	circle(320,360,55);
	circle(320,360,56);
	}
    //search
    if(x>=426 && x<=534 && y>=66 && y<=174)// ((x-160)*(x-160))+((y-120)*(y-120))-2916 <= 0)
       {
	setcolor(GREEN);
	circle(480,120,55);
	circle(480,120,56);
	  }
   else
       {setcolor(BLACK);
	circle(480,120,55);
	circle(480,120,56);
	}
    //logout
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
    //me
    if(x>=426 && x<=534 && y>=306 && y<=414)// ((x-160)*(x-160))+((y-120)*(y-120))-2916 <= 0)
       {
	setcolor(GREEN);
	circle(480,360,55);
	circle(480,360,56);
	}
   else
       {setcolor(BLACK);
	circle(480,360,55);
	circle(480,360,56);
       }

   if(x>=590 && x<=630 && y>=10 && y<=40)// ((x-160)*(x-160))+((y-120)*(y-120))-2916 <= 0)
       {
	setcolor(GREEN);
	rectangle(591,11,629,39);
	rectangle(592,12,628,38);
	}
   else
       {setcolor(BLACK);
	rectangle(591,11,629,39);
	rectangle(592,12,628,38);
	}
    //mouse button pressed
    showmouse();
    if( button & 1 == 1 )
	{
	//edit
	if(x>=106 && x<=214 && y>=66 && y<=174)//((x-160)*(x-160)+(y-120)*(y-120)-(54*54)) <= 0)
	  {cleardevice();
	   option=1;
	   }
	//delete
	if(x>=106 && x<=214 && y>=186 && y<=294)
	  {cleardevice();
	  option=4;
	  break;}

	  //friend request
	  if(x>=106 && x<=214 && y>=306 && y<=414)
	  {option=7;
	  break;}

	   //game on
	  if(x>=266 && x<=374 && y>=66 && y<=174)
	  {option=2;
	  break;}

	   //chat
	   if(x>=266 && x<=374 && y>=186 && y<=294)
	   {option=5;
	   break;}

	   //friend
	   if(x>=266 && x<=374 && y>=306 && y<=414)
	   {option=8;
	   break;}

	   //search
	   if(x>=426 && x<=534 && y>=66 && y<=174)
	   {option=3;
	   break;}

	   //logout
	   if(x>=426 && x<=534 && y>=186 && y<=294)
	   {option=6;
	   break;}

	   //about
	   if(x>=426 && x<=534 && y>=306 && y<=414)
	    {option=9;
	    break;}

	   //hist
	    if(x>=590 && x<=630 && y>=10 && y<=40)
	    {option=10;
	    break;}

	} //if button pressed
   if(option>=1 && option<=9)
     break;
 }//while
hidemouse();
return option;

}
