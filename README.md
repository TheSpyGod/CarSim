# Simple Grid-Based Game Demo / Prosta gra siatkowa 2D

## English Version

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


# Prosta gra siatkowa 2D

## Polish Version

## Opis

Minimalna gra 2D oparta na siatce, napisana w **C++** z użyciem **Raylib**.  
Gracz porusza się po siatce, w której losowo rozmieszczone są wrogowie i przedmioty.  
Siatka przechowywana jest jako **jednowymiarowy wektor wskaźników do obiektów typu Entity**, a osobny wektor przechowuje same obiekty.

---

## Funkcje

- Ruch gracza za pomocą strzałek  
- Losowe rozmieszczenie wrogów i przedmiotów  
- Renderowanie siatki w 2D z kolorowymi prostokątami:
  - Gracz: niebieski  
  - Wróg: czerwony  
  - Przedmiot: żółty  
  - Puste pole: biały  
- Wydajna implementacja 1D siatki z mapowaniem na 2D do rysowania  

---

## Jak działa

1. Klasa `Map`: zarządza encjami, siatką, ruchem i losowym rozmieszczeniem  
2. Klasa `Draw`: rysuje siatkę za pomocą Raylib  
3. Klasa `Window`: uruchamia pętlę gry, obsługuje wejście i rysowanie sceny  
4. Interakcje gracza (wrogowie, przedmioty) obsługiwane są w `Map::moveObject()` i `Map::movePlayer()`  

---

## Sterowanie

- Strzałki: poruszanie graczem  

---

## Wymagania

- [Raylib](https://www.raylib.com/)  

---

## Kompilacja i uruchomienie

```bash
g++ -std=c++17 -lraylib -o game main.cpp
./game
