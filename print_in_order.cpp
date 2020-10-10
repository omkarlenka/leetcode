//
//  print_in_order.cpp
//
//  Created by omlenka on 10/10/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <pthread.h>

using namespace std;

class Foo {
    pthread_cond_t condition;
    pthread_mutex_t mutex;
    int printed;
public:
    Foo() {
        pthread_cond_init(&condition, NULL);
        pthread_mutex_init(&mutex, NULL);
        printed = 0;
    }
    
    ~Foo(){
        pthread_cond_destroy(&condition);
        pthread_mutex_destroy(&mutex);
    }
    
    void first(function<void()> printFirst) {
        pthread_mutex_lock(&mutex);
        printFirst();
        printed = 1;
        pthread_cond_broadcast(&condition);
        pthread_mutex_unlock(&mutex);
    }
    
    void second(function<void()> printSecond) {
        pthread_mutex_lock(&mutex);
        while(printed != 1)
            pthread_cond_wait(&condition, &mutex);
        printSecond();
        printed = 2;
        pthread_cond_broadcast(&condition);
        pthread_mutex_unlock(&mutex);
    }
    
    void third(function<void()> printThird) {
        pthread_mutex_lock(&mutex);
        while(printed != 2)
            pthread_cond_wait(&condition, &mutex);
        printThird();
        pthread_mutex_unlock(&mutex);
    }
};
