#include "../Engine/space.h"

int main(int, char**){
    space app;
    
    while(app.running()) {
        app.run();
    }
    return 0;
}
