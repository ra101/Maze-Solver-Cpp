ref : <a href="https://www.youtube.com/watch?v=rop0W4QDOUI">https://www.youtube.com/watch?v=rop0W4QDOUI</a>
# Maze Solver
A variety of algorithms *(DFS,BFS,Dijstra,Astar)* to solve mazes from an input image.<br>
*Light green specifies the shortest dist but we added some stops(blue marks) and the new shortest path covering all stops is formed*<br>
![maze image](https://raw.githubusercontent.com/ra101/Maze-Solver-Cpp/master/readmeExamples/%23stopsSolved.PNG)

## lib
- opencv2.4.9.1
- chrono (timing of each algorithm can be viewed)
- stl

## Input
I have copied maze images from ref, acc. to ref. these were generated either by hand, or using the software [Daedalus](http://www.astrolog.org/labyrnth/daedalus.htm). Once exported I edited the mazes to ensure that the following rules are adhered to:

## Rules
- Each maze is black and white. White represents paths, black represents walls.
- All mazes are surrounded entirely by black walls.
- One white square exists on the top row of the image, and is the start of the maze.
- One white square exists on the bottom row of the image, and is the end of the maze.
- blue spots are BGR::(255,0,0);
- there are some rule on bases of which Node are formed after forming nodes,connected are made
![maze image](https://raw.githubusercontent.com/ra101/Maze-Solver-Cpp/master/readmeExamples/Nodelist.PNG)

