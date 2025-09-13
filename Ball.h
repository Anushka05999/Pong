#include <SFML/Graphics.hpp>
using namespace sf;
class Ball{
	Vector2f m_Position;
	CircleShape m_Shape;
	
	float m_Speed=2000.0f;
	float m_DirectionX=0.2f;//ball moves to tha right
	float m_DirectionY=0.2f;//ball moves downward
	public:
		Ball(float startX,float startY);
		FloatRect getPosition();
		CircleShape getShape();
		

		void reboundSides();//called whwn the ball hits the left or right wolls
		void reboundBatOrTop();//called when the ball hits the bat or top of the screen;change the vertical direction
		void reboundBottom();//called when the ball misses the bat and hits the bottom;resests the ball(player loses a life)
		void update(Time dt);//update its position
		
		};
