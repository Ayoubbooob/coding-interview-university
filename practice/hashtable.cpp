#include <bits/stdc++.h>

using namespace std;


int arr[5];



int hashMe(int k, int m){
    return k%m;
}

void add(int key, int value){
    if()
    arr[hashMe(key, 5)] = value;
}


bool exist(int key){
    for(int i=0; i<5; i++){
        if(arr[i] == key) return true;
    }
    return false;
}


void get(int key){
    if(exist(key)){

        printf("The key %d exists in the position %d\n", key, arr[hashMe(key, 5)]);
    }else{
        printf("The key %d does not exist in the array\n", key);

    }

    return ;
}

void displayArray(int arr[5]){
    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
}




int main(){


    add(10, 5); 
    add(84, 5); add(125, 5); add(27, 5); add(91, 5);
    displayArray(arr);


    return 0;
}