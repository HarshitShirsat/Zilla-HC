//function to draw the graphicvs for the login,signup option page
void login_signup_graphics()
{
   setcolor(YELLOW);
   rectangle(200,200,400,250);
   rectangle(205,205,395,245);

   rectangle(200,300,400,350);
   rectangle(205,305,395,345);
   setcolor(RED);
   settextstyle(0,0,2);
   outtextxy(250,225,"LoGiN");
   outtextxy(250,325,"SiGn Up");
   rectangle(600,10,630,30);
   outtextxy(610,13,"X");
}