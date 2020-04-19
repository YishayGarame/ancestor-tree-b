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

    //consructor and functions

    Node(string name, int level) : name(name), relation("me"), level(level), mother(NULL), father(NULL){};

    string findMyRelation(int level, string sex);
};

class Tree
{
public:
    Node *root;

    Tree(string name) : root(new Node(name, 0)){};

    Tree &addFather(string child, string father);
    Tree &addMother(string child, string mother);
    string relation(string relation);
    string find(string name);
    void display();
    void remove(string name);
    void deleteParent(Node *remove);
    Node *findReletive(Node *root, string relation);
    Node *findPerson(Node *root, string name);
    Node *findChild(Node *node, string name);
    void printInorder(Node *node);
};

} // namespace family