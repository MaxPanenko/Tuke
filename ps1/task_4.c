//GROUP : D6
#include <superkarel.h>
void k(){
    while(not_facing_north())turn_left();
    while(front_is_clear())step();
    turn_left();
    turn_left();
    while(front_is_clear()){
    if(no_beepers_present()){put_beeper();step();}
    else step();
    }
    if(no_beepers_present())put_beeper();
}
	int main(){
		turn_on("task_4.kw");
		set_step_delay(50);
while(front_is_clear()){
	turn_left();
while(front_is_clear()){
	if(!no_beepers_present()){k();break;}
   	step();
	if(!no_beepers_present()){k();break;}
	}
		while(not_facing_south())turn_left();
		while(front_is_clear())step();
			turn_left();
			step();
		}
		turn_left();
			while(front_is_clear()){step();
			if(!no_beepers_present()){
   				 k();break;
        		 }
			}
				while(not_facing_south())turn_left();
				while(front_is_clear())step();
					turn_left();
					turn_off();
						return 0;
		}
