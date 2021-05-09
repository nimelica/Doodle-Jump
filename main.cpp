#include <SFML/Graphics.hpp>
#include <time.h>

using namespace std;
using namespace sf;

struct point
{
	int x, y;
};

//Global variables for the position of ninja doodle
int x = 100, y = 100;
int h = 200;
double dx = 0, dy = 0;

void keyboardControl(Event& event)
{
	if (event.type == event.KeyPressed)
	{
		if (event.key.code == Keyboard::Right)
			x++;
		if (event.key.code == Keyboard::Left)
			x--;
	}
}
void mouseControl(Event& event)
{

}

int main()
{
	srand(time(0));

	ContextSettings settings;
	settings.antialiasingLevel = 8; //pixel setting

	RenderWindow app(VideoMode(400, 533), "Doodle Game!");
	app.setFramerateLimit(60);

	Texture background, platform, ninja;
	background.loadFromFile("desert.jpg");
	platform.loadFromFile("platform.png");
	ninja.loadFromFile("doodle.png");

	background.setSmooth(true);
	platform.setSmooth(true);
	ninja.setSmooth(true);

	Sprite sBackground(background), sPlat(platform), sPers(ninja);

	sPlat.setColor(Color::Red);

	point plat[20];

	for (int i = 0; i < 10; i++)
	{
		plat[i].x = rand() % 400;
		plat[i].y = rand() % 533;
	}

	while (app.isOpen())
	{
		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
		}

		dy += 0.2;
		y += dy;

		if (y > 500) //remember our y is 533 in window setting 
		{
			//--dy;
			dy = -10;
		}

		keyboardControl(e);

		sPers.setPosition(x, y);

		app.draw(sBackground);
		app.draw(sPers);
		for (int i = 0; i < 10; i++)
		{
			sPlat.setPosition(plat[i].x, plat[i].y);
			app.draw(sPlat);
		}

		app.display();
	
	}

	return 0;
}

