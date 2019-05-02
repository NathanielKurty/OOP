#ifndef BOARD.H
#define BOARD.H




class Board{

private:
int N,M,Size,w,h;

public:

void innitialize_board();

int Return_N(){return N;}
int Return_M(){return M;}
int Return_Size(){return Size;}
int Return_w(){return w;}
int Return_h(){return h;}

};

#endif
