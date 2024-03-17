# README.md

## Project Name: illuminati: The end of the world

## Project Description

This is a demo of a 2D RPG game developed using C language and the SDL library. The game features basic player control, fighting with the Boss, interaction using the Enter key, and a puzzle. It includes collision detection, animation effects, text dialogue boxes, and more.

## Puzzle 1 Description

In Puzzle 1, the hero（Prince） and the villain（Dragon） fall into a time machine together. They take turns controlling the time machine, with each player having one turn. Their goal is to control the time machine from January 1st to December 31st. However, time travel follows specific rules:

- Within the same turn, the time machine can only travel to the future and cannot go back to the past.
- The time machine can only travel within the same month (e.g., from January 1st to January 20th) or between different months but the same day (e.g., from February 24th to May 24th).

## Features

- Player Control: The player can control the character's movement using the keyboard. The character can freely move within the game world and interact with the environment.
- Interaction: The player can interact with objects in the game using the Enter key, triggering dialogues, item collection, and events.
- Puzzle: The game includes a puzzle named Puzzle 1, which involves time travel as described above.
- Boss：The Player need to kill the final Boss to end the end of the world. Your HP will be deducted when you are hit by the Boss. But don't worry, you can respawn , so enjoy the fight!

## Technical Implementation

- Programming Language: C
- Game Engine: SDL library
- Graphics Handling: SDL_Renderer for drawing and rendering game objects, SDL_Texture for converting graphics into renderable traces.
- Animation Effects: Animation effects are achieved using SDL_Surface and SDL_Texture, rendering image sequences in the game window.
- Text Dialogue Boxes: TTF_Font library is used to load and render fonts for displaying text dialogue boxes.
- Sound Effects and Music: SDL_Mixer library is used to load and play sound effects and background music.

## System Requirements

- Operating System: Supports operating systems that can run the SDL library, such as Windows, Linux, etc.
- Graphics and Sound Card: Requires graphics and sound cards that support the SDL library.

## Controls

- Keyboard Controls: The player uses the arrow keys on the keyboard to control character movement.
- Enter Key: The Enter key is used to interact with objects in the game, triggering dialogues, collecting items, etc.

## User Interface

The game interface presents a 2D perspective game window where the player controls character movement, interaction, and puzzle solving.

## How to Compile and Run the Game

1. Install SDL Library: Ensure that the SDL library is correctly installed and configured on your system.
2. Download Source Code: Download the game source code files from the project repository.
3. Compile Source Code: Compile the game source code files using an appropriate compiler, such as gcc.
4. Link Library Files: During the compilation process, make sure to link the SDL library and SDL_Mixer library.
5. Run the Game: After successful compilation and linking, run the generated executable file to start the game.

## Development Team

- Game Design and Programming: [Your Name]
- Graphics Design: [Graphic Designer Name]
- Sound Effects and Music: [Sound Designer Name]

## Copyright and License

illuminati: The end of the world is a demo project and is protected by copyright. Reproduction, modification, distribution, or sale of the game is prohibited without permission. This project is intended for educational and demonstration purposes only.

## Other Notes

- This game is a demo version and may contain some unresolved issues or bugs.
- If you encounter any problems or errors during the game, please refer to the troubleshooting section in the project documentation or contact the development team for support.

We hope you enjoy this demo version of the 2D RPG game! If you have any feedback, suggestions, or questions, feel free to contact us. Thank you!
