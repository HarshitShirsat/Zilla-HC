//friend request
void add_friend(int );
int accept_friend_request();
void see_friend_request()
{
int friends_req_userid=0;
int no_of_friend_request=0;
strcpy(filename,per_filepath);
strcat(filename,"friend_request\\");
current_user.return_username();
strcat(filename,global_username);
strcat(filename,".dat");
fstream friend_requests;
friend_requests.open(filename,ios::in || ios::binary);
if(friend_requests)
 {
 friend_requests>>(friends_req_userid);
 while(!friend_requests.eof())
  {fstream allusers;
   strcpy(filename,per_filepath);
   strcat(filename,"account.dat");
   allusers.open(filename,ios::in | ios::binary);
   alluser.read((char*)&person,sizeof(person));
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
   alluser.read((char*)&person,sizeof(person));
   }
  friend_requests>>(friends_req_userid);
  }

 }
if(!friend_requests || no_of_friend_request==0)
 cout<<"YOU HAVE NO FRIEND REQUESTS";

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
 friends.put(friends_userid);
 friends.close();
}
int accept_friend_requests()
{
setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(500,400,600,430);
bar(500,440,600,470);
settextstyle(1,0,1);
setcolor(GREEN);
outtextxy(510,405,"ACCEPT");
setcolor(RED);
outtextxy(510,445,"DECLINE");
restrictmouse(0,0,640,480);
movemouseptr(0,0);
showmouse();
changecursor(cursorhc);
int option=3;
while(1)
{
   getmousepos(&button, &x, &y );

   if((x>=500 && y>=400 && x<=600 && y<=430) || (x>=500 && y>=440 && x<=600 && y<=470))
     { changecursor(cursorhand);  }
   else
     {changecursor(cursorhc);}
   if(x>=500 && y>=400 && x<=600 && y<=430)
   {setlinestyle(0,0,3);
   setcolor(GREEN);
   rectangle(498,398,600,430);
   }
   else
   {
   setlinestyle(0,0,3);
   setcolor(BLACK);
   rectangle(498,398,600,430);
   }
   if(x>=500 && y>=440 && x<=600 && y<=470)
   {
   setlinestyle(0,0,3);
   setcolor(GREEN);
   rectangle(498,438,600,470);
   }
   else
   {setlinestyle(0,0,3);
   setcolor(BLACK);
   rectangle(498,398,600,470);
   }
   showmouse();
   if( button & 1 == 1 )
    {
     if(x>=500 && y>=405 && x<=600 && y<=430)
     {option=1;
     break;}
     if(x>=500 && y>=440 && x<=600 && y<=470)
     {option=0;
     break;}
    }
}
return option;
}

void send_friend_request()
{
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
 int flag=0;
 temp_file.open(filename,ios::in | ios::binary);
 if(temp_file)
 {
 int second_userid;
 temp_file>>second_userid;
 while(!temp_file.eof())
  {if(second_userid==user_id);
   else
   { person.output();
     cout<<"\n\n";
     flag=1;
   }
   temp_file>>second_userid;
  }//inner while
 }      //if temp file exists
 else
 {flag=1;}
 temp_file.close();
  send_req.read((char*)&person,sizeof(person));
 }//outer while
 send_req.close();

 if(flag==1)
 {cout<<"\n\n\nTO WHOM WOULD YOU LIKE TO SEND REQ:(USERID) ";
 cin>>to_whom_friend_request;
 fstream allusers;
 strcpy(filename,per_filepath);
 strcat(filename,"account.dat");
 allusers.open(filename,ios::app | ios::binary);
 allusers.read((char*)&person,sizeof(person));
 int temp_flag=0;
 while(temp_flag!=1 || !allusers.eof())
 { if(person.return_userid==to_whom_friend_request)
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
       person.return_username();
       break;
      }
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
     send_request();
 }
 else if(flag==0)
 {cout<<"NONE AVAILABLE TO PERFORM THIS OPERATION";}



}

void  send_request()
{
strcpy(filename,per_filepath);
strcat(filename,"friend_request\\");
strcat(filename,global_username);
strcat(filename,".dat");
fstream write_to_his_file;
write_to_his_file.open(filename,ios::app | ios::binary);
write_to_his_file<<current_user.return_userid();
write_to_his_file.close();
}



















