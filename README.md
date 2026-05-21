# 🏎️ ASCII Car Game

Welcome to the **ASCII Car Game**—a nostalgic, terminal-based racing experience that brings back the simple joy of local multiplayer arcade games! Written entirely in C++, this game turns your everyday Windows command prompt into a fast-paced 2-player race for survival.

This project was passionately crafted by **Muhammad Faizan Naeem**. Grab a friend, share a keyboard, and see who has the better reflexes!

---

## 🌟 What makes it fun?

- **Local Multiplayer Madness:** Why play alone when you can aggressively bump shoulders with a friend on the same keyboard? Player 1 and Player 2 race side-by-side.
- **Dynamic Pacing:** Don't get too comfortable! As you cover more distance, the game speeds up, testing your reaction times to the absolute limit.
- **Hazards & Handicaps:** 
  - Watch out for the **brick walls (`#`)**! Crashing into these will cost you a life.
  - Beware the **oil spills (`~`)**! Driving over them will temporarily reverse your steering controls—a recipe for disaster (and lots of laughs).
- **Pick Your Poison (Difficulty Modes):**
  - **Easy:** A relaxed pace with 3 lives. Perfect for warming up.
  - **Normal:** Things get a bit faster. You still get 3 lives, but you'll need to pay attention.
  - **Hard:** Only for the brave. Blistering speeds and sudden death—just 1 life. One mistake, and it's game over.

## 🎮 How to Control Your Car

You both share the keyboard, so play nice! 

**Player 1 (Car 'A')**
- Steer Left: `A`
- Steer Right: `D`

**Player 2 (Car 'B')**
- Steer Left: `J`
- Steer Right: `L`

*Need a quick breather? Just hit `P` to Pause the game!*

---

## 🛠️ Getting the Game Running

Because this game relies on some classic Windows-specific libraries (`<windows.h>` and `<conio.h>`), it is designed exclusively for Windows machines. 

### Prerequisites
You'll need a C++ compiler installed on your computer. Some common options include:
- **MinGW / GCC** (e.g., if you have Code::Blocks or Dev-C++ installed)
- **MSVC** (if you have Visual Studio installed)

### Compilation & Execution
1. Open your terminal or command prompt.
2. Navigate to the folder containing `Game.cpp`.
3. Compile the game. If you're using GCC, you can type:
   ```bash
   g++ Game.cpp -o ASCII-Car-Game.exe
   ```
4. Run your brand new game!
   ```bash
   ./ASCII-Car-Game.exe
   ```

### Gameplay Loop
1. When the menu pops up, type `1` to hit **START GAME**.
2. Pick your difficulty (1, 2, or 3).
3. Wait for the 3-2-1 countdown.
4. Try to survive longer than your friend!

---

*Thank you for checking out our game! We hope you have a blast dodging those walls.*