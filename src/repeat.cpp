#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;

int main(int ac, char** av) {
	SoundBuffer buf;
	buf.loadFromFile("/home/zeta/Music/app.wav");
	Sound sound;
	sound.setBuffer(buf);
//	sound.play();//ending alarm

//	VideoMode vm{1280, 720};
	RenderWindow window({1280, 720}, "Hello", sf::Style::Default);
	window.setFramerateLimit(60);
	Texture texture;
	texture.loadFromFile("../opencv/Lenna.png");
	Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(250, 250);
	int x=250, y=250;
	float r = 0;

	Font font, font2;
	font2.loadFromFile("/usr/lib/ruby/2.5.0/rdoc/generator/template/darkfish/fonts/SourceCodePro-Bold.ttf");
	font.loadFromFile("/usr/share/fonts/truetype/nanum/NanumSquareL.ttf");
	Text text{"Hello World!", font2, 80};
	text.setPosition(20, 20);
	text.setFillColor({255, 0, 0, 125});
	text.setStyle(Text::Bold);
	text.setOutlineThickness(2);
	text.setOutlineColor({0, 255, 0, 255});

	while(window.isOpen()) {
		if(Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
		else if(Keyboard::isKeyPressed(Keyboard::Right)) x++;
		else if(Keyboard::isKeyPressed(Keyboard::Left)) x--;
		else if(Keyboard::isKeyPressed(Keyboard::Up)) y--;
		else if(Keyboard::isKeyPressed(Keyboard::Down)) y++;
		else if(Keyboard::isKeyPressed(Keyboard::Return)) sprite.rotate(1);
		
		sprite.setPosition(x, y);
		window.clear();
		window.draw(sprite);
		window.draw(text);
		window.display();
	}
}


