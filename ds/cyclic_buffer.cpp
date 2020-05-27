//
// Created by rajverm2 on 27/05/20.
//

#include "cyclic_buffer.h"

#include <iostream>

void cyclic_buffer::add(int a){
    if(start == -1){
        start  = 0;
        end = 1;
        buffer[start]=a;
    }else{
        if(end == start){
            start=next(start);
            buffer[end]=a;
            end=next(end);
        }else{
            buffer[end]=a;
            end=next(end);
        }
    }
}

void cyclic_buffer::pop_front(){
    if(start == -1){
        return;;
    }
    start = next(start);
    if(start == end){
        start = -1;
        end = -1;
    }
}

void cyclic_buffer::pop_back(){
    if(start == -1){
        return;
    }
    end = back(end);
    if(end == start ){
        start = -1;
        end = -1;
    }
}