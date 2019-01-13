// A.K.A. NodeList
class Node
{
    int x;
    int y;
    int id;
    Node* neighbours[4];//Up Down Left Right
    friend class Maze;
    public:
    Node(int x,int y,int id)
    {
        this->x =x;
        this->y=y;
        this->id=id;
        neighbours[0]=nullptr;
        neighbours[1]=nullptr;
        neighbours[2]=nullptr;
        neighbours[3]=nullptr;
    }

};
