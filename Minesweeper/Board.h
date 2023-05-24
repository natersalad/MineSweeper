#pragma once
#include "Tile.h"
#include <vector>
#include <fstream>
#include "TextureLoader.h"
#include <iostream>
#include <time.h>

using namespace std;

struct Board : Drawable
{
	bool debug = false;
	bool gameOver = false;
	int mines, len, wid, flags;

	vector<vector<Tile>> tiles;

	Board(int, int, int, TextureLoader _textures);

	Board(ifstream&, TextureLoader _textures);

	virtual void draw(RenderTarget& target, RenderStates states) const;

	void onTileLeftClick(int, int);

	void onTileRightClick(int, int);

};