#include "Bat.h"// include the bat class header

Bat::Bat(float startX, float startY)
{
	m_Position.x=startX;	//Set the horizontal position
	m_Position.y=startY;	//Vertical position
	
	m_Shape.setSize(sf::Vector2f(200,20));	// create a rectangle (200px wide, 20px tall)
	m_Shape.setPosition(m_Position);	//Set bat's position
}
	
FloatRect Bat::getPosition()
{
	return m_Shape.getGlobalBounds();// return rectangle bounds for collisions
}

RectangleShape Bat::getShape()
{
	return m_Shape;// return the shape to draw it on screen
}

void Bat::moveLeft()
{
	m_movingLeft=true;// enable left movement
}

void Bat::moveRight()
{
	m_movingRight=true;// enable right movemen
}

void Bat::stopLeft()
{
	m_movingLeft=false;// stop left movement
}

void Bat::stopRight()
{
	m_movingRight=false;// stop right movement
}

void Bat::update(Time dt)
{
	if(m_movingLeft)
	{
		m_Position.x-=m_Speed*dt.asSeconds();	//moves left (speed × time)
	}
	if(m_movingRight)
	{
		m_Position.x+=m_Speed*dt.asSeconds();	//moves right
	}
	m_Shape.setPosition(m_Position);// update bat’s position
}
