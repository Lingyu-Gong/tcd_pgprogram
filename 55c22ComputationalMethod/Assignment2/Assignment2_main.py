#Assignment2_main.py

import numpy as np
import unittest
import scipy.io.wavfile as wav
import matplotlib.pyplot as plt

#from tqdm import tqdm

# import data
## input window size
window_size = int(input("Please input your window size: "))
## read audio file
fs, audio_clean = wav.read('C:/GONG/pgprogram/tcd_pgprogram/55c22ComputationalMethod/Assignment2/clean.wav')
fs, audio_degraded = wav.read('C:/GONG/pgprogram/tcd_pgprogram/55c22ComputationalMethod/Assignment2/degraded.wav')

## show input audio
fig = plt.figure()
ax1 = fig.add_subplot(2, 1, 1)
ax2 = fig.add_subplot(2, 1, 2)
ax1.plot(audio_clean)
ax1.set_title('Clean Audio', fontdict={'size': 10})
ax1.set_xlabel('Time')
ax1.set_ylabel('Amplitude')
ax1.tick_params(axis='both', labelsize=10)
fig.suptitle('Original Signal', fontdict={'size': 10})

ax2.plot(audio_degraded)
ax2.set_title('Degraded Audio', fontdict={'size': 10})
ax2.set_xlabel('Time')
ax2.set_ylabel('Amplitude')
ax2.tick_params(axis='both', labelsize=8)
plt.rcParams['font.size'] = 8
plt.show()

# check wether is odd or not
def check_odd_filterlen(window_size):
    if(len(window_size)% 2 == 1):
        print("The window length can works, please keep going.")
    else:
        raise ValueError("Error: The window size is not odd.")

click_doc = np.loadtxt("C:/GONG/pgprogram/tcd_pgprogram/55c22ComputationalMethod/Assignment2/bk.txt")

# Find the position
click_pos = np.where(click_doc == 1)
click_pos_len = np.shape(click_pos)
print(click_pos_len)

# Median Filter
audio_len = len(audio_degraded)
print(audio_len)

# find the position and choose block
for i in range(audio_len):
    for k in range(click_pos_len):
        if(i == click_pos(k)):
            


def calculate_med_num(input_data, window_size):
    """
    Calculate the moving median of a sequence of numbers.

    Args:
        input_data (str): A string of integers separated by spaces
        window_size (int): The size of window. Must be a positive integer.

    Returns:
        list: A list of medians for each window position.
    """
    num = [int(n) for n in input_data.split()]
    length_padding = (window_size-1)/ 2
    padding = [0] * int(length_padding)
    num = padding + num + padding

    # design median function
    len_input_data = len(num)
    median_arr = []
    reorder_arr = []

    for i in range(len_input_data):
        if(i+window_size <= len_input_data):
            # in order
            reorder_arr = num[i: i+window_size]
            reorder_arr.sort()
            if(window_size % 2 == 0): # if even
                mid_num = (reorder_arr[window_size//2]+ reorder_arr[window_size//2- 1])/ 2
                median_arr.append(mid_num)
            elif (window_size % 2 == 1): # if odd
                mid_num = reorder_arr[window_size//2]
                median_arr.append(mid_num)
    
    return median_arr


median_arr = calculate_med_num(input_data, window_size)
print("Result:", median_arr)


class TestMedianArrayFunction(unittest.TestCase):
    def test_odd_window_size(self):
        input_data = "1 2 3 4 5"
        window_size = 3
        expected_output = [1, 2, 3, 4, 4]
        self.assertEqual(calculate_med_num(input_data, window_size), expected_output)

    def test_even_window_size(self):
        input_data = "1 2 3 4 5 6"
        window_size = 4
        expected_output = [1.5, 2.5, 3.5, 4.5, 4.5]
        self.assertEqual(calculate_med_num(input_data, window_size), expected_output)

    def test_single_element(self):
        input_data = "5"
        window_size = 1
        expected_output = [5]
        self.assertEqual(calculate_med_num(input_data, window_size), expected_output)

    def test_empty_input(self):
        input_data = ""
        window_size = 3
        expected_output = []
        self.assertEqual(calculate_med_num(input_data, window_size), expected_output)

if __name__ == '__main__':
    unittest.main()