//allows the user to select his/her gender and then returns the gender
char return_gender()
{
char gender;
setlinestyle(SOLID_LINE,0,3);
 setcolor(RED);
 rectangle(10,10,630,470);
dis_img("images\\mnf",50,50);
setcolor(RED);
setlinestyle(0,0,3);
rectangle(52,54,600,440);
line(340,54,340,440);
	movemouseptr(0,0);
	showmouse();
       changecursor(cursorhc);

       //Hovering
       while(1)
	{
	getmousepos(&button, &x, &y );
       if( (x>=52 && y>=54 && x<=340 && y<=440) ||  (x>=340 && y>=54 && x<=600 && y<=440))
	 {changecursor(cursorhand);}
       else
	 {changecursor(cursorhc);}
       if( x>=52 && y>=54 && x<=340 && y<=440 )
	 {setcolor(GREEN);
	 setlinestyle(0,0,3);
	rectangle(52+3,54+3,340-3,440-3);


	}
       else
	  {setcolor(WHITE);
	 setlinestyle(0,0,3);
	rectangle(52+3,54+3,340-3,440-3);


	}
       if(x>=340 && y>=54 && x<=600 && y<=440)
	{setcolor(GREEN);
	setlinestyle(0,0,3);
	rectangle(340+3,54+3,600-3,440-3);
	}
       else
	{setcolor(WHITE);
	setlinestyle(0,0,3);
	rectangle(340+3,54+3,600-3,440-3);
	}
	showmouse();


	 if( button & 1 == 1 )
	 {
	 if(x>=52 && y>=54 && x<=340 && y<=440 )
		gender='F';
	 if(x>=340 && y>=54 && x<=600 && y<=440)
		gender='M';
	  return gender;
	  }
	}
}