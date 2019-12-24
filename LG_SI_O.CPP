//allows the user to select between the login amd signup option
int login_signup_option()
{
   cleardevice();
   setlinestyle(SOLID_LINE,0,3);
   setcolor(RED);
   rectangle(10,10,630,470);


   char imagename[50]={"images\\lss"};
   dis_img(imagename,150,200);
   setlinestyle(SOLID_FILL,1,2);
   login_signup_graphics();
   movemouseptr(0,0);
   showmouse();

  while(1)
   {
   getmousepos(&button, &x, &y );
   //Hovering
   if( (x>=200 && x<=300 && y>=200 && y<=250) || (x>=200 && x<=300 && y>=300 && y<=350) ||(x>=600 && x<=630 && y>=10 && y<=30))
    {changecursor(cursorhand);}
    else
    {changecursor(cursorhc);}
   if( x>=200 && x<=300 && y>=200 && y<=250 )
       {
	setcolor(YELLOW);
	outtextxy(250,225,"LoGiN");

	}
   else
       {setcolor(RED);
	outtextxy(250,225,"LoGiN");

	}
   if(x>=200 && x<=300 && y>=300 && y<=350)
       {setcolor(YELLOW);
       outtextxy(250,325,"SiGn Up");
	}
   else
      {   setcolor(RED);
       outtextxy(250,325,"SiGn Up");
	}
   if(x>=600 && x<=630 && y>=10 && y<=30)
      {setcolor(RED);
      outtextxy(300,420,"EXIT");
	}
   else
      {setcolor(BLACK);
      outtextxy(300,420,"EXIT");
	}
    //mouse button pressed
    showmouse();
    if( button & 1 == 1 )
	{
	 if( x>=200 && x<=300 && y>=200 && y<=250 )
	  {hidemouse();
	  cleardevice();
	  // loading(1);
	   option=1;
	   break;
	   }


	 if(x>=200 && x<=300 && y>=300 && y<=350)
	  {hidemouse();
	   cleardevice();
	   //loading(1);
	    option=2;
	    break;
	    }
	 if(x>=600 && x<=640 && y>=10 && y<=30)
	  {hidemouse();
	  int flag=dia_box(1);
	  if(flag==1)
	    {closegraph();
	    exit(0);}
	    else
	     login_signup_option();}
	}//if button pressed

}//while
return option;
}
