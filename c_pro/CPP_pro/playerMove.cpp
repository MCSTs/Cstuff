#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define LOG(x) std::cout << x << std::endl;


class Player {
    public:
        int x, y;
        int speed;

        void move(char act) {
            switch(act) {
                case'a' : 
                    if (x >= 2)
                        x -= speed; 
                    break;
                case'd' : 
                    if (x <= 1920)
                        x += speed; 
                    break;
                case's' : 
                    if (y >= 2)
                        y -= speed; 
                    break;
                case'w' : 
                    if (y <= 1080 )
                        y += speed; 
                    break;
                default : break;
            }
            return;
        }
};

int main(void)
{

    Player kim;
    kim.x = 0;
    kim.y = 0;
    kim.speed = 2;

    struct termios termios_p;
    struct termios term_src;
    tcgetattr(STDIN_FILENO, &termios_p);
    term_src = termios_p;
    termios_p.c_lflag &= ~ECHO;
    termios_p.c_lflag &= ~ICANON;
    

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &termios_p);

    char act;
    for (;;) {
        read(STDIN_FILENO, &act, 1);
        kim.move(act);
        LOG("x = " << kim.x); 
        LOG("y = " << kim.y); 
        //std::cout << "x = " << kim.x << std::endl; 
        //std::cout << "y = " << kim.y << std::endl; 
        LOG("");
        if (act == 'q')
            break;

    }

    //tcsetattr(STDIN_FILENO, TCSAFLUSH, &term_src);

    return 0;
}
