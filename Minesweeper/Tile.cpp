#include "Tile.h"



Tile::Tile()
{
	state = TileState::closed;
	value = TileValue::zero;
	x = 0;
	y = 0;
}

Tile::Tile(int _x, int _y, TileValue _value, TextureLoader _textures)
{
	state = TileState::open;
	value = _value;
	x = _x;
	y = _y;
	textures = _textures;
}

void Tile::setState(TileState _state)
{
	state = _state;
}

void Tile::setValue(TileValue _value)
{
	value = _value;
}

void Tile::draw(RenderTarget &target, RenderStates states) const
{
	Texture t;
	switch (state)
	{
		case(TileState::open):
		{
			Sprite open(textures.open);
			open.setPosition(x*32, y*32);
			target.draw(open, states);
			switch (value)
			{
			case(TileValue::zero):
				t = textures.open;
				break;
			case(TileValue::one):
				t = textures.one;
				break;
			case(TileValue::two):
				t = textures.two;
			case(TileValue::three):
				t = textures.three;
				break;
			case(TileValue::four):
				t = textures.four;
				break;
			case(TileValue::five):
				t = textures.five;
				break;
			case(TileValue::six):
				t = textures.six;
				break;
			case(TileValue::seven):
				t = textures.seven;
				break;
			case(TileValue::eight):
				t = textures.eight;
				break;
			case(TileValue::mine):
				t = textures.mine;
				break;
			}
			break;
		}

		case (TileState::closed):
			t = textures.closed;
			break;

		case (TileState::flag):
		{
			Sprite closed(textures.closed);
			closed.setPosition(x*32, y*32);
			target.draw(closed, states);
			t = textures.flag;
			break;
		}
			
	}
	Sprite s(t);
	s.setPosition(x*32, y*32);
	target.draw(s, states);
}
