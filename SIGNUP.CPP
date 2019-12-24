//controls the signup page (draws the graphics,accepts username,name and password).
void signup()
{       char name[50];
	char check1[50];
	char ch;
	char u_name[50];
	int c=0;
	settextstyle(0,0,1);
	hidemouse();
	cleardevice();

	setlinestyle(SOLID_LINE,0,3);
	setcolor(RED);
	rectangle(10,10,630,470);
	setlinestyle(SOLID_FILL,0,2);

	setcolor(13);
	settextstyle(0,0,3);
	outtextxy(200,100,"SIGN UP");
	settextstyle(0,0,1);
	setcolor(13);
	rectangle(110,210,500,250);
	rectangle(115,215,495,245);

	rectangle(110,260,500,300);
	rectangle(115,265,495,295);

	rectangle(110,310,500,350);
	rectangle(115,315,495,345);

	rectangle(110,360,500,400);
	rectangle(115,365,495,395);

	setcolor(RED);
	outtextxy(150,225,"Enter the Username:");
	outtextxy(150,275,"Enter the Password:");
	outtextxy(148,325,"Renter the Password:");
	outtextxy(150,375,"Enter Your name:");
	//username
	gotoxy(39,15);
	gets(u_name );
	//first password
	gotoxy(39,18);
	ch=getch();
	while(ch!='\r')
	{ cout<<"*";
	check1[c++]=ch;
	ch=getch();
	if(ch==8)
	 c--;
	}
	check1[c]='\0';

	//second password
	char check2[50];
	gotoxy(39,21);
	c=0;
	ch=getch();
	while(ch!='\r')
	{cout<<"*";
	check2[c++]=ch;
	ch=getch();
	}
	check2[c]='\0';
	gotoxy(39,24);

	gets(name);
	if(strcmp(check1,check2)==0)
	{

	cleardevice();

	//searching file to check if the username already exists
	int flag0=0;
	strcpy(filename,per_filepath);
	strcat(filename,"account.dat");
	file.open( filename, ios :: in | ios ::binary);
	if(file)
	{
	  file.read((char*)&person, sizeof(person)) ;
	  while( !file.eof() )
	   { if(person.comp_username(u_name))
	      { flag0=1; break; }
	     file.read((char*)&person, sizeof(person)) ;

	   }

	}//if(file)
	else //file doesnt exist
	  flag0=0;
	file.close();

	if(flag0==1)
	{

	   setcolor(RED);
	  settextstyle(0,0,2);
	  cleardevice();
	  outtextxy(100,180,"THIS USERNAME ALREADY EXISTS");
	  outtextxy(150,220,"TRY AGAIN........");
	  getch();
	  login_signup_option();
	  cleardevice();
	  signup();
	}
	else
	{
	 int flag=captchathing();
	 if(flag==1)
	  {     open_lic();
		strcpy(current_user.name,name);
		current_user.assign_username(u_name);
		current_user.assign_password(check2);
		strcpy(filename,per_filepath);
		strcat(filename,"account.dat");
		//assignin user id
		file.open( filename, ios :: in | ios ::binary);
		if(file)
		 {
		   file.seekg(sizeof(person),ios::end);
		   file.read((char*)&person,sizeof(person));
		   int userid=person.return_userid();
		   userid++;
		   current_user.assign_userid(userid);
		}
		else
		  current_user.assign_userid(1);
		file.close();


	file.open( filename, ios :: app | ios ::binary);
	file.write((char*)&current_user, sizeof(current_user));
	file.close();
	//current_user.assignall(person);
	//User current_user(person);
	strcpy(global_name,name);
	person.return_username();
	cleardevice();
	profile();
	}
	else if(flag==0)
	 login_signup_option();

	}  //username already exists
       }//password does not match
    else
	 {setcolor(RED);
	  settextstyle(0,0,2);
	  cleardevice();
	  outtextxy(100,180,"YOUR PASSWORDS DONT MATCH");
	  outtextxy(150,220,"TRY AGAIN........"); delay(3000);
	  getch();
	  cleardevice();
	  signup();
	  }


}
