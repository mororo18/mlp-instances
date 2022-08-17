import os

list_path = os.path.abspath("../list-all")
#f = open(list_path)

from os import listdir
from os.path import isfile, join
instdir =os.path.abspath("..") 
rnddir =os.path.abspath("../rnd") 

inst_files = [f.replace('.tsp', '') for f in listdir(instdir) if isfile(join(instdir, f)) and f.find('.tsp') != -1]
rnd_files = [f.replace('.rnd', '') for f in listdir(rnddir) if isfile(join(rnddir, f))]

numbrs = [str(n) for n in range(0, 10)]

def inst_size(inst):
    size = int(''.join([char for char in inst if char in numbrs]))
    return size

SIZE = 201
        
inst_gen = [inst for inst in inst_files if (inst_size(inst) < SIZE)]
#inst_gen = [inst for inst in inst_files if (inst not in rnd_files and inst_size(inst) < SIZE)]

#inst_list = [inst for

print(len(inst_gen))
#exit(0)
myList = open("myList", "w")
for inst in inst_gen:
    myList.write(inst + ".tsp\n")

myList.close()

"""
os.chdir("../")

for inst in inst_gen:
    inst += '.tsp'
    print(inst)
    #continue
    #exit(0)
    os.system("./load " + inst)
    os.chdir("rnd_gen")
    os.system("julia main.jl")
    os.chdir("../")
    os.system("./load " + inst)
    """
