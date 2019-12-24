
//function to give the effect of loading...
void loading(int op)
{
int maxx=getmaxx();
int maxy=getmaxy();
switch(op)
 {
  case 1:
	   setcolor(RED);
	   for(int i=0; i <= 600 ; i++)
	      {cleardevice();
	       for( int r=32; r <= 35; r++)
		  arc(maxx/2, maxy/2, i, i+300, r);
	      }
	 break;
  case 2:{
	setcolor(RED);
	int count=0;
	delay(2000);
	int j=775;
	int k=90;

	settextstyle(SMALL_FONT,HORIZ_DIR,10);
	outtextxy(225,320,"LOADING");

	for(int i=90;i<=1890;i++)
	{
	setcolor(RED);
	arc(300,300,i,i+225,10);
	if(count%3==0)
	if(j>=90)
	{setcolor(BLUE);
	arc(300,300,j,j-225,12);
	}
	if(count%4==0)
	{setcolor(RED);
	arc(300,300,k+225,k,14);
	}
	delay(10);
	count++;
	setcolor(BLACK);
	arc(300,300,i,i+225,10);
	if(count%3==0)
	{
	arc(300,300,j,j-222,12);
	j--;
	}


	if(count%4==0)
	{arc(300,300,k+225,k,14);
	k++;
	 }
	}
	arc(300,300,j,j-222,12);
	arc(300,300,k+225,k,14);
	break;
	}
 }//switch
}//loading function
