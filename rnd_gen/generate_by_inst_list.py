import os
f = open("../list-all")

os.chdir("../")

for inst in f:
    os.system("./load " + inst)
    os.chdir("rnd_gen")
    os.system("julia main.jl")
    os.chdir("../")
    os.system("./load " + inst)
