//GROUP :i D6
#include <superkarel.h>

int main(){
turn_on("task_2.kw");
set_step_delay(100);

   while(1){
    if(front_is_clear())step();
    if(left_is_clear())turn_left();
    if(!no_beepers_present()){pick_beeper();break;}
   }
	turn_left();
	turn_left();
   while(1){
    if(front_is_clear())step();
    if(right_is_clear()){turn_left();turn_left();turn_left();}
    if(front_is_blocked()&&left_is_blocked()&&right_is_blocked())break;
   }
	turn_left();
	turn_left();
	turn_left();
	turn_off();
	return 0;
	}
