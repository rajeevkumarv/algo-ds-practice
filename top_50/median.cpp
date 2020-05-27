//
// Created by rajverm2 on 16/05/20.
//

#include "std_def.h"

float median_of_sorted_arrays(vector<int>& arr1,vector<int> &arr2){

    int x = 0;
    int y = 0;
    int n = (arr1.size() + arr2.size())/2+1;
    int i = 0;
    int j = 0;

    while(i < arr1.size() && j < arr2.size() && n > 0 ){
    }

    return 0;
}

TEST(median,median_of_two_sorted_ranges){
    vector<int> arr1 = {1,2,3};
    vector<int> arr2 = {3,4,5};
    EXPECT_EQ(3.5,median_of_sorted_arrays(arr1,arr2));
}