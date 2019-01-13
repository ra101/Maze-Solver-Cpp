#include<iostream>
#include <chrono>
#include "Node.h"
#include "maze.h"
#include "dfs.h"
#include "bfs.h"
#include "dijkstra.h"
#include "Astar.h"
using namespace std::chrono;

int UI();

int main()
{
    Maze *maze;
    char *imageName="#stops.png";
    maze=new Maze(imageName);
   system("clear");
    int switchVariable =UI();
    auto start = high_resolution_clock::now();
    switch(switchVariable)
    {
    case 1:
        maze->dfs();
        break;
    case 2:
            maze->bfs();
        break;
    case 3:
             maze->dijkstra();
        break;
    case 4:
        maze->aStar();
        break;
    default:
        std::cout<<"INVALID INPUT";
        return -1;
    }
        auto stop = high_resolution_clock::now();
 auto duration = duration_cast<microseconds>(stop - start);
    system("clear");
  switch(switchVariable)
    {
    case 1:
        std::cout<<"+ Depth First Search +";
        std::cout<<"\nTime Complexity: O(|V|+|E|)";
        break;
    case 2:
        std::cout<<"+ Breadth First Search +";
        std::cout<<"\nTime Complexity: O(|V|+|E|)";;
        break;
    case 3:
        std::cout<<"+ Dijkstra +";
        std::cout<<"\nTime Complexity: O(V^2)";
        break;
    case 4:
        std::cout<<"+ A* +";
        std::cout<<"\nTime Complexity: O(|V|)";
        break;
    }
    std::cout<<"\nTotal Time taken by Algorithm: "<<duration.count()<< " ms";
    std::cout<<"\nNo. of Steps: "<<maze->steps;
    std::cout << "\nAverage Time taken by Algorithm: "<< (float) duration.count() / maze->steps<< " ms";
    std::cout<<"\nTotal Nodes: "<<maze->nodeList.size();
    std::cout<<"\nUsed Nodes: "<<maze->path.size();
    std::cout<<"\nDistance: "<<maze->printSolution();
    return 0;
}

int UI()
{
    std::cout<<"+ Choose Solving Algorithm +";
    std::cout<<"\n1. Depth First Search";
    std::cout<<"\n2. Breadth First Search";
    std::cout<<"\n3. Dijkstra";
    std::cout<<"\n4. A*";
    std::cout<<"\nEnter You Choice: ";
    //the Key
    int retVal;
    std::cin>>retVal;
    return retVal;
}
