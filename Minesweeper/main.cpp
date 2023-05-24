
#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Tile.h"
#include "TextureLoader.h" 
#include "Board.h"

using namespace std;
using namespace sf;



int main()
{
	TextureLoader textures;

	ifstream file;
	file.open("boards/config.cfg");
	int len, wid, mines;
	string temp;
	getline(file, temp);
	len = stoi(temp);
	getline(file, temp);
	wid = stoi(temp);
	getline(file, temp);
	mines = stoi(temp);

	RenderWindow window;
	window.create(VideoMode(400, 400), "Nathan's Minesweeper");

	Board board(10, 10, 10, textures);
	
	while (window.isOpen())
	{
		window.clear(Color::White);
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case Event::Closed:
					window.close();
					break;
				case Event::KeyPressed:
					if (event.key.code == Keyboard::Escape)
					{
						window.close();
						break;
					}

			}
			
		}
		window.draw(board);
		window.display();
	}






	return 0;
}