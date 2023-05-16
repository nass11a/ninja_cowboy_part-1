#include "doctest.h"
#include "Point.hpp"
#include "Team2.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include <iostream>
#include <cmath>
using namespace std;
using namespace ariel;

TEST_CASE("Point test"){
    Point a(32.3,44),b(1.3,3.5);
    CHECK_EQ(a.distance(b),b.distance(a));
    CHECK_EQ(a.distance(b),sqrt(32.3*32.3+44*44));
    CHECK_EQ(b.distance(a),sqrt(32.3*32.3+44*44));
    CHECK_EQ(a.distance(a),0);
    CHECK_EQ(b.distance(b),0);
    CHECK_NE(a.getX(),b.getX());

    Point c(1.0,1.0),d(1.0,1.0);
    CHECK_EQ(c.distance(d),c.distance(d));
    CHECK_EQ(c.distance(d),0);
    CHECK_EQ(d.distance(c),0);
    CHECK_EQ(c.getX(),d.getX());
    CHECK_EQ(c.getY(),d.getY());
 
}


TEST_CASE("Cowboy vs OldNinja test"){

    Point g(3.3,5),k(1.2,3.1);
    Cowboy *tom = new Cowboy("Firas", g);
    OldNinja *sushi = new OldNinja("Nael", k);
    CHECK_EQ(tom->print(),"Firas");
    CHECK_EQ(sushi->print(),"Nael");
    CHECK_EQ(tom->gethitpoints(),011);
    CHECK_EQ(sushi->gethitpoints(),150);
    CHECK_EQ(tom->getLocation().getX(),3.3);
    CHECK_EQ(tom->getLocation().getY(),5);
    CHECK_EQ(sushi->getLocation().getX(),1.2);
    CHECK_EQ(sushi->getLocation().getY(),3.1);
    CHECK_EQ(tom->getName(),"Firas");
    CHECK_EQ(sushi->getName(),"Nael");

    CHECK(tom->isAlive()==true);
    CHECK(sushi->isAlive()==true);
    CHECK(tom->distance(sushi)==sqrt(pow((k.getX()-g.getX()),2) + pow((k.getY()-g.getY()),2)));
    CHECK(sushi->distance(tom)==sqrt(pow((k.getX()-g.getX()),2) + pow((k.getY()-g.getY()),2)));
    CHECK(tom->distance(sushi)==sushi->distance(tom));

    CHECK_EQ(tom->gethitpoints(),011);
    CHECK_EQ(tom->bulletsnum(),6);

    tom->hit(03);
    
    CHECK_EQ(tom->gethitpoints(),8);

    tom->shoot(sushi);
    CHECK_EQ(tom->bulletsnum(),5);
    CHECK_EQ(sushi->gethitpoints(),149);

    CHECK_EQ(tom->bulletsnum(),true);

    tom->reload();
    CHECK_EQ(tom->bulletsnum(),6);

    CHECK_EQ(sushi->getspeed(),8);


   CHECK_NOTHROW(sushi->move(tom));

    sushi->slash(tom);

    CHECK_EQ(tom->isAlive(),false);



}

TEST_CASE("YoungNinja vs TrainedNinja"){
    Point m(2.4,1.4),n(1.2,3.1);
    YoungNinja *yashi = new YoungNinja("kali", m);
    TrainedNinja *mali = new TrainedNinja("muller", n);
    CHECK_EQ(yashi->print(),"kali");
    CHECK_EQ(mali->print(),"muller");
    CHECK_EQ(yashi->gethitpoints(),100);
    CHECK_EQ(mali->gethitpoints(),120);
    
    CHECK(yashi->getspeed()==14);
    CHECK(mali->getspeed()==12);

    CHECK_NOTHROW(yashi->move(mali));

    yashi->slash(mali);

    CHECK_EQ(mali->gethitpoints(),89);

    mali->slash(yashi);

    CHECK_EQ(yashi->gethitpoints(),69);

    CHECK_EQ(yashi->isAlive(),true);

    CHECK_EQ(mali->isAlive(),true);

    CHECK_NOTHROW(yashi->hit(10));

    CHECK_EQ(yashi->gethitpoints(),59);

    CHECK_NOTHROW(mali->hit(10));

    CHECK_EQ(mali->gethitpoints(),79);

    mali->slash(yashi);
    mali->slash(yashi);
    mali->slash(yashi);

    CHECK_EQ(yashi->isAlive(),false);

    CHECK_LT(mali->gethitpoints(),0);

    CHECK_EQ(mali->isAlive(),true);
    
}


