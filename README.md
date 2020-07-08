# FDF
FDF is a project from [Codam](https://www.codam.nl). This is a 2 person project about creating a simplified graphic “wireframe” (“fils de fer” in french, hence the name of the project) representation of a relief landscape linking various points (x, y, z) via segments. The coordinates of this landscape are stored in a file passed as a parameter to the program. It also allows you to learn and use the graphic library miniLibX. 

In order to draw the individual lines, or wires if you will, we utilised a slightly altered version of the [Bresenham Algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm).

This project is written in C and made to work on: MacOS.

## Compiling
Run ```make```, an executables called ```fdf``` should compile directly.

## Challenge
#### For FDF:
The goal is to create three types of graphic, wireframe projections from the coordinates of a landscape stored in a file passed as a parameter to the program. Each number inside the file corresponds to a point in space:
- The horizontal position corresponds to its axis.
- The vertical position corresponds to its ordinate.
- The value corrseponds to its altitude.

## Bonus
We added multiple extra's to the project as a bonus:
- Change type of projection inside the window.
- Create a standard color alteration changed by the height of a coordinate.
- Allow the user to add a color themselves to the coordinate inside the map.
- Control/move the wireframe 3-Dimensionally.
- Auto Zoom.
- Reset the Rotation.
- An integrated UI showing the user the keybindings to control the wireframe.

## Usage
After creating the executable file, ```fdf```, it can be executed by giving it a file with coordinates as parameter e.g.:

```$>cat test_maps/42.fdf```
```
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
$>
```

```./fdf test_maps/42.fdf```

In this case, the output looks like shown below. 

<img src="images/fdf.png" width="600"></img>

This and other example maps can be found inside the folder test_maps.

- To zoom out the wireframe projection, move the scrolling wheel of the mouse upwards.
- To zoom in, move the scrolling wheel of the mouse downwards.
- To rotate the wireframe projection you can either left click the mouse and drag.
- Or you can use the ```arrow keys``` to rotate on the x and y axis, and ```page up``` and ```page down``` for the z axis.
- To change projection you can press the ```spacebar```. To reset the projection to its origin press ```r```.
- Press the ```esc``` button or close the window to exit the program.

## Challenge
Allowed functions for the mandatory part are
- ```open```, ```read```, ```write```, ```close```
- ```malloc```, ```free```
- ```perror```, ```strerror```
- ```exit```
- All the functions defined in the ```math``` library (-lm and man 3 math)
- All the functions defined in the ```miniLibX``` library
