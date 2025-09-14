#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "Bat.h"
#include "Ball.h"

using namespace sf;

int main() {
    // Define a window
    VideoMode vm(1920, 1080);

    // Create a window
    RenderWindow window(vm, "Pong Game", Style::Fullscreen);

    View view(FloatRect(0, 0, 1920, 1080));
    window.setView(view);

    bool isPaused = false;
    bool isOver = false;

    int score = 0;
    int lives = 3;

    Bat bat(900, 1000);
    Ball ball(960, 500); // start in middle

    // HUD setup
    Text hud;
    Font font;
    font.loadFromFile("font/KOMIKAP_.ttf");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setFillColor(Color::White);
    hud.setPosition(20, 10);

    // Game Over text
    Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(100);
    gameOverText.setFillColor(Color::Red);
    gameOverText.setPosition(700, 500);
    gameOverText.setString("GAME OVER !!!");

    Clock clock;

    // Gaming loop
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {
                    window.close();
                }
                if (event.key.code == Keyboard::Space && !isOver) {
                    isPaused = !isPaused;
                }
            }
        }

        // If game is over, stop updating
        if (isOver) {
            window.clear();
            window.draw(gameOverText);
            window.display();
            continue; // skip the rest
        }

        // Handle movement keys
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            bat.moveLeft();
        } else {
            bat.stopLeft();
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            bat.moveRight();
        } else {
            bat.stopRight();
        }

        // Ball collision checks
        if (ball.getPosition().left < 0 || 
            ball.getPosition().left + ball.getPosition().width > 1920) {
            ball.reboundSides();
        }

        if (ball.getPosition().top < 0) {
            ball.reboundBatOrTop();
        }

        if (ball.getPosition().intersects(bat.getPosition())) {
            ball.reboundBatOrTop();
            score++;
            // Increase difficulty by speeding up the ball
            // (You can also add this inside Ball class if you prefer)
        }

        if (ball.getPosition().top > 1080) {
            // Reset above the bat
            FloatRect batBounds = bat.getPosition();
            ball = Ball(batBounds.left + batBounds.width / 2, batBounds.top - 30);
            lives--;

            if (lives < 1) {
                isOver = true;
                lives = 0;
            }
        }

        // Update game objects
        Time dt = clock.restart();
        if (!isPaused) {
            bat.update(dt);
            ball.update(dt);
        }

        // HUD update
        std::stringstream ss;
        ss << "Score: " << score << "\nLives: " << lives;
        hud.setString(ss.str());

        // Draw
        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.draw(ball.getShape());

        if (isPaused) {
            Text pause;
            pause.setFont(font);
            pause.setCharacterSize(75);
            pause.setFillColor(Color::White);
            pause.setString("Paused");
            pause.setPosition(850, 540);
            window.draw(pause);
        }

        window.display();
    }
}
