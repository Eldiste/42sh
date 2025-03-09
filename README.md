# 42sh - UNIX Shell Implementation

<p align="center">
  <img src="https://img.shields.io/badge/MADE%20WITH-C-blue" alt="C">
  <img src="https://img.shields.io/badge/PLATFORM-UNIX%20%7C%20LINUX-lightgrey" alt="Platform">
  <img src="https://img.shields.io/badge/LICENSE-MIT-red" alt="License">
</p>

## 🚀 Overview

42sh is a UNIX command interpreter (shell) implemented in C. This project aims to recreate the functionality of traditional shells like bash or tcsh, providing a powerful command-line interface with various features including command execution, environment variable management, and more advanced shell functionalities.

## ✨ Features

- **Command Execution**: Run system commands and applications
- **Built-in Commands**: Implementation of common shell commands:
  - `cd`: Change directory with support for relative and absolute paths
  - `env`: Display environment variables
  - `setenv`: Set environment variables
  - `unsetenv`: Unset environment variables
  - `exit`: Exit the shell
  - `echo`: Display text
  - `which`: Locate a command
  - `where`: Locate all instances of a command
  - `repeat`: Execute a command multiple times
- **Command Separators**: Support for `;`, `&&`, and `||` operators
- **Pipes**: Command piping with `|` operator
- **Redirections**: Input/output redirections (`<`, `>`, `<<`, `>>`)
- **Background Processes**: Run commands in the background with `&`
- **Command History**: Track and recall previously executed commands
- **Aliases**: Define command aliases
- **Inhibitors**: Support for escape characters
- **Backticks**: Command substitution with backticks
- **Job Control**: Manage background processes

## 🛠️ Installation

### Prerequisites
- GCC compiler
- UNIX-like operating system (Linux, macOS)

### Building from Source

1. Clone the repository:
   ```bash
   git clone https://github.com/Eldiste/42sh.git
   cd 42sh
   ```

2. Compile the project:
   ```bash
   make
   ```

3. Run the shell:
   ```bash
   ./42sh
   ```

## 📖 Usage

Once the shell is running, you can use it like any other UNIX shell:

```bash
# Basic command execution
$ ls -la

# Using pipes
$ ls -l | grep ".c"

# Using redirections
$ ls > file.txt
$ cat < file.txt

# Setting environment variables
$ setenv VAR value

# Using command separators
$ ls ; pwd

# Conditional execution
$ mkdir test && cd test

# Background processes
$ sleep 10 &
```

## 🧪 Testing

The project includes a comprehensive test suite to verify the shell's functionality:

```bash
# Run all tests
$ ./my_tester.sh

# Run a specific test with detailed output
$ ./my_tester.sh 1
```

## 🧩 Project Structure

```
42sh/
├── include/         # Header files
│   ├── my.h         # Utility functions declarations
│   └── mysh.h       # Shell structure and function declarations
├── src/             # Source code
│   ├── cd/          # CD command implementation
│   ├── env/         # Environment variable management
│   ├── exit/        # Exit command implementation
│   ├── separator/   # Command separator handling
│   ├── setenv/      # Setenv command implementation
│   ├── unsetenv/    # Unsetenv command implementation
│   ├── where_which/ # Where and which commands
│   └── ...          # Other shell components
├── lib/             # Library functions
├── tests/           # Test files
└── my_tester.sh     # Testing script
```

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the project
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📜 License

This project is licensed under the MIT License - see the LICENSE file for details.

## 👥 Authors

* **Matéo Lechantre** - *Initial work* - [@eldiste](https://github.com/Eldiste)

## 🙏 Acknowledgments

* UNIX shell developers for the inspiration
* Epitech for the project guidelines
* All contributors who have helped with the development 