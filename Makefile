# SFML is made of 5 modules (system, window, graphics, network and audio), and there's one library for each of them.
# To link an SFML library, you must add "-lsfml-xxx" to your command line, for example "-lsfml-graphics" for the graphics module 

all:
	g++ src/*.cpp -o app -lsfml-graphics -lsfml-window -lsfml-system -g -std=c++11
