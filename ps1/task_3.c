//GROUP : D6
#include <superkarel.h>

void home1();

void zero(){
    while(front_is_clear()){
        if(beepers_present()){
            pick_beeper();
        }
        step();
    }
    if(beepers_present()){
        pick_beeper();
    }
}

void a(){
    turn_left();
    turn_left();
}

void r(){
    turn_left();
    turn_left();
    turn_left();
}

void step_back(){
    while(front_is_clear()){
        if(right_is_blocked()){
            if(beepers_in_bag()){
                put_beeper();
            }
        }
        step();
    }
}

void step_back1(){
    while(front_is_clear()){
        r();
        step();
        if(beepers_present()){
            a();
            step();
            r();
            if(beepers_in_bag()){
                put_beeper();
            }
            step();
        } else {
            a();
            step();
            r();
            step();
        }
    }
    if(left_is_blocked()){
        home1();
        turn_off();
    }
}

void home(){
    turn_left();
    step();
    turn_left();
    while(no_beepers_present()){
        step();
    }
    r();
    while(front_is_clear()){
        step();
    }
    turn_left();
    while(front_is_clear()){
        step();
    }
    a();
}

void home1(){
    r();
    step();
    r();
    while(no_beepers_present()){
        step();
    }
    turn_left();
    while(front_is_clear()){
        step();
    }
    turn_left();
    while(front_is_clear()){
        step();
    }
    a();
}

int main(){
    turn_on("task_3.kw");
    set_step_delay(5);
    zero();
    a();
    step_back();
    do{
        turn_left();
        step();
        turn_left();
        zero();
        if(!beepers_in_bag()){
            break;
        }
        a();
        step_back1();
    }while(front_is_clear() || left_is_clear());
    home();
    turn_off();
    return 1;
}
