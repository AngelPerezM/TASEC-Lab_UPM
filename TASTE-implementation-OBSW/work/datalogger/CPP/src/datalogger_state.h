// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"
#include "Utils/CSVWriter.h"
#include <string>

using namespace utils;

class datalogger_state {
public:
  // Add your members here
  // int counter;
    
    bool stopped_dl = false;
    
    CSVWriter csv_pt1000s;
    CSVWriter csv_tc74s;
    CSVWriter csv_heaters;
    CSVWriter csv_pressure_sensors;
    CSVWriter csv_gps;
    CSVWriter csv_imu;
    CSVWriter csv_anemometer;
    
    std::string pt1000s_fn = "/home/pi/Logs/pt1000s.csv";
    std::string tc74s_fn = "/home/pi/Logs/tc74s.csv";
    std::string heaters_fn = "/home/pi/Logs/heaters.csv";
    std::string pressure_sensors_fn = "/home/pi/Logs/pressure_sensors.csv";
    std::string gps_fn = "/home/pi/Logs/gps.csv";
    std::string imu_fn = "/home/pi/Logs/imu.csv";
    std::string anemometer_fn = "/home/pi/Logs/anemometer.csv";
    
    int nIters = 0;
    asn1SccOBSW_DP_Data all_data;
    
    datalogger_state () : 
        csv_pt1000s(","), csv_tc74s(","), csv_heaters(","),
        csv_pressure_sensors(","), csv_gps(","), csv_imu(","),
        csv_anemometer(",")
    {
        csv_pt1000s.newRow() << "HTL state" << "Time GPS" << "Mission time" << 
                                "anemometro Celsius" << "anemometro Volts" << "anemometro Vcc" <<
                                "aire abajo Celsius" << "aire abajo Volts" << "aire abajo Vcc" <<
                                "infinito Celsius" << "infinito Volts" << "infinito Vcc" <<
                                "aire arriba Celsius" << "aire arriba Volts" << "aire arriba Vcc" <<
                                "exterior Celsius" << "exterior Volts" << "exterior Vcc" <<
                                "placa arriba Celsius" << "placa arriba Volts" << "placa arriba Vcc" <<
                                "placa abajo Celsius" << "placa abajo Volts" << "placa abajo Vcc";

        csv_tc74s.newRow() << "HTL state" << "Time GPS" << "Mission time" <<
                              "TC74-0" << "TC74-1" << "TC74-2" << "TC74-3" << "TC74-4";
        
        csv_heaters.newRow() << "HTL state" << "Time GPS" << "Mission time" <<
                                "heater-anemoemeter" << "heater-HTL";
                                         
        csv_gps.newRow() << "HTL state" << "Mission time" << "Time GPS" << "err time" <<
                            "lat" << "err lat" << 
                            "long" << "err long" <<
                            "alt" << "err alt" << 
                            "course" << "err course" <<
                            "speed" << "err speed" <<
                            "climb" << "err climb";
        
        csv_imu.newRow() << "HTL state" << "Time GPS" << "Mission time" <<
                            "MGT-X raw" << "MGT-Y raw" << "MGT-Z raw" <<
                            "MGT-X mgauss" << "MGT-Y mgauss" << "MGT-Z mgauss" <<
                            "ACC-X raw" << "ACC-Y raw" << "ACC-Z raw" <<
                            "ACC-X mg" << "ACC-Y mg" << "ACC-Z mg" <<
                            "GYRO-X raw" << "GYRO-Y raw" << "GYRO-Z raw" <<
                            "GYRO-X mdps" << "GYRO-Y mdps" << "GYRO-Z mdps" <<
                            "Temp raw" << "Temp Celsius";
                            
        csv_heaters.newRow() << "HTL state" << "Time GPS" << "Mission time" <<"heater-HTL" <<
                                "Time GPS" << "Mission time" <<"heater-anemometer";
    }
    
    ~datalogger_state() {
        writeToFile();
    }
    
    void writeToFile (void) {
        csv_pt1000s.writeToFile(pt1000s_fn, true);                           
        csv_tc74s.writeToFile(tc74s_fn, true);
        csv_heaters.writeToFile(heaters_fn, true);                        
        csv_pressure_sensors.writeToFile(pressure_sensors_fn, true);
        csv_gps.writeToFile(gps_fn, true);
        csv_imu.writeToFile(imu_fn, true);
        csv_anemometer.writeToFile(anemometer_fn, true);
    }

};
