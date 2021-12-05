#include <functional>
//#include "global_variables.h"
using namespace std;
class parameter {
    public:
        int midi_control; // midi control number (0-127);
        double value; //calculated value
        int position; // physical position of potentiometer (0-1023)
        int old_position; // old physical position (0-1023)

        int mux_position; // which pin of the mux to read (0-15)
        int mux_address; // which mux to search in (0-2)

        function <int (int)> scaling_function; //function to convert raw value into useable
        function <void (int)> update_function; //function to update synth with value
        
        parameter(int n_midi_control, int n_mux_address, int n_mux_position, function <int (int)> n_scaling_function, function <void (int)> n_update_function) {
            midi_control = n_midi_control;
            mux_position = n_mux_position;
            mux_address = n_mux_address;
            scaling_function = n_scaling_function;
            update_function = n_update_function;
        };
                
        void initialize() {
            old_position = position = read();
        }

        int check() {
            int temp = read();
            if (temp != old_position) {
                old_position = position = temp;
                value = calculate(position);
            } else {
                return -1;
            }
        };

        int calculate(int n_position) {
            return scaling_function(n_position);
        }

        read() {
            return mux_array[mux_address].Mux::read(mux_position);
        }
};
