
//draws a dialog box for several operations and returns the selected result
int dia_box(int option)
{

//1-exit
//2-captcha code incorrect
//3-delete account
cleardevice();
setlinestyle(SOLID_FILL,0,2);

switch(option)
{
 case 1://dis_img("proj\\images\\exit",50,50);
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	pieslice(160,220,0,360,10);
	setcolor(WHITE);
	circle(160,220,11);
	setfillstyle(SOLID_FILL,WHITE);
	line(152,212,166,226);
	line(153,227,167,213);
	setcolor(YELLOW);
	rectangle(120,190,520,290);
	rectangle(130,200,510,280);
	rectangle(170,244,220,260);      //YES
	rectangle(420,244,470,260);      //NO
	settextstyle(0,0,1);
	setcolor(WHITE);
	outtextxy(205,220,"ARE YOU SURE YOU WANT TO EXIT");
	outtextxy(185,249,"YES");
	outtextxy(440,249,"NO");
	movemouseptr(0,0);
	showmouse();
       changecursor(cursorhc);
       //Hovering
       while(!kbhit())
	{
	getmousepos(&button, &x, &y );
	 if( (x>=170 && y>=244 && x<=220 && y<=260) ||  (x>=420 && y>=244 && x<=470 && y<=260))
	       changecursor(cursorhand);
	 else
		changecursor(cursorhc);
       if( x>=170 && y>=244 && x<=220 && y<=260 )
	 {setcolor(RED);
	 outtextxy(185,249,"YES");
	 }
       else
	  {setcolor(WHITE);
	 outtextxy(185,249,"YES");
	 }
       if(x>=420 && y>=244 && x<=470 && y<=260)
	{setcolor(GREEN);
	outtextxy(440,249,"NO");
	}
       else
	{setcolor(WHITE);
	outtextxy(440,249,"NO");
	}
	showmouse();


	 if( button & 1 == 1 )
	 {
	 if(x>=170 && y>=244 && x<=220 && y<=260 )
		return 1;
	 if(x>=420 && y>=244 && x<=470 && y<=260)
		return 0;
	  }
	}
	 break;

case 2: settextstyle(0,0,1);
	setcolor(YELLOW);
	rectangle(120,190,520,290);
	rectangle(130,200,510,280);
	rectangle(170,244,220,260);      //YES
	rectangle(420,244,470,260);      //NO

	setcolor(WHITE);
	outtextxy(205,220,"YOU ARE OUT OF YOUR CHANCES!");
	outtextxy(178,249,"RETRY");
	outtextxy(435,249,"EXIT");
	movemouseptr(0,0);
	showmouse();

       //Hovering
       while(!kbhit())
	{
	getmousepos(&button, &x, &y );
       if( x>=170 && y>=244 && x<=220 && y<=260 )
	 {setcolor(GREEN);
	 outtextxy(178,249,"RETRY");}
       else
	  {setcolor(WHITE);
	 outtextxy(178,249,"RETRY");}
       if(x>=420 && y>=244 && x<=470 && y<=260)
	{setcolor(RED);
	outtextxy(435,249,"EXIT");}
       else
	{setcolor(WHITE);
	outtextxy(435,249,"EXIT");}
	showmouse();


	 if( button & 1 == 1 )
	 {
	 if(x>=170 && y>=244 && x<=220 && y<=260 )
		return 1;
	 if(x>=420 && y>=244 && x<=470 && y<=260)
		return 0;
	  }
	}
	 break;
case 3: settextstyle(0,0,1);
	setcolor(YELLOW);
	rectangle(120,190,520,290);
	rectangle(130,200,510,280);
	rectangle(170,244,220,260);      //YES
	rectangle(420,244,470,260);      //NO

	setcolor(WHITE);
	outtextxy(150,220,"ARE YOU SURE YOU WANT TO DELETE YOUR ACCOUNT");
	outtextxy(185,249,"YES");
	outtextxy(440,249,"NO");
	movemouseptr(0,0);
	showmouse();

       //Hovering
       while(!kbhit())
	{
	getmousepos(&button, &x, &y );
       if( x>=170 && y>=244 && x<=220 && y<=260 )
	 {setcolor(RED);
	 outtextxy(185,249,"YES");}
       else
	  {setcolor(WHITE);
	 outtextxy(185,249,"YES");}
       if(x>=420 && y>=244 && x<=470 && y<=260)
	{setcolor(GREEN);
	outtextxy(440,249,"NO");}
       else
	{setcolor(WHITE);
	outtextxy(440,249,"NO");}
	showmouse();


	 if( button & 1 == 1 )
	 {
	 if(x>=170 && y>=244 && x<=220 && y<=260 )
		return 1;
	 if(x>=420 && y>=244 && x<=470 && y<=260)
		return 0;
	  }
	}
	 break;


}
getch();
return 3;

}