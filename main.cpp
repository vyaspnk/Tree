//
//  main.cpp
//  Tree
//
//  Created by Vijetha Malla on 2/15/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
using namespace std;
void foo(int x) {
    while(x){
        foo(x--);
    }
    cout << x;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    foo(2);
    return 0;
}
