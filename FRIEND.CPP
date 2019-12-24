
//FOR FRIENDS

void see_my_friends()
{int flag_friends=0;
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
   {person.output(); cout<<"\n"; flag_friends=1;}
   file1.read((char*)&person,sizeof(person));
  }
  file>>user_id;
  file1.close();
 }
 }//if(file)
  if(!file || flag_friends==0)
 {
 settextstyle(7,0,3);
 setcolor(RED);
 outtextxy(150,200,"YOU HAVE NO FRIENDS ");
 }
 file.close();
 setlinestyle(SOLID_LINE,0,3);
 setcolor(RED);
 rectangle(10,10,630,470);
 getch();
}