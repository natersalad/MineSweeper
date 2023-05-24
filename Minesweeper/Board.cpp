#include "Board.h"



Board::Board(int _mines, int _len, int _wid, TextureLoader _textures)
{
	srand(time(NULL));
	mines = _mines;
	len = _len;
	wid = _wid;
	flags = 0;
	vector<vector<Tile>> _tiles(len, vector<Tile>(wid));
		
	for (int i = 0; i < mines; i++)
	{
		int x = rand() % len;
		int y = rand() % wid;
		if (_tiles[x][y].value != TileValue::mine)
		{
			_tiles[x][y] = Tile(x, y, TileValue::mine, _textures);
		}
		else
		{
			i--;
		}
			
	}

	for(int i = 0; i < len; i++)
		for (int j = 0; j < wid; j++)
		{
			int n = 0;
			if (_tiles[i][j].value == TileValue::mine) continue;
			if (i + 1 < len && _tiles[i+1][j].value == TileValue::mine) n++;
			if (j + 1 < wid && _tiles[i][j+1].value == TileValue::mine) n++;
			if (i > 0 && _tiles[i-1][j].value == TileValue::mine) n++;
			if (j > 0 && _tiles[i][j-1].value == TileValue::mine) n++;
			if (i + 1 < len && j + 1 < wid && _tiles[i+1][j+1].value == TileValue::mine) n++;
			if (i > 0 && j + 1 < wid && _tiles[i-1][j+1].value == TileValue::mine) n++;
			if (i + 1 < len && j > 0 && _tiles[i+1][j-1].value == TileValue::mine) n++;
			if (i > 0 && j > 0 && _tiles[i-1][j-1].value == TileValue::mine) n++;
			_tiles[i][j] = Tile(i, j, TileValue(n), _textures);
		}
	tiles = _tiles;
}

Board::Board(ifstream&, TextureLoader _textures)
{

}

void Board::draw(RenderTarget& target, RenderStates states) const
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < wid; j++)
		{
			target.draw(tiles[i][j], states);
		}
	}
}

void Board::onTileLeftClick(int, int)
{
}

void Board::onTileRightClick(int, int)
{
}


