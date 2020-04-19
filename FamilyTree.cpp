#include "FamilyTree.hpp"

using namespace family;

//Node

string Node::findMyRelation(int level, string sex)
{
  if (level == 0)
  {
    return "Just Me";
  }
  else if (level == 1)
  {
    return sex;
  }
  else if (level == 2)
  {
    return "grand" + sex;
  }
  else
  {
    string relation = "grand" + sex;
    for (int i = 3; i <= level; i++)
    {
      string temp = relation;
      relation = "great-" + temp;
    }
    return relation;
  }
}

//Tree

Tree &Tree::addFather(string child, string name)
{
  Node *found = findPerson(root, child);
  if (found == NULL)
  {
    throw std::runtime_error(child + " does not exist");
  }
  else if (found->father != NULL)
  {
    throw std::runtime_error(child + " allready has a father");
  }
  else
  {
    Node *temp = new Node(name, found->level + 1);
    found->father = temp;
    temp->relation = temp->findMyRelation(temp->level, "father");
  }
  return *this;
}
Tree &Tree::addMother(string child, string name)
{
  Node *found = findPerson(root, child);
  if (found == NULL)
  {
    throw std::runtime_error(child + " does not exist");
  }
  else if (found->mother != NULL)
  {
    throw std::runtime_error(child + " allready has a mother");
  }
  else
  {
    Node *temp = new Node(name, found->level + 1);
    found->mother = temp;
    temp->relation = temp->findMyRelation(temp->level, "mother");
  }
  return *this;
}
string Tree::relation(string name)
{
  Node *found = findPerson(root, name);
  if (found == NULL)
  {
    return "unrelated";
  }
  else
  {
    return found->relation;
  }
}

string Tree::find(string relation)
{
  Node *found = findReletive(root, relation);
  if (found == NULL)
  {
    throw std::runtime_error(relation + " does not exist");
  }
  else
  {
    return found->name;
  }
}

void Tree::display()
{
  printInorder(root);
};
void Tree::printInorder(Node *node)
{
  if (node == NULL)
    return;

  /* first recur on left child */
  printInorder(node->father);

  /* then print the data of node */
  cout << node->name << " ";

  /* now recur on right child */
  printInorder(node->mother);
}

void Tree::remove(string name)
{
  if (root->name == name)
  {
    throw std::runtime_error(name + "is the Root of the tree so you cant remove it");
  }
  else
  {
    Node *found = findChild(root, name);
    if (found == NULL)
    {
      throw std::runtime_error(name + " doesnt belong to the tree");
    }
    if (found->father != NULL && found->father->name == name) //delete father sub-tree
    {
      deleteParent(found->father);
      found->father = NULL;
    }
    else if (found->mother != NULL && found->mother->name == name) //delete mother sub-tree
    {
      deleteParent(found->mother);
      found->mother = NULL;
    }
  }
};
void Tree::deleteParent(Node *remove)
{
  if (remove->father == NULL && remove->mother == NULL)
  {
    delete remove;
  }
  else if (remove->father != NULL && remove->mother == NULL)
  {
    deleteParent(remove->father);
    remove->father = NULL;
    delete remove->father;
  }
  else if (remove->mother != NULL && remove->father == NULL)
  {
    deleteParent(remove->mother);
    remove->mother = NULL;
    delete remove->mother;
  }
  else
  {
    deleteParent(remove->father);
    remove->father = NULL;
    deleteParent(remove->mother);
    remove->mother = NULL;
    delete remove->father;
    delete remove->mother;
  }
};

Node *Tree::findPerson(Node *node, string name)
{
  if (node != NULL)
  {
    if (node->name == name)
    {
      return node;
    }
    else
    {
      Node *foundNode = findPerson(node->father, name);
      if (foundNode == NULL)
      {
        foundNode = findPerson(node->mother, name);
      }
      return foundNode;
    }
  }
  else
  {
    return NULL;
  }
}

Node *Tree::findReletive(Node *node, string relation)

{
  if (node != NULL)
  {
    if (node->relation == relation)
    {
      return node;
    }
    else
    {
      Node *foundNode = findReletive(node->father, relation);
      if (foundNode == NULL)
      {
        foundNode = findReletive(node->mother, relation);
      }
      return foundNode;
    }
  }
  else
  {
    return NULL;
  }
}

Node *Tree::findChild(Node *node, string name)
{
  if (node != NULL)
  {
    if ((node->father != NULL && node->father->name == name) || (node->mother != NULL && node->mother->name == name))
    {
      return node;
    }
    else
    {
      Node *foundNode = findChild(node->father, name);
      if (foundNode == NULL)
      {
        foundNode = findChild(node->mother, name);
      }
      return foundNode;
    }
  }
  else
  {
    return NULL;
  }
}

//         #include <iostream>
// #include <string>
// using namespace std;

// // Data structure to store a Binary Tree node
// struct Node
// {
//     int data;
//     Node *left, *right;

//     Node(int data)
//     {
//         this->data = data;
//         this->left = this->right = nullptr;
//     }
// };

// struct Trunk
// {
//     Trunk *prev;
//     string str;

//     Trunk(Trunk *prev, string str)
//     {
//         this->prev = prev;
//         this->str = str;
//     }
// };

// // Helper function to print branches of the binary tree
// void showTrunks(Trunk *p)
// {
//     if (p == nullptr)
//         return;

//     showTrunks(p->prev);

//     cout << p->str;
// }

// // Recursive function to print binary tree
// // It uses inorder traversal
// void printTree(Node *root, Trunk *prev, bool isLeft)
// {
//     if (root == nullptr)
//         return;

//     string prev_str = "    ";
//     Trunk *trunk = new Trunk(prev, prev_str);

//     printTree(root->left, trunk, true);

//     if (!prev)
//         trunk->str = "---";
//     else if (isLeft)
//     {
//         trunk->str = ".---";
//         prev_str = "   |";
//     }
//     else
//     {
//         trunk->str = "`---";
//         prev->str = prev_str;
//     }

//     showTrunks(trunk);
//     cout << root->data << endl;

//     if (prev)
//         prev->str = prev_str;
//     trunk->str = "   |";

//     printTree(root->right, trunk, false);
// }
