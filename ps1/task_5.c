//GROUP : D6
#include <superkarel.h>

void a();

void line(){
    while(front_is_clear()){
        step();
        put_beeper();
    }
    pick_beeper();
}

void center(){
    step();
    while(beepers_present()){
        step();
        if(no_beepers_present()){
            a();
            step();
            if(beepers_present()){
                pick_beeper();
                step();
            }
        }
    }
    a();
    step();
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

void over(){
    while(no_beepers_present()){
        if(!front_is_clear()){
            r();
        }
        put_beeper();
        step();
    }
}


int main(){
    turn_on("task_5.kw");
    set_step_delay(200);
    while(not_facing_north()){
        turn_left();
    }
    while(front_is_clear()){
        step();
    }
    a();
    line();
    a();
    center();
    while(not_facing_east()){
        turn_left();
    }
    while(front_is_clear()){
        step();
    }
    a();
    line();
    a();
    center();
    put_beeper();
    while(front_is_clear()){
        step();
    }
    r();
    over();
    r();
    step();
    while(no_beepers_present()){
        step();
    }
    pick_beeper();
    while(not_facing_north()){
        turn_left();
    }

    turn_off();

    return 1;
}
