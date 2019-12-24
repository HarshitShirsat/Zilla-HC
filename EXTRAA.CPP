//friend request
void add_friend(int );
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
    outtextxy(80,200,"YOU HAVE NOT RECEIVED ANY FRIEND REQUEST");
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

void send_friend_request()
{
clrscr();
cleardevice();
hidemouse();
int flag=0;
int to_whom_friend_request;
settextstyle(7,0,3);
setcolor(GREEN);
outtextxy(100,20,"TO WHOM");
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
   { /*
     fstream temp_file2;
     strcpy(filename,per_filepath);
     strcat(filename,"friends\\");
     current_user.return_username();
     strcat(filename,global_username);
     strcat(filename,".dat");
     temp_file.open(filename,ios::in | ios::binary);
       */
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



void see_my_friends()
{clrscr();
cleardevice();
int flag_friends=0;
int second_flag=0;
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
 while(!file.eof())
 {fstream file1;
 strcpy(filename,per_filepath);
 strcat(filename,"account.dat");
 file1.open(filename,ios::in | ios::binary);
 file1.read((char*)&person,sizeof(person));
  while(!file1.eof())
  {
  if(user_id==person.return_userid())
   {person.output(); cout<<"\n"; flag_friends++;}
   file1.read((char*)&person,sizeof(person));
  }
  file>>user_id;
  file1.close();
 }
 }//if(file)
 else
 {
 settextstyle(7,0,3);
 setcolor(RED);
 outtextxy(150,200,"YOU HAVE NO FRIENDS ");
 second_flag=1;
 }
 if(flag_friends==0)
  {
  if(second_flag==0)
   settextstyle(7,0,3);
   setcolor(RED);
   outtextxy(150,200,"YOU HAVE NO FRIENDS ");
  }
 file.close();
 getch();
}