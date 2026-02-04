# Hero Battle Game 🎮

A turn-based combat game written in C++ where players choose heroes and pets to battle against each other.

## 📋 Description

This is a text-based battle game where:
- Players choose from 4 unique heroes, each with different stats
- Each player selects a pet that provides defensive support
- Pets absorb a percentage of incoming damage based on their defense stat
- Battle continues in rounds until one hero is defeated

## 🎯 Features

- **4 Heroes to choose from:**
  - Ashe - Balanced fighter
  - Caitlyn - High damage dealer
  - Fiora - High health tank
  - Katarina - Glass cannon

- **4 Pets with unique defense stats:**
  - Wolf (40% defense)
  - Dragon (35% defense)
  - Fox (33% defense)
  - Bear (38% defense)

- **Combat System:**
  - Turn-based battles
  - Pet defense mechanics (absorbs damage percentage)
  - Automatic damage calculation
  - Visual health tracking

## 🚀 How to Run

### Prerequisites
- C++ compiler (g++, MinGW, or Visual Studio)

### Compilation and Execution

**Windows (MinGW):**
```bash
g++ main.cpp -o game
.\game.exe
```

**Mac/Linux:**
```bash
g++ main.cpp -o game
./game
```

## 🎮 How to Play

1. Choose your hero (1-4)
2. Choose your opponent's hero (1-4)
3. Choose your pet (1-4)
4. Choose your opponent's pet (1-4)
5. Press ENTER to start the battle
6. Watch the automated battle unfold!

## 💡 What I Learned

- **Object-Oriented Programming:** Created `Hero` and `Pet` classes with encapsulation
- **Functions:** Organized code into reusable display and battle functions
- **References:** Used pass-by-reference to modify objects in battle
- **Game Balance:** Implemented percentage-based damage calculation
- **Input Validation:** Ensured players can't select invalid or duplicate choices

## 🛠️ Technical Details

**Language:** C++  
**Compiler:** g++ (C++11 or higher)  
**Libraries Used:** iostream, iomanip, thread, chrono  

## 📸 Example Output
```
==========================
   WELCOME TO THE GAME
==========================

======= HEROES =======

1. Ashe
   Kick: 15 | Life: 85

2. Caitlyn
   Kick: 18 | Life: 80

...

>>> Choose your Hero: 1
>>> Choose opponent's Hero: 2

====== BATTLE ======

ROUND 1
----------------

Ashe attacks Caitlyn
Caitlyn attacks Ashe

Ashe life: 73 / 85
Caitlyn life: 76 / 80
Wolf life: 24 / 30
Dragon life: 22 / 28
```

## 🔮 Future Improvements

- [ ] Add special abilities for each hero
- [ ] Implement an XP/leveling system
- [ ] Add more heroes and pets
- [ ] Create a save/load game feature
- [ ] Add player vs AI mode

## 👤 Author

**Dimitra Dodopoulou** 
IEK AKMI Student - Programming Course
2025/2026 Academic Year

## 📝 License

This project is open source and available under the [MIT License](LICENSE).
