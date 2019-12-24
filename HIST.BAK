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
#include<iomanip.h>
const char per_filepath[50]="f:\\proj\\";
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
	void output();
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

void User::output()
{
cout<<userid;
cout<<"\t"<<setw(20)<<name;
}

void main()
{
clrscr();
char with_whom[50];
cout<<"\n\n\nCHAT HISTORY";
cout<<"\n\n\t\tWith whom(name)";//name
gets(with_whom);
int count=0;
{      //simply braces
fstream allusers;
strcpy(filename,per_filepath);
strcat(filename,"account.dat");
allusers.open(filename,ios::in | ios::binary);
if(allusers)
{allusers.read((char*)&person,sizeof(person));
while(!allusers.eof())
 {
 if(!strcmpi(with_whom,person.name))
  { person.output();
   cout<<"\n";
   count++;
  }
 allusers.read((char*)&person,sizeof(person));
 }
}
else
{exit(0);}
allusers.close();

}//simply braces
int flag=0;
if(count>1)
{
unsigned int user_id;
cout<<"\nEnter the userid of the person";
cin>>user_id;
fstream allusers;
strcpy(filename,per_filepath);
strcat(filename,"account.dat");
allusers.open(filename,ios::in | ios::binary);
if(allusers)
{allusers.read((char*)&person,sizeof(person));
while(!allusers.eof())
 {
 if(person.return_userid()==user_id)
  {flag=1;
  }
 allusers.read((char*)&person,sizeof(person));
 }
}
else
{exit(0);}
}
else
 flag=1;

 if(flag==1)
 { clrscr();
   cout<<"\n\n\t\t\t\tCHAT HISTORY\n\n";
   current_user.return_username();
   strcpy(filename,per_filepath);
   strcat(filename,"\\chat_hist\\");
   strcat(filename,global_username);
   strcat(filename,"_");
   other_user.return_username();
   strcat(filename,global_username);
   strcat(filename,".txt");
   fstream chat_hist;
   chat_hist.open(filename,ios::in | ios::binary);
   char from_chat_hist;
   chat_hist.get(from_chat_hist);
   while(!chat_hist.eof())
   {cout<<from_chat_hist;
   chat_hist.get(from_chat_hist);
   }
   chat_hist.close();
 }
 else
   cout<<"error";
}

