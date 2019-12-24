void User::assignall(User &user)
       {strcpy(username,user.username);
	strcpy(password,user.password);
	dob_dd=user.dob_dd;
	dob_mm=user.dob_mm;
	dob_yy=user.dob_yy;
	strcpy(gender,user.gender);
	strcpy(city,user.city);
	strcpy(name,user.name);
	presence=user.presence;
	userid=user.userid;
	highscore=user.highscore;
	profile_pic_char=user.profile_pic_char;
	}
int User::comp_username(char temp_username[50])
{if(strcmp(username,temp_username)==0)
   return 1;
 else
   return 0;
}

int User::comp_password(char temp_password[50])
{if(strcmp(password,temp_password)==0)
   return 1;
 else
   return 0;
}
void User::assign_username(char uname[50])
{strcpy(username,uname);}
void User::assign_city(char cit[50])
{strcpy(city,cit);}
void User::assign_userid(int user_id)
{userid=user_id;}
void User::assign_password(char pname[50])
{strcpy(password,pname);}
void User::assign_gender(char gendr)
{if(gendr=='m' || gendr=='M')
   strcpy(gender,"MALE");
if(gendr=='f' || gendr=='F')
   strcpy(gender,"FEMALE");
}
void User::assign_profile_pic_char(char character)
{profile_pic_char=character;}
int User::return_userid()
{return userid;}
void User::return_username()
{strcpy(global_username,username);}
int User::return_presence()
{return presence;}
unsigned int User::return_highscore()
{return highscore;}
int User::return_profile_pic_char()
{return profile_pic_char;}


void User::output_city()
{cout<<city;}
void User::output_gender()
{cout<<gender;}
void User::change_presence(int pres)
{presence=pres;}
void User::change_highscore(unsigned int hghscr)
{highscore=hghscr;}

void User::output()
{
cout<<"\t"<<userid;
cout<<setw(20)<<name;
}

//memeber functions which displays user's profile.
void User::my_details()
{
hidemouse();
setlinestyle(0,0,3);
setcolor(MAGENTA);
rectangle(1,1,639,479);
line(1,300,640,300);
line(1,50,640,50);
settextstyle(0,0,3);
setcolor(WHITE);
outtextxy(10,20,name);
settextstyle(2,0,6);
outtextxy(30,317,"USER ID:");
settextstyle(2,0,6);
outtextxy(60,347,"CITY:");
settextstyle(2,0,6);
outtextxy(38,380,"GENDER:");
settextstyle(2,0,6);
outtextxy(200,380,"HIGH SCORE:");
settextstyle(2,0,6);
outtextxy(210,60,"PROFILE PICTURE");
textcolor(3);
gotoxy(15,21);
cout<<userid;
gotoxy(15,23);
cout<<city;
gotoxy(15,25);
cout<<gender;
gotoxy(40,25);
cout<<highscore;
strcpy(filename,"images\\smileys\\");
if(profile_pic_char=='a')
  strcat(filename,"a");
else if(profile_pic_char=='b')
  strcat(filename,"b");
else if(profile_pic_char=='c')
  strcat(filename,"c");
else if(profile_pic_char=='d')
  strcat(filename,"d");
else if(profile_pic_char=='e')
  strcat(filename,"e");
else if(profile_pic_char=='f')
  strcat(filename,"f");
else if(profile_pic_char=='g')
  strcat(filename,"g");
else if(profile_pic_char=='h')
  strcat(filename,"h");
else if(profile_pic_char=='i')
  strcat(filename,"i");
else
  strcat(filename,"j");

if(profile_pic_char=='j')
   {
   setfillstyle(SOLID_FILL,WHITE);
   setcolor(BLACK);
   bar(210,90,350,230);
   settextstyle(0,0,10);
   outtextxy(250,120,"?");
   }
else
  {dis_img(filename,210,90);
  }

}