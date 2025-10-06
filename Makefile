all:
	clear
	g++ -static -static-libstdc++ -static-libgcc text_viewer.cpp -o text_viewer -lncurses -ltinfo
	./text_viewer


