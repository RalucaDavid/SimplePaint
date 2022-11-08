#include <graphics.h>
#include <windows.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int culoare(int mX,int s[],int d[])
{
    for(int i=0;i<=15;i++)
     if((s[i]<=mX)&&(mX<=d[i]))
      return i;
    return -1;
}
int marime(int mX,int mar)
{
    if((845<mX)&&(mX<=900))
          mar=70;
    else if((905<mX)&&(mX<=955))
          mar=10;
    return mar;
}
int form(int mX,int s1[],int d1[])
{
   for(int i=0;i<5;i++)
    if((s1[i]<=mX)&&(mX<=d1[i]))
      return i;
    return -1;
}
void design()
{ 
   //Design
  setfillstyle(SOLID_FILL,DARKGRAY);
  bar(0,0,GetSystemMetrics(SM_CXSCREEN),60);
  
  //Paleta de culori
  for(int i=0;i<=15;i++)
  {
      setfillstyle(SOLID_FILL,i);
      bar(50*i+10,10,50*(i+1),50);
  }
  
 
  //Butoane marime
  bar(850,10,900,50);
  setcolor(BLACK);
  line(875,15,875,45);
  line(855,30,895,30);
  bar(905,10,955,50);
  line(915,30,945,30);
  rectangle(845,5,960,55);
 
  //Buton schimbare fundal
  setcolor(WHITE);
  bar(1000,10,1050,50);
  setcolor(BLACK);
  rectangle(1010,20,1040,40); 
  line(1010,20,1040,40);
  line(1040,20,1010,40);
  rectangle(995,5,1055,55);
 
  //Butoane forma
  setcolor(WHITE);
  for(int i=0;i<5;i++)
   bar(1085+50*i+5*(i+1),10,1085+50*(i+1)+5*(i+1),50);
  setfillstyle(SOLID_FILL,BLACK);
  bar(1105,20,1125,40);
  setcolor(BLACK);
  rectangle(1160,20,1180,40);
  line(1215,20,1235,40);
  circle(1280,30,10);
  line(1335,20,1350,40);
  line(1320,40,1350,40);
  line(1320,40,1335,20);
 
  //Buton special
  setfillstyle(SOLID_FILL,WHITE);
  bar(1400,10,1450,50);
  line(1405,45,1427,28);
  setcolor(5);
  circle(1443,18,4);
  setcolor(11);
  circle(1430,26,8);
 
  //Buton inchidere
  bar(1520,10,1560,50);
  setcolor(RED);
  circle(1540,30,20);
  circle(1540,30,10);
  line(1540,30,1540,40);
 
  //Design2
  setcolor(BLACK);
  for(int i=1;i<=15;i++)
    rectangle(50*i+10,10,50*(i+1),50);
  rectangle(850,10,900,50);
  rectangle(905,10,955,50);
  rectangle(1000,10,1050,50);
  rectangle(5,5,805,55);
  rectangle(1085,5,1365,55);
  for(int i=0;i<5;i++)
    rectangle(1085+50*i+5*(i+1),10,1085+50*(i+1)+5*(i+1),50);
  rectangle(0,0,GetSystemMetrics(SM_CXSCREEN),60);
  rectangle(1395,5,1455,55);
  rectangle(1400,10,1450,50);
  rectangle(1515,5,1565,55);
 
  //Default
   setcolor(WHITE);
   setfillstyle(SOLID_FILL,WHITE);
}
int main()
{
  DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
  DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
  initwindow(screenWidth,screenHeight," ",-3,-3);
  POINT cursorPosition;
  int mX,mY,mar=10,cul=15,forma=0;
  int s[16],d[16],s1[5],d1[5];
  for(int i=0;i<=15;i++)
  {
     s[i]=50*i+10;
     d[i]=50*(i+1);
  }
  for(int i=0;i<5;i++)
  {
     s1[i]=1085+50*i+5*(i+1);
     d1[i]=1085+50*(i+1)+5*(i+1);
  }
  design();
  while(1)
  {
      GetCursorPos(&cursorPosition);
      mX=cursorPosition.x;
      mY=cursorPosition.y;
      //Butoane 
      if(mY<=60)
      {
             // Schimbare culoare
             if(((10<=mX)&&(mX<=805))&&(GetAsyncKeyState(VK_LBUTTON)))
            {
                if(culoare(mX,s,d)!=-1)
                {
                 setfillstyle(SOLID_FILL,culoare(mX,s,d));
                 setcolor(culoare(mX,s,d));
                 cul=culoare(mX,s,d);
                }
            }
             // Schimbare marime
             else if(((845<=mX)&&(mX<=960))&&(GetAsyncKeyState(VK_LBUTTON)))
                mar=marime(mX,mar);
             // Schimbare fundal 
             else if(((955<=mX)&&(mX<=1055))&&(GetAsyncKeyState(VK_LBUTTON)))
            {
                cleardevice();
                setfillstyle(SOLID_FILL,cul);
                bar(0,0,screenWidth,screenHeight);
               design();
            }
             // Schimbare forma 
             else if(((1090<=mX)&&(mX<=1360))&&(GetAsyncKeyState(VK_LBUTTON)))
               forma=form(mX,s1,d1);
             // Buton special 
             else if(((1400<=mX)&&(mX<=1450))&&(GetAsyncKeyState(VK_LBUTTON)))
               cul=16;
             else if(((1510<=mX)&&(mX<=1560))&&(GetAsyncKeyState(VK_LBUTTON)))
             {
               closegraph();
               break;
             }
      }
      // Desenare
      else if ((GetAsyncKeyState(VK_LBUTTON)))
      {
         if(forma==0)
           bar(mX-mar,mY-mar,mX+mar,mY+mar);
         else if(forma==1)
           rectangle(mX-mar,mY-mar,mX+mar,mY+mar);
         else if(forma==2)
           line(mX,mY,mX,mY+mar);
         else if(forma==3)
           circle(mX,mY,mar);
         else 
         {
            line(mX+mar,mY+mar,mX,mY-mar);
            line(mX-mar,mY+mar,mX+mar,mY+mar);
            line(mX-mar,mY+mar,mX,mY-mar);
         }
         if(mY-mar<=60)
         {
          design();
          setcolor(cul);
          setfillstyle(SOLID_FILL,cul);
         }
         if(cul==16)
         {
           setcolor(rand()%16);
           setfillstyle(SOLID_FILL,rand()%16);
         }
      }
      delay(0.1);
  }
}