//controls the login page (draws the graphics,accepts username and password).
void login()
{       char u_name[50], pass[50];
	int username_correct= 0;
	int password_correct=0;
	fstream file ;


	cleardevice();
	setlinestyle(SOLID_LINE,0,3);
	setcolor(RED);
	rectangle(10,10,630,470);
	hidemouse();
	setcolor(13);
	settextstyle(0,0,3);
	outtextxy(250,50,"LOGIN");

	setcolor(WHITE);
	setlinestyle(SOLID_FILL,0,2);
	rectangle(100,205,500,255);
	rectangle(105,210,495,250);

	rectangle(100,300,500,350);
	rectangle(105,305,495,345);

	setcolor(RED);
	settextstyle(0,0,1);
	outtextxy(150,230,"UsErNaMe:");
	outtextxy(150,325,"PaSsWoRd:");
	gotoxy(29,15);
	gets( u_name ) ;

	strcpy(filename,per_filepath);
	strcat(filename,"account.dat");
	file.open( filename, ios :: in | ios ::binary );
	if(file)
	{
	file.read((char*)&person, sizeof(person)) ;
	while(!file.eof() )
	{
		if(person.comp_username(u_name))
		{
			username_correct = 1 ;
			gotoxy(29,21);
			int c=0;
			char ch;
			ch=getch();
			while(ch!='\r')
			{cout<<"*";
			pass[c++]=ch;
			ch=getch();
			if(ch==8)
			 c--;
			}
			pass[c]='\0';

			if(person.comp_password(pass))
			{       cleardevice();
				settextstyle(7,0,3);
				setcolor(GREEN);
				outtextxy(150,200,"ACCESS GRANTED");
				delay(1000);
				password_correct=1;
				cleardevice();
				person.change_presence(1);

				//User current_user(person);
				current_user.assignall(person);

				strcpy(global_name,current_user.name);
				person.return_username();

			}
			else
			{cleardevice();
			settextstyle(7,0,3);
			setcolor(RED);
			outtextxy(100,200,"PASSWORD WRONG!!");
			outtextxy(150,250,"ACCESS DENIED");
			delay(1000);
			login_signup_option();
			}
		}


		file.read((char*)&person, sizeof(person)) ;
	}//while(file.eof)
	}//if(file)
	else
	  {settextstyle(0,0,0);
	  outtextxy(300,240,"File not Found");}
	file.close() ;
	if( username_correct== 0 )
	  {  cleardevice();
	     settextstyle(7,0,3);
	     setcolor(RED);
	     outtextxy(100,200,"USERNAME WRONG!!");
	     outtextxy(150,250,"ACCESS DENIED");
	     delay(1000);
	     login_signup_option();
	  }
	if (username_correct==1 && password_correct==1)
	  {
	  cleardevice();
	  settextstyle(0,0,2);
	  setcolor(WHITE);
	  settextstyle(0,0,3);
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
	  profile2();
	  }

}
