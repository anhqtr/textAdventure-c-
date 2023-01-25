// TA.cpp
// Anna Tran, CISP 360
// 5/20/20

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


int room1(int);
int room2(int);
int room3(int);
int room4(int);
// Specification C1 - five rooms
int room5(int, int);
int monsterSpawn(int);
string roomPick(string);
void room1Desc();
int room2Desc(int);
int room3Desc(int);
void room4Desc();
void room5Desc();
void spawnSlime();
void spawnUnicorn();
void spawnGhoul();
void spawnFairy();


int main() {
  int game = 1;
  char temp;
  string pName;
  string look;
  int choice;
  string choice2;
  int monster;
  int dagger;
  int coins = 0;
  int cake = 0;
  string back;
  int roomOneCount = 1;
  int roomTwoCount = 1;
  int roomThreeCount = 1;
  int roomFourCount = 1;
  int roomFiveCount = 1;
  // Specification C2 - Player Name
  cout << "\n\nEnter your name: ";
  getline(cin,pName);
  cout << "Hello " 
       << pName
       << ", welcome to the game."
       << " Use keys to move through the rooms and try to find a way out. Be careful- there may be monsters and traps lurking around every corner.\n"
       << "Enter any key to start\n";
  cin >> temp;
  roomOneCount =room1(roomOneCount);
  cout << "\nA long, curved dagger rests on a table in the center of the room.\n"
       <<"Press 1 to take the dagger.\n"
       << "Press 2 to leave the dagger.\n";
      
    cin >> dagger;
    // Specification C3 - Input Validation
    while (!(dagger ==1 || dagger == 2)) {
      cout << "Please enter 1 or 2.\n";
      cin >> dagger;
    }
  
   monsterSpawn(dagger);
 // Specification A2 - game loop to move through rooms 
 while (game ==1) {
 choice2 =roomPick(choice2);
 // Specification A1 - Upper and lower case
 if (choice2 == "N" || choice2 == "n")
 {
   roomTwoCount = room2(roomTwoCount);
   if (roomTwoCount == 2)
 {
  coins=room2Desc(coins);      
 } 
 else if (roomTwoCount > 2)
  { cout << "Press L to look around.  Otherwise, enter any key\n";
   cin >> look;
    if (look == "L" || look == "l")
    {
      coins =room2Desc(coins);
    }
   }
   monsterSpawn(dagger);
 }
 else if (choice2 == "E" || choice2 == "e")
 {
   roomThreeCount = room3(roomThreeCount);
   cake = room3Desc(cake);
   if (cake == 1)
   {
     break;
   }
   monsterSpawn(dagger);
 }
 else if (choice2 == "W" || choice2 == "w")
 {
   roomFourCount = room4(roomFourCount);
   monsterSpawn(dagger);
 }
 else if (choice2 == "S" || choice2 == "s")
 {
   roomFiveCount = room5(roomFiveCount, coins);
   if (roomFiveCount == 9000)
   {
     cout << "\nCongratulations, you escaped and won the game!";
     break;
   }
   monsterSpawn(dagger);
 }
 cout << "\nEnter any key to return to room one\n";
 cin >> back;
 room1(roomOneCount);

  }
 
}

string roomPick(string choice2) {
  
  cout << "Choose a door to go through:\nN- The red door, room two\nE- The iron doors, room three\nW- The trapdoor, room four\nS- The curtain, room five\n";
 
 cin >> choice2;
 
 while (!(choice2 == "N" || choice2 == "n" || choice2 == "E" || choice2 == "e" || choice2 == "W" || choice2 == "w" || choice2 == "S" || choice2 == "s")) {
   cout << "Enter one of the letters to move on. ";
   cin >> choice2;
 }
 return choice2;
}

int room1(int roomOneCount) {
  string look;
  cout << "\nROOM ONE\n";
  // Specification C4 - Abbreviated Room Description
 if (roomOneCount == 1)
 {
  room1Desc();      
 } 
 else if (roomOneCount > 1)
  { cout << "Press L to look around.  Otherwise, enter any key\n";
   cin >> look;
    if (look == "L" || look == "l")
    {
      room1Desc();
    }
   }
  roomOneCount = roomOneCount + 1;
  
  return roomOneCount;
}

int room2(int roomTwoCount) {
  string look;
  int move;
  int choice;
  cout << "\nROOM TWO\n";
 
  roomTwoCount = roomTwoCount + 1;
  return roomTwoCount;
}

int room3(int roomThreeCount) {
  string look;
  cout << "\nROOM THREE\n";
  
  
  roomThreeCount = roomThreeCount + 1;
  
  return roomThreeCount;
}

int room4(int roomFourCount) {
  string look;
  cout << "\nROOM FOUR\n";
  
 if (roomFourCount == 1)
 {
  room4Desc();      
 } 
 else if (roomFourCount > 1)
  { cout << "Press L to look around.  Otherwise, enter any key\n";
   cin >> look;
    if (look == "L" || look == "l")
    {
      room4Desc();
    }
   }
  roomFourCount = roomFourCount + 1;
  return roomFourCount;
}

