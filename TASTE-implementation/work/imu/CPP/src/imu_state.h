// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"
#include <iostream>
#include <unistd.h> // usleep
#include "EquipementHandlers/IMU.h"

using namespace equipementHandlers;

class imu_state {
public:
  // Add your members here
  // int counter;
    IMU imu;
    double et = 0.0;
    int nIters = 0.0;    
    int fifo_nSamples = 0;
    int fifo_capacity = 30;
    
    imu_state() : imu (1) {

    }
    
    void stop () {
        std::cout << "+-------------------------------------------------------------\n"
                  << "| IMU::readIMUData = " << std::to_string(et/nIters) << "\n"
                  << "+-------------------------------------------------------------" << std::endl;
        imu.accAndGyro.disableFIFO();
        usleep(20000);
        imu.accAndGyro.setFIFO(0, 0x00);
        imu.~IMU();
    }

};
