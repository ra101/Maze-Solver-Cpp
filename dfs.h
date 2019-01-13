#include<stack>

void Maze::dfs()
{
    for(std::vector<Node*>::iterator itr=connections.end()-1;itr!=connections.begin();itr--)
    {
        dfs(*(itr-1),*itr);
    }

}

void Maze::dfs(Node *stNode,Node* edNode)
{
    steps=1;
    int pred[noOfNodes]={-1};
    std::stack<int> s;
    bool visited[noOfNodes]={false};
    visited[stNode->id] = true;
    s.push(stNode->id);
    Node* u;
    int i=0;
    while(!s.empty())
    {
        u=nodeList[s.top()];
        s.pop();
        for(i=0;i<4;i++)
        {

            if(u->neighbours[i]!=nullptr)
                {
                    if(!visited[(u->neighbours[i])->id])
                    {
                                            steps=steps+1;

                        s.push(u->neighbours[i]->id);
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
