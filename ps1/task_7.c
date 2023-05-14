//GROUP : D6


#include <superkarel.h>

void turnl();
void check();
void turn_right();

int main(){
  turn_on("task_7.kw");
  set_step_delay(50);
  while(front_is_clear()){
    if(left_is_clear()){
      turn_left();
      step();
      put_beeper();
      put_beeper();
      turnl();
      step();
      turn_left();
      step();  
      
    }else{
      step();
    }
    
  }
  // ok
  if(left_is_clear()){
    turn_left();
    step();
    put_beeper();
    put_beeper();
    turnl();
    step();  
    turn_left();
  }else{}//ok task1



  turnl();
  while(front_is_clear()){
    step();
  }
  turnl();
    // ok

  while(front_is_clear()){
    if(left_is_clear()){
      check();
    }else{
      step();
    }
  }
  if(front_is_blocked() && right_is_clear()){
    if(left_is_clear()){
      turn_left();
      step();
      pick_beeper();
      pick_beeper();
      turnl();
      step();
      turn_left();
    }else{}
    }

    if (left_is_clear()) {
        turn_left();
        step();
        if (beepers_present()) {
            pick_beeper();
            if (beepers_present()) {
                pick_beeper();
            }
            else {
                put_beeper();
            }
        }
        turn_left();
        turn_left();
        step();
        turn_left();
    }
  
  


  turn_off();
  return 0;
}
void turnl(){
  turn_left();
  turn_left();
}
void check(){
  turn_left();
  step();
  pick_beeper();
  while(front_is_clear()){
    step();
  }
    turn_right();
  while(no_beepers_present()){
    if(front_is_clear() && left_is_blocked()){
      step();
    }else if(front_is_blocked() && left_is_blocked()){
      turn_right();
    }else if(left_is_clear()){
      turn_left();
      step();
    }
  }
  
  
  while(beepers_present()){
    pick_beeper();
    step();
    turn_left();
      if(front_is_clear()){
      step();
    }else{}
  }
  
}
void turn_right(){
  turn_left();
  turn_left();
  turn_left();
}
