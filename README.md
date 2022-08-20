

To run, build project by running `make` which produces executable. Because I have a custom location for my sfml library, i need to set it by running `export LD_LIBRARY_PATH=/usr/local/lib`


# TODO

- [ ] Draw Window to screen
- [ ] Draw Square to screen
- [ ] Use user input to make square move


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


