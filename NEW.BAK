#include <iostream.h>
#include <ctype.h>
#include <fstream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <alloc.h>
#include <process.h>
#include <string.h>
#include <iomanip.h>

int x,y,button;
int maxx=640;//getmaxx();
int maxy=480;//getmaxy();
char global_name[50]="USER";
char global_username[50];
int second_userid;
int idiot=0;
int ypos;
fstream file;
const char directory[20]="h:\\proj\\";
#include "h:\proj\dis_img.cpp"
char per_filename[10]={"h:\\proj\\"};
class User
{
  private:
	char password[50];
	unsigned int dob_dd;
	unsigned int dob_mm;
	unsigned int dob_yy;
	char username[50];
	char profile_pic_char;
	char city[50];
	int userid;
	char gender[50];
	int presence;
	unsigned int highscore;
  public:
	char name[50];
	int comp_password(char[]);
	int comp_username(char []);
	void assign_username(char []);
	void assign_userid(int);
	void assign_password(char []);
	void return_username();
	void assign_gender(char);
	void assignall(User &user);
	void assign_city(char[]);
	void output_gender();
	void output_city();
	int return_userid();
	void my_details();
	void change_presence(int);
	int  return_presence();
	void change_highscore(unsigned int);
	void output();
	unsigned int return_highscore();
	void assign_profile_pic_char(char);
	int return_profile_pic_char();
	//constructor
	User()
	{
	strcpy(username,"username");
	strcpy(password,"password");
	dob_dd=0;
	dob_mm=0;
	dob_yy=0;
	strcpy(gender,"MALE");
	strcpy(city,"NA");
	presence=1;
	highscore=0;
	userid=0;
	strcpy(name,"USER");
	profile_pic_char='j';
	}
	//copy constructor
       User(User &user)
       {strcpy(username,user.username);
	strcpy(password,user.password);
	dob_dd=user.dob_dd;
	dob_mm=user.dob_mm;
	dob_yy=user.dob_yy;
	strcpy(gender,user.gender);
	strcpy(city,user.city);
	presence=user.presence;
	userid=user.userid;
	highscore=user.highscore;
	profile_pic_char=user.profile_pic_char;
       }
}person,current_user,other_user;


const char per_filepath[50]="i:\\proj\\";
	char filename[50];
const char for_images_directory[15]="h:\\proj\\";
int option;
void profile2();
void profile();
void see_friend_request();
void send_friend_request();
void send_request(int);
void see_my_friends();
void add_friend(int );

#include "h:\proj\allmose.cpp"
//#include "d:\proj\cursor.cpp"
#include "h:\proj\drop_dow.cpp"
#include "h:\proj\start.cpp"
#include "h:\proj\dia_box.cpp"
#include "h:\proj\l_sig_gr.cpp"
#include "h:\proj\loadin.cpp"
#include "h:\proj\img_con.cpp"
#include "h:\proj\gender.cpp"
#include "h:\proj\open_lic.cpp"
#include "h:\proj\lg_si_o.cpp"
#include "h:\proj\acc_fr.cpp"
#include "h:\proj\pro_grap.cpp"
#include "h:\proj\fr_rq_m.cpp"
#include "h:\proj\abt_pg.cpp"
#include "h:\proj\game2.cpp"
#include "h:\proj\signup.cpp"
#include "h:\proj\login.cpp"
#include "h:\proj\pro_pic.cpp"
#include "h:\proj\ext_det.cpp"
#include "h:\proj\mn_chat.cpp"
#include "h:\proj\user_fun.cpp"
#include "h:\proj\chat_hi.cpp"
void main()
{
int GD=DETECT,GM;
initgraph(&GD,&GM,"c:\\tc\\bgi");
 start();
 int status=initmouse();
 if(status==1)
  {cout<<"\n\n\n\n\n\t\t\t\tMOUSE SUPPORT NOT AVAILABLE";
   getch();
   exit(0);}

  option=login_signup_option();
   if(option==1)
    login();
   else if(option==2)
    signup();

cleardevice();
getch();
closegraph();
}

