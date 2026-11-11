# DSA01 – Assignment 2 (CO2)

**Student Name:** [Enter your name]  
**Register Number:** [Enter your register number]  
**Repository:** `DSA01-RegisterNumber-Assignment2`  
**Compiler:** g++ [enter installed version]  
**Language standard:** C++17

## Compile command
```bash
g++ -std=c++17 -Wall -Wextra source.cpp -o program
```
Run on Windows PowerShell:
```powershell
.\program.exe
```
Run on macOS/Linux:
```bash
./program
```

## Task execution guide
Compile each source file separately from its task folder. Example:
```powershell
cd Task01_CallByValueReferencePointer
g++ -std=c++17 -Wall -Wextra q1_implementations.cpp -o q1.exe
.\q1.exe
```
Repeat with the required `.cpp` file in each task folder. For Q2, the unsafe function returning a local reference is deliberately not called; compile with warnings to observe the diagnostic without invoking undefined behaviour.

## Tasks and result notes
- **Q1:** Compares value, reference and pointer parameters. Value changes only its local copy; reference and pointer can modify the caller's variable.
- **Q2:** Demonstrates a modifiable reference to an array element, plus index and pointer alternatives. The dangling-reference function is intentionally not executed.
- **Q3:** Uses distinct overloads for grams (`int`), kilograms (`double`) and `Parcel`. Default arguments supply optional express and insurance settings.
- **Q4:** Encapsulates account data and retains the latest ten transactions using a circular index.
- **Q5:** Uses a static class counter to allocate three seats across all `BusTicket` objects.
- **Q6:** Uses friend functions to compare private time fields. The benchmark is a local measurement; record your own results at `-O0` and `-O2`.
- **Q7:** Compares shifting history with a circular buffer. Both should retain the same latest ten values; the circular buffer avoids shifting.

## Evidence to add
For every task, save screenshots of:
1. The source code in VS Code.
2. The successful compilation command (or compiler warning where relevant).
3. The program output in the terminal.
4. For Q6, benchmark results for both `-O0` and `-O2`.

Do not insert fabricated screenshots or timings. Record the actual compiler version and results from your machine.

## GitHub workflow
```bash
git init
git add .
git commit -m "Add Assignment 2 structure and Q1"
git branch -M main
git remote add origin https://github.com/YOUR-USERNAME/DSA01-RegisterNumber-Assignment2.git
git push -u origin main
```
Continue committing progressively, at least one commit per task:
```bash
git add Task02_ReturnByReference
git commit -m "Complete Q2 return by reference"
git push
```
Use your actual repository URL and register number. Create the repository with the exact required name and give faculty access if it is private.
