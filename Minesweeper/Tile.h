#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "TextureLoader.h"

using namespace std;
using namespace sf;

enum struct TileState
{
	open, closed, flag
};

enum struct TileValue
{
	zero, one, two, three, four, five, six, seven, eight, mine
};

class Tile : public Drawable
{
	public:
		TileState state;
		TileValue value;
		TextureLoader textures;
		int x, y;
		Tile();
		Tile(int x, int y, TileValue _value, TextureLoader textures);
		void setState(TileState state);
		void setValue(TileValue value);
	private:
		virtual void draw(RenderTarget& target, RenderStates states) const;
};