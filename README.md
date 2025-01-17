<div align="center">
    <img src="https://raw.githubusercontent.com/jdneo/vscode-leetcode/master/resources/LeetCode.png" alt="LeetCode Logo" />
    <h1>LeetCode Solutions</h1>
</div>

Welcome to my **LeetCode Solutions** repository! 

Here, you'll find solutions to various LeetCode problems that I’ve tackled, written primarily in **C**, and possibly in other programming languages as well. Whether you're here to learn or simply explore, I hope you find these solutions helpful.

## 🚀 Getting Started

#### Clone the Repository
```bash
git clone https://github.com/wxrayut/leetcode.git 
cd ./leetcode
```

#### Compile and Run a Solution

Use the provided Makefile to compile and run a specific solution:

```bash
make run file=solutions/<problem>.c
```

#### Check for Memory Leaks

Use Valgrind to ensure memory safety:

```bash
make leak-check file=solutions/<problem>.c
```

## 📂 File Structure

    LeetCode/
    ├── Makefile
    ├── README.md
    ├── solutions/
    │   ├── problem_20_valid_parentheses.c
    │   ├── ...

- **Makefile**: For compiling and testing solutions.
- **solutions/**: Contains all LeetCode problem solutions.

## 🛠 Tools Used

- C Compiler: gcc
- Valgrind: For memory leak checks.
- Makefile: Simplified build process.

## 📄 License

This repository is licensed under the [MIT License](https://github.com/wxrayut/leetcode/blob/main/LICENSE). Feel free to use and modify the code as needed.