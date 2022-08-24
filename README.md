

To run, build project by running `make` which produces executable. Because I have a custom location for my sfml library, i need to set it by running `export LD_LIBRARY_PATH=/usr/local/lib`. 

Goal : Try to come up with game engine without referring to existing game engine code.


# TODO

- [x] Draw Window to screen
- [x] Draw Square to screen
- [x] Use user input to make square move
- [ ] Collision Detection
  - [X] Basic
  - [ ] Fix Bugs
- [x] Draw TileMap
  - [x] Add texture to TileMap
- [ ] Allow character to move to other parts of Map
 

# DAY 1

Finding a library to provide API to draw stuff to screen

### Options
 
LibX11 - Archiac
Directly Interfacing with OpenGL -> too involved
GLFW
SFML - Simplier, more community support


# Day 2
Abstract out and create character
- Created character
- Created tilemap

need to do collision detection.

# Day 3

Very basic collision detection algorithm. Using the library's [globalbounds object](https://www.sfml-dev.org/tutorials/2.5/graphics-transform.php) after each movement we check whether the movement will cause 2 opaque objects to intersect. If intersect we reverse this movement.

# Day 4
Refactored code alittle + added some texture for background

# Day 5
Aim : Allow character to explore other areas of map.

Currently map fits screen just nice, but in reality maps will be much larger then screen. viewpoint should update automatically when character moves past certain boundaries.

solutions:
1. when character "moves", the world moves instead, keeping character as center piece.
   - Easier to implement.
   - More work to be done to properly seperate concerns (Map will now need to know that character exists)
2. create a `cameraview` abstraction which contains the current x,y position of the camera and the size of the camera view.
   - More flexible.