int room5(int roomFiveCount, int coins) {
  string look;
  string choice;
  string gold;
  cout << "\nROOM FIVE\n";
  
 if (roomFiveCount == 1)
 {
  room5Desc();      
 } 
 else if (roomFiveCount > 1)
  { cout << "Press L to look around.  Otherwise, enter any key\n";
   cin >> look;
    if (look == "L" || look == "l")
    {
      room5Desc();
    }
   }
   // Specification B3 - add more command options
   cout << "\nPress 1 to talk to the goblin. Otherwise, press any key\n";
   cin >> choice;
   if (choice == "1")
   {
    if (coins >= 1)
    {
      cout << "\"Why hello there\"! The goblin says. \"If you give me those coins you have, I'll let you out.\"";

     cout << "\nPress 1 to pay the goblin\nPress any other key to ignore him\n";
     cin >> gold;
     if (gold == "1")
     {
       roomFiveCount = 9000;
     }
    }
    else
    { cout << "\"I can let you out,\" The  goblin says. \"But only if you pay me! 5  gold coins.\"";
     cout << "\nYou dont have gold coins. Perhaps they are hidden in another room. ";
     roomFiveCount = roomFiveCount + 1;
    }
   }
  
  return roomFiveCount;
}

int monsterSpawn(int dagger) {

  int monster;
  int choice;  
  srand(time(NULL));
  monster = (rand() %4) + 1;
  switch (monster)
  {
    case 1: spawnSlime();
     break;
    case 2: spawnUnicorn();
     break;
    case 3: spawnGhoul();
     break;
    default: spawnFairy();
  }
 
 if (monster == 3)
 {
  if (dagger == 1 && monster == 3)
  {
    //specification B1 - Add Combat
    cout << "Press 1 to stab the ghoul\n"
         << "Press 2 to run away\n";
    cin >> choice;
    while (!(choice == 1 || choice == 2)) {
      cout << "Enter 1 or 2\n";
      cin >> choice;
    }
    if (choice == 1)
    {
      cout << "\nYou stab the ghoul, it falls over and disintegrates. I'ts a good thing you took that dagger.\n";
    }
  }

 }
 return dagger;
}

void room1Desc() {
  cout << "The room is rectangular in shape, with an exit by each side.\nTo your North is a large red door with a brass knob. The plaque on the door reads ROOM TWO\nTo your right is a set of wrought iron double doors. A plaque reads ROOM THREE\nTo your left is a dark oak trapdoor, leading to a room below. A plaque reads ROOM FOUR\nBehind you is a winding staircase that leads up, ending at a heavy velvet curtain. Stitching on the curtain reads ROOM FIVE\n";
}

int room2Desc(int coins) {
  int move;
  int choice;
  cout << "The room is round, with only one way in and out- back to room one.\nThe wall is made of wood, painted white.\nA box sits at the far end\n";
  cout << "\nPress 1 to look inside the box\nPress any other key to return to room1\n";
 cin >> move;
 if (move == 1)
 {
   // specification B2 - add treasure
   cout << "The box contains 5 gold coins!"
        <<"\nPress 1 to take the coins\n"
        << "Press another key to leave the coins\n";
   cin >> choice;
   if (choice == 1)
   {
     coins = 1;
   }
 }
 return coins;
}

int room3Desc(int cake) {
  cout << "\nThis room is triangular in shape, with mirrored walls. There is no way out except back to room one. A 3 tier cake, covered in white frosting, is at the center\n";
  
   cout << "\nPress 1 to eat the cake\nPress any other key to leave the cake alone\n";
   cin >> cake;
   if (cake == 1)
   {
     // specification A3 - Loss
     cout << "\nYou can't help but eat that delicious looking cake. Sadly, it was poisoned.\nGAME OVER\n";
   }
  return cake;
}

void room4Desc() {
  cout << "The room is dark, dimly lit by a single light bulb hanging from the ceiling. The room is flooded with water, about a foot deep. Your socks are wet and you are miserable. The room is otherwise bare, and the only exit is the trapdoor.";

}

void room5Desc() {
  cout << "\nThis room is less of a room and more of a long hall. At the end is a shimmering portal, guarded by a goblin.";
}

void spawnSlime() {
  cout << "\nA shapeless blob appears in the room, spreading flourescent green slime across the floor. It smells and you struggle to walk through it.\n";
}

void spawnUnicorn() {
  cout << "\nA beautiful white unicorn appears, lifting your spirits.\n";
}

void spawnGhoul() {
  cout << "\nA rotting, animated corpse appears, groaning as it shuffles towards you.\n";
}

void spawnFairy() {
  cout << "\nA tiny pixie appears, trailing sparkling dust that makes you sneeze.\n";
}
