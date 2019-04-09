#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <time.h>


class Snake {


private:

//direction snake goes
int direction;

//size of the snake
int BodySize;

//snake itself
struct snake
{
    int x,y;
}s[100];

//new snake segment
struct New_Segment
{
    int x,y;
}f;

struct New_Hazard
{
    int x,y;
}g[100];

//height and width of board for snake purposes
int M,N;

public:

//for direction changing
void Set_Direction(int);
//sets height and width
void Set_Board_Parameters(int,int);

//sets the starting point of the snake
void Set_Start_New_Segment(int,int);

void innitialize_snake();

void Set_Start_New_Hazard(int i,int w,int z);

//returns the segment values
int Return_Snake_X(int i){return s[i].x;}
int Return_Snake_Y(int i){return s[i].y;}
int Return_New_Segment_X(){return f.x;}
int Return_New_Segment_Y(){return f.y;}
int Return_New_Hazard_X(int i){return g[i].x;}
int Return_New_Hazard_Y(int i){return g[i].y;}

int Return_Body_Size(){return BodySize;}


//deals with the logic of the snake
void Tick();


};



#endif
