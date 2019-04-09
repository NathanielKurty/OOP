
#ifndef SNAKE_HPP
#define SNAKE_HPP



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

//height and width of board for snake purposes
int M,N;

public:

//for direction changing
void Set_Direction(int);
//sets height and width
void Set_Board_Parameters(int,int,int);

//sets the starting point of the snake
void Set_Start_New_Segment(int,int);

//returns the segment values
int Return_Snake_X(int i){return s[i].x;}
int Return_Snake_Y(int i){return s[i].y;}
int Return_New_Segment_X(){return f.x;}
int Return_New_Segment_Y(){return f.y;}

int Return_Body_Size(){return BodySize;}


//deals with the logic of the snake
void Tick();


};

void Snake::Set_Board_Parameters(int h,int w, int body)
{
    M = h;
    N = w;
    BodySize = body;
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
        std::cout<< "body count " << BodySize << std::endl;
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
    }

 }

#endif
