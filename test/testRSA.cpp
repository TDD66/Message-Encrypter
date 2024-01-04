// Created by Tadiwanashe Dzvoti on 04/01/2024.
//

// Code responsible for doing RSA encryption

#include <iostream>
#include <cstring>
#include <algorithm>
#include <numeric>

void GenPublicKey();
bool IsPrime(long long num);
long long int p, q, n, z, e; // variables to hold prime numbers for encryption

std::string RsaEncrypt(std::string message){

    GenPublicKey();

    return "blah";
}

void GenPublicKey(){
    int i = 0;
    bool flag = false;
    bool prime;
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
                    return;
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
                    return;
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
    z = (p-1) *(z-1);

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
                return;
            }
        }
    }

    std::cout << "Public key values are (" << n << ", " << e << ")" << std::endl;
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
