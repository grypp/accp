#guray ozen
#accp with ompss simple makefile



#EXTRAEO	= --instrument

CC     =  gcc 
ACCP	= accp
MNVCC   = mnvcc
NVCC   = nvcc
CFLAGS  = -Wall -std=c99 -O2
CUFLAGS  = -O2 $(EXTRAEO)
OMPFLAGS = -fopenmp

#EXTRAEI	= -I$(EXTRAE_HOME)/include 
#EXTRAEL	= -L$(EXTRAE_HOME)/lib -lomptrace -L/usr/lib64 -lrt

SOURCE = vecadd.c

ALL 	= accp-backend accp-frontend ompss

all:  $(ALL)

accp-backend: kernel.cu grouplet.cu
	$(ACCP) -i __*.cu -o kernel.cu -k
	$(ACCP) -i __*.cu -o grouplet.cu -g

accp-frontend: $(SOURCE)_ompss.c
	$(ACCP) -i $(SOURCE) -o $(SOURCE)_ompss.c -f $(SOURCE)*.translated.i

ompss: 	$(SOURCE)_ompss.x
	$(MNVCC) $(EXTRAEO) --ompss $(SOURCE)_ompss.c kernel.cu grouplet.cu -o$(SOURCE)_ompss.x

.PHONY: clean

clean:
        rm -f *.o oa __hmpp* *.lst *.cub *.ptx *.prv *.pcf 

