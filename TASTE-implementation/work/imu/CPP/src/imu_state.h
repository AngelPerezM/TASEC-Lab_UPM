// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"
#include <iostream>
#include "EquipementHandlers/IMU.h"

using namespace equipementHandlers;

class imu_state {
public:
  // Add your members here
  // int counter;
    IMU imu;
    double et = 0.0;
    int nIters = 0.0;    
    
    imu_state() : imu (1) {
        ;
    }
    
    ~imu_state() {
        std::cout << "+-------------------------------------------------------------\n"
                  << "| IMU::readIMUData = " << std::to_string(et/nIters) << "\n"
                  << "+-------------------------------------------------------------" << std::endl;
    }

};
