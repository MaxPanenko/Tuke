//GROUP : D6
#include <superkarel.h>

int main(){
    turn_on("task_6.kw");
    set_step_delay(50);
    while(1){
        if(no_beepers_present())
            step();
        if(!no_beepers_present()){
            pick_beeper();
            while(not_facing_north())
                turn_left();
        }
        if(!no_beepers_present()){pick_beeper();turn_left();}
        if(!no_beepers_present()){pick_beeper();turn_left();}
        if(!no_beepers_present()){pick_beeper();turn_left();}
        if(!no_beepers_present()){pick_beeper();break;}
        }
    turn_off();
    return 0;
}
