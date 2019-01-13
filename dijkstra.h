#include<queue>

class dijkstraNode {

public:
    int id;
    int dist;
    // this is used to initialize the variables of the class
    dijkstraNode(int id, int dist)
        : id(id), dist(dist)
    {
    }
};

// we are doing operator overloading through this
bool operator<(const dijkstraNode& dn1, const dijkstraNode& dn2)
{


    return dn1.dist < dn2.dist;
}


int Maze::getdistance(int id1,int id2)
{
  int curX=nodeList[id1]->x;
        int nxtX=nodeList[id2]->x;
        int curY=nodeList[id1]->y;
        int nxtY=nodeList[id2]->y;
       if(curX==nxtX)
       {
           return abs(nxtY-curY);
       }
    else
        {
               return abs(nxtX-curX);
        }
}

void Maze::dijkstra()
{
    for(std::vector<Node*>::iterator itr=connections.end()-1;itr!=connections.begin();itr--)
    {
        dijkstra(*(itr-1),*itr);
    }

}

void Maze::dijkstra(Node *stNode,Node* edNode)
{
    int pred[noOfNodes]={-1};
    std::vector<int> dist(noOfNodes,99999);
    std::priority_queue<dijkstraNode*> pq;
    dist[stNode->id] = 0;
    pq.push(new dijkstraNode(stNode->id,std::numeric_limits<int>::max()));
    Node* u;

    while(!pq.empty())
    {
        u=nodeList[pq.top()->id];
        pq.pop();
        for(int i=0;i<4;i++)
        {

            if(u->neighbours[i]!=nullptr)
                {
		int weight = getdistance(u->neighbours[i]->id,u->id);
                     if (dist[u->neighbours[i]->id] > dist[u->id] + weight)
                        {
                    steps=steps+1;
                             pred[(u->neighbours[i])->id] = u->id;
                            dist[u->neighbours[i]->id] = dist[u->id] + weight;
                        pq.push(new dijkstraNode(u->neighbours[i]->id,weight));
                        }
                }
        }
    }
    int crawl = edNode->id;
    path.push_back(crawl);
    while (crawl != stNode->id)
        {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
        }
}
