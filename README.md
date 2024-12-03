# mlp-instances 

## Setup

```
sudo apt install gcc make
```

## Build

```
cd loader/
make
cd ../
```
After compilation, the generated executable `load` will be moved outside the `loader/` directory.

## Run

```
./load <instace-name>.tsp
```
After execution, the generated file `distance-matrix` will be copied to the parent directory.
