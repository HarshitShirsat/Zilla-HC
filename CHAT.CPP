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

/*void writefile(char name[]);
const char ESC = 27;
const char LEFT_ARROW= 75;
const char fil_path[20]="g:\\";
char filename[20]; */

/*
class User
{       public:
	unsigned int user_no;
	char username[30];
	char password[10];
	unsigned int dob_dd;
	unsigned int dob_mm;
	unsigned int dob_yy;
	int presence;
	char gender;
	char city[30];
	void profile();
	void signup();
	void login();
	User()
	{strcpy(username,"\0");
	strcpy(password,"\0");
	dob_dd=01;
	dob_mm=01;
	dob_yy=1999;
	gender='N';
	strcpy(city,"NA");
	presence=1;

}person;

void main()
{
cout<<"enter username,password";
gets(person.username);
gets(person.password);
fstream file;
file.open( "J:\\Account.dat", ios :: app | ios ::binary);
file.write((char*)&person.username, sizeof(person.username)) ;
file.write((char*)&person.password, sizeof(person.password)) ;
file.close();


//as soon as signup
char u_name[20];
char pass[20];
gets(u_name);
gets(pass);
file.open( "J:\\Account.dat", ios :: app | ios ::binary);
file.read((char*)&person.username, sizeof(person.username)) ;

while( !file.eof() )
	{       person.user_no++;
		if( strcmpi(u_name, person.username ) == 0 )
		{cout<<"This username already exists...try again";
		login_signup_option();
		break;}

	}
fstream file3;
file3.open( "J:\\userno.dat", ios :: app | ios ::binary);
file3.write((char*)&person.user_no, sizeof(person.user_no)) ;
file3.close();                //uptill here signup stuff


fstream file2;
file2.open( "J:\\Presence.dat", ios :: app | ios ::binary);
file2.write((char*)&person.presence, sizeof(person.presence)) ;
file2.close();


//as soon as login
char chat_line[200];
char filename1[30] = "j:\\";
strcat(filename1, person.username);
fstream file2;
file2.open(filename1, ios :: out | ios ::binary  );
char charc;
charc=getch();
if(
while(charc != '')
cout<<person.username<<"says";

  while( ch != ESC )
  {
  if( ch== '\r' )
  {
	ch = '\n';
	cout<<ch;
  }
	file.put( ch ) ;
	ch = getche() ;
  }
  file.close() ;

/*
const char ESC = 27;
void WriteFile(char Name[])
{

  fstream file;
  char ch;
  file.open(Name, ios :: out | ios ::binary  );
  ch = getche() ;
  while( ch != ESC )
  {
  if( ch== '\r' )
  {
	ch = '\n';
	cout<<ch;
  }
	file.put( ch ) ;
	ch = getche() ;
  }
  file.close() ;
}

void chat()
{
clrscr();
char Name1[30], Name2[30];
cout<<"User 1: Enter your name";
gets( Name1);


cout<<"User 2: Enter your name";
gets( Name2);

char filename1[30] = "D:\\";
strcat(filename1, Name1);

char filename2[30] = "D:\\";
strcat(filename2, Name2);


WriteFile( filename1 ) ;
WriteFile( filename2 ) ;



getch();
}*/
/*
class User
{
 char username[20];
 char password[20];
};
void main()
{strcpy(filename,fil_path);
clrscr();
char username[20],password[20];
cin>>username>>password;
int n=0;
fstream file2;
char chatname[20][20];
char garbage;
int temp_presence=0,temp_userno=0;
strcat(filename,"Presence.dat");
file2.open( filename, ios :: in | ios ::binary);
file2>>temp_presence>>garbage;
//file2.read((char*)&temp_presence, sizeof(temp_presence)) ;
while( !file2.eof() )
{temp_userno++;
if(temp_presence==1)
   { fstream file1;
   strcpy(filename,fil_path);
   strcat(filename,"UAccount");
     file1.open(filename, ios :: in | ios ::binary );
     int temp_userno2=0;
     while( !file1.eof() )

       {char garbaged[20];
       file1.read((char*)&garbaged, sizeof(garbaged)) ;
       temp_userno2++;
       if(temp_userno2==temp_userno)
	       {  file1.read((char*)&chatname[n], sizeof(chatname[n])) ;
		  cout<<"u can chat with: "<<chatname[n++];     }
       }//while file1.eof

   } //if temp_presence==1
file2>>temp_presence>>garbage;
//file2.read((int)&temp_presence, sizeof(temp_presence)) ;
} //while file2.close
file2.close();
cout<<"with whom";
int flag7=0;
char chat_person[20];
gets(chat_person);
for(int i=0;i<20;i++)
{
if(strcmpi(chat_person,chatname[i])==0)
  {flag7=1;
  break;}

}
if(flag7==0)
  cout<<"the name either doesn't exist or hasn't come online";
else
 {
  clrscr();
  cout<<"\n\n\t\t\t\tCHAT ZONE";
  strcpy(filename,fil_path);
  strcat(filename,username);
  writefile(filename);
 }

}//main

void writefile(char name[])
{
  fstream file;
  char ch;
  file.open(name, ios :: app | ios ::binary  );
  ch = getche() ;
  if(ch==ESC)
    exit(0);//profile
  while( ch != ESC)
  {
  if(ch==LEFT_ARROW)
   {
   }
  if( ch== '\r' )
  {
	ch = '\n';
	cout<<ch;
  }
	file.put( ch ) ;
	ch = getche() ;
  }
  file.close() ;
}*/