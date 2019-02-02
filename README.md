# filler
## Filler
The goal of this project is to code an AI for the game of Filler, for which we have a virtual machine.
## Compiling and running
run 
``` 
git clone https://github.com/superuzer/filler.git ~/Filler
cd ~/Filler
make
```
My bot was compiled (iganich.filler). To see it in action, run the VM
```
./resources/filler_vm -f resources/maps/map00 -p1 ./iganich.filler -p2 resources/players/superjeannot.filler
```
