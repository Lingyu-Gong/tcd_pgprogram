import numpy as np
#from tqdm import tqdm

# check wether is odd or not
def check_odd_filterlen(window_size):
    if(len(window_size)% 2 == 1):
        print("The window length can works, please keep going.")
    else:
        raise ValueError("Error: The window size is not odd.")

# input
read_doc = open("C:/Users/gongl/OneDrive - Trinity College Dublin/Desktop/bk.txt", "r") # import bk
click_doc = read_doc.readlines()
window_size = int(input("Please input your window size: "))

click_pos = []

# find the position of the clicks
for i in range(len(click_doc)):
    click_doc[i] = click_doc[i].strip('\n')
    click_doc[i] = click_doc[i].split(' ')

click_pos = np.array(click_doc)
click_pos = np.where(click_pos == 0)
print(click_pos)
