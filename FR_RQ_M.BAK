
//allows to switch between the received friend request and sending a friend request
int return_friend_request_option()
{
int option=0;
setcolor(WHITE);
circle(160,240,54);
circle(480,240,54);
outtextxy(150,230,"SEE");
outtextxy(130,250,"RECEIVED");
outtextxy(460,250,"SEND");

restrictmouse(0,0,640,480);
movemouseptr(0,0);
showmouse();
changecursor(cursorhc);
int button,x,y;

while(1)
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
	  break;}
	  //send
	  if(x>=426 && x<=534 && y>=186 && y<=294)
	   {option=2;
	   break;}
	}


 }//while
 return option;
}