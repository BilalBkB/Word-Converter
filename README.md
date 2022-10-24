# Word Converter

This application translate all text numbers at digit numeric form at text of file.

<!-- GETTING STARTED -->
## Getting Started

To compile the solution you can use the scripts generated for linux and windows platforms.

### Prerequisites

CMake Version 3 or higher
Compiler g++ with c++ version 14 or higher.
MinGW for windows

### Build Solution
#### Linux

Use the script '_build.sh [-r]_' to build solution, you can rebuild this with argument '_-r_'.
  ```sh
  ./build.sh
  ```
#### Windows

Use the script '_build.bat [-r]_' to build solution, you can rebuild this with argument '_-r_'.
  ```sh
  .\build.bat
  ```

### Usage

Executable will be create at folder '_build/bin/'. To use, pass to arguments file input and can save the result of output at other file.

  ```sh
  ./build/bin/word_converter -i <input_file> [ -o <output_file]
  ```
The order of blocks of arguments (input or output block) not necesary ordered, for example:
  ```sh
  ./build/bin/word_converter -o output_file -i input_file
  ```

### Logic

The logic for program is read all input file, separate text for dots, and read by sentence and translate if that contains numbers at text format. Before join all sentences and save if is necesary and print to standanrd output.
