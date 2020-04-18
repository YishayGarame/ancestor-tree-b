#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
using namespace std;
using namespace family;


TEST_CASE("This test case check the following functuons : addFather(),relation(),find()") 
{

    ////////////////////////Test 1////////////////////////

    Tree a("Avi");
    a.addFather("Avi","Benny");
    a.addFather("Benny","Caleb");
    a.addFather("Caleb","Dani");
    a.addFather("Dani","Emmet");
    a.addFather("Emmet","Fredy");

    //check relation() function

    CHECK(a.relation("Avi") ==string("Just Me"));
    CHECK(a.relation("Benny")==string("father"));
    CHECK(a.relation("Caleb")==string("grandfather"));
    CHECK(a.relation("Dani")==string("great-grandfather"));
    CHECK(a.relation("Emmet")==string("great-great-grandfather"));
    CHECK(a.relation("Fredy")==string("great-great-great-grandfather"));
    CHECK(a.relation("avrahm")==string("unrelated"));


    //check find() function

    CHECK(a.find("Just Me") == string("Avi"));
    CHECK(a.find("father") == string("Benny"));
    CHECK(a.find("grandfather") == string("Caleb"));
    CHECK(a.find("great-grandfather") == string("Dani"));
    CHECK(a.find("great-great-grandfather") == string("Emmet"));
    CHECK(a.find("great-great-great-grandfather") == string("Freddy"));

    CHECK_THROWS_AS(a.find("uncle"),std::exception);
    CHECK_THROWS_AS(a.find("son"),std::exception);
    CHECK_THROWS_AS(a.find("brother"),std::exception); 
    CHECK_THROWS_AS(a.find("great-great-great-great-great-grandfather"),std::exception);
    CHECK_THROWS_AS(a.find("adopted"),std::exception);
    CHECK_THROWS_AS(a.find("friend"),std::exception);
    CHECK_THROWS_AS(a.find("greatt"),std::exception);


     
    ////////////////////////Test 2////////////////////////

    Tree an("Anna");
    an.addMother("Anna","Bella");
    an.addMother("Bella","Catty");
    an.addMother("Catty","Danna");
    an.addMother("Daana","Emma");
    an.addMother("Emma","Flura");

    //check relation() function

    CHECK(an.relation("Anna") ==string("Just Me"));
    CHECK(an.relation("Bella")==string("mother"));
    CHECK(an.relation("Catty")==string("grandmother"));
    CHECK(an.relation("Danna")==string("great-grandmother"));
    CHECK(an.relation("Emma")==string("great-great-grandmother"));
    CHECK(an.relation("Flura")==string("great-great-great-grandmother"));
    CHECK(an.relation("Annabel")==string("unrelated"));


    //check find() function

    CHECK(an.find("Just Me") == string("Anna"));
    CHECK(an.find("mother") == string("Bella"));
    CHECK(an.find("grandmother") == string("Catty"));
    CHECK(an.find("great-grandmother") == string("Danna"));
    CHECK(an.find("great-great-grandmother") == string("Emma"));
    CHECK(an.find("great-great-great-grandmother") == string("Flura"));

    CHECK_THROWS_AS(an.find("aunt"),std::exception);
    CHECK_THROWS_AS(an.find("daghter"),std::exception);
    CHECK_THROWS_AS(an.find("sister"),std::exception); 
    CHECK_THROWS_AS(an.find("great-great-great-great-great-grandmother"),std::exception);
    CHECK_THROWS_AS(an.find("adopted"),std::exception);
    CHECK_THROWS_AS(an.find("me"),std::exception);
    CHECK_THROWS_AS(an.find("just"),std::exception);


    

        
    ////////////////////////Test 3//////////////////////// 

    Tree al ("Alon");     
    al.addFather("Alon","Bob");
    al.addFather("Bob","Corey");
    al.addFather("Corey","Dovie");
    al.addFather("Dovie","Eli");
    al.addFather("Eli","Fin");

    //check relation() function

    CHECK(al.relation("Alon") ==string("Just Me"));   
    CHECK(al.relation("Bob")==string("father"));
    CHECK(al.relation("Corey")==string("grandfather"));
    CHECK(al.relation("Dovie")==string("great-grandfather"));
    CHECK(al.relation("Eli")==string("great-great-grandfather"));
    CHECK(al.relation("Fin")==string("great-great-great-grandfather"));
    CHECK(al.relation("Jack")==string("unrelated"));




    //check find() function

    CHECK(al.find("Just Me") == string("Alon")); 
    CHECK(al.find("father") == string("Bob"));
    CHECK(al.find("grandfather") == string("Corey"));
    CHECK(al.find("great-grandfather") == string("Dovie"));
    CHECK(al.find("great-great-grandfather") == string("Eli"));
    CHECK(al.find("great-great-great-grandfather") == string("Fin"));

    CHECK_THROWS_AS(al.find("auntie"),std::exception);  
    CHECK_THROWS_AS(al.find("enemy"),std::exception);
    CHECK_THROWS_AS(al.find("bro"),std::exception); 
    CHECK_THROWS_AS(al.find("great-great-great-great-great-grandfather"),std::exception);
    CHECK_THROWS_AS(al.find("half-brother"),std::exception);
    CHECK_THROWS_AS(al.find("neighbor"),std::exception);
    CHECK_THROWS_AS(al.find("niece"),std::exception);



 


////////////////////////Test 4//////////////////////// 

    Tree b ("Betty");     
    b.addFather("Betty","Geva");
    b.addMother("Betty","Gill");

    b.addFather("Geva","Dekel");
    b.addMother("Geva","Dikla");

    b.addFather("Gill","Dori");
    b.addMother("Gill","Dalia");

    b.addFather("Dekel","Erik");
    b.addMother("Dekel","Ella");

    b.addFather("Dikla","Eli");
    b.addMother("Dikla","Elit");

    b.addFather("Dori","Ezer");
    b.addMother("Dori","Eliana");

    b.addFather("Dalia","Gilad");
    b.addMother("Dalia","Gilat");

    b.addFather("Erik","Yuval");
    b.addMother("Yuval","Zoe");
    b.addFather("Erik","Yishay");




    //check relation() function

    CHECK(b.relation("Betty") ==string("Just Me"));   

    CHECK(b.relation("Geva")==string("father"));
    CHECK(b.relation("Gill")==string("mother"));

    CHECK(b.relation("Dekel")==string("grandfather"));
    CHECK(b.relation("Dikla")==string("grandmother"));

    CHECK(b.relation("Dori")==string("grandfather"));
    CHECK(b.relation("Dalia")==string("grandmother"));



    CHECK(b.relation("Erik")==string("great-grandfather"));
    CHECK(b.relation("Ella")==string("great-grandmother"));

    CHECK(b.relation("Eli")==string("great-grandfather"));
    CHECK(b.relation("Elit")==string("great-grandmother"));

    CHECK(b.relation("Ezer")==string("great-grandfather"));
    CHECK(b.relation("Eliana")==string("great-grandmother"));

    CHECK(b.relation("Gilad")==string("great-grandfather"));
    CHECK(b.relation("Gilat")==string("great-grandmother"));

    CHECK(b.relation("Yuval")==string("great-great-grandfather"));
    CHECK(b.relation("Zoe")==string("great-great-great-grandmother"));
    CHECK(b.relation("Yishay")==string("great-great-great-great-grandfather"));






    //check find() function

    CHECK(b.find("Just Me") == string("Betty")); 

    CHECK(b.find("father") == string("Geva"));
    CHECK(b.find("mother") == string("Gill"));

    CHECK(b.find("grandfather") == string("Dekel"));
    CHECK(b.find("grandmother") == string("Dikla"));
    CHECK(b.find("grandfather") == string("Dori"));
    CHECK(b.find("grandmother") == string("Dalia"));

    CHECK(b.find("great-grandfather") == string("Erik"));
    CHECK(b.find("great-grandmother") == string("Ella"));
    CHECK(b.find("great-grandfather") == string("Eli"));
    CHECK(b.find("great-grandmother") == string("Elit"));
    CHECK(b.find("great-grandfather") == string("Ezer"));
    CHECK(b.find("great-grandmother") == string("Eliana"));
    CHECK(b.find("great-grandfather") == string("Gilad"));
    CHECK(b.find("great-grandmother") == string("Gilat"));

    CHECK(b.find("great-great-grandfather") == string("Yuval"));
    CHECK(b.find("great-great-great-grandmother") == string("Zoe"));
    CHECK(b.find("great-great-great-great-grandfather") == string("Yishay"));

}

TEST_CASE("This test case check remove() function") 
{
    Tree r ("Betty");     
    r.addFather("Betty","Geva");
    r.addMother("Betty","Gill");
    r.addFather("Geva","Dekel");
    r.addMother("Geva","Dikla");
    r.addFather("Dekel","Erik");
    r.addMother("Dekel","Ella");


    ///remove///
    r.remove("Erik");
    r.remove("Dikla");
    r.remove("Gill");

    CHECK_THROWS_AS(r.find("great-grandfather"),std::exception);
    CHECK_THROWS_AS(r.find("grandmother"),std::exception);
    CHECK_THROWS_AS(r.find("mother"),std::exception);

    CHECK(r.relation("Erik") == string("unrelated"));
    CHECK(r.relation("Dikla") == string("unrelated"));
    CHECK(r.relation("Gill") == string("unrelated"));

    CHECK(r.find("father") == string("Geva"));
    CHECK(r.find("grandfather") == string("Dekel"));
    CHECK(r.find("Just me") == string("Betty"));
    CHECK(r.find("great-grandmother") == string("Ella"));

}