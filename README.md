# Pipex

Pipex is a project that allows you to explore the UNIX mechanism of pipes by implementing it in your own program. The project involves handling multiple processes and redirecting their inputs and outputs in a manner similar to shell pipelines.

---

## Features
- **Pipe Handling**: Implements the functionality of pipes to redirect the output of one command to the input of another.
- **Command Execution**: Executes shell commands with their parameters.
- **File Redirection**: Handles input and output redirection from and to files.


### Usage
The program will be executed as follows:
```bash
./pipex file1 cmd1 cmd2 file2
```

### Examples
```bash
./pipex infile "ls -l" "wc -l" outfile
```

---

## Compilation

To compile Pipex, use the provided Makefile. The Makefile includes the following rules:
- `all`: Compile the source files.
- `clean`: Remove object files.
- `fclean`: Remove all generated files.
- `re`: Recompile the project.
- `bonus`: Compile bonus features (if applicable).

---

## Programming Languages:
<p align="left">
  <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="C" width="40" height="40"/>
</p>

---

## Authors

- [hasabir](https://github.com/hasabir)

---


## Acknowledgments

- [42 School](https://42.fr/)

---
