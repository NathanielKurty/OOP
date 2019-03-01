

#include <SFML/Graphics.hpp>
#include <time.h>
#include "snake.h"
#include "Board.h"

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

    RenderWindow window(VideoMode(w, h), "Snake Game!");

	Texture t1,t2;
	t1.loadFromFile("images/white.png");
	t2.loadFromFile("images/red.png");

	Sprite sprite1(t1);
	Sprite sprite2(t2);

    //delay controls the speed of the game (0.1 is default, lower this to increase speed or increase to lower speed)
	Clock clock;
    float timer=0, delay=0.1;

    //produces the first segment at this location every time

    //the actual running of the game
    while (window.isOpen())
    {
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
        timer+=time;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) S.Set_Direction(1);
	    if (Keyboard::isKeyPressed(Keyboard::Right))  S.Set_Direction(2);
	    if (Keyboard::isKeyPressed(Keyboard::Up)) S.Set_Direction(3);
		if (Keyboard::isKeyPressed(Keyboard::Down)) S.Set_Direction(0);

		if (timer>delay) {timer=0; S.Tick();}

   ////// draw  ///////
    window.clear();

    for (int i=0; i<N; i++)
	  for (int j=0; j<M; j++)
		{ sprite1.setPosition(i*size,j*size);  window.draw(sprite1); }

	for (int i=0;i<S.Return_Body_Size();i++)
	    {
	    sprite2.setPosition(S.Return_Snake_X(i)*size, S.Return_Snake_Y(i)*size);
	    window.draw(sprite2);
	    }


	sprite2.setPosition(S.Return_New_Segment_X()*size,S.Return_New_Segment_Y()*size);
	window.draw(sprite2);

	window.display();
	}

    return 0;
}
