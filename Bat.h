#include<SFML/Graphics.hpp>// include SFML graphics module
using namespace sf;//allows using SFML classes directly (e.g., Vector2f, RectangleShape)
 class Bat{
  
private:
          Vector2f m_Position; // stores x, y position of the bat
          RectangleShape m_Shape;// rectangle representing the bat
          float m_Speed=600.0f; // bat movement speed in pixels per second
          bool m_movingRight=false; // flag to check if bat is moving right
          bool m_movingLeft=false;// flag to check if bat is moving left
          
public:
        Bat(float startX,float startY);  // constructor (initializes bat position and shape)
        
         FloatRect getPosition();// returns bat boundary box for collision detection
         RectangleShape getShape();// returns bat shape for rendering
         
         void moveLeft(); // sets left movement flag
         void moveRight(); // sets right movement flag
         void stopLeft();// clears left movement flag
         void stopRight();// clears right movement flag
         void update(Time dt);// updates bat’s position using delta time
         };
