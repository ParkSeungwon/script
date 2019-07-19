#include<SFML/Audio.hpp>
#include<thread>
#include<chrono>
#include<cstdlib>
#include<iostream>
using namespace std;

bool finish = false;

void get_input() {
	while(1) {
		char c;
		cin >> c;
		if(c == 'q') {
			finish = true;
			break;
		}
	}
}

int main(int ac, char** av) {
	if(ac < 2) return 0;

	cout << "enter q to finish" << endl;
	thread th{get_input};
	while(system(av[1]) && !finish);//quit
	sf::SoundBuffer buf;
	buf.loadFromFile("/home/zezeon/Programming/script/wallewal.wav");
	sf::Sound sound;
	sound.setBuffer(buf);
	sound.play();//ending alarm
	this_thread::sleep_for(4.5s);
	th.join();
}


