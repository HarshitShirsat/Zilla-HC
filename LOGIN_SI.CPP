
int x,y,button;

void login_signup_option()
{
   rectangle(200,200,400,250);
   rectangle(205,205,395,245);

   rectangle(200,300,400,350);
   rectangle(205,305,395,345);
   setcolor(RED);
   settextstyle(0,0,2);
   outtextxy(250,225,"LoGiN");
   outtextxy(250,325,"SiGn Up");
   rectangle(600,10,630,30);
   outtextxy(610,13,"X");

while( !kbhit() )
{


   getmousepos(&button, &x, &y );
   //Hovering
   if( x>=200 && x<=300 && y>=200 && y<=250 )
       {
	setcolor(YELLOW);
	outtextxy(250,225,"LoGiN");}
   else
       {setcolor(RED);
	outtextxy(250,225,"LoGiN");}
   if(x>=200 && x<=300 && y>=300 && y<=350)
       {setcolor(YELLOW);
       outtextxy(250,325,"SiGn Up");}
   else
   {   setcolor(RED);
       outtextxy(250,325,"SiGn Up");}
   if(x>=600 && x<=630 && y>=10 && y<=30)
      {setcolor(RED);
      outtextxy(300,420,"EXIT");}
   else
      {setcolor(BLACK);
      outtextxy(300,420,"EXIT");}
    //mouse button pressed
    if( button & 1 == 1 )
	{
	 if( x>=200 && x<=300 && y>=200 && y<=250 )
	  {cleardevice();
	   setcolor(RED);
	   for(int i=0; i <= 600 ; i++)
	      {cleardevice();
	       for( int r=32; r <= 35; r++)
		  arc(maxx/2, maxy/2, i, i+300, r);}
		person.login();
	       }


	 if(x>=200 && x<=300 && y>=300 && y<=350)
	  {cleardevice();
	   setcolor(RED);
	   for(int z=0; z <= 600 ; z++)
	      {cleardevice();
	      for(int r=32; r <= 35; r++)
		 arc(maxx/2, maxy/2, z, z+300, r);    }//i
	   cleardevice();
	    person.signup();
	    }
	 if(x>=600 && x<=640 && y>=10 && y<=30)
	  {exit(0);}
	}//if button pressed

}//while
cleardevice();
}
