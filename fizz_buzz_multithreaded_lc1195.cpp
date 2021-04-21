//
//  fizz_buzz_multithreaded_lc1195.cpp
//
//  Created by omlenka on 21/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

using namespace std;

class FizzBuzz {
private:
    int n;
    std::mutex m;
    int current_n;
    std::condition_variable cv;
public:
    FizzBuzz(int n) {
        this->n = n;
        this->current_n = 1;
    }
    
    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true){
            unique_lock<mutex> lock(m);
            while(current_n <=n && (current_n % 3 != 0 || current_n % 5 == 0)){
                cv.wait(lock);
            }
            if(current_n > n){
                return;
            }
            printFizz();
            current_n++;
            cv.notify_all();
        }
    }
    
    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(true){
            unique_lock<mutex> lock(m);
            while(current_n <=n && (current_n % 5 !=0 || current_n % 3 == 0)){
                cv.wait(lock);
            }
            if(current_n > n){
                return;
            }
            printBuzz();
            current_n++;
            cv.notify_all();
        }
    }
    
    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while(true){
            unique_lock<mutex> lock(m);
            while(current_n <=n && (current_n % 5 !=0 || current_n % 3 != 0)){
                cv.wait(lock);
            }
            if(current_n > n){
                return;
            }
            printFizzBuzz();
            current_n++;
            cv.notify_all();
        }
    }
    
    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> lock(m);
            while(current_n <=n && (current_n % 5 ==0 || current_n % 3 == 0)){
                cv.wait(lock);
            }
            if(current_n > n){
                return;
            }
            printNumber(current_n);
            current_n++;
            cv.notify_all();
        }
    }
};
