#include "Ball.h"
using namespace sf;
Ball::Ball(float startX,float startY)
{
	m_Position.x=startX;// set starting x
	m_Position.y=startY;// set starting y
	
	m_Shape.setRadius(10);	// ball radius = 10px
	m_Shape.setPosition(m_Position);// place ball at position
}
FloatRect Ball::getPosition()
{
	return m_Shape.getGlobalBounds();// return boundary for collisions
}
CircleShape Ball::getShape()
{
	return m_Shape;// return shape for rendering
}
void Ball::reboundSides()
{
	m_DirectionX=-m_DirectionX; // reverse horizontal direction
}
void Ball::reboundBatOrTop()
{
	m_DirectionY=-m_DirectionY;// reverse vertical direction
	m_Speed *= 1.05f; // increase speed by 5%
}
void Ball::reboundBottom()
{
	m_Position.x=910;// reset x position (middle)
	m_Position.y=0;// reset y position (top)
	m_DirectionY=-m_DirectionY;// reverse direction
}
void Ball::update(Time dt)
{
	// move ball using speed × direction × time
	m_Position.x+=m_DirectionX*m_Speed*dt.asSeconds();
	m_Position.y+=m_DirectionY*m_Speed*dt.asSeconds();
	m_Shape.setPosition(m_Position);
	// update ball’s shape position
}
	
