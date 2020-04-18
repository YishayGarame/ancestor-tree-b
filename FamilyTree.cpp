#include "FamilyTree.hpp"



using namespace family;

//Node

     string findMyRelation(int level,string sex)
    {
      if (level == 0)
      {
        return "Just Me";
      }
      else if(level == 1)
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
            relation ="great-" + temp;
        }
       return relation;
      }
    }



//Tree

        Tree::Tree(string name){};

       Tree& Tree::addFather(string child ,string name)
        {
            Node *a=findchild(root,name);
            if(a==NULL)
            {
            //throw exception("fgfgf");
            }
            else if(a->father != NULL)
            {
            //throw exception("fgfgf");

            }
            else 
            {
              Node *b=new Node(name,a->level+1);
              a->father=b;
              b->relation = findMyRelation(b->level,"father");
            }
        }
      Tree& Tree::addMother(string child,string name)
        {
            return *this;  
        }

      string Tree::relation(string)
        {
            string s="relation";
            return s;
        }

        string Tree::find(string)
        {
             string s="find";
            return s;
        }

        void Tree::display()
        {

        };

        void Tree::remove(string name)
        {

        };

        Node* findchild(Node *root,string name)
        {

        }
