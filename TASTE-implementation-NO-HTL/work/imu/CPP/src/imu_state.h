// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"
#include "EquipementHandlers/IMU.h"

using namespace equipementHandlers;

class imu_state {
public:
  // Add your members here
  // int counter;
    IMU imu;
    
    imu_state() : imu (1) {
        ;
    }

};
