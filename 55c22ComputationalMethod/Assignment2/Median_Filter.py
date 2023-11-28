#Assignment2_main.py

import numpy as np
import unittest
import scipy.io.wavfile as wav
import matplotlib.pyplot as plt
from tqdm import tqdm


# import data
## input window size
window_size = int(input("Please input your window size: "))
## read audio file
fs, audio_clean = wav.read('C:/GONG/pgprogram/tcd_pgprogram/55c22ComputationalMethod/Assignment2/clean.wav')
fs, audio_degraded = wav.read('C:/GONG/pgprogram/tcd_pgprogram/55c22ComputationalMethod/Assignment2/degraded.wav')
#print(fs)
audio_clean = audio_clean / 32678
audio_clean = audio_clean / 2
audio_degraded = audio_degraded / 32678
#----------------------------------Vitualization----------------------------------------#
## show input audio
fig = plt.figure()
ax1 = fig.add_subplot(3, 1, 1)
ax2 = fig.add_subplot(3, 1, 2)
ax3 = fig.add_subplot(3, 1, 3)

ax1.plot(audio_clean)
ax1.set_title('Clean Audio', fontdict={'size': 10})
ax1.set_xlabel('Time')
ax1.set_ylabel('Amplitude')
ax1.tick_params(axis='both', labelsize=8)

ax2.plot(audio_degraded)
ax2.set_title('Degraded Audio', fontdict={'size': 10})
ax2.set_xlabel('Time')
ax2.set_ylabel('Amplitude')
ax2.tick_params(axis='both', labelsize=8)


# check wether is odd or not
def check_odd_filterlen(window_size):
    """_summary_

    Args:
        window_size (_type_): _description_

    Raises:
        ValueError: _description_
    """
    if(len(window_size)% 2 == 1):
        print("The window length can works, please keep going.")
    else:
        raise ValueError("Error: The window size is not odd.")

click_doc = np.loadtxt("C:/GONG/pgprogram/tcd_pgprogram/55c22ComputationalMethod/Assignment2/bk.txt")

# Find the position
click_pos = np.where(click_doc == 1)
click_pos_len = np.shape(click_pos)
print('The number of clicks in your audio: ', click_pos_len[1])

# Median Filter
audio_len = len(audio_degraded)
#print(audio_len)

def calculate_med_num(input_data, window_size):
    """
    Calculate the moving median of a sequence of numbers.

    Args:
        input_data (str): A string of integers separated by spaces
        window_size (int): The size of window. Must be a positive integer.

    Returns:
        list: A list of medians for each window position.
    """
    # design median function
    len_input_data = len(input_data)
    reorder_arr = np.array(window_size)

    for i in range(len_input_data):
        if(i+ window_size <= len_input_data):
            # in order
            reorder_arr = input_data[i: i+window_size]
            reorder_arr = list(reorder_arr)
            reorder_arr.sort()
            mid_num = reorder_arr[window_size//2]
    
    return mid_num

def calculate_mse(actual, predicted):
    """Calculate Mean Squared Error between actual and predicted values.

    Args:
        actual (array): Array of actual values.
        predicted (array): Array of predicted values.

    Returns:
        float: Mean Squared Error.
    """
    # Calculate MSE
    mse = np.mean((actual - predicted) ** 2)
    return mse

#-------------------------------Eliminate the clicks----------------------------------------#

for i in tqdm(click_pos[0], desc="Processing clicks"):
    block_size = int((window_size-1)/ 2)
    block = audio_degraded[i- block_size: i+ block_size+ 1]
    mid_num = calculate_med_num(block, window_size) # get the restored data
    audio_degraded[i] = mid_num


audio_restored = wav.write("C:/GONG/pgprogram/tcd_pgprogram/55c22ComputationalMethod/Assignment2/Restored_Audio.wav", fs, audio_degraded)

fs, audio_restored = wav.read('C:/GONG/pgprogram/tcd_pgprogram/55c22ComputationalMethod/Assignment2/Restored_Audio.wav')
ax3.plot(audio_restored)
ax3.set_title('Restored Audio', fontdict={'size': 10})
ax3.set_xlabel('Time')
ax3.set_ylabel('Amplitude')
ax3.tick_params(axis='both', labelsize=8)

plt.tight_layout()
plt.show()


#---------------------------------------Calculate MSE----------------------------------------#

mse_score = calculate_mse(audio_clean[click_pos[0]], audio_restored[click_pos[0]])            
print("MSE score: ", mse_score)



class TestAudioProcessing(unittest.TestCase):

    def test_calculate_med_num(self):
        # Example test for calculate_med_num
        data = np.array([1, 2, 3, 4, 5])
        window_size = 3
        expected_median = 4
        result = calculate_med_num(data, window_size)
        self.assertEqual(result, expected_median, "The median calculation is incorrect")

if __name__ == '__main__':
    unittest.main()