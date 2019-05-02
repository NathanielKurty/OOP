
#include "snake.h"
#include <time.h>
#include <SFML/Graphics.hpp>

void Snake::innitialize_snake()
{
    direction = 4;
    BodySize = 1;
    f.x = 10;
    f.y = 10;
    g[0].x = 15;
    g[0].y = 15;
}

void Snake::Set_Board_Parameters(int h,int w)
{
    M = h;
    N = w;
}

void Snake::Set_Direction(int dir)
{
    direction = dir;
}

void Snake::Set_Start_New_Segment(int w,int z)
{
    f.x = w;
    f.y = z;
}

void Snake::Set_Start_New_Hazard(int i,int w,int z)
{
    g[i].x = w;
    g[i].y = z;
}



void Snake::Tick()
 {

//controls the segments following the snake
    for (int i=BodySize;i>0;--i)
	 {
        s[i].x=s[i-1].x;
        s[i].y=s[i-1].y;
     }

//adjusts the direction of the snake
    if (direction==0) s[0].y+=1;
    if (direction==1) s[0].x-=1;
    if (direction==2) s[0].x+=1;
    if (direction==3) s[0].y-=1;

//adds new segment to snake and spawns new
	if ((s[0].x==f.x) && (s[0].y==f.y))
      {
        BodySize++;
    	f.x=rand() % N;
        f.y=rand() % M;
        for (int i=0;i<BodySize;i++)
        {
            g[i].x=rand() % N;
            g[i].y=rand() % M;
        }
      }





//allows snake to go to opposite side
    if (s[0].x>N)
        s[0].x=0;
    if (s[0].x<0)
        s[0].x=N;
    if (s[0].y>M)
        s[0].y=0;
    if (s[0].y<0)
        s[0].y=M;

//controls the snake hitting itself (changed to num = i -1 so it would be single segment after hit)
    for (int i=1;i<BodySize;i++)
    {
        if (s[0].x==s[i].x && s[0].y==s[i].y)
            BodySize=1;//now it sets you back to one if you hit yourself
//controls the hazard portion
        if ((s[0].x==g[i].x) && (s[0].y==g[i].y))
      {
        BodySize = 1;
        f.x=rand() % N;
        f.y=rand() % M;
    	g[0].x=rand() % N;
        g[0].y=rand() % M;
      }
    }


 }
