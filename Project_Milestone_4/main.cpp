#include <SFML/Graphics.hpp>
#include <time.h>
#include "snake.h"
#include "Board.h"
#include "Events.h"
using namespace sf;


int N,M,size,w,h;

int main()
{
    Board B;
    Snake S;
    B.innitialize_board();
    S.innitialize_snake();
    S.Set_Board_Parameters(B.Return_M(),B.Return_N());


    N = B.Return_N();
    M = B.Return_M();
    size = B.Return_Size();
    w = B.Return_w();
	h = B.Return_h();

	srand(time(0));
    //produces the first segment at this location every time

    //the actual running of the game

    Game_Events(N,M,size,w,h,B,S);

    return 0;
}



