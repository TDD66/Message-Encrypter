# RSA Encryption in C++

## Overview

This project demonstrates RSA encryption and decryption in C++.

## Getting Started

To run the program, ensure you have a C++ compiler (C++17) installed. You can compile and execute the program using the following steps:

1. **Clone the repository:**
    ```bash
    git clone https://github.com/TDD66/Message-Encrypter.git
    cd Message-Encrypter
    ```

2. **Compile the code:**
    ```bash
    g++ -std=c++17 Encryption.cpp -o message_encrypter
    ```

3. **Run the program:**
    ```bash
    ./message_encrypter
    ```


### Features

- **Key Generation**: Allows users to generate public and private RSA keys by entering prime numbers.
- **Encryption**: Converts a user-provided string message into an encrypted form using the generated keys.
- **Decryption**: Decrypts the encrypted message using the corresponding private key.

## Prerequisites

To run this project, ensure you have:
- C++ compiler (supporting C++11 or higher)
- Standard Library

## Usage

1. **Key Generation:**
   - Run the program and follow the prompts to input two prime numbers.
   - The program will generate public and private keys based on these numbers.

2. **Encryption:**
   - Input a string message to be encrypted using the generated public key.

3. **Decryption:**
   - Input the encrypted message and use the generated private key to decrypt it.

## Contributing

Contributions to enhance the functionality, optimize the code, or fix issues are welcome! 
- Fork this repository
- Make your changes
- Create a pull request

## License

This project is licensed under the [GNU General Public License (GNU GPL)](LICENSE).
