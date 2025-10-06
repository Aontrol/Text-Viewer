Simple Terminal Text Viewer in C++ (with ncurses)

This project is a basic terminal-based text file viewer built in C++ using the ncurses library. It allows users to open and scroll through a text file inside a terminal window with a simple interface and keyboard controls.

Features

Load and display text files line by line

Scroll up and down using arrow keys

Simple status bar showing file name and quit instructions

Automatically handles window resizing

Quit with Ctrl + Q

Screenshot

(Include a screenshot here if desired — capture the terminal while the viewer is running.)

Requirements

C++ compiler (e.g., g++)

ncurses library installed

On Ubuntu/Debian:
sudo apt install libncurses5-dev libncursesw5-dev

Usage
Compile:
g++ -o viewer viewer.cpp -lncurses

Run:
./viewer filename.txt

Controls:

↑ / ↓ – Scroll up and down

Ctrl + Q – Exit

File Structure

viewer.cpp – Main source code

scr_buf – In-memory map of line numbers to text

window – Class handling terminal initialization, printing, and the status bar

Note

This project is a minimal implementation aimed at learning and experimenting with ncurses and terminal-based UI design in C++. It's ideal as a base for building a full text editor or pager like less.
