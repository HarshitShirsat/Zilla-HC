int no_of_times_this_loop_is_runnin=0;
void chat2();


//checks if the any friend of yours is online  and diplays it in a list
void chat()
{
clrscr();
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
  {flag_friends=1;
   if(user_id==person.return_userid())
  //   {if(person.return_presence()==1)
       {
	person.output();
	cout<<"\n\n";
       }
    // }
   file1.read((char*)&person,sizeof(person));
  }
  file1.close();
  file>>user_id;

 }
 }//if(file)
  if(flag_friends==0)
 {
 settextstyle(7,0,3);
 setcolor(RED);
 outtextxy(150,200,"YOU HAVE NO FRIENDS TO CHAT");
 getch();
 idiot=1;
 }
 file.close();
 if(idiot==0)
 {
 cout<<"With Whom do you want to chat(USER ID): ";
 cin>>second_userid;
 strcpy(filename,per_filepath);
 strcat(filename,"account.dat");
 textcolor(BLACK);
 textbackground(WHITE);
 window(wherex()+1,wherey()-1,wherex()+10,wherey()-1);
 fstream allusers;
 int flg=0;
 allusers.open(filename,ios::in |ios::binary);
//if(allusers)
//{
allusers.read((char*)&person,sizeof(person));
 while(!allusers.eof())
 {
 if(/*person.return_presence()==1 && */person.return_userid()!=current_user.return_userid())
   {if(person.return_userid()==second_userid)
     {cout<<"\n\n\t\t\tPERSON AVAILABLE";
     flg=1;
     getch();}
   }
/* if(person.return_userid()==current_user.return_userid())
  {cout<<"\n\n-_- you can\'t chat with yourself...";
   }     */
 allusers.read((char*)&person,sizeof(person));
 }
//}
//else
//{exit(0);}
allusers.close();
if(flg==1)
 {clrscr();
 cleardevice();
 chat2();}
else if(flg==0)
 {settextstyle(7,0,3);
 setcolor(RED);
 outtextxy(100,200,"NOBODY WITH THAT USERID");
 getch();}
 }
 else
   idiot=0;

}
//function which allows the user to chat with his friend
void chat2()
{
clrscr();
cleardevice();
//int check=check_if_he_is_present();
setfillstyle(SOLID_FILL,BLACK);
bar(0,360,640,410);

setcolor(RED);
setlinestyle(0,0,2);
line(60,400,610,400);
setlinestyle(0,0,3);
line(0,370,640,370);

gotoxy(9,25);

char temp[100]="\0",main[1000]="\0";
int n=0,m=0,no=1;
fstream othr_user;

strcpy(filename,per_filepath);
strcat(filename,"account.dat");

othr_user.open(filename,ios::in | ios::binary);
//if(othr_user)
//{
othr_user.read((char*)&person,sizeof(person));
 while(!othr_user.eof())
 {
 if(person.return_presence()==1)
   {if(person.return_userid()==second_userid)
     {person.return_username();
      other_user.assignall(person);

     }
   }
 else   //ifperson.return_prescence==0
 {
    ypos+=15;
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(380,ypos-5,400+strlen(other_user.name)+30,ypos+30);
    setcolor(RED);
    settextstyle(3,0,4);
    outtextxy(400,ypos,other_user.name);
    outtextxy(400+strlen(other_user.name)+5,ypos," LEFT");
    getch();
 }
 othr_user.read((char*)&person,sizeof(person));
 }
/*}
else
{exit(0);}     */
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
char his_text[1000]="\0";
hisfile.get(hisfile_read);
int his_no_of_char=0;
while(!hisfile.eof())
 {
  his_text[his_no_of_char++]=hisfile_read;
  hisfile.get(hisfile_read);
 }
 his_text[his_no_of_char]='\0';

   if(strcmpi(his_text,"\0"))
   {
   strcpy(filename,per_filepath);
   strcat(filename,"chat_hist\\");
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


 int bar_height=((strlen(his_text)/40)+1)*5;
 for(int s=0;his_text[s]!='\0';)
 {
 char his_temp_contents[40];
   int c=0;
   for(c=0;c<40;c++)
    {
     his_temp_contents[c]=his_text[s++];
     }
    his_temp_contents[c]='\0';
  setfillstyle(SOLID_FILL,LIGHTGREEN);
  bar(10,ypos+10,210,ypos+10+bar_height);
  settextstyle(2,0,3);
  setcolor(WHITE);
  outtextxy(15,ypos+5,his_temp_contents);
  ypos+=5;
 }
 }
}
else;

char ch=getch();
int flag=0;
if(ch=='\r')
  flag=1;
while(ch!=27 && flag==0)
{
if(m!=68 && ch!='\r' && ch!='\t')
{cout<<ch;}
 if(ch!='\r' && ch!='\t')
   {main[m]=ch;}

if(m>=68)
 {
  n=0;
  for(int i=no;i<=m;i++)
  {
  if(ch!='\r' && ch!='\t')
  {temp[n++]=main[i];  }
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
if(ch=='\r')
 {flag=1; }
}//while
if(ch==27)
  {profile2();}

if(flag==1 && strcmpi(main,"\0"))
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
   for(int s=0;main[s]!='\0';)
   {
   char my_temp_contents[40];
   int c=0;
   for(c=0;c<40;c++)
    {
     my_temp_contents[c]=main[s++];
     }
    my_temp_contents[c]='\0';
  setfillstyle(SOLID_FILL,LIGHTBLUE);
  bar(430,ypos+10,630,ypos+10+bar_height);
  settextstyle(2,0,3);
  setcolor(WHITE);
  outtextxy(15,ypos+5,my_temp_contents);
  ypos+=5;
  }

   strcpy(filename,per_filepath);
   strcat(filename,"chat_hist\\");
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
if(ypos>=350)
  {ypos=0;
  cleardevice();}

}
