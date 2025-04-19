🖌️ CLI Paint App

A simple Command Line Interface (CLI) Paint application built in C++. This lightweight drawing program lets users draw lines and rectangles, erase elements, clear the canvas, display it in the console, and save it to a file.

📁 File
main.cpp: The main C++ source file containing the logic for the CLI-based paint application.
🎨 Features
Draw horizontal or vertical lines with a character of your choice
Draw rectangles by defining opposite corners
Erase individual characters on the canvas
Clear the entire canvas
Display current canvas state in terminal
Save the canvas as a text file
🛠️ Usage
Compile the code:
g++ main.cpp -o cli_paint
Run the program:
./cli_paint
Menu Options:
1. Draw Line
2. Draw Rectangle
3. Erase
4. Clear Canvas
5. Display Canvas
6. Save to File
0. Exit
📏 Canvas Size
Rows: 20
Columns: 40
You can customize this by modifying ROWS and COLS in the code.
💾 Save Output
When you select "Save to File", the canvas will be saved as a .txt file with your specified name.

🧠 Notes
Only horizontal and vertical lines are supported.
The coordinate system starts at the top-left corner of the canvas (0,0).
📌 Example
start (x1,y1): 5 5
end (x2,y2): 5 10
char: #
Draws a vertical line from (5,5) to (5,10) using #.

