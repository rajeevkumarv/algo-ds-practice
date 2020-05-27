//
// Created by rajverm2 on 27/05/20.
//

#include <gtest/gtest.h>
#include "cyclic_buffer.h"

class TestCyclicBuffer : public ::testing::Test{
protected:

    cyclic_buffer *cyclicBuffer = nullptr;

    void SetUp(){
        cyclicBuffer = new cyclic_buffer(5);
    }
    void TearDown(){
        delete cyclicBuffer;
    }
};

TEST_F(TestCyclicBuffer,testLen1InsertDelete){
    cyclicBuffer->add(100);
    ASSERT_EQ(cyclicBuffer->front(), 100);
    ASSERT_EQ(cyclicBuffer->size(), 1);
    ASSERT_EQ(cyclicBuffer->empty(), false);
}

TEST_F(TestCyclicBuffer,testAllInsert){
    cyclicBuffer->add(100);
    cyclicBuffer->add(200);
    cyclicBuffer->add(300);
    cyclicBuffer->add(400);
    cyclicBuffer->add(500);
    ASSERT_EQ(cyclicBuffer->front(), 100);
    ASSERT_EQ(cyclicBuffer->back(), 500);

    cyclicBuffer->add(600);
    ASSERT_EQ(cyclicBuffer->front(), 200);
    ASSERT_EQ(cyclicBuffer->back(), 600);

    cyclicBuffer->add(700);
    ASSERT_EQ(cyclicBuffer->front(), 300);
    ASSERT_EQ(cyclicBuffer->back(), 700);

    cyclicBuffer->add(800);
    ASSERT_EQ(cyclicBuffer->front(), 400);
    ASSERT_EQ(cyclicBuffer->back(), 800);

    cyclicBuffer->add(900);
    ASSERT_EQ(cyclicBuffer->front(), 500);
    ASSERT_EQ(cyclicBuffer->back(), 900);

    cyclicBuffer->add(1000);
    ASSERT_EQ(cyclicBuffer->front(), 600);
    ASSERT_EQ(cyclicBuffer->back(), 1000);

}

TEST_F(TestCyclicBuffer,testDeleteAllFromBack){
    cyclicBuffer->add(100);
    cyclicBuffer->add(200);
    cyclicBuffer->add(300);
    cyclicBuffer->add(400);
    cyclicBuffer->add(500);
    cyclicBuffer->add(600);
    cyclicBuffer->add(700);

    ASSERT_EQ(cyclicBuffer->back(), 700);

    cyclicBuffer->pop_back();
    ASSERT_EQ(cyclicBuffer->back(), 600);

    cyclicBuffer->pop_back();
    ASSERT_EQ(cyclicBuffer->back(), 500);

    cyclicBuffer->pop_back();
    ASSERT_EQ(cyclicBuffer->back(), 400);

    cyclicBuffer->pop_back();
    ASSERT_EQ(cyclicBuffer->back(), 300);

    cyclicBuffer->pop_back();
    ASSERT_EQ(cyclicBuffer->empty(), true);

}


TEST_F(TestCyclicBuffer,testDeleteAllFromFront){
    cyclicBuffer->add(100);
    cyclicBuffer->add(200);
    cyclicBuffer->add(300);
    cyclicBuffer->add(400);
    cyclicBuffer->add(500);
    cyclicBuffer->add(600);
    cyclicBuffer->add(700);

    ASSERT_EQ(cyclicBuffer->front(), 300);

    cyclicBuffer->pop_front();
    ASSERT_EQ(cyclicBuffer->front(), 400);

    cyclicBuffer->pop_front();
    ASSERT_EQ(cyclicBuffer->front(), 500);

    cyclicBuffer->pop_front();
    ASSERT_EQ(cyclicBuffer->front(), 600);

    cyclicBuffer->pop_front();
    ASSERT_EQ(cyclicBuffer->front(), 700);

    cyclicBuffer->pop_front();
    ASSERT_EQ(cyclicBuffer->empty(), true);

}