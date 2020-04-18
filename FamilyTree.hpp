#include <iostream> 
#include <string> 
using namespace std; 

namespace family
{
    class Node
    {
    public:
    string name; 
    string relation;
    int level;
    Node *mother, *father; 

   

    Node(string name,int level):
    name(name), relation("Just me") , level(level), mother(NULL),father(NULL){};

    string findMyRelation(int level,string sex);


    };
 
    class Tree 
    {
    private:
    Node * root;

    public:

    Tree(string name);

        Tree& addFather(string child,string father);
        Tree& addMother(string child,string mother);
        string relation(string relation);
        string find(string name);
        void display();
        void remove(string name);
        Node* findchild(Node *root,string name);

    };


}