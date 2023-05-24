#include "TextureLoader.h"


TextureLoader::TextureLoader()
{

	mine.loadFromFile("images/mine.png");

	flag.loadFromFile("images/flag.png");

	open.loadFromFile("images/tile_revealed.png");

	closed.loadFromFile("images/tile_hidden.png");

	one.loadFromFile("images/number_1.png");

	two.loadFromFile("images/number_2.png");

	three.loadFromFile("images/number_3.png");

	four.loadFromFile("images/number_4.png");

	five.loadFromFile("images/number_5.png");

	six.loadFromFile("images/number_6.png");

	seven.loadFromFile("images/number_7.png");

	eight.loadFromFile("images/number_8.png");

	test1.loadFromFile("images/test_1.png");

	test2.loadFromFile("images/test_2.png");

	test3.loadFromFile("images/test_3.png");

	facewin.loadFromFile("images/face_win.png");

	facelose.loadFromFile("images/face_lose.png");

	facehappy.loadFromFile("images/face_happy.png");

	digits.loadFromFile("images/digits.png");

	debug.loadFromFile("images/debug.png");
}

