#include <vector>
#include <iostream>
#define MAX_SIZE 501
using namespace std;

enum State{
    STATE_NONE,
    STATE_START
};
int main(){
    int h, w;
    int world[MAX_SIZE][MAX_SIZE] = {0,};//w h
    cin>>h>>w;

    for(int i = 0; i < w; i++){
        int height;
        cin>>height;
        for(int j = 0; j < height; j++){
            world[i][j] = 1;
        }
    }


    int ans = 0;
    for(int i = 0; i < h; i++){
        State state = STATE_NONE;
        int water = 0;
        for(int j = 0; j < w; j++){
            if(state == STATE_START && world[j][i] == 0){
                water++;
            }
            if(world[j][i] == 1){
                if(state == STATE_NONE){
                    state = STATE_START;
                }
                else if(state == STATE_START){
                    ans += water;
                    water = 0;
                }
            }
        }
    }

    cout<<ans;
return 0;
}
