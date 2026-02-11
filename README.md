# Simple Grid-Based Game Demo

Description
-----------
This is a minimal 2D grid-based game built using **C++** and **Raylib**.
The player moves on a grid populated with enemies and items.
Internally, the grid is stored as a **1D vector of pointers to entities**, while another vector stores the actual entities.

Features
--------
- Player movement using arrow keys
- Randomly placed enemies and items
- 2D grid rendering using colored rectangles:
  - Player: Blue
  - Enemy: Red
  - Item: Yellow
  - Empty cell: White
- Efficient 1D grid representation mapped to 2D for drawing

How It Works
------------
1. `Map` class: handles entities, grid, movement, and random placement
2. `Draw` class: renders the grid using Raylib
3. `Window` class: runs the game loop, captures input, and draws the scene
4. Player interactions (enemies, items) are handled in `Map::moveObject()` and `Map::movePlayer()`

Controls
--------
- Arrow keys: Move the player

Dependencies
------------
- [Raylib](https://www.raylib.com/)

Compile and Run
---------------
```bash
g++ -std=c++17 -lraylib -o game main.cpp
./game
