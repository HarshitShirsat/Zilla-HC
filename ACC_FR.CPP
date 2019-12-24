//function which allows the user to either accept or decline the friend request
int accept_friend_request()
{
setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(500,400,600,430);
bar(500,440,600,470);
settextstyle(1,0,1);
setcolor(GREEN);
outtextxy(510,405,"ACCEPT");
setcolor(RED);
outtextxy(510,445,"DECLINE");
restrictmouse(0,0,640,480);
movemouseptr(0,0);
showmouse();
changecursor(cursorhc);
int option=1;
while(1)
{
   getmousepos(&button, &x, &y );

   if((x>=500 && y>=400 && x<=600 && y<=430) || (x>=500 && y>=440 && x<=600 && y<=470))
     { changecursor(cursorhand);  }
   else
     {changecursor(cursorhc);}
   if(x>=500 && y>=400 && x<=600 && y<=430)
   {setlinestyle(0,0,3);
   setcolor(GREEN);
   rectangle(498,398,600,430);
   }
   else
   {
   setlinestyle(0,0,3);
   setcolor(BLACK);
   rectangle(498,398,600,430);
   }
   if(x>=500 && y>=440 && x<=600 && y<=470)
   {
   setlinestyle(0,0,3);
   setcolor(GREEN);
   rectangle(498,438,600,470);
   }
   else
   {setlinestyle(0,0,3);
   setcolor(BLACK);
   rectangle(498,398,600,470);
   }
   showmouse();
   if( button & 1 == 1 )
    {
     if(x>=500 && y>=400 && x<=600 && y<=430)
     {option=1;
     break;}
     if(x>=500 && y>=440 && x<=600 && y<=470)
     {option=2;
     break;}
    }
}
return option;
}
