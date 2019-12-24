
//allows the user to edit his city,name and profile picture
void edit_function()
{
hidemouse();
cleardevice();
setlinestyle(SOLID_LINE,0,3);
 setcolor(RED);
 rectangle(10,10,630,470);
int option;
setcolor(GREEN);
setlinestyle(0,0,3);
rectangle(1,1,639,479);
setcolor(YELLOW);
settextstyle(10,0,2);
outtextxy(280,10,"EDIT");
settextstyle(2,0,5);
setcolor(WHITE);
circle(160,120,54);
circle(320,120,54);
circle(480,120,54);
outtextxy(140,110,"CITY");
outtextxy(305,110,"NAME");
outtextxy(446,110,"PROFILE PIC");
  restrictmouse(0,0,640,480);
  movemouseptr(0,0);
  showmouse();
  changecursor(cursorhc);
while(1)
{
   getmousepos(&button, &x, &y );
   if((x>=106 && x<=214 && y>=66 && y<=174) || (x>=266 && x<=374 && y>=66 && y<=174) || (x>=426 && x<=534 && y>=66 && y<=174))
       changecursor(cursorhand);
   else
       changecursor(cursorhc);
   //city
   if(x>=106 && x<=214 && y>=66 && y<=174)
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
   //name
   if(x>=266 && x<=374 && y>=66 && y<=174)
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
   //password
   if(x>=426 && x<=534 && y>=66 && y<=174)
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
    showmouse();
    if( button & 1 == 1 )
	{
	//city
	if(x>=106 && x<=214 && y>=66 && y<=174)//((x-160)*(x-160)+(y-120)*(y-120)-(54*54)) <= 0)
	  {
	   option=1;
	   break;
	   }
	 //name
	  if(x>=266 && x<=374 && y>=66 && y<=174)
	  {option=2;
	  break;}
	  //password
	   if(x>=426 && x<=534 && y>=66 && y<=174)
	   {option=3;
	   break;}
       }
}
switch(option)
{
 case 1:{hidemouse();
	cleardevice();
	setlinestyle(SOLID_LINE,0,3);
	setcolor(RED);
	rectangle(10,10,630,470);
	char city[50];
	setcolor(YELLOW);
	settextstyle(0,0,5);
	outtextxy(230,120,"CITY");
	setcolor(13);
	rectangle(10,210,600,250);
	rectangle(15,215,595,245);
	settextstyle(2,0,5);
	setcolor(RED);
	outtextxy(21,223,"ENTER YOUR CITY:");
	gotoxy(20,15);
	gets(city);
	strcpy(filename,per_filepath);
	strcat(filename,"account.dat");
	file.open(filename,ios::in |ios::out |ios::binary);
	 if(file)
	 {
	  file.read((char*)&person,sizeof(person));
	 while(!file.eof())
	    { if(!strcmpi(person.name,global_name))
	       {current_user.assign_city(city);

	       file.seekp(file.tellg()-sizeof(current_user));
	       file.write((char*)&current_user,sizeof(current_user));

	       }
	    file.read((char*)&person,sizeof(person));

	    }
	 }
	 else
	 cout<<"\n\n data doesn't exists";
	 file.close();
	}
	break;
 case 2:{hidemouse();
	cleardevice();
	setlinestyle(SOLID_LINE,0,3);
	setcolor(RED);
	rectangle(10,10,630,470);
	char name[50];
	setcolor(YELLOW);
	settextstyle(0,0,4);
	outtextxy(230,120,"NAME");
	setcolor(13);
	rectangle(10,210,600,250);
	rectangle(15,215,595,245);
	settextstyle(2,0,5);
	setcolor(RED);
	outtextxy(21,223,"ENTER YOUR NAME:");
	gotoxy(20,15);
	gets(name);

	strcpy(filename,per_filepath);
	strcat(filename,"account.dat");
	file.open(filename,ios::in |ios::out |ios::binary);
	 if(file)
	 {
	  file.read((char*)&person,sizeof(person));
	 while(!file.eof())
	    { if(!strcmpi(person.name,global_name))
	       {strcpy(current_user.name,name);
	       file.seekp(file.tellg()-sizeof(person));
	       file.write((char*)&current_user,sizeof(current_user));
	       strcpy(global_name,name);
	       break;
	       }
	    file.read((char*)&person,sizeof(person));

	    }
	 }
	 else
	 cout<<"\n\n data doesn't exists";
	 file.close();
	}
	break;
 case 3:{
	hidemouse();
	cleardevice();
	setlinestyle(SOLID_LINE,0,3);
	setcolor(RED);
	rectangle(10,10,630,470);
	current_user.assign_profile_pic_char(profile_picture());
	fstream file;
	  strcpy(filename,per_filepath);
	  strcat(filename,"account.dat");
	  file.open( filename, ios :: in |ios::out | ios ::binary );
	  if(file)
	   {
	    file.read((char*)&person, sizeof(person)) ;
	    while(!file.eof() )
	    {if(person.return_userid()==current_user.return_userid())
	     {  file.seekp(file.tellg()-sizeof(current_user));
	       file.write((char*)&current_user,sizeof(current_user));
	     }
	    file.read((char*)&person, sizeof(person)) ;
	    }
	   }
	   else
	   {exit(0);}
	}
	break;
}//switch
profile2();

}