//shows the welcome page
void profile()
{
char gender=return_gender();
strcpy(filename,per_filepath);
strcat(filename,"account.dat");
file.open(filename,ios::in | ios::out | ios::binary);
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

setlinestyle(SOLID_LINE,0,3);
 setcolor(RED);
 rectangle(10,10,630,470);


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


//controls the menu in which the user can switch between different options
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
	 director();
	 break;

  case 3://search
	 {
	 clrscr();
	 cleardevice();
	 setlinestyle(SOLID_LINE,0,3);
	 setcolor(RED);
	 rectangle(10,10,630,470);
	 line(10,50,630,50);
	 setcolor(GREEN);
	 outtextxy(220,20,"ALL USERS");
	 cout<<"\n\n\n\n\t"<<"USER ID"<<setw(20)<<"NAME\n\n";
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
	    setlinestyle(SOLID_LINE,0,3);
	 setcolor(RED);
	 rectangle(10,10,630,470);
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
	       getch();
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
	     int fg=0;
	     fstream file2;
	     strcpy(temp_filename,per_filepath);
	     strcat(temp_filename,"temp.dat");
	     file2.open(temp_filename,ios::out | ios::binary);
	     file.read((char*)&person,sizeof(person));
	     current_user.return_username();
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
		strcpy(filename,per_filepath);
		strcat(filename,"account.dat");
		remove(filename);
		/*
		strcpy(temp_filename,per_filepath);
		strcat(temp_filename,"temp.dat");
		rename(temp_filename,filename);

		strcpy(filename,per_filepath);
		strcat(filename,"friends\\");
		current_user.return_username();
		strcat(filename,global_username);
		strcat(filename,".dat");
		remove(filename);

		strcpy(filename,per_filepath);
		strcat(filename,"fri_req\\");
		current_user.return_username();
		strcat(filename,global_username);
		strcat(filename,".dat");
		remove(filename);

		strcpy(filename,per_filepath);
		strcat(filename,"chat_hist\\");
		current_user.return_username();
		strcat(filename,global_username);
		strcat(filename,".dat");
		remove(filename);
		  */
	       settextstyle(7,0,3);
	       setcolor(RED);
	       outtextxy(100,200,"ACCOUNT SUCCESSFULLY DELETED");
	       getch();
	       login_signup_option();
	       }


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
	   if(option==1)
	    {see_friend_request();}
	    else if(option==2)
	    {send_friend_request();}

	 }
	 break;
  case 8:see_my_friends();
	 break;


  case 9:current_user.my_details();
	getch();
	break;
  case 10: chat_hist();
	   break;
  }//switch
}while(option!=6 || (option!=4 && flag!=1));
}//profile

//checks the file for any newly recieved friend requests
void see_friend_request()
{
cleardevice();
hidemouse();
int friends_req_userid=0;
int no_of_friend_request=0;
strcpy(filename,per_filepath);
strcat(filename,"fri_req\\");
current_user.return_username();
strcat(filename,global_username);
strcat(filename,".dat");
fstream friend_requests;
friend_requests.open(filename,ios::in | ios::binary);
if(friend_requests)
 {
 friend_requests>>friends_req_userid;
 while(!friend_requests.eof())
  {fstream allusers;
   strcpy(filename,per_filepath);
   strcat(filename,"account.dat");
   allusers.open(filename,ios::in | ios::binary);
   allusers.read((char*)&person,sizeof(person));
   while(!allusers.eof())
   {
   if(person.return_userid()==friends_req_userid)
    {person.my_details();
     int option=accept_friend_request();
      if(option==1)
      {person.return_username();
       add_friend(friends_req_userid);
       no_of_friend_request++;
       }
    }
   allusers.read((char*)&person,sizeof(person));
   }
  friend_requests>>friends_req_userid;
  }

 }
else
  {if(no_of_friend_request==0)
    settextstyle(7,0,3);
    setcolor(RED);
    outtextxy(30,200,"YOU HAVE NOT RECEIVED ANY FRIEND REQUEST");
    getch();
  }
friend_requests.close();
strcpy(filename,per_filepath);
strcat(filename,"fri_req\\");
current_user.return_username();
strcat(filename,global_username);
strcat(filename,".dat");
friend_requests.open(filename,ios::out | ios::binary);
friend_requests.close();
}
//function  to add the user id of the friend whose friend request has been just accepted
void add_friend(int friends_userid)
{
fstream friends;
 strcpy(filename,per_filepath);
 strcat(filename,"friends\\");
 strcat(filename,global_username);
 strcat(filename,".dat");
 friends.open(filename,ios::app | ios::binary);
 friends<<current_user.return_userid();
 friends.close();

 current_user.return_username();
 strcpy(filename,per_filepath);
 strcat(filename,"friends\\");
 strcat(filename,global_username);
 strcat(filename,".dat");
 friends.open(filename,ios::app | ios::binary);
 friends<<friends_userid;
 friends.close();
}
//function to search for another person to whom the friend request has to be sent
void send_friend_request()
{
clrscr();
cleardevice();
hidemouse();
int flag=0;
int to_whom_friend_request;
fstream send_req;
strcpy(filename,per_filepath);
strcat(filename,"account.dat");
send_req.open(filename,ios::in | ios::binary);
send_req.read((char*)&person,sizeof(person));
while(!send_req.eof())
 {int user_id=person.return_userid();
 fstream temp_file;
 strcpy(filename,per_filepath);
 strcat(filename,"friends\\");
 current_user.return_username();
 strcat(filename,global_username);
 strcat(filename,".dat");
 temp_file.open(filename,ios::in | ios::binary);
 if(temp_file)
 {
 int second_userid;
 temp_file>>second_userid;
 while(!temp_file.eof())
  {if(second_userid==user_id);
   else
   {
     fstream temp_file2;
     strcpy(filename,per_filepath);
     strcat(filename,"friends\\");
     current_user.return_username();
     strcat(filename,global_username);
     strcat(filename,".dat");
     temp_file.open(filename,ios::in | ios::binary);
     person.output();
     cout<<"\n";
     flag=1;
   }
   temp_file>>second_userid;
  }//inner while
 }      //if temp file exists
 else
 {flag=1;
 if(person.return_userid()!=current_user.return_userid())
 {person.output();
 cout<<"\n"; }
 }
 temp_file.close();
  send_req.read((char*)&person,sizeof(person));
 }//outer while
 send_req.close();

 if(flag==1)
 {cout<<"\nTO WHOM WOULD YOU LIKE TO SEND REQ:(USERID) ";
 cin>>to_whom_friend_request;
 fstream allusers;
 strcpy(filename,per_filepath);
 strcat(filename,"account.dat");
 allusers.open(filename,ios::in | ios::binary);
 allusers.read((char*)&person,sizeof(person));
 int temp_flag=0;
 while(!allusers.eof())
 { if(person.return_userid()==to_whom_friend_request)
   {
   fstream temp_file;
   strcpy(filename,per_filepath);
   strcat(filename,"friends\\");
   current_user.return_username();
   strcat(filename,global_username);
   strcat(filename,".dat");
   temp_file.open(filename,ios::in | ios:: binary);
   if(temp_file)
   {
   char read;
   temp_file>>read;
   while(!temp_file.eof())
    {
     if(to_whom_friend_request==read)
      { cout<<"THIS PERSON IS ALREADY YOUR FRIEND";
       temp_flag=1;
       break;
      }
      else
       person.return_username();
     temp_file>>read;
    }
   } //if file exists
   else
    flag=0;
   }
 allusers.read((char*)&person,sizeof(person));
 }    //all user while
 allusers.close();
 if(temp_flag==0)
     send_request(to_whom_friend_request);
 }
 else if(flag==0)
 {cout<<"NOONE AVAILABLE TO PERFORM THIS OPERATION";}



}


