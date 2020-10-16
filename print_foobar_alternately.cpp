//
//  print_foobar_alternately.cpp
//
//  Created by omlenka on 16/10/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <pthread.h>

using namespace std;

class FooBar {
private:
    int n;
    pthread_cond_t condition;
    pthread_mutex_t mutex;
    bool fooPrinted;
    bool barPrinted;
    
public:
    FooBar(int n) {
        this->n = n;
        pthread_mutex_init(&mutex, NULL);
        pthread_cond_init(&condition, NULL);
        fooPrinted = false;
        barPrinted = true;
    }
    
    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
            // printFoo() outputs "foo". Do not change or remove this line.
            pthread_mutex_lock(&mutex);
            while(!barPrinted)
                pthread_cond_wait(&condition, &mutex);
            printFoo();
            fooPrinted = true;
            barPrinted = false;
            pthread_cond_signal(&condition);
            pthread_mutex_unlock(&mutex);
        }
    }
    
    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
            // printBar() outputs "bar". Do not change or remove this line.
            pthread_mutex_lock(&mutex);
            while(!fooPrinted)
                pthread_cond_wait(&condition, &mutex);
            printBar();
            barPrinted = true;
            fooPrinted = false;
            pthread_cond_signal(&condition);
            pthread_mutex_unlock(&mutex);
        }
    }
};