TEST_CASE("Team2 tests"){
  Point a(1,1),b(2,2),c(3,3),d(4,4),e(2,2);
     TrainedNinja * mali = new TrainedNinja("muller", a);
     YoungNinja *yashi = new YoungNinja("kali", b);
     Cowboy *tom = new Cowboy("Firas", c);
     OldNinja *sushi = new OldNinja("Nael",d);
     YoungNinja *laui = new YoungNinja("lakik", e);
     

     Team2 Team2_A(mali); 
    Point t(64,57);

    Team2_A.add(new YoungNinja("Yogi", t));
    CHECK_THROWS(Team2_A.add(new YoungNinja("Yogi", t)));

    Team2_A.add(yashi);
    Team2_A.add(tom);
    Team2_A.add(sushi);
    Team2_A.add(laui);  

     CHECK_EQ(Team2_A.stillAlive(),5);

     TrainedNinja *flake = new TrainedNinja("flake", a);
     YoungNinja *drake = new YoungNinja("drake", b);
     Cowboy *snake = new Cowboy("snake", c);
     OldNinja *rake = new OldNinja("rake", d);
     YoungNinja *jack = new YoungNinja("jack",e);
     

    Team2 Team2_B(flake); 
    Team2_B.add(drake);
    Team2_B.add(snake);
    Team2_B.add(rake);
    Team2_B.add(jack);

    CHECK_EQ(Team2_B.stillAlive(),5);

    Team2_A.attack(&Team2_B);

    // all A Team2 members should attack B Team2 leader flake

    CHECK_EQ(flake->gethitpoints(),-1);

    CHECK_EQ(Team2_A.stillAlive(),5);

    CHECK_EQ(Team2_B.stillAlive(),4);

    Team2_B.attack(&Team2_A);

    // all B Team2 members should attack A Team2 leader mali
    CHECK_EQ(mali->gethitpoints(),-1);
    CHECK_EQ(Team2_A.stillAlive(),4);
    CHECK_EQ(Team2_B.stillAlive(),4);

      while(Team2_A.stillAlive() > 0 && Team2_B.stillAlive() > 0){
        Team2_A.attack(&Team2_B);
        Team2_B.attack(&Team2_A);
        Team2_A.print();
        Team2_B.print();
     }

     CHECK_EQ((Team2_A.stillAlive() && Team2_B.stillAlive()), false);

}

TEST_CASE(" Team2 tests"){
    Point a(1,1),b(2,2),c(3,3),d(4,4),e(2,2);
    Point t(64,57);

     YoungNinja *malia = new YoungNinja("Yogia", a);
     YoungNinja *yashia = new YoungNinja("kalia", b);
     Cowboy *toma = new Cowboy("Firasa", c);
     OldNinja *sushia = new OldNinja("Naela", d);
     YoungNinja *lauia = new YoungNinja("lakika", b);
     

     Team2 Team2_A(malia); 

    Team2_A.add(new YoungNinja("Yogiass", t));
    CHECK_THROWS(Team2_A.add(new YoungNinja("Yogiass", t)));

    Team2_A.add(yashia);
    Team2_A.add(toma);
    Team2_A.add(sushia);
    Team2_A.add(lauia);  

     CHECK_EQ(Team2_A.stillAlive(),5);

     TrainedNinja *flakea = new TrainedNinja("flakea", a);
     YoungNinja *drakea = new YoungNinja("drakea", b);
     Cowboy *snakea = new Cowboy("snakea", c);
     OldNinja *rakea = new OldNinja("rakea", d);
     YoungNinja *jacka = new YoungNinja("jacka", b);
     

    Team2 Team2_B(flakea); 
    Team2_B.add(drakea);
    Team2_B.add(snakea);
    Team2_B.add(rakea);
    Team2_B.add(jacka);

    CHECK_EQ(Team2_B.stillAlive(),5);

    Team2_A.attack(&Team2_B);

    // team A will not attack team B because they are not in the same location from the leader

    CHECK_EQ(flakea->gethitpoints(),120);

    CHECK_EQ(Team2_A.stillAlive(),5);

    CHECK_EQ(Team2_B.stillAlive(),5);

    Team2_B.attack(&Team2_A);

 
    //  all team B should attack  ->  YoungNinja *yashia = new YoungNinja("kalia", Point(2,2));   
    //flakea and drakea and jacka are within 1 meter from yashia so splash * 3 = 31 * 3 = 93 + 10 from cowboy = 103
    CHECK_EQ(yashia->gethitpoints(),-3);
    CHECK_EQ(Team2_A.stillAlive(),4);
    CHECK_EQ(Team2_B.stillAlive(),5);

      while(Team2_A.stillAlive() > 0 && Team2_B.stillAlive() > 0){
        Team2_A.attack(&Team2_B);
        Team2_B.attack(&Team2_A);
        Team2_A.print();
        Team2_B.print();
     }

     CHECK_EQ((Team2_A.stillAlive() && Team2_B.stillAlive()), false);

}