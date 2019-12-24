#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>

char temp_filename[20];
char per_filename[10]={"f:\\proj\\"};
struct captcha
{
  char cap_name;
  char cap_code[5];
}tcapt;
captcha capt[26]={
	   {'a',"VE2E3"},
	   {'b',"WR64S"},
	   {'c',"RM3KS"},
	   {'d',"2V5VH"},
	   {'e',"SUCFX"},
	   {'f',"ZZZ8H"},
	   {'g',"4Z5P3"},
	   {'h',"H4TC6"},
	   {'i',"J5CV8"},
	   {'j',"JEE9H"},
	   {'k',"HPW5G"},
	   {'l',"TC845"},
	   {'m',"EVJWM"},
	   {'n',"S2KY8"},
	   {'o',"XF2K2"},
	   {'p',"KHP5S"},
	   {'q',"PCHED"},
	   {'r',"UJFCB"},
	   {'s',"43EX5"},
	   {'t',"RP2C6"},
	   {'u',"EBTKF"},
	   {'v',"GYR35"},
	   {'w',"EKYBJ"},
	   {'x',"EWCJ8"},
	   {'y',"MSYPV"},
	   {'z',"UVZ33"}

	 };

void main()
{
strcpy(temp_filename,per_filename);
strcat(temp_filename,"captcha.dat");
fstream file;
file.open(temp_filename,ios::out | ios::binary);
for(int i=0;i<26;i++)
{
file.write((char*)&capt[i],sizeof(capt[i]));
cout<<"successfull";
}
file.close();

}
