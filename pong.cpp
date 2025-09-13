#include <SFML/Graphics.hpp>
#include<sstream>
#include<iostream>
#include "Bat.h"
#include"Ball.h"
using namespace sf;

int main(){

	//Define a window
	VideoMode vm(1920,1080);

	//Create a window
	RenderWindow window(vm, "Pong Game", Style::Fullscreen);

	View view(FloatRect(0,0,1920,1080));         //Calculates the coordinates according to the main resolution
	window.setView(view);
	
	bool isPaused=false;
	bool isover=false;
	
	int score=0;
	int lives=3;

	Bat bat(900, 1000);
	Ball ball(910,0);
	
	Text hud;
	Font font;
	font.loadFromFile("font/KOMIKAP_.ttf");
	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(Color::White);
	hud.setPosition(20,10);
	Text obj;
	obj.setFont(font);
	obj.setCharacterSize(75);
	obj.setFillColor(Color::White);
	obj.setPosition(450,540);

	Clock clock;

	//Gaming loop
	while(window.isOpen()){
		Event event;
		while(window.pollEvent(event)){
			if(event.type==Event::Closed){
				window.close();
			}
		}
		if(Keyboard::isKeyPressed(Keyboard::Escape)){
			window.close();
		}

		if(Keyboard::isKeyPressed(Keyboard::Left)){
			bat.moveLeft();
		}
		else{
			bat.stopLeft();
		}

		if(Keyboard::isKeyPressed(Keyboard::Right)){
			bat.moveRight();
		}
		else{
			bat.stopRight();
		}
		if(ball.getPosition().left<0 || ball.getPosition().left + ball.getPosition().width>1920){
			ball.reboundSides();
			}
		if(ball.getPosition().top<0){
			ball.reboundBatOrTop();
			}

		if(ball.getPosition().intersects(bat.getPosition())){
			ball.reboundBatOrTop();
			score++;
			}
		if(ball.getPosition().top>1080){
			ball.reboundBottom();
			lives--;
			if(lives < 1){
				if(lives < 1){
					std::stringstream s;
					s << "Game Over!!!";
					obj.setString(s.str());
					isover = true; // ✅ Mark the game as over
					lives=0;
				}

				}

			}
		if(Keyboard::isKeyPressed(Keyboard::Space)){
			isPaused=!isPaused;
			}

		Time dt=clock.restart();	//update the delta time
		if(!isPaused && !isover){
			bat.update(dt);
			ball.update(dt);
			}

		
		
		std::stringstream ss;
		ss<<"Score: "<<score<<"\nLives: "<<lives;
		hud.setString(ss.str());

		//Draw
		window.clear();
		window.draw(hud);
		window.draw(obj);
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		if(isPaused){
			Text pause;
			pause.setFont(font);
			pause.setCharacterSize(75);
			pause.setFillColor(Color::White);
			pause.setString("Paused");
			pause.setPosition(900,540);
			window.draw(pause);
			}
		window.display();
		}
		}
