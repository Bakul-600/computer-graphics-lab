OpenGLLab Setup (MacBook Air M1 + Ventura)

1. Install Xcode Command Line Tools:
   xcode-select --install

2. Install Homebrew if needed:
   brew --version

3. Install freeglut:
   brew install freeglut

4. Open this folder in VS Code.

5. Press Cmd + Shift + B to build.

6. Run:
   ./app

If GLUT errors occur, update tasks.json to use:
-I/opt/homebrew/include
-L/opt/homebrew/lib
-lglut
