#include <superkarel.h>

void start();

void ar(){
    turn_left();
    turn_left();
}

void r(){
    turn_left();
    turn_left();
    turn_left();
}

void end(){
    turn_left();
    while(right_is_blocked()){
        step();
    }
    r();
    step();
    while(right_is_blocked()){
        step();
    }
    r();
    while(front_is_clear()){
        step();
    }
    turn_left();
    while(front_is_clear()){
        if(beepers_present()){
            pick_beeper();
            ar();
            while(front_is_clear()){
                step();
                if(beepers_present()){
                    pick_beeper();
                    turn_off();
                }
            }
            while(no_beepers_present()){
                start();
            }
            pick_beeper();
            turn_off();
        }
        step();
    }
    
}

void start(){
    r();
    while(left_is_blocked()){
        step();
    }
    turn_left();
    step();
    while(left_is_blocked()){
        step();
    }
    turn_left();
    while(front_is_clear()){
        step();
    }
    r();
    while(front_is_clear()){
        if(beepers_present()){
            pick_beeper();
            turn_off();
        }
        step();
    }
}

int main(){
    turn_on("task_1.kw");
    set_step_delay(1000);
    put_beeper();
    if(front_is_clear()){
        step();
    }
    while(front_is_clear()){
        if(no_beepers_present()){
            step();
        } 
        else 
        {
            pick_beeper();
            ar();
            while(no_beepers_present()){
                step();
            }
            pick_beeper();
            turn_off();
       }
    }
    if(front_is_blocked()){
        turn_left();
        step();
        r();
    }
    while(no_beepers_present()){
        end();
    }
    pick_beeper();
    ar();
    while(front_is_clear()){
        step();
    }
    while(no_beepers_present()){
        start();
    }
    pick_beeper();
    turn_off();
    return 1;
}

