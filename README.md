# Sudoku

To build this program (using CMake):

Windows:
run 'cmake .' from the command prompt at the location of the downloaded directory. After this completes, run 'msbuild Sudoku.sln' from the Visual Studio Command Prompt. Then, run Sudoku.exe from Debug directory

Linux:
run 'cmake .' from terminal at the location of the downloaded directory. After this completes, run 'make' from terminal. Then, run Sudoku from build directory.


To use this program:
Follow the prompts from the terminal. If "load" is selected, then the program will look for a file called "sudoku.txt" in the same directory as the executable. The default sudoku.txt is a mostly-solved puzzle with a few spaces left to be filled in - you can change the contents of this file to any sudoku puzzle, where each entry is listed in order from left-to-right, top-to-bottom. The solving algorithm isn't very robust, and won't handle ambiguity well, so don't expect this to solve a puzzle where any space could potentially have more than 1 immediate solution.
