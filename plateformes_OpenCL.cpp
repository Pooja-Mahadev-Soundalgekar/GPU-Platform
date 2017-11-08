#define __CL_ENABLE_EXCEPTIONS
#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#ifdef __APPLE__
#include <OpenCL/cl.hpp>
#else
#include <CL/cl.hpp>
#endif

#include <cstdlib>
#include <iostream>
#include <map>
#include <cmath>
#include <fstream>
#include <string>


void showPlatforms();

int main(int argc, char** argv) {
   showPlatforms();
   return 0;
}

// show available platforms and devices
void showPlatforms() {
   std::vector<cl::Platform> platforms;
   std::cout << "Maps" << std::endl;
   std::map<int,std::string> dev_type_name;
   dev_type_name[CL_DEVICE_TYPE_CPU] = "CPU";
   dev_type_name[CL_DEVICE_TYPE_GPU] = "GPU";
   std::cout << "Dev. name type" << std::endl;
   std::map<int,std::string> local_mem_type_name;
   local_mem_type_name[CL_LOCAL] = "LOCAL";
   local_mem_type_name[CL_GLOBAL] = "GLOBAL";
   std::cout << "Mem. name type" << std::endl;  
   try {
      cl::Platform::get(&platforms);
      std::cout << "Nb. platforms: " << platforms.size() << std::endl;
      for (unsigned int i=0;i<platforms.size();i++){
         std::cout<<"Platform[" << i << "]: "<<platforms[i].getInfo<CL_PLATFORM_NAME>()<<std::endl;
         std::vector<cl::Device> devices;
         platforms[i].getDevices(CL_DEVICE_TYPE_GPU | CL_DEVICE_TYPE_CPU, &devices);
         for (unsigned int j=0;j<devices.size();j++) {
            std::cout << "\t Device[" << j << "]" << std::endl;
            std::cout << "\t\t" << dev_type_name[devices[j].getInfo<CL_DEVICE_TYPE>()]
                      << ": "  << devices[j].getInfo<CL_DEVICE_MAX_COMPUTE_UNITS>() 
                      << " compute units, " << devices[j].getInfo<CL_DEVICE_NAME>() << std::endl;
            std::cout << "\t\t   : "  << devices[j].getInfo<CL_DEVICE_GLOBAL_MEM_SIZE>()/1000000 
                      << " [Mbytes] DRAM" << std::endl;
            std::cout << "\t\t   : "  << devices[j].getInfo<CL_DEVICE_LOCAL_MEM_SIZE>()/1000 
                      << " [Kbytes] local memory"
                      << " of type " << local_mem_type_name[devices[j].getInfo<CL_DEVICE_LOCAL_MEM_TYPE>()] 
                      << std::endl;
            std::cout << "\t\t   : max. " << (int)sqrt(devices[j].getInfo<CL_DEVICE_LOCAL_MEM_SIZE>()/sizeof(float))
                      << " matrix block size" << std::endl;
            std::cout << "\t\t   : max. "  << devices[j].getInfo<CL_DEVICE_MAX_WORK_GROUP_SIZE>() 
                      << " work group size" << std::endl;
            std::cout << "\t\t   : max. ("     
                      << (devices[j].getInfo<CL_DEVICE_MAX_WORK_ITEM_SIZES>())[0] << ","
                      << (devices[j].getInfo<CL_DEVICE_MAX_WORK_ITEM_SIZES>())[1] << ","
                      << (devices[j].getInfo<CL_DEVICE_MAX_WORK_ITEM_SIZES>())[2] << ")"
                      << " work items per work group and dimension" << std::endl;
         }
      }
   } catch(cl::Error error) {
      std::cerr << error.what() << "(" << error.err() << ")" << std::endl;
   }
}



