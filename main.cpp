#include "FamilyTree.hpp"
#include <string>
using namespace family;

int main()
{
    Tree a("Avi");
    a.addFather("Avi", "Benny");
    a.addFather("Benny", "Caleb");
    a.addFather("Caleb", "Dani");
    a.addFather("Dani", "Emmet");
    a.addFather("Emmet", "Fredy");
    a.display();
    cout << "\n";

    cout << a.relation("Avi");
    cout << "\n";

    cout << a.relation("Benny");
    cout << "\n";

    cout << a.relation("Caleb");
    cout << "\n";

    cout << a.relation("Dani");
    cout << "\n";

    cout << a.relation("Emmet");
    cout << "\n";

    cout << a.relation("Fredy");
    cout << "\n";
    a.remove("Avi");
    a.display();
}
