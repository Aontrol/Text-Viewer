#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <map>

#define CTRL_Q 17
#define ESC 27
#define CTRL_I 9
#define BACKSPACE 8
#define CTRL_P 16
#define NEWLINE 10
#define CTRL_S 19

std::map<int,std::string> scr_buf;

int row_count = 0;

int cur_x = 0;
int cur_y = 0;

int win_row;
int win_col;

std::string file_name;

class window{

    public:
        window(){
            initscr();
            noecho();
            scrollok(stdscr,true);
            keypad(stdscr,true);
            raw();
            curs_set(0);
            getmaxyx(stdscr,win_row,win_col);
        }

        ~window(){
            endwin();
        }

        void print(int start,int end){
            erase();
            for(int i=start;i<row_count;i++){
                if(i < end-2){
                    cur_y = i + 1;
                    move(cur_y,0);
                    printw("%d\t|\t%s\n",i+1,scr_buf.at(i).data());
                }
                
            }
            status_bar();
            refresh();
        }

        void status_bar(){
            move(win_row-1,0);
            printw("File Name : %s",file_name.data());
            move(win_row-1,win_col-22);
            printw(" Ctrl + q for exit! ");
        }
};



int main(int argc,char **argv){
    window win;

    if(argc >= 2){
        file_name = argv[1];
    }else{
        file_name = "null";
    }

    

    std::ifstream file(file_name);

    std::string line;
    while(std::getline(file,line)){
        //line += "\n";
        scr_buf[row_count] = line;
        row_count++;
    }

    file.close();

    win.print(0,win_row);
   

    int scroll = 0;

    while(int ch = getch()){
        if(ch == CTRL_Q) break;
        if(KEY_UP == ch) scrl(-1);
        if(KEY_DOWN == ch) scrl(1);
        if(KEY_RESIZE) getmaxyx(stdscr,win_row,win_col);

        
        if(KEY_DOWN == ch) if(scroll < row_count - win_row)scroll++;
        if(KEY_UP == ch)  if(scroll > 0) scroll--;

        
        win.print(scroll,win_row+scroll);
    }

    return 0;
}