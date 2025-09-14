#include "Ball.h"
using namespace sf;
Ball::Ball(float startX,float startY){
	m_Position.x=startX;
	m_Position.y=startY;	
	
	m_Shape.setRadius(10);	
	m_Shape.setPosition(m_Position);
}
FloatRect Ball::getPosition(){
	return m_Shape.getGlobalBounds();}
CircleShape Ball::getShape(){
	return m_Shape;
	}
void Ball::reboundSides(){
	m_DirectionX=-m_DirectionX;
	}
void Ball::reboundBatOrTop(){
	m_DirectionY=-m_DirectionY;
	m_Speed *= 1.05f; // increase speed by 5%
	}
void Ball::reboundBottom(){
	m_Position.x=910;
	m_Position.y=0;
	m_DirectionY=-m_DirectionY;
	}
void Ball::update(Time dt){
	m_Position.x+=m_DirectionX*m_Speed*dt.asSeconds();
	m_Position.y+=m_DirectionY*m_Speed*dt.asSeconds();
	m_Shape.setPosition(m_Position);
	}
	
