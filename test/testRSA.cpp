// Created by Tadiwanashe Dzvoti on 04/01/2024.
//

// Code responsible for doing RSA encryption

#include <iostream>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>

long long int GenPublicKey();
void GenPrivateKey(long long int);
bool IsPrime(long long num);
long long int p, q, n, e; // variables to hold prime numbers for encryption

std::string RsaEncrypt(std::string message){

    int z_return = GenPublicKey();

    if(z_return == -1){
        std::cout << "Invalid, exiting.";
        return "";
    }
    GenPrivateKey(z_return);

    // Convert string to numeric message
    std::vector<long long> numeric_message;
    for(char ch : message){
        numeric_message.push_back(static_cast<long long>(ch));
    }

    std::string encrypted_message = "";
    // Perform encryption on message
    for(long long j : numeric_message){
        long long encrypted = 1;
        for(int k = 0; k < e; ++k){
            encrypted = (encrypted * j)  % n;
        }
        encrypted_message += std::to_string(encrypted) + " ";
    }

    std::cout << "Encrypted Message: " << encrypted_message << std::endl;

    return encrypted_message;
}

long long int GenPublicKey(){
    int i = 0;
    bool flag = false;
    bool prime;
    long long int z;
    std::string max_attempts_message = "Maximum attempts exceeded, exiting";
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
    long long d, d1; // d and a temp variable
    bool d_flag = false;
    int i = 1;
    while(!d_flag){

        d1 = ((z_use * i) + 1);
        // Check if d will be a whole number
        if(d1 % e == 0){
            d = d1 / e;
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

int main(){
    RsaEncrypt("blah");
    return 0;
}
