// Created by Tadiwanashe Dzvoti on 04/01/2024.
//
//
// Code responsible for doing RSA encryption

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <sstream>

std::string RsaEncrypt(const std::string& message);
void RsaDecrypt(const std::string& encrypted_message);
long long int GenPublicKey();
void GenPrivateKey(long long int);
bool IsPrime(long long num);
long long int p, q, n, e, d; // variables to hold prime numbers for encryption

int main(){

    std::string message;
    std::cout <<"Enter message you wish to encrypt: ";
    std::getline(std::cin, message);

    std::string cyphertext = RsaEncrypt(message);
    RsaDecrypt(cyphertext);

    return 0;
}

// Function to Encrypt a message into cyphertext
std::string RsaEncrypt(const std::string& message){

    long long z_return = GenPublicKey();

    if(z_return == -1){
        std::cout << "Invalid, exiting.";
        return "";
    }
    GenPrivateKey(z_return);

    std::cout <<"Original Message: " << message << std::endl;

    // Convert string to numeric message
    std::vector<long long> numeric_message;
    for(char ch : message){
        numeric_message.push_back(static_cast<long long>(ch));
    }

    // Print ASCII code of message
    std::cout <<"Message in ASCII form: ";
    for(long long i : numeric_message){
        std::cout << std::to_string(i) << " ";
    }
    std::cout << std::endl;

    std::string encrypted_message;
    // Perform encryption on message
    for(long long j : numeric_message){
        long long encrypted = 1;
        for(int k = 0; k < e; k++){
            encrypted = (encrypted * j)  % n;
        }
        encrypted_message += std::to_string(encrypted) + " ";
    }

    std::cout << "Encrypted Message: " << encrypted_message << std::endl;

    return encrypted_message;
}

// Function to decrypt cyphertext
void RsaDecrypt(const std::string& encrypted_message){

    std::istringstream iss(encrypted_message);
    std::vector <long long> encrypted_values;
    std::string temp; // temp variable to store individual values from encrypted message

    // Push individual values into encrypted values vector
    while(std::getline(iss, temp, ' ')){
        encrypted_values.push_back(std::stoll(temp));
    }

    std::string decrypted_message;
    // Perform decryption
    for(long long encrypted : encrypted_values){

        long long decrypted = 1;
        for(int j = 0; j < d; j++){
            decrypted = (decrypted * encrypted) % n;
        }
        decrypted_message += static_cast<char>(decrypted);
    }

    std::cout << "Decrypted Message: " << decrypted_message << std::endl;
}

// Function to generate public key
long long int GenPublicKey(){
    int i = 0;
    bool flag = false;
    bool prime;
    long long int z;
    std::cout << "You have 3 attempts to enter valid prime number" << std::endl;

    while(i < 3 && !flag){
        std::cout << "Enter first prime number (Attempt " << i + 1 << "): ";
        std::cin >> p;
        if(!std::cin){
            std::cout <<"Invalid input" << std::endl;
            // Clear error flags
            std::cin.clear();
            // Discard invalid input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            i++;
        }
        else{
            prime = IsPrime(p);
            if(!prime){
                std::cout <<"That was not a prime number" << std::endl;
                i++;
                if(i == 3){
                    return -1;
                }
            }
            else{
                std::cout <<"First prime number is: " << p << std::endl;
                flag = true;
            }
        }
    }

    i = 0;
    flag = false;
    std::cout << "You have 3 attempts to enter valid prime number" << std::endl;
    while(i < 3 && !flag){
        std::cout << "Enter second prime number (Attempt " << i + 1 << "): ";
        std::cin >> q;
        if(!std::cin){
            std::cout <<"Invalid input" << std::endl;
            // Clear error flags
            std::cin.clear();
            // Discard invalid input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            i++;
        }
        else{
            prime = IsPrime(q);
            if(!prime){
                std::cout <<"That was not a prime number" << std::endl;
                i++;
                if(i == 3){
                    return -1;
                }
            }
            else{
                std::cout <<"Second prime number is: " << q << std::endl;
                flag = true;
            }
        }
    }

    // Calculate first part of public key
    n = p * q;
    // Calculate z and tell the user z
    z = (p-1) *(q-1);

    // e means encrypt
    // e is selected for the user
    // short bit length e is ideal so will start from 3
    // e must be coprime to z and smaller than z
    e = 3;
    while(e < z){
        if(std::gcd(e, z) == 1){
            break;
        }else{
            e++;
            if(e == z){
                std::cout <<"No suitable values found";
                return -1;
            }
        }
    }

    std::cout << "Public key values are (" << n << ", " << e << ")" << std::endl;
    return z;
}

// Function to generate private key
void GenPrivateKey(long long int z_use){

    // d means decrypt
    // choose d such that it satisfies
    // d*e = 1 mod z and d must be a whole number
    // d will be selected by iteration
    long long d_temp; // d and a temp variable
    bool d_flag = false;
    int i = 1;
    while(!d_flag){

        d_temp = ((z_use * i) + 1);
        // Check if d will be a whole number
        if(d_temp % e == 0){
            d = d_temp / e;
            d_flag = true;
        }
        i++;
    }

    std::cout << "Private key values are (" << n << ", " << d << ")" << std::endl;
}

// Function to check whether a number is prime
bool IsPrime(long long num){

    // corner case
    if(num == 1){
        return false;
    }
    // After 2 all prime numbers are odd, so n/2 is safe
    for(int i = 2; i <= num/2; i++){
        // If the remainder is 0, that means the number is not prime
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}
