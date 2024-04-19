# Country Rating System

This program allows users to rate different countries based on various criteria and stores the ratings in a text file. It provides a simple command-line interface for inputting ratings for each country.

## Features

- Allows users to rate countries based on predefined criteria.
- Stores the ratings in a text file named `list.txt`.
- Retrieves the names of countries from a predefined list.
- Provides links to Wikipedia pages for each country for reference.

## How to Use

### Using Makefile

1. Compile the code using the provided Makefile:

    ```bash
    make
    ```

2. Run the compiled executable:

    ```bash
    ./main
    ```

### Manual Compilation

If you prefer to compile manually, you can use the following command:

```bash
g++ -g -std=c++14 -Wall main.cpp -o main