//function to send the  friend request to another person
void  send_request(int userid)
{
strcpy(filename,per_filepath);
strcat(filename,"account.dat");
fstream file;
file.open(filename,ios::in || ios::binary);
file.read((char*)&person,sizeof(person));
while(!file.eof())
{if(person.return_userid()==userid)
	person.return_username();
file.read((char*)&person,sizeof(person));
}

strcpy(filename,per_filepath);
strcat(filename,"fri_req\\");
strcat(filename,global_username);
strcat(filename,".dat");
fstream write_to_his_file;
write_to_his_file.open(filename,ios::app | ios::binary);
write_to_his_file<<current_user.return_userid();
write_to_his_file.close();
settextstyle(7,0,3);
setcolor(GREEN);
outtextxy(100,200,"FRIEND REQUEST SUCCESSFULLY SENT");
getch();
}


//function to see how many friends the user has and to see their basic data
void see_my_friends()
{clrscr();
cleardevice();
 int flag_friends=0;
 fstream file;
 int user_id=0;
 current_user.return_username();
 strcpy(filename,per_filepath);
 strcat(filename,"friends\\");
 strcat(filename,global_username);
 strcat(filename,".dat");
 file.open(filename,ios::in | ios::binary);
 if(file)
 {
  file>>user_id;
 cout<<"\n\n\t\t\t\tFRIENDS LIST\n\n";
 cout<<"\n\n\t"<<"USERID";
 cout<<setw(20)<<"NAME\n\n\n";
 while(!file.eof())
 {fstream file1;
 strcpy(filename,per_filepath);
 strcat(filename,"account.dat");
 file1.open(filename,ios::in | ios::binary);
 file1.read((char*)&person,sizeof(person));
  while(!file1.eof())
  {
  if(user_id==person.return_userid())
   {person.output(); cout<<"\n"; flag_friends=1;}
   file1.read((char*)&person,sizeof(person));
  }
  file>>user_id;
  file1.close();
 }
 }//if(file)
  if(flag_friends==0)
 {
 settextstyle(7,0,3);
 setcolor(RED);
 outtextxy(150,200,"YOU HAVE NO FRIENDS ");
 }
 file.close();
 getch();
}