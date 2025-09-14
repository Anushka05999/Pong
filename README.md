# Pong Game (C++ & SFML)

A simple **Pong clone** built using **C++ and SFML**.  
This project was created to practice **object-oriented programming**, **game loops**, and **SFML graphics**.

---

Features
  - **Bat & Ball classes** with encapsulated logic  
  -**Score and Lives HUD**
  -**Pause functionality** (press `Space`)  
  -**Game Over screen** when lives run out  
  -Ball **bounces off walls, top, and bat**  
  -Ball **resets above the bat** when missed  
  -Ball **speeds up** every time it hits the bat  
  -**Frame-independent movement** using delta time

Controls
  ← Move bat left
  → Move bat right
  Space Pause/Unpause
  Esc Quit game

  
Installation & Run
  1. Prerequisites
      C++ compiler (MinGW or g++)
      SFML 2.5+
  2. Build & Run
      g++ pong.cpp Bat.cpp Ball.cpp -o pong -lsfml-graphics -lsfml-window -lsfml-system
      ./pong

Project Structure
      pong-game/
      │── Bat.h
      │── Bat.cpp
      │── Ball.h
      │── Ball.cpp
      │── pong.cpp   # main game loop
      │── font/      # fonts used in game
      │── screenshots/ (optional for README images)
      │── README.md


Future Improvements
  Add sound effects on bounce and scoring
  Add two-player mode
  Add different levels or increasing difficult
