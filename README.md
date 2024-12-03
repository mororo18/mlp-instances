# mlp-instances 

## Setup

```
sudo apt install gcc make
```

## Build

After compilation, the generated executable `load` will be moved outside the `loader/` directory.
```
cd loader/
make
cd ../
```
## Run

After execution, the generated file `distance-matrix` will be copied to the parent directory.
```
./load <instace-name>.tsp
```
