void profile2();
void profile()
{
char gender=return_gender();
strcpy(filename,per_filepath);
strcat(filename,"account.dat");
file.open(filename,ios::in |ios::out |ios::binary);
	 if(file)
	 {
	  file.read((char*)&person,sizeof(person));
	 while(!file.eof())
	    { if(!strcmpi(person.name,global_name))
	       {person.assign_gender(gender);
	       current_user.assignall(person);
	       file.seekp(file.tellg()-sizeof(person));
	       file.write((char*)&person,sizeof(person));

	       }
	    file.read((char*)&person,sizeof(person));

	    }
	 }
	 else
	 cout<<"\n\n data doesn't exists";
	 file.close();
movemouseptr(0,0);
cleardevice();
setcolor(GREEN);
settextstyle(10,0,6);
outtextxy(100,100,"WELCOME");
settextstyle(8,0,4);
outtextxy(250,300,global_name);
setcolor(WHITE);
circle(320,450,10);
putpixel(316,450,WHITE);
putpixel(324,450,WHITE);
putpixel(316,446,WHITE);
putpixel(316,454,WHITE);
putpixel(324,446,WHITE);
putpixel(324,454,WHITE);
putpixel(320,454,WHITE);
putpixel(320,446,WHITE);
putpixel(320,450,WHITE);
initmouse();
restrictmouse(270,400,370,500);
movemouseptr(270,400);
showmouse();
changecursor(cursorhc);

int flag=0;
while(flag==0)
{
   getmousepos(&button, &x, &y );
   if( ((x-320)*(x-320)+(y-450)*(y-450)-100) <= 0)
       {
	setcolor(GREEN);
	circle(320,450,11);
	circle(320,450,12);
	changecursor(cursorhand);
	}
   else
       {setcolor(BLACK);
	circle(320,450,11);
	circle(320,450,12);
	changecursor(cursorhc);
	}
    //mouse button pressed
    showmouse();
    if( button & 1 == 1 )
	{
	 if( ((x-320)*(x-320)+(y-450)*(y-450)-100) <= 0)
	  {cleardevice();
	   hidemouse();
	   flag=1;
	   }
	}
 }//while

profile2();
}
void profile2()
{hidemouse();
int option;
 int flag=10;
do
{
setlinestyle(SOLID_FILL,0,1);
 option=profile_graphics();
movemouseptr(0,0);
cleardevice();
switch(option)
{
  case 1://edit   name city password
	 edit_function();
	 break;
  case 2:// game on
	 /*{int current_highscore=current_user.return_highscore();
	 unsigned int is_it_new_highscore=game(current_highscore);
	 if(is_it_new_highscore==1)
	 {
	 current_user.change_highscore(highscore);
	 fstream file;
	  strcpy(filename,per_filepath);
	  strcat(filename,"account.dat");
	  file.open( filename, ios :: in | ios::out | ios ::binary );
	  if(file)
	   {
	    file.read((char*)&person, sizeof(person)) ;
	    while(!file.eof() )
	    {
	    if(current_user.return_userid()==person.return_userid())
	    { file.seekp(file.tellg()-sizeof(current_user));
	       file.write((char*)&current_user,sizeof(current_user));
	    }
	    file.read((char*)&person, sizeof(person)) ;
	    }
	   }
	   else
	   {exit(0);}
	  }

	   profile2();
	 } */
	 break;

  case 3://search
	 {
	 clrscr();
	 cleardevice();
	    cout<<"\n\n\t\t\t\t ALL USERS\n";
	 cout<<"\n\n\t"<<"USER ID"<<setw(20)<<"NAME\n\n";
	 fstream file;
	 strcpy(filename,per_filepath);
	  strcat(filename,"account.dat");
	  file.open( filename, ios :: in  | ios ::binary );
	  if(file)
	   {
	    file.read((char*)&person, sizeof(person)) ;
	    while(!file.eof() )
	    {
	    person.output();
	    cout<<"\n";
	    file.read((char*)&person, sizeof(person)) ;
	    }
	   }
	   else
	   {exit(0);}
	   cout<<"\n\n\t\tABOUT WHOM(USER ID):";
	    int search_id;
	    cin>>search_id;
	   file.close();
	   strcpy(filename,per_filepath);
	  strcat(filename,"account.dat");
	  file.open( filename, ios :: in | ios ::binary );
	  if(file)
	   {int flagg=0;
	    file.read((char*)&person, sizeof(person)) ;
	    while(flagg==0)
	    {
	    if(search_id==person.return_userid())
	      {clrscr();
	      cleardevice();
	      person.my_details();
	       flagg=1;}
	    file.read((char*)&person, sizeof(person)) ;
	    }
	    if(flagg==0)
	     cout<<"No person with that username";
	   file.close();
	   }
	   else
	   {file.close();
	   exit(0);}
	 cleardevice();
	 }
	 break;
  case 4://delete
	 {char temp_filename[50];
	 flag=dia_box(3);
	 if(flag==1)
	  {  cleardevice();
	     strcpy(filename,per_filepath);
	     strcat(filename,"account.dat");
	     file.open(filename,ios::in |ios::binary);
	     if(file)
	     { int fg=0;
	     file.read((char*)&person,sizeof(person));
	     fstream file2;

		strcpy(temp_filename,per_filepath);
		strcat(temp_filename,"temp.dat");
	     file2.open(temp_filename,ios::out | ios::binary);
	     while(!file.eof())
	      {
	     if(person.comp_username(global_username))
	      fg=1;
	     else
	     {file2.write((char*)&person,sizeof(person));}

	     file.read((char*)&person,sizeof(person));
	      }//while
	     file.close();
	     file2.close();
	     if(fg==1)
	       {
	       settextstyle(7,0,3);
	       setcolor(RED);
	       outtextxy(100,200,"ACCOUNT SUCCESSFULLY DELETED");
	       getch();
	       login_signup_option();
	       }
		strcpy(filename,per_filepath);
		strcat(filename,"account.dat");

		strcpy(temp_filename,per_filepath);
		strcat(temp_filename,"temp.dat");
		remove(filename);
		rename(temp_filename,filename);
	   }
	   else
	    {cout<<"\n\n Data doesn't exist";
	    getch();}


	  }//if flag=1
	 else
	  profile2();
	 break;
	 }
  case 5:chat();
	 break;
  case 6://logout
	 {
	 cleardevice();
	 current_user.change_presence(0);
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
	   int option=login_signup_option();
	     if(option==1)
	      {login();}
	     else if(option==2)
	      {signup();}
	 }
	 break;
  case 7://friend request
	 {
	 int option=return_friend_request_option();
	   if(option==1);
	     //{see_friend_request();}
	    else if(option==2);
	     // {send_friend_request();}

	 }
	 break;
  case 8://friend
	 break;
  case 9://about
	about_page();
	break;
  case 10:current_user.my_details();
	break;

  }//switch
}while(option!=6 || (option!=4 && flag!=1));
}//profile