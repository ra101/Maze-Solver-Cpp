#include<math.h>

class ANode {
public:
    int id;
    float heuristic;
    // this is used to initialize the variables of the class
    ANode(int id,float heuristic)
        : id(id),heuristic(heuristic)
    {
    }
};

float Maze::getVirtualDist(int id)
{
  return ((float)sqrt((nodeList[id]->x - endNode->x)^2 + (nodeList[id]->y - endNode->y)^2));
}


// we are doing operator overloading through this
bool operator<(const ANode& an1, const ANode& an2)
{


    return an1.heuristic < an2.heuristic;
}
void Maze::aStar()
{
    for(std::vector<Node*>::iterator itr=connections.end()-1;itr!=connections.begin();itr--)
    {
        aStar(*(itr-1),*itr);
    }

}

void Maze::aStar(Node *stNode,Node* edNode)
{
    steps=1;
    int pred[noOfNodes]={-1};
    std::priority_queue<ANode*> pq;
    std::vector<int> dist(noOfNodes,std::numeric_limits<int>::max());
    dist[stNode->id] = 0;
    pq.push(new ANode(stNode->id,getVirtualDist(stNode->id)));
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
                            // Updating distance of v
                                                    pred[(u->neighbours[i])->id] = u->id;
                            dist[u->neighbours[i]->id] = dist[u->id] + weight;
                        pq.push(new ANode(u->neighbours[i]->id,dist[u->neighbours[i]->id]+getVirtualDist(u->neighbours[i]->id)));
                        }
                }
                if (u->neighbours[i] == edNode)
                        {
                            goto done;
                        }
        }
    }
done:
 int crawl = edNode->id;
    path.push_back(crawl);
    while (crawl != stNode->id)
        {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
        }
}
