//draws the image  at the specified position
void Loadimg(char path[50],int x=0,int y=0)
{
fstream file;
char ch;
file.open(path, ios ::in | ios::binary );
if(file)
 {
  file.get(ch);
  int i=x,j=y,l,b;
   while( !file.eof() )
   {
     if(ch=='%')
     {
      j++;
      i=x;
      file.get(ch);
      continue;
     }
    putpixel(i,j,(int)(ch));
    file.get( ch );
    i++;
   }
}
else
  {cout<<"FILE NOT FOUND !";}
file.close();
}

//accepts  the parameters for the image to be drawn
void dis_img(char filename[50],int x1,int y1)
{ char fil_path[50];
strcpy(fil_path,directory);
strcat(fil_path,filename);
strcat(fil_path,".txt");
Loadimg(fil_path,x1,y1);
}