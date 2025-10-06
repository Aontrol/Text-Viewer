# Simple Terminal Text Viewer in C++ (with ncurses)

This project is a basic terminal-based text file viewer built in C++ using the `ncurses` library. It allows users to open and scroll through a text file inside a terminal window with a simple interface and keyboard controls.

## Features

- Load and display text files line by line  
- Scroll up and down using arrow keys  
- Simple status bar showing file name and quit instructions  
- Automatically handles window resizing  
- Quit with `Ctrl + Q`

## Requirements

To compile and run this program, you need:

- A C++ compiler (e.g., `g++`)
- The `ncurses` library installed on your system

### Installing ncurses (Ubuntu/Debian)

```bash
sudo apt install libncurses5-dev libncursesw5-dev
