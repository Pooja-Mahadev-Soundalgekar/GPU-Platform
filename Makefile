#A432-3, plateforme NVidia
all:
	g++ -Wall plateformes_OpenCL.cpp -o plateformes_OpenCL -I/usr/local/cuda/include -L/usr/lib/x86_64-linux-gnu -lOpenCL 
# En fait, inutile de spécifier le -L
# à noter que l'exéc. de cette compilation génèrre un segfault d'entrée au load de la dll OpenCL
#	g++ -Wall plateformes_OpenCL.cpp -o plateformes_OpenCL -I/usr/local/cuda/include -L/usr/local/cuda/lib64 -lOpenCL 
intel:
	g++ -Wall plateformes_OpenCL.cpp -o plateformes_OpenCL -I/opt/intel/opencl/include -lOpenCL
clean:
	rm plateformes_OpenCL *~
 
