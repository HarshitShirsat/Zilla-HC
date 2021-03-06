#include<iostream.h>
#include<ctype.h>
#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include <alloc.h>
#include <process.h>
#include<string.h>
const char per_filepath[50]="d:\\proj\\";
char filename[50];
int ypos=0;
char global_username[50];
class User
{
  private:
	char password[50];
	unsigned int dob_dd;
	unsigned int dob_mm;
	unsigned int dob_yy;
	char username[50];

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
       }
}person,current_user,other_user;

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
int User::return_userid()
{return userid;}
void User::return_username()
{strcpy(global_username,username);
}
int User::return_presence()
{return presence;}

void User::output_city()
{cout<<city;}
void User::output_gender()
{cout<<gender;}
void User::change_presence(int pres)
{presence=pres;}

void chat();
void chat2();
char second_userid;

//void chat()
void main()
{
int GD=DETECT,GM;
initgraph(&GD,&GM,"c:\\tc\\bgi");

clrscr();
int flg=0;
fstream allusers;
strcpy(filename,per_filepath);
strcat(filename,"account.dat");
allusers.open(filename,ios::in | ios::out);
if(allusers)
{allusers.read((char*)&person,sizeof(person));
 while(!allusers.eof())
 {
 if(person.return_presence()==1)
   {cout<<person.return_userid()<<"\t"<<person.name<<"\n\n";
   }
 allusers.read((char*)&person,sizeof(person));
 }
}
else
{exit(0);}
allusers.close();
cout<<"With Whom do you want to chat(USER ID): ";
cin>>second_userid;
strcpy(filename,per_filepath);
strcat(filename,"account.dat");

 allusers.open(filename,ios::in | ios::out);
if(allusers)
{allusers.read((char*)&person,sizeof(person));
 while(!allusers.eof())
 {
 if(person.return_presence()==1)
   {if(person.return_userid()==second_userid)
     {cout<<"PERSON AVAILABLE";
     flg=1;}
   }
 allusers.read((char*)&person,sizeof(person));
 }
}
else
{exit(0);}
if(flg==1)
 {chat();}
else if(flg==0)
 cout<<"no person with that user id is available.";

}
void chat2()
{
setfillstyle(SOLID_FILL,BLACK);
bar(0,360,640,410);

setcolor(RED);
setlinestyle(0,0,2);
line(60,400,610,400);
setlinestyle(0,0,3);
line(0,370,640,370);

setcolor(8);
gotoxy(9,25);
char temp[100]="\0",main[500]="\0";
int n=0,m=0,no=1;
fstream othr_user;

strcpy(filename,per_filepath);
strcat(filename,"account.dat");

othr_user.open(filename,ios::in | ios::binary);
if(othr_user)
{
othr_user.read((char*)&person,sizeof(person));
 while(!othr_user.eof())
 {
 if(person.return_presence()==1)
   {if(person.return_userid()==second_userid)
     {person.return_username();
      other_user.assignall(person);
     }
   }
 othr_user.read((char*)&person,sizeof(person));
 }
}
else
{exit(0);}
othr_user.close();


strcpy(filename,per_filepath);
strcat(filename,"temp_");
strcat(filename,global_username);
strcat(filename,".txt");

current_user.return_username();

fstream hisfile;
hisfile.open(filename,ios::in | ios::binary);
if(hisfile)
{
char hisfile_read;
char his_text[500];
hisfile.get(hisfile_read);
int his_no_of_char=0;
while(!hisfile.eof())
 {
  his_text[his_no_of_char++]=hisfile_read;
  hisfile.get(hisfile_read);
 }
 his_text[his_no_of_char]='\0';

   {
   strcpy(filename,per_filepath);
   strcat(filename,"\\chat_hist\\");
   strcat(filename,global_username);
   strcat(filename,"_");
   other_user.return_username();
   strcat(filename,global_username);
   strcat(filename,".txt");

   fstream chat_hist;
   chat_hist.open(filename,ios::app | ios::binary);
   other_user.return_username();
   chat_hist.write(global_username,strlen(global_username));
   chat_hist.put(':');
   chat_hist.write(main,strlen(main));
   chat_hist.put('\n');
   chat_hist.close();
   }
 int bar_height=((strlen(his_text)/40)+1)*5;
 for(int s=0;his_text[s]!='\0';s++)
 {
 char his_temp_contents[40];
   int c=0;
   for(c=0;c<40;c++)
    {
     his_temp_contents[c]=his_text[s];
     }
    his_temp_contents[c]='\0';
  setfillstyle(SOLID_FILL,LIGHTGREEN);
  bar(10,ypos+10,210,ypos+10+bar_height);
  settextstyle(1,0,1);
  setcolor(WHITE);
  outtextxy(15,ypos+5,his_temp_contents);
  ypos+=5;
 }
}
else;

char ch=getch();
int flag=0;
if(ch=='\n')
  flag=1;
while(ch!=27 && flag==0)
{
if(m!=68)
{cout<<ch;}
 if(ch!='\n' && ch!='\t')
   {main[m]=ch;}
if(m>=68)
 {
  n=0;
  for(int i=no;i<=m;i++)
  {
  temp[n++]=main[i];
  }
  temp[n]='\0';
  gotoxy(9,25);
  cout<<temp;
  gotoxy(wherex()-1,25);
    ch=getch();
  no++;
 }
else
 {
  ch=getch();
 }
m++;
if(ch=='\n')
 {flag=1; break;}
}//while
if(ch==27)
  {exit(0);}
if(flag==1)
 {
   fstream myfile;
   strcpy(filename,per_filepath);
   strcat(filename,"temp_");
   current_user.return_username();
   strcat(filename,global_username);
   strcat(filename,".txt");
   myfile.open(filename,ios::out | ios::binary);
   myfile.write(main,strlen(main));
   myfile.close();
   ypos+=15;
   int bar_height=((strlen(main)/40)+1)*5;
   for(int s=0;main[s]!='\0';s++)
   {
   char my_temp_contents[40];
   int c=0;
   for(c=0;c<40;c++)
    {
     my_temp_contents[c]=main[s];
     }
    my_temp_contents[c]='\0';
  setfillstyle(SOLID_FILL,LIGHTBLUE);
  bar(430,ypos+10,630,ypos+10+bar_height);
  settextstyle(1,0,1);
  setcolor(WHITE);
  outtextxy(15,ypos+5,my_temp_contents);
  ypos+=5;
  }

   strcpy(filename,per_filepath);
   strcat(filename,"\\chat_hist\\");
   strcat(filename,global_username);
   strcat(filename,"_");
   other_user.return_username();
   strcat(filename,global_username);
   strcat(filename,".txt");

   fstream chat_hist;
   chat_hist.open(filename,ios::app | ios::binary);
   current_user.return_username();
   chat_hist.write(global_username,strlen(global_username));
   chat_hist.put(':');
   chat_hist.write(main,strlen(main));
   chat_hist.put('\n');
   chat_hist.close();
   chat();
 }
getch();
}