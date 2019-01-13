#include<queue>

void Maze::bfs()
{
    for(std::vector<Node*>::iterator itr=connections.end()-1;itr!=connections.begin();itr--)
    {
        bfs(*(itr-1),*itr);
    }

}

void Maze::bfs(Node *stNode,Node* edNode)
{
    steps=1;
    int pred[noOfNodes]={-1};
    std::queue<int> q;
    bool visited[noOfNodes]={false};
    visited[stNode->id] = true;
    q.push(stNode->id);
    Node* u;
    int i=0;
    while(!q.empty())
    {
        u=nodeList[q.front()];
        q.pop();
        for(i=0;i<4;i++)
        {

            if(u->neighbours[i]!=nullptr)
                {
                    if(!visited[(u->neighbours[i])->id])
                    {
                        steps=steps+1;
                        q.push(u->neighbours[i]->id);
                        visited[(u->neighbours[i])->id] = true;
                        pred[(u->neighbours[i])->id] = u->id;
                         if (u->neighbours[i] == edNode)
                        {
                            goto done;
                        }
                    }
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
