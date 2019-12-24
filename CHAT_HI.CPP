void chat_hist()
{  char with[50];
   fstream myfile;
   strcpy(filename,per_filepath);
   current_user.return_username();
   strcat(filename,global_username);
   strcat(filename,"_");
   cout<<"With Whom:";
   gets(with);
   strcat(filename,with);
   strcat(filename,".txt");
   clrscr();
   cleardevice();
   cout<<"\n\n";
   char ch;
   if(myfile)
   {
   myfile.open(filename,ios::out | ios::binary);
   file.get(ch);
   while(!file.eof())
    { cout<<ch;
       file.get(ch);
    }
   }
   myfile.close();
   getch();
}